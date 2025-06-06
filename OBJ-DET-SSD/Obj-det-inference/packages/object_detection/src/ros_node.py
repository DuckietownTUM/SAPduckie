#!/usr/bin/env python
import os
import rospy
import copy
import numpy as np
import cv2
from duckietown.dtros import \
    DTROS, \
    NodeType
from sensor_msgs.msg import CompressedImage
from cv_bridge import CvBridge
import json
import time

class Detector(DTROS):

    def __init__(self, node_name):

        # Initialize the DTROS parent class
        super(Detector, self).__init__(node_name=node_name, node_type=NodeType.VISUALIZATION)

        # Get vehicle name
        self.veh_name = str(os.environ['VEHICLE_NAME'])

        # Initialize FPS
        self.fps = str(0)   

        #Load camera resolution
        try:
            self.res_w = int(os.environ['resolution_w'])
            rospy.loginfo("Resolution is set to {} x {} px.".format(self.res_w, self.res_w*3/4))
        except:
            rospy.loginfo("The environment variable resolution_w is not set. Resolution is set to default (320x240).")
            self.res_w = 320

        self.res_h = self.res_w*3/4
        rospy.set_param('/%s/camera_node/exposure_mode' %(self.veh_name) , 'off')
        rospy.set_param('/%s/camera_node/res_w' %(self.veh_name), self.res_w)
        rospy.set_param('/%s/camera_node/res_h' %(self.veh_name), self.res_h)

        # Initialize ROS topics
        self.sub_image = rospy.Subscriber("/{}/camera_node/image/compressed".format(self.veh_name), CompressedImage, self.callback, queue_size=1)
        self.pub = rospy.Publisher("/{}/coral_object_detection/image/compressed".format(self.veh_name), CompressedImage, latch=True, queue_size=1)
        rospy.loginfo("Publishing image")
        

    def callback(self, data):
        rospy.loginfo("Callback function called")

        # Convert compressed image to BGR
        np_arr = np.fromstring(data.data, np.uint8)
        orig = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

        print(f"[INFO] Before Saved from rosnode Frame shape")
        frame = cv2.cvtColor(orig, cv2.COLOR_BGR2RGB)
        np.save('/code/catkin_ws/src/coral/packages/object_detection/src/temp_frame', frame)
        print(f"[INFO] Saved from rosnode Frame shape: {frame.shape}")

        try:
            with open('/code/catkin_ws/src/coral/packages/object_detection/src/prediction') as json_file:
                prediction = json.load(json_file)
            
            for p in prediction:
                # Read FPS              
                self.fps = str(p['FPS'])

                # Read bounding box, label, and score
                startX, startY, endX, endY = p['startX'], p['startY'], p['endX'], p['endY']
                label = p['label']
                score = p['score']
                box_color = eval(p['color'])

                # Text specification
                font = cv2.FONT_HERSHEY_SIMPLEX
                font_scale = 0.25
                font_color = (0,0,0)
                font_thickness=1
                y_text = startY - 5
                text = "{}: {:.2f}%".format(label, score * 100)
                
                # Draw the bounding box and label on the image
                cv2.rectangle(orig, (startX, startY), (endX, endY), box_color, 1)
                # Add text fill
                (w, h) = cv2.getTextSize(text, font, font_scale, font_thickness)[0]
                cv2.rectangle(orig, (startX, startY), (startX+w, startY-h-6), box_color, -1)
                                
                # Render text
                cv2.putText(orig, text, (startX, y_text), font, font_scale, font_color, font_thickness)

        except:
            pass
        
        # Render FPS
        textfps = "Inference FPS: {}".format(self.fps)
        cv2.putText(orig, textfps, (10, 10), cv2.FONT_HERSHEY_SIMPLEX, 0.25, (255, 255, 255), 1)
        
        # Publish image     
        compressed_img = br.cv2_to_compressed_imgmsg(orig, dst_format='jpg')
        self.pub.publish(compressed_img)

if __name__ == '__main__':
    # Initialize the node
    br = CvBridge()
    print(f"before rosnode taking pass")
    Detector_node = Detector(node_name='detector')
    print(f"after rosnode taking pass")
    # Keep it spinning to keep the node alive
    rospy.spin()