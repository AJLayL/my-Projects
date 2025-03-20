//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
unsigned long Time;

//create an RF24 object
RF24 radio(7, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();

  radio.setAutoAck(false);
}
void loop()
{
  //Send message to receiver
  Serial.println("meow");
  delay(2000);
}
