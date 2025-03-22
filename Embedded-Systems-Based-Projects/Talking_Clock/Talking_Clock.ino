#define SD_ChipSelectPin 4
#include <LiquidCrystal_I2C.h>
#include <TMRpcm.h>
#include <Wire.h> 
#include <SPI.h>
#include <SD.h>
#include "RTClib.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 myRTC;
TMRpcm tmrpcm;

int temp=1;
int pp=5;
int next=6;
int ButtonPin = 2;
int buttonPressed;
int hr;
int minit;
String set_waktu;
String waktu[4] = {"PAGI","TENGAHARI","PETANG","MALAM"};
String dayoftheweek[]={"ISNIN","SELASA","RABU","KHAMIS","JUMAAT","SABTU","AHAD"};
String play_hour;
String play_minit;
String play_waktu;
int num;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ButtonPin, INPUT_PULLUP);

  pinMode(pp,INPUT_PULLUP);
  pinMode(next,INPUT_PULLUP);
  
  tmrpcm.speakerPin = 9;
  if (!SD.begin(SD_ChipSelectPin)) // returns 1 if the card is present
    {
      lcd.print("SD fail");
      return;
    }
  lcd.begin();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (buttonPressed == 0){
    if (digitalRead(ButtonPin) == LOW){
      song();
      buttonPressed = 1;
    }
  }
  buttonPressed = 0;
  DateTime now = myRTC.now(); 
  hr = now.hour();
  minit = now.minute();

  if(hr < 12){set_waktu = waktu[0];}
  if(hr == 0){set_waktu = waktu[3];}
  if(hr == 12){set_waktu = waktu[1];}
  if(hr > 12){set_waktu = waktu[2];}
  if(hr > 18){set_waktu = waktu[3];}

  if (hr > 12){hr = hr - 12;}
  if (hr < 10){lcd.print("0");}
  lcd.print(hr);
  lcd.print(":");
  if (minit < 10){lcd.print("0");}
  lcd.print(minit);
  lcd.print(" ");
  lcd.print(set_waktu);
  lcd.setCursor(0,1);
  lcd.print(dayoftheweek[now.dayOfTheWeek() -1]);
  lcd.print(" ");
  lcd.print(now.day());
  lcd.print("/");
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.year());
  delay(100);
  lcd.clear();
  
}


void song (void)
{
  if (hr > 12){hr = hr - 12;}
  if (hr == 0){tmrpcm.play("12.wav");  delay(2500); }
  if (hr == 1){tmrpcm.play("1.wav");  delay(2500); }
  if (hr == 2){tmrpcm.play("2.wav");  delay(2500); }
  if (hr == 3){tmrpcm.play("3.wav");  delay(2500); } 
  if (hr == 4){tmrpcm.play("4.wav");  delay(2500); }
  if (hr == 5){tmrpcm.play("5.wav");  delay(2500); }
  if (hr == 6){tmrpcm.play("6.wav");  delay(2500); }
  if (hr == 7){tmrpcm.play("7.wav");  delay(2500); }
  if (hr == 8){tmrpcm.play("8.wav");  delay(2500); }
  if (hr == 9){tmrpcm.play("9.wav");  delay(2500); }
  if (hr == 10){tmrpcm.play("10.wav");  delay(2500); }
  if (hr == 11){tmrpcm.play("11.wav");  delay(2500); }
  if (hr == 12){tmrpcm.play("12.wav");  delay(2500); }
  if (minit > 9){if (minit < 20){tmrpcm.play("suku.wav");  delay(2500);}}
  if (minit > 19){if (minit < 30){tmrpcm.play("20.wav");  delay(2500);}}
  if (minit > 29){if (minit < 40){tmrpcm.play("setengah.wav");  delay(2500);}}
  if (minit > 39){if (minit < 50){tmrpcm.play("40.wav");  delay(2500);}}
  if (minit > 49){if (minit < 59){tmrpcm.play("50.wav");  delay(2500);}}

  if (set_waktu == "PAGI"){tmrpcm.play("Pagi.wav");  delay(3000); }
  if (set_waktu == "TENGAHARI"){tmrpcm.play("Petang.wav");  delay(3000); }
  if (set_waktu == "PETANG"){tmrpcm.play("Petang.wav");  delay(3000); }
  if (set_waktu == "MALAM"){tmrpcm.play("Malam.wav");  delay(3000); Serial.print("playing");}
  
  
  
  
  delay(100); 
  Serial.print("is playing");

  
}
