import threading

class Car:
    def __init__(self, max_speed=120, gear=1):
        self.speed = 0
        self.acceleration = 0
        self.max_speed = max_speed
        self.gear = gear
        self.gear_speeds = {1: 20, 2: 40, 3: 60, 4: 80, 5: 100}
        self.speed_thread = threading.Thread(target=self.check_speed)
        self.speed_thread.start()
        self.speed_sensor = SpeedSensor()
        self.brake_sensor = BrakeSensor()
        self.engine_load = EngineLoadSensor()

    def check_speed(self):
        while True:
            self.speed = self.speed_sensor.get_speed()
            if self.speed > self.max_speed:
                self.speed = self.max_speed
            elif self.speed < 0:
                self.speed = 0
            elif self.speed > self.gear_speeds.get(self.gear):
                self.shift_gear(self.gear+1)
            elif self.speed < self.gear_speeds.get(self.gear-1):
                self.shift_gear(self.gear-1)
            time.sleep(0.1)

    def accelerate(self):
        self.acceleration = self.engine_load.get_acceleration()
        self.speed += self.acceleration

    def brake(self):
        self.acceleration = - self.brake_sensor.get_brake()
        self.speed -= self.acceleration

    def shift_gear(self, gear):
        if gear in self.gear_speeds:
            self.gear = gear
            self.speed = self.gear_speeds[gear]
            self.acceleration = 0
        else:
            print("Invalid gear")

    def get_speed(self):
        return self.speed

    def get_gear(self):
        return self.gear
