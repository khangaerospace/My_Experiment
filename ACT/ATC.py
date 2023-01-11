""" This is the Area of the plane"""
import numpy as np
from plane import Plane
from Queue import PriorityQueue
import math


class Area:
    def __init__(self, radius, distance, n_runway, runway_x, runway_y, aircircle):
        """
        radius (m): is the radius distance
        distance (m): distance between each plane
        n_runway (m): number of the runway in the area
        runway_x (m): the width of the runway
        runway_y (m): The length of the runway
        d_rw_cen (m): distance of the centre of the runway to the centre of the circle
        aircircle (m): The radius that the plane need to travel in while waiting
        """
        # Set up the parameter that related to the airplane
        self.radius = radius
        self.distance = distance
        self.n_runway = n_runway
        self.runway_x = runway_x
        self.runway_y = runway_y
        self.d_rw_cen = (radius / 2) + (runway_x / 2)
        self.aircircle = aircircle
        # Set the zone that the plane can enter
        self.zone_A = PriorityQueue()
        self.zone_B = PriorityQueue()
        self.zone_C = PriorityQueue()
        self.zone_D = PriorityQueue()

    def outer_circle(self):
        out_radius = self.radius - self.distance
        return out_radius

    def iner_circle(self):
        side = self.d_rw_cen + self.unway_x
        length = np.sqrt(side**2 + (self.runway_y) ** 2)
        iner_radius = length + self.distance
        return iner_radius

    def max_plane(self):
        R = self.radius
        circle = 2 * np.pi * R
        arc = 2 * R * np.arcsin(d / (2 * R))
        P_max = math.floor(circle / arc)
        return P_max

    def find_zone(self, latitude, longitude):
        if x_axis > 0 and y_axis > 0:
            zone = "A"
        if x_axis < 0 and y_axis > 0:
            zone = "B"
        if x_axis < 0 and y_axis < 0:
            zone = "C"
        if x_axis < 0 and y_axis < 0:
            zone = "D"
        return zone

    def OuterSafeZone(self):
        out_ter = self.radius - self.distance
        return out_ter

    def InerSafeZone(self):
        inner_radius = (
            np.sqrt((self.d_rw_cen + self.runway_x) ** 2 + self.runway_y**2)
            + self.distance
        )
        return inner_radius

    def NSetUpArea(self):
        out_ter = self.OuterSafeZone(self)
        iner = self.InerSafeZone(self)
        distance_each_circle = self.distance + self.aircircle
        N_circle = ((out_ter - iner) / distance_each_circle) + 1
        # we need to round up since this number can not be a double dude to physical reason. We will round it down.
        N_circle = math.floor(N_circle)
        return N_circle

    def insert_plane(self, plane):
        latitude = plane.latitude
        longitude = plane.latitude
        zone = self.find_zone(latitude, longitude)
        if zone == "A":
            self.zone_A.append(plane)
        elif zone == "B":
            self.zone_B.append(plane)
        elif zone == "C":
            self.zone_C.append(plane)
        else:
            self.zone_D.append(plane)

    def land(self):
        # We need to see which plane land first
        # land A first
        self.zone_A.delete()
        # then B
        self.zone_B.delete()
        # then C
        self.zone_C.delete()
        # then D
        self.zone_D.delete()

    # TODO: Check to see if any place planning to land. If there are, add the plane that enters the nearest waiting circle.


# TODO: If there is one plane, send it to the closes runway. A zone and B zone will have priority. C and D land will have less priority.

# TODO If the airplane can not land, append it to the nearest number waiting for the circle.

# TODO When landing, remove the plane from the priority queue.

# TODO Move the airplane from the outer circle into the inner circle
