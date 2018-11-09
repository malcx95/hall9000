import servocontrol
import time


def main():
    while True:
        servo = servocontrol.Servo(2)
        servo.move_left()
        time.sleep(5)
        servo.move_right()
        time.sleep(5)


if __name__ == "__main__":
    main()
