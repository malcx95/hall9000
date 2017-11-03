from datetime import datetime
import RPi.GPIO as GPIO
import time
import os
import picamera

def main():

    with picamera.PiCamera(resolution="1920x1080") as camera:
        pass


def detect_motion(im1, im2):
    """
    Detects motion between two frames.
    """


if __name__ == "__main__":
    try:
        main()
    finally:
        GPIO.cleanup()

