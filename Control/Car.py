class Car:
    def __init__(self, speed=0):
        self.speed = speed
        self.acceleration = 0

    def accelerate(self, a):
        self.acceleration = a
        self.speed += a

    def brake(self, b):
        self.acceleration = -b
        self.speed -= b

    def get_speed(self):
        return self.speed

car = Car()
car.accelerate(5)
print(car.get_speed()) # Output: 5
car.brake(3)
print(car.get_speed()) # Output: 2




