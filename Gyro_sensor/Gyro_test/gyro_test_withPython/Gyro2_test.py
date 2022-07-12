# -*- coding: utf-8 -*-
"""
Created on Mon Jan  3 00:33:00 2022

@author: jdh38
"""

import numpy as np
from math import *
import time
import sys
import serial


data = np.array([], dtype=np.int16)
data_avg = np.zeros(7)
Adata = np.array([], dtype=np.int16)
Gdata = np.array([], dtype=np.int16)

All_Adata = []
All_Gdata = []

All_Ang = []

phi = 0
theta = 0
psi = 0

start = 0
end = 0
dt = 0



try :
    ser = serial.Serial("COM3", 9600)
    print("connected to: " + ser.portstr)

except OSError :
    print("disconnected to: COM3")
    sys.exit(1)
    

def get_data() :
    global data

    line_temp = ser.readline()
    line = line_temp.split()
    
    data = np.array([], dtype=np.int8)
    
    for i in line :
        j = int(i.decode())
        data = np.append(data, j)
        
        

def get_dt() :
    global start, end, dt
    
    end = time.time()
    dt = end - start
    
    start = end
    
    
def avg_cal() :
    global data, data_avg
    
    for i in range(10) :
        get_data()
        data_avg += data
    
    data_avg /= 10   
    
    
    
def data_save() :
    global data, data_avg, Adata, Gdata, All_Adata, All_Gdata
    
    get_data()
    
    data[4] -= data_avg[4]
    data[5] -= data_avg[5]
    data[6] -= data_avg[6]
    

        
    Adata = data[0:3] * 9.8 / 16384
    Gdata = data[4:7] / 65

    
    All_Adata.append(Adata)
    All_Gdata.append(Gdata)


def data_cal() :
    global data, All_Adata, All_Gdata, count
    global All_Ang, phi, theta, psi, dt
    
    All_Ang.append([0, 0, 0])


    
    if (count == 0) :
        
        #phi = atan2(data[1], sqrt(pow(data[0], 2) + pow(data[2], 2))) * 180 / pi
        #theta = atan2(data[0], sqrt(pow(data[1], 2) + pow(data[2], 2))) * 180 / pi
        
       
        phi = 0
        theta = 0
        psi = 0

        
        All_Ang[0][0] = phi
        All_Ang[0][1] = theta
        All_Ang[0][2] = psi
        
    else :  

        phi += All_Gdata[count][0] * 36/1000 #대략적인 dt가 36/1000 s 정도가 된다.
        theta += All_Gdata[count][1] * 36/1000
        psi += All_Gdata[count][2] * 36/1000
    
        
        
        All_Ang[count][0] = phi
        All_Ang[count][1] = theta
        All_Ang[count][2] = psi
        


    print(" Angle : [Roll, Pitch, Yaw]\n\t\t\t ", All_Ang[count])




if (__name__ == "__main__") :
    global count
    count = 0
    avg_cal()
    
    while (count < 25000) :
        data_save()
        data_cal()
        count += 1

       
