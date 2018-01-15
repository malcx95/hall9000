#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <WebSocketsClient.h>
#include <Servo.h>

Servo spoolservo;
Servo angleservo;

ESP8266WiFiMulti WiFiMulti;
WebSocketsClient webSocket;


void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {

	switch(type) {
		case WStype_DISCONNECTED:
			Serial.println("Disconnected");
			break;
		case WStype_CONNECTED: {
			// send message to server when Connected
			webSocket.sendTXT("Connected");

            Serial.println("Connected");
		}
			break;
		case WStype_TEXT:
			// send message to server
			// webSocket.sendTXT("message here");
            Serial.print("GOT TEXT: ");
            Serial.println(payload[0]);
			break;
		case WStype_BIN:
			// send data to server
			// webSocket.sendBIN(payload, length);
            Serial.print("GOT BIN: ");
            Serial.println(payload[0]);
			break;
	}

}

long i;

void setup() {
    i = 0;
    
    pinMode(15, OUTPUT);
    pinMode(D0, OUTPUT);
    pinMode(13, INPUT);
    spoolservo.attach(2);
    angleservo.attach(0);

    spoolservo.writeMicroseconds(2000);
    angleservo.writeMicroseconds(1500);
    
    Serial.begin(9600);

    delay(2000);

    Serial.println("Kebab1");

    WiFiMulti.addAP("Snuffs", "Kebabsyster101");

    while (WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }
    
    webSocket.begin("192.168.0.123", 81, "/");

    webSocket.onEvent(webSocketEvent);

    webSocket.setReconnectInterval(5000);
    Serial.println("Kebab");
}


void loop() {

    digitalWrite(D0, digitalRead(13));

    webSocket.loop();

    // angleservo.writeMicroseconds(2000);
    // spoolservo.writeMicroseconds(1500);

    // delay(2000);

    // angleservo.writeMicroseconds(1000);
    // spoolservo.writeMicroseconds(1500);

    // delay(2000);

    // spoolservo.writeMicroseconds(2000);

    // delay(2000);

    Serial.println(i);
    ++i;

}
