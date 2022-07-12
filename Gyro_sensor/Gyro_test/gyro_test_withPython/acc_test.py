# -*- coding: utf-8 -*-
"""
Created on Sat Jan  1 22:18:02 2022

@author: jdh38
"""

import serial
import numpy as np
import time
import sys
import matplotlib.pyplot as plt
from math import *


data = np.array([], dtype=np.int16)
Adata = np.array([], dtype=np.int16)

All_Adata = []

All_Ang = np.empty((0, 2))
phi = np.array([], dtype=np.float64)
theta = np.array([], dtype=np.float64)


try :
    ser = serial.Serial("COM3", 9600)
    print("connected to: " + ser.portstr)
except OSError :
    print("disconnected to: COM3")
    sys.exit(1)
    
    
def get_data() :
    global data, Adata, All_Adata
    
    line_temp = ser.readline()
    line = line_temp.split()
    
    data = np.array([], dtype=np.int8)
    
    for i in line :
        j = int(i.decode())
        data = np.append(data, j)
    
    
def data_save() :
    
    get_data()
        
    print(" ======================================================================")
    print(" Received data : [Acc_x, Acc_y, Acc_z, Temp, Gyro_x, Gyro_y, Gyro_z]\n\t\t\t ", data)
   

    Adata = data[0:3] * 9.8 / 16384

    
    All_Adata.append(Adata)
    
    
    print(" Acceleration : data[0:2] * 9.8 / 16384\n\t\t\t ", Adata)
    
    

def data_cal() :
    global All_Adata, count
    global All_Ang, phi, theta
    
    All_Ang = np.append(All_Ang, [[0., 0.]], axis = 0)
    
        
    phi = np.append(phi, atan2(data[1], sqrt(pow(data[0], 2) + pow(data[2], 2))) * 180 / pi)
    theta = np.append(theta, atan2(data[0], sqrt(pow(data[1], 2) + pow(data[2], 2))) * 180 / pi)


    All_Ang[count][0] = phi[count]
    All_Ang[count][1] = theta[count]
    

        
    print(" Angle : [Roll, Pitch]\n\t\t\t ", All_Ang[count])

    

def wait() :
    for i in range(10) :
        get_data()



if (__name__ == "__main__") :
    global count
    count = 0
    wait()
    while (count < 25000) :
        data_save()
        data_cal()
        count += 1

       
