import os
import numpy as np
import matplotlib.pyplot as plt

plt.figure(1, figsize=(8,4))

plt.subplot(1,2,2)
data = np.loadtxt("Ejer.dat")

plt.plot(data[:,0], data[:,1])

plt.subplot(1,2,1)
plt.imshow(data.T)            
            
plt.title("hola")
plt.xlabel('X')
plt.ylabel('Y')
plt.savefig("Ejer.png")
