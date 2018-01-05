#include <Servo.h>

Servo spoolservo;
Servo angleservo;

void setup() {
    
    pinMode(15, OUTPUT);
    spoolservo.attach(2);
    angleservo.attach(0);

    spoolservo.writeMicroseconds(2000);
    angleservo.writeMicroseconds(1500);
    
    Serial.begin(9600);

    delay(2000);

}

void loop() {

    Serial.println("Hejhej");
    
    // spoolservo.writeMicroseconds(2000);

    digitalWrite(15, HIGH);

    delay(2000);

    digitalWrite(15, LOW);

    delay(2000);

}
