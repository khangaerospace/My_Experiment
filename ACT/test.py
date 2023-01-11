""" This will the code that we use to set up our problem and solve it"""


from ATC import Area
from plane import Plane


# The parameter that given in the problem
def create_area(radius, distance, n_runway, runway_x, runway_y, aircircle):
    RunwayLength = runway_y / 2
    area = Area(radius, distance, n_runway, runway_x, RunwayLength, aircircle)
    print(area.radius)
    return area


def create_plane(latitude, longitude, speed, com):
    plane = Plane(latitude, longitude, speed, com)
    return plane


# Example Code
if __name__ == "__main__":
    """
    radius (m): is the radius distance
    distance (m): distance between each plane
    n_runway (m): number of the runway in the area
    runway_x (m): the width of the runway
    runway_y (m): The length of the runway
    aircircle (m): The radius that the plane need to travel in while waiting
    """
    # first, we need to create the ATC
    radius = 10 * 1000  # m
    distance = 100  # m
    n_runway = 2
    runway_y = 500  # m
    runway_x = 100
    aircircle = 1000

    area = create_area(radius, distance, n_runway, runway_x, runway_y, aircircle)

    # After create the area, we need to add in the plane
    # Let's call the plane
    latitude = 10000
    longitude = 500
    speed = 140  # m/s
    com = 10  # Hz
    plane = create_plane(area, latitude, longitude, speed, com)

