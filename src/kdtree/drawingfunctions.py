from mpl_toolkits.mplot3d import axes3d
import numpy as np
import matplotlib.pyplot as plt

def getPointsPositions(file,positions,num_points,k):
	for i in range(num_points):
		line = file.readline()
		arr = line.split(" ")
		for j in range(k):
			positions[j].append(int(arr[j]))

def drawFromLevel(level_data,old_dimensions,dimensions,new_dimensions,plt):
	fixed_dimension = int(level_data[0])
	if(len(dimensions) == 0):
		line_points = [[],[]]
		left_dim = [[],[]]
		right_dim = [[],[]]	
		if level_data[1] != 'N':
			for j in range(2):
				old_dim = old_dimensions[0][j]
				if j == fixed_dimension:
					line_points[j] = [int(level_data[1]),int(level_data[1])]
					left_dim[j] = [old_dim[0],int(level_data[1])]
					right_dim[j] = [int(level_data[1]),old_dim[1]]
				else:
					line_points[j] = [old_dim[0],old_dim[1]]
					left_dim[j] = line_points[j]
					right_dim[j] = line_points[j]
			dimensions.append(line_points)
			new_dimensions.append(left_dim)
			new_dimensions.append(right_dim)
			plt.plot(line_points[0],line_points[1])
		else:
			new_dimensions.append([])
		
	
	else:
		for i in range(1,len(level_data)):
			line_points = [[],[]]
			left_dim = [[],[]]
			right_dim = [[],[]]		
			if level_data[i] != 'N':
				for j in range(2):
					old_dim = old_dimensions[int((i-1)/2)][j]
					dim = dimensions[i-1][j]
					if j == fixed_dimension:
						line_points[j] = [int(level_data[i]),int(level_data[i])]
						left_dim[j] = [old_dim[0],int(level_data[i])]
						right_dim[j] = [int(level_data[i]),old_dim[1]]
					else:	
						line_points[j] = [dim[0],dim[1]]
						left_dim[j] = line_points[j]
						right_dim[j] = line_points[j]

				new_dimensions.append(left_dim)
				new_dimensions.append(right_dim)
				plt.plot(line_points[0],line_points[1])
			else:
				new_dimensions.append([])
		
	old_dimensions[:] = dimensions
	dimensions[:] = new_dimensions
	new_dimensions[:] = []
	

def drawLines(maxX,maxY,plt):
	tree = open("tree.txt", "r")
	old_dimensions = [[[0,maxX],[0,maxY]]]
	dimensions = []
	new_dimensions = []
	for level in tree:
		level_data = level.split(" ")
		level_data.pop()
		drawFromLevel(level_data,old_dimensions,dimensions,new_dimensions,plt)

def drawUserPoint(k,argv,plt):
	user_point = []
	for i in range(k):
		user_point.append(int(argv[2+i]))
	if k == 2:
		plt.scatter(user_point[0], user_point[1],color="red")
	else: 
		plt.scatter(user_point[0], user_point[1],user_point[2],color="red")

def drawNNPoint(k,plt):
	nnP = []
	file = open("nn.txt", "r")
	line = file.readline()
	array = line.split(" ")
	for j in range(k):
		nnP.append(int(array[j]))
	if k == 2:
		plt.scatter(nnP[0], nnP[1],color="green")
	else:
		plt.scatter(nnP[0], nnP[1],nnP[2],color="green")		
