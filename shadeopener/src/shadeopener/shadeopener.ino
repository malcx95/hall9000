#include <Servo.h>

Servo servo;

void setup() {
    
    servo.attach(2);

    servo.writeMicroseconds(1500);
    
    Serial.begin(9600);

    delay(2000);

}

void loop() {

    Serial.println("Hejhej");
    

    delay(1000);


}
