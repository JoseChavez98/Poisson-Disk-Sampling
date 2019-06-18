from mpl_toolkits.mplot3d import axes3d
import numpy as np
import matplotlib.pyplot as plt
import sys
from drawingfunctions import *

input_point = False
if len(sys.argv) > 2:
	input_point = True


# get number of points and dimensions
f = open(sys.argv[1], "r")
positions = []
line = f.readline()
arr = line.split(" ")
k = int(arr[1])
points = int(arr[0])


for i in range(k):
	positions.append([])


fig = plt.figure()
if k == 2:
	ax = fig.add_subplot(111)
	maxX = 10
	maxY = 10
	
	getPointsPositions(f,positions,points,k)

	ax.set_xlim(0, maxX)
	ax.set_ylim(0, maxY)
	plt.scatter(positions[0], positions[1])
	
	if not input_point:
		drawLines(maxX,maxY,plt)

	else:
		drawUserPoint(k,sys.argv,plt)
		drawNNPoint(k,plt)
	plt.show()

elif k == 3:
	ax = fig.add_subplot(111,projection = '3d')
	
	getPointsPositions(f,positions,points,k)

	positions[0] = np.array(positions[0])
	positions[1] = np.array(positions[1])
	positions[2] = np.array(positions[2])
	ax.scatter(positions[0],positions[1],positions[2])

	if input_point:
		drawUserPoint(k,sys.argv,ax)
		drawNNPoint(k,ax)

	plt.show()

else:
	print("cant draw that many dimensions")