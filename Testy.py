import math
import os

radius = 400
angle = 125

def calcPos(radius, angle):
	x = math.cos(math.radians(angle)) * radius
	y = math.sin(math.radians(angle)) * radius
	print(x, y)

calcPos(radius, angle)
os.system('pause')