Cvx_Pose
========

Computer vision package for algorithms built on convex pose estimation. Wrappers for PCL and Matlab are included. Compiled and tested with gcc.

Authored by Matanya Horowitz http://matanyahorowitz.com.
Based on the work by **Matanya Horowitz**, **Nikolai Matni**.

Academic papers:
- Convex Relaxations of SE (2) and SE (3) for Visual Pose Estimation. http://arxiv.org/abs/1401.3700 

The CVX_CV package currently contains solutions based on the convex relaxation of SO(n) for n=2,3 for the following problems:
- ICP
- Pose Estimation

Future versions will include support for Structure from Motion (SfM), Simultaneous Localization and Mapping (SLAM), and more.

The package currently includes a number of examples (in progress):
- Head tracking for the cardboard virtual reality headset
- Pose estimation of juggling balls

Dependencies:
-------------

- PCL 1.7 + 
- Eigen 3.2 +
- OpenCV 2.4 + - for running some examples based on visual features
- Mosek or CSDPA - for running convex estimation, include point-to-plane ICP

Installation
============

Linux (Ubuntu):
---------------

1. First install CMake. Open a command prompt and type 
	sudo apt-get install cmake
2. Download Eigen library from http://eigen.tuxfamily.org/index.php. Create a folder in the download directory called build_dir, and move into it. Then type
	cmake ..
	sudo make install
3. Install PCL. In the command prompt type
	sudo add-apt-repository ppa:v-launchpad-jochen-sprickerhof-de/pcl
	sudo apt-get update
	sudo apt-get install libpcl-all
4. Install git:
	sudo apt-get install git

Mac: 
-----

Use Homebrew to get the latest version of PCL

Windows:
--------
Once the dependencies have been installed, move into your chosen directory and type
	git clone git@github.com:matanyahorowitz/Cvx_Pose.git

Compiling
=========

Navigate to build/ and then type
	cmake ..
	make

