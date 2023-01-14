import numpy as np
import  matplotlib.pyplot as plt
#df/dv must be local min

#      v
#    / |  \
# u1  U2  U3
def min_dist(u1, u2, u3):
    for i in len(u1):
        dfdw1 =  2*((v-u1)**2)*2*(c[1]*u1[i])
        dfdw2 =  2*((v-u2)**2)*2*(c[2]*u1[i])
        dfdw1 =  2*((v-u3)**2)*2*(c[3]*u1[i])
    # solve for v?


legth = len(u1)
c = np.random.random((11,))