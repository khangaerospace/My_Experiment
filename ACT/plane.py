# SpaceRyde Challenge

# Set up the area

class Plane():
    def __init__(self, latitude, longitude, speed, com):
        '''
        Latitude: The airplane lattitude
        longitude: the airplane longitude
        r_time:
        '''
        # We allow for the plane parameter to change, we will let the ATC set the plane parameter.
        self.latitude = latitude
        self.longitude = longitude
        self.r_time = r_time
        self.speed = speed
        self.com = com

    def distance_travel_1sec(self):
        distance = self.speed()*1
        return distance


