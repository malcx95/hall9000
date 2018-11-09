import RPi.GPIO as GPIO
import time

class Servo:

    LEFT = 0.6
    RIGHT = 2.4
    MS_PER_CYCLE = 1000 / 50

    def __init__(self, port):
        self.port = port
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(port, GPIO.OUT)
        self.pwm = GPIO.PWM(port, 50)

    def move_left(self):
        dCP = Servo.get_dcp(Servo.LEFT)
        self.pwm.start(dCP)

    def move_right(self):
        dCP = Servo.get_dcp(Servo.RIGHT)
        self.pwm.start(dCP)

    def set_position(self, angle):
        if angle < 0 or angle > 180:
            raise Exception("Angle must be between 0 and 180 degrees!")
        r = Servo.RIGHT - Servo.LEFT
        pos = r * (angle/180) + Servo.LEFT
        dCP = Servo.get_dcp(pos)
        self.pwm.start(dCP)
    
    def get_dcp(pos):
        return pos * 100 / Servo.MS_PER_CYCLE

    def stop(self):
        self.pwm.stop()
        GPIO.cleanup()
