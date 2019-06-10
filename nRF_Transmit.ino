#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(D4, D8); // CE, CSN

const byte address[6] = "00100";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);
  Serial.println("ok");
}
