import cv2
import glob
import copy
import math
import numpy as np
import imageio
import matplotlib.pyplot as plt

from pprint import pprint as pp

def get_chessboard_points(chessboard_shape, dx, dy):
    return [[(i%chessboard_shape[0])*dx, (i//chessboard_shape[0])*dy, 0] for i in range(np.prod(chessboard_shape))]

def load_images(filenames):
    return [imageio.imread(filename)]
	

filenames = list(sorted(glob.glob("../input/wsawdq/*.jpg")))
imgs = load_images(filenames)

corners = [cv2.findChessboardCorners(i, (6,8)) for i in imgs]


corners2 = copy.deepcopy(corners)

criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.01)

imgs_grey = [cv2.cvtColor(img, cv2.COLOR_RGB2GRAY) for img in imgs]

cornersRefined = [cv2.cornerSubPix(i, cor[1], (8, 6), (-1, -1), criteria) if cor[0] else [] for i, cor in zip(imgs_grey, corners2)]


imgs2 = copy.deepcopy(imgs)

tmp = [cv2.drawChessboardCorners(img, (8,6), cor[1], cor[0]) for img, cor in zip(imgs2, corners) if cor[0]]


plt.figure()
plt.imshow(imgs2[0])

plt.figure()
plt.imshow(imgs2[2])


cb_points = get_chessboard_points((6, 8), 30, 30)
# pp(cb_points)


valid_corners = [cor[1] for cor in corners if cor[0]]

num_valid_images = len(valid_corners)


real_points = get_chessboard_points((8, 6), 30, 30)


object_points = np.asarray([real_points for i in range(num_valid_images)], dtype=np.float32)


image_points = np.asarray(valid_corners, dtype=np.float32)


rms, intrinsics, dist_coeffs, rvecs, tvecs = cv2.calibrateCamera(object_points, image_points, imgs[1].shape[0:2], None, None)

extrinsics = list(map(lambda rvec, tvec: np.hstack((cv2.Rodrigues(rvec)[0], tvec)), rvecs, tvecs))

np.savez('calib_left', intrinsic=intrinsics, extrinsic=extrinsics)


# Displayig required output 
print(" Camera matrix:") 
print(intrinsics) 
  
print("\n Distortion coefficient:") 
print(dist_coeffs) 
  
print("\n Rotation Vectors:") 
print(rvecs) 
  
print("\n Translation Vectors:") 
print(tvecs)