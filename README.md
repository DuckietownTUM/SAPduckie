DuckieBot Autonomous Navigation

Welcome to the DuckieBot Autonomous Navigation repository! This repository contains the codebase for implementing various components of autonomous navigation for DuckieBots. From lane following to intersection navigation, this project aims to equip DuckieBots with the capability to navigate through environments autonomously.

Features

Lane Following: Utilizes a modified pure pursuit controller for precise tracking of lanes on the road.
Stop Line Detection: Detects stop lines and halts the DuckieBot appropriately.
Intersection Navigation: Uses apriltags to identify legal turn directions at intersections, facilitating safe navigation.
Object Detection: Implementation of object detection algorithms, including SSD and YOLO, for identifying obstacles and traffic signs.

Installation

Clone the repository:

bash

    git clone <repository_url>

Usage

Ensure all necessary packages are installed and properly configured.
Launch the appropriate ROS nodes for lane following, stop line detection, and intersection navigation.
Calibrate parameters and tune algorithms as needed for optimal performance.
Monitor the DuckieBot's navigation behavior and make adjustments as necessary.

Documentation

1. Object Detection using SSD

The OBJ-DET-SSD module is responsible for performing object detection on the DuckieBot using a Single Shot Multibox Detector (SSD) model. This module includes all the necessary training data, allowing you to train the model using the provided training script. Once trained, you can execute inference to detect objects in real-time.

2. Object Detection using YOLO

The OBJ-DET-YOLO module employs a different approach to object detection, utilizing a You Only Look Once (YOLO) model. This module consists of four notebooks that need to be executed in sequence to recreate the work. By following the steps outlined in these notebooks, you can train the YOLO model and perform object detection on the DuckieBot.

3. Lane Following and Harmonized Navigation

The Pure-PursuitLF and Harmonized modules are designed to integrate various autonomous navigation components and orchestrate their simultaneous operation on the DuckieBot. This integration requires each individual module to be packaged with a launch file. Additionally, a main project launch file orchestrates the execution of all modules. To deploy the integrated navigation system on the DuckieBot, you can build a Docker image using the provided Dockerfile and execute it on the bot using the following commands:

Building the Docker Image:

bash

    dts devel build -f -H ROBOT_NAME

Running the Built Image:

bash

    dts devel run -H ROBOT_NAME

Contributing

Contributions are welcome! If you have ideas for improvements or new features, feel free to open an issue or submit a pull request.

Acknowledgements

This project is inspired by the Duckietown project (https://www.duckietown.org/).
Special thanks to the contributors and maintainers of the DuckieBot Autonomous Navigation project.