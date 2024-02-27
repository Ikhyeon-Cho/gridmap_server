# gridmap_server

## Overview
gridmap_server provides the `gridmap_server` ROS Node, which offers grid map data as a ROS Topic. It also provides the `gridmap_saver` command-line utility, which allows dynamically generated grid maps to be saved to PNG image or [rosbag](https://wiki.ros.org/rosbag) files. 

## 1. Installation
**Dependencies:** This software is built on the Robotic Operating System ([ROS](https://www.ros.org/)).
- Ubuntu and ROS. (Tested on [ROS Noetic](https://wiki.ros.org/noetic), Ubuntu 20.04)
- [grid_map](https://github.com/ANYbotics/grid_map) (grid map C++ library for mobile robots)

**Building:** In order to install the `gridmap_server` package, clone the latest version from this repository into your workspace and compile the package using ROS.
  ```
  cd ~/your-ros-workspace/src
  git clone https://github.com/Ikhyeon-Cho/gridmap_server.git
  cd ..
  catkin build gridmap_server
  ```

## 2. Basic Usage
1. Locate the map image or rosbag file in the `gridmap_server/map` folder.
2. Configure the parameters in `gridmap_server/launch/config/params.yaml`
3. Run the launch file:
  ```
  roslaunch gridmap_server run.launch
  ```

## 3. Map format
- To be updated.
<!-- Maps manipulated by the tools in this package are  -->

### 3.1 Occupancy grid map
- To be updated

### 3.2 Grid map
- To be updated
