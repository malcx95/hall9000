#include <Servo.h>

Servo servo;

void setup() {
    
    servo.attach(2);

    servo.writeMicroseconds(2000);
    
    Serial.begin(9600);

    delay(2000);

}

void loop() {

    Serial.println("Hejhej");
    
    servo.writeMicroseconds(2000);

    delay(1000);

    servo.writeMicroseconds(1000);

    delay(1000);

    servo.writeMicroseconds(1500);

    delay(1000);

}
