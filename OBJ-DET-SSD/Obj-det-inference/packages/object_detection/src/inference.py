import tensorflow as tf
import numpy as np
from PIL import Image
import json
import time
import os

# loop over the class labels file
labels = {}
colors = {}
for row in open("/code/catkin_ws/src/coral/packages/object_detection/src/duckie_labels_colors.txt"):
	# unpack the row and update labels and colors dictionaries
	(classID, label, color) = row.strip().split(";")
	labels[int(classID)] = label.strip()
	colors[int(classID)] = color.strip()

try:
	MODEL_NAME = str(os.environ['model_name'])
except:
	print("Model is not specified. To specify, set environment variable model_name to your model choice (e.g. -e model_name=MODEL_NAME).")
	print("Choices are: augmentation, class, localization, class_localization, vanilla")
	print("Model is set to default (class_localization)")
	MODEL_NAME = 'simple_wo_tf'

#if MODEL_NAME not in ["simple_wo_tf","augmentation", "class", "localization", "class_localization", "vanilla"]:
#    print("No correct model is chosen. Model is set to default (class_localization).")
#    MODEL_NAME = 'simple_wo_tf'


# Retrieve threshold
try:
	THRESHOLD = float(os.environ['threshold'])
except:
	THRESHOLD = 0.5    

# Retrieve top_k
try:
	TOP_K = int(os.environ['top_k'])
except:
	TOP_K = 15

print("model: {}".format(MODEL_NAME))
print("threshold: {}".format(THRESHOLD))   
print("top_k: {}".format(TOP_K))

# Load the TensorFlow model
print("[INFO] loading TensorFlow model...")
model = tf.saved_model.load("/code/catkin_ws/src/coral/packages/object_detection/src/dt_inference_models/dt_{}".format(MODEL_NAME))
infer = model.signatures['serving_default']

input_mean = 128
input_std = 127

# Initialize FPS
FPS = []
AvgFPS = 0

while True:
    try:
        start_time = time.time()

        # Read numpy array of image stream
        frame = np.load('/code/catkin_ws/src/coral/packages/object_detection/src/temp_frame.npy')
        frame = Image.fromarray(frame)
        
        #frame = Image.open("/code/catkin_ws/src/coral/packages/object_detection/src/dt_inference_models/b_BR_doort_frame00336.jpg")

        # Preprocess the image to required size and cast
        input_shape = (320, 320)  # Size used for training
        frame = frame.resize(input_shape)  # Resize frame
        input_data = np.expand_dims(frame, axis=0)
        # Normalize the input data to [0, 255] and cast it to uint8
        input_data = ((input_data - input_mean) / input_std) * 255
        input_data = input_data.astype(np.uint8)

        # Run inference
        predictions = infer(tf.constant(input_data))

        # Obtain results
        boxes = predictions['detection_boxes'].numpy()[0]
        classes = predictions['detection_classes'].numpy()[0]
        scores = predictions['detection_scores'].numpy()[0]
        num_detections = int(predictions['num_detections'].numpy()[0])
        
        #print(boxes)
        #print(classes)
        #print(scores)
        #print(num_detections)

        # Initialize empty dictionary and list
        d = {}
        l = []

        # Get inference results
        for i in range(num_detections):
            # Get the bounding box coordinates
            box = boxes[i]
            
            # Convert coordinates to integers
            box = (box * np.array([frame.height, frame.width, frame.height, frame.width])).astype(int)

            # Get label and color
            label = labels[int(classes[i])]
            color = colors[int(classes[i])]

            # Get the score
            score = float(scores[i])

            # Only add the detection to the result if the score is above the threshold
            if score >= THRESHOLD:
                # Update dictionary
                d['startY'], d['startX'], d['endY'], d['endX'] = map(int, box)
                d['label'] = label
                d['color'] = color
                d['score'] = score
                d['FPS'] = int(AvgFPS)
                l.append(d.copy())

            # Stop adding detections if we have reached the maximum number
            if len(l) >= TOP_K:
                break

            
        print(f"[INFO] After model annot")
        print(l)
        for i, item in enumerate(l):
            print(f"Type of item {i} in 'l':", type(item))
            for key, value in item.items():
                print(f"Type of value for key '{key}' in item {i}:", type(value))
        # Dump inference results to prediction.json
        with open('/code/catkin_ws/src/coral/packages/object_detection/src/prediction', 'w') as fout:
            json.dump(l, fout)

        diff = time.time() - start_time
        fps = 1/diff
        FPS.append(fps)

        # Average 20 FPS records
        if len(FPS)==20:
            AvgFPS = sum(FPS)/len(FPS)
            FPS = []

    except (ValueError, FileNotFoundError):
        pass