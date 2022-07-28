# Camera-Calibration

A smart and easy to now find parameters for the camera calibration. 
The method will first define real world coordinates of 3D points using known size of checkerboard pattern.

With a help of a smartphone, a couple of pictures are captured of the checkboard provided. Different Viewpoints are captured. 
[Checkboard PDF link](https://raw.githubusercontent.com/MarkHedleyJones/markhedleyjones.github.io/master/media/calibration-checkerboard-collection/Checkerboard-A4-30mm-8x6.pdf)

To find pixel coordinates (u,v), findChessboardCorners() is a method in OpenCV. 

CalibrateCamera() method is used to find camera parameters.
It will take our calculated (threedpoints, twodpoints, grayColor.shape[::-1], None, None) as parameters and returns list having elements as Camera matrix, Distortion coefficient, Rotation Vectors, and Translation Vectors. 


Camera Matrix helps to transform 3D objects points to 2D image points and the Distortion Coefficient returns the position of the camera in the world, with the values of Rotation and Translation vectors

Video explanation: (click on the image below):
[![Youtube Link](https://img.youtube.com/vi/6cxVcynXIME/0.jpg)](https://youtu.be/6cxVcynXIME)