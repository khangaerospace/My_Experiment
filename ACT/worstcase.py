import numpy as np

"""This function will calculate the maxiumum plane can enter the area at a time"""


def max_plane(R, d):
    # estimate that number of maz plane enter the circle
    circle = 2 * np.pi * R
    arc = 2 * R * np.arcsin(d / (2 * R))
    P_max = circle / arc
    return P_max
