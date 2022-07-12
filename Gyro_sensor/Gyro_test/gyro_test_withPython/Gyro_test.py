# -*- coding: utf-8 -*-
"""
Created on Thu Dec 30 19:07:35 2021

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
Gdata = np.array([], dtype=np.int16)
Temp = 0

All_Adata = []
All_Gdata = []
All_Temp = []

All_Ang = []
phi = []
theta = []
psi = []

Adata_offset = np.array([1.2, 0, 9.67])
Gdata_offset = np.array([-9.45, -1.24, -0.9])

try :
    ser = serial.Serial("COM3", 9600)
    print("connected to: " + ser.portstr)
    Acc_saveFile = open('acc.txt', 'w')
    Temp_saveFile = open('temp.txt', 'w')
    Gyro_saveFile = open('gyro.txt', 'w')
except OSError :
    print("disconnected to: COM3")
    sys.exit(1)
    
    
    
def data_save() :
    global data, Adata, Gdata, Temp, All_Adata, All_Gdata, All_Temp
    
    
    line_temp = ser.readline()
    line = line_temp.split()
    
    data = np.array([], dtype=np.int8)
    
    for i in line :
        j = int(i.decode())
        data = np.append(data, j)
        
    print(" ======================================================================")
    print(" Received data : [Acc_x, Acc_y, Acc_z, Temp, Gyro_x, Gyro_y, Gyro_z]\n\t\t\t ", data)
    Adata = data[0:3] * 9.8 / 16384 - Adata_offset
    Temp = data[3] / 340.0 + 36.53
    Gdata = data[4:7] / 65 - Gdata_offset

    
    All_Adata.append(Adata)
    All_Gdata.append(Gdata)
    All_Temp.append(Temp)
    
    print(" Acceleration : data[0:2] * 9.8 / 16384\n\t\t\t ", Adata,
          "\n Temporature : data[3] / 340.0 + 36.53\n\t\t\t ", Temp,
          "\n Angular Velocity : data[4:6] / 131\n\t\t\t ", Gdata)
    
    
    Acc_saveFile.write(str(Adata[0])+' '+str(Adata[1])+' '+str(Adata[2])+'\n')
    Temp_saveFile.write(str(Temp)+'\n')
    Gyro_saveFile.write(str(Gdata[0])+' '+str(Gdata[1])+' '+str(Gdata[2])+'\n')
    
    

def data_cal() :
    global data, All_Adata, All_Gdata, All_Temp, count
    global All_Ang, phi, theta, psi
    
    All_Ang.append([0, 0, 0])
    
    if (count == 0) :
        
        #phi.append(atan2(data[1], sqrt(pow(data[0], 2) + pow(data[2], 2))) * 180 / pi)
        #theta.append(atan2(data[0], sqrt(pow(data[1], 2) + pow(data[2], 2))) * 180 / pi)
        
        phi.append(0)
        theta.append(0)
        psi.append(0)

        
        
        All_Ang[0][0] = phi[0]
        All_Ang[0][1] = theta[0]
        All_Ang[0][2] = psi[0]
        
    else :
        wx = All_Gdata[count-1][0]
        wy = All_Gdata[count-1][1]
        wz = All_Gdata[count-1][2]
        
        
        phi.append(phi[count-1] + (wx + wy * sin(phi[count-1] * pi / 180) * tan(theta[count-1] * pi / 180) 
                                     + wz * cos(phi[count-1] * pi / 180) * tan(theta[count-1] * pi / 180)) * 36/1000)
        theta.append(theta[count-1] + (wy * cos(phi[count-1] * pi / 180) - wz * sin(phi[count-1] * pi / 180)) * 36/1000)
        psi.append(psi[count-1] + ((wy * sin(phi[count-1] * pi / 180) + wz * cos(phi[count-1] * pi / 180))
                                     / cos(theta[count-1] * pi / 180)) * 36/1000)
      
        
        All_Ang[count][0] = phi[count]
        All_Ang[count][1] = theta[count]
        All_Ang[count][2] = psi[count]
        

    print(" Angle : [Roll, Pitch, Yaw]\n\t\t\t ", All_Ang[count])

    
    



if (__name__ == "__main__") :
    global count
    count = 0
    while (count < 25000) :
        data_save()
        data_cal()
        count += 1
    else :
        Acc_saveFile.close()
        Temp_saveFile.close()
        Gyro_saveFile.close()
       
