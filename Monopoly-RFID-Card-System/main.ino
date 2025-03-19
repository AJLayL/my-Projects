//monopoly card system using RFID. 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 2
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

LiquidCrystal_I2C lcd(0x27,16,2);

int x;
int y;
int ToggleClick = 3;
int Confirm = 4;
int val_;
int CardBalance[4]= {1500,1500,1500,1500};
int CardNumber = 1;
int amountExchange = 100;
int increment[7] = {1,5,10,20,50,100,500};
int incrementCount = 0;
int buttonState;

void setup() {
  Serial.begin(9600);                //Initiate Serial Communication
  pinMode(ToggleClick, INPUT);
  pinMode(Confirm, INPUT_PULLUP);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);               // set cursor to 1 symbol of 1 line
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  
  
}

void loop() {
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("<-");
  lcd.print(increment[incrementCount]);
  lcd.print("->");
  
  lcd.setCursor(8,0);
  lcd.print(amountExchange);
  
  x = analogRead(A1);
  y = analogRead(A2);
  PayGetSystem();
  
  buttonState = digitalRead(Confirm);
//  Serial.print(buttonState);
  if (buttonState == 0){
    Serial.print(buttonState);
    CardBalance[CardNumber] += amountExchange;
    }
//  if (card is scan){then cardbalance + amountexchange and print card number and cardbalance}
  RFID_cardRead();
  lcd.setCursor(0,1);
  lcd.print("Card:");
  lcd.print(CardNumber);
  lcd.setCursor(8,1);
  lcd.print(CardBalance[CardNumber]);
    
  delay(100);   //just written for proper readability
}
///*
int PayGetSystem() {
    /////////////////////////////////////////////////////////////////////
  // Pay and Get system
  if (y < 10){
    amountExchange = amountExchange - increment[incrementCount];
    
  }
  if (y > 900){
    amountExchange = amountExchange + increment[incrementCount];
  }
  if (x < 10){
    if (incrementCount != 0){
          incrementCount = incrementCount - 1;
      }
  }
  if (x > 900){
    if (incrementCount != 6){
          incrementCount = incrementCount + 1;
      }
  }
}
////////////////////////////////////////////////////////////////////////
//*/

///*
//Read RFID Card
int RFID_cardRead(){
// Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();

  if (content.substring(1) == "B9 C5 1C C2"){
    Serial.println("Card1");
    CardNumber = 1;
    delay(100);
    }
  if (content.substring(1) == "13 37 48 92"){
    Serial.println("Card2");
    CardNumber = 2;
    delay(100);
    }
  if (content.substring(1) == "F1 C5 A6 1C"){
    Serial.println("Card3");
    CardNumber = 3;
    delay(100);
    }
} 

  
