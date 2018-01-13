#include <Servo.h>

Servo spoolservo;
Servo angleservo;

void setup() {
    
    pinMode(15, OUTPUT);
    pinMode(D0, OUTPUT);
    pinMode(13, INPUT);
    spoolservo.attach(2);
    angleservo.attach(0);

    spoolservo.writeMicroseconds(2000);
    angleservo.writeMicroseconds(1500);
    
    Serial.begin(9600);

    delay(2000);

}

void loop() {

    digitalWrite(D0, digitalRead(13));
    // Serial.println("Hejhej");
    
    // angleservo.writeMicroseconds(2000);
    // spoolservo.writeMicroseconds(1500);

    // delay(2000);

    // angleservo.writeMicroseconds(1000);
    // spoolservo.writeMicroseconds(1500);

    // delay(2000);

    // spoolservo.writeMicroseconds(2000);

    // delay(2000);

}
