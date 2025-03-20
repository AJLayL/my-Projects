//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(7, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

long LastTime;
long CurrentTime;
long Difference;
unsigned long Time = 0;
void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();

  radio.setAutoAck(false);
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    
    radio.read(&Time, sizeof(Time));
    Serial.println(Time);
    CurrentTime = Time;
    Difference = CurrentTime - LastTime;
    LastTime = Time;
    Serial.print("Difference: ");
    Serial.println(Difference);
  }
  
  
}
