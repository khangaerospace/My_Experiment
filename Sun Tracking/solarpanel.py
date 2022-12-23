'''
    ESC204 Team 1056C - EGGSTENDER 
    The following code was used to demonstrate the functionality of the Eggstender's 
    turntable mechanism. 
    
    One photoresistor was attached to each side of our prototype (for four photoresistors 
    in total). These are labelled from 1 to 4 in CCW order, where photoresistor 1 is at 
    the front of the apparatus. 
    
    This code determines which photoresistor detects the maximum amount of light. Based off 
    this information, a stepper motor causes the wheel at the end of the drying chamber to 
    rotate. In turn, this rotates the entire apparatus such that its heating chamber is positioned 
    towards the direction of maximal light.
'''

import time
import board
import digitalio
from adafruit_motor import stepper
import analogio

# set up photoresistors as analog input over analog pins
photoresistor_pin_1 = board.A0 #red and blue wires
photoresistor_1 = analogio.AnalogIn(photoresistor_pin_1)

photoresistor_pin_2 = board.A1 #black wires
photoresistor_2 = analogio.AnalogIn(photoresistor_pin_2)

photoresistor_pin_3 = board.A2 #red wires
photoresistor_3 = analogio.AnalogIn(photoresistor_pin_3)

photoresistor_pin_4 = board.A3 #blue wires
photoresistor_4 = analogio.AnalogIn(photoresistor_pin_4)

# initialize DELAY and STEPS variables
# STEPS represents how much the motor needs to rotate the wheel in order to rotate the apparatus 90deg
# note that a full rotation of the motor would occur if STEPS was = 200
DELAY = 0.005
STEPS = 200*19.2/4

# initialize pins which connect to the A4988 stepper motor driver
microstep_pins = (digitalio.DigitalInOut(board.D6),digitalio.DigitalInOut(board.D5),digitalio.DigitalInOut(board.D4))
step_pin = digitalio.DigitalInOut(board.D3)
dirn_pin = digitalio.DigitalInOut(board.D2)
step_pin.direction = digitalio.Direction.OUTPUT
dirn_pin.direction = digitalio.Direction.OUTPUT

# set motor to run with full steps (not microsteps)
for pin in microstep_pins:
    pin.direction = digitalio.Direction.OUTPUT
    pin.value = False

# sends a pulse to the STEP output to actuate the stepper motor through one step
def single_step(d):
    # pulse high to drive step
    step_pin.value = True
    time.sleep(d)

    # bring low in between steps
    step_pin.value = False
    time.sleep(d)
 
# continously check for the photoresistor with the highest reading
# and rotate the motor to position the apparatus in the direction of maximum light 
curr = 0
while True:

    values = [photoresistor_1.value, photoresistor_2.value, photoresistor_3.value, photoresistor_4.value]
    ma_val = max(values)
    ma_ind = values.index(ma_val)
    
    # if the photoresistor detecting max light is lower in order/position than the current photoresistor,
    # rotate the apparatus in the other direction (CW)
    # this prevents the photoresistor wires from tangling 
    if ma_ind < curr:
        # motor is set to spin CCW
        # therefore, apparatus spins CW
        dirn_pin.value = False
        steps_no = curr - ma_ind
        
    else:
        # motor is set to spin CW
        # therefore, apparatus spins CCW
        dirn_pin.value = True
        steps_no = ma_ind

    # actuate the stepper motor
    # steps_no represents the number of 90deg steps the apparatus needs to rotate
    for i in range(STEPS*steps_no):
        single_step(DELAY)
    time.sleep(3)
    
    curr = max_ind
