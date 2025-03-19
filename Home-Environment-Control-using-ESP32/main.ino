//Home Environment Control using ESP32. 
//This is done for school education. Most code is made so that it explain how it works while not using a complicated library.
//INPUT
//DHT22
#include <DHT.h>
#define DHT22_PIN 5 
DHT dht22(DHT22_PIN, DHT22);
float Temp; 
float Humidity;

//LDR
#define Light_intensity_A0 35
float lightValue;

//mpu6050
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

//Potentiometer
#define potentiometer 34
int currentPWM;
int LED_pwm;
int DC_Motor_pwm;
int deviceState = 1;

//Knob
#define Knob_CLK 2
#define Knob_DT 4
#define Knob_SW 0
int newClk = 0;
int lastClk = 0;

int sensor_page = 7;
String Sensor;
float Reading;

//Button_LED
#define LED_Button 18

//Button_Motor
#define DCMotor_Button 19

//OUTPUT
//LED
#define LED 16

//Motor
#define DCMotor 17

//Fan switch
int FanState = 0;
//LED switch
int LightState = 0;

//Display OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); 
  // create SSD1306 display object connected to I2C

String displayString;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  //INPUT
  //DHT22
  dht22.begin();
  //LDR
  pinMode(Light_intensity_A0, INPUT);
  //mpu6050
  mpu.begin();
  //Potentiometer
  pinMode(potentiometer, INPUT);
  //Knob
  pinMode(Knob_CLK, INPUT);
  pinMode(Knob_DT, INPUT);
  //Button_LED
  pinMode(LED_Button, INPUT_PULLUP);
  //Button_Motor
  pinMode(DCMotor_Button, INPUT_PULLUP);

  //OUTPUT
  //LED
  pinMode(LED, OUTPUT);
  //Motor
  pinMode(DCMotor, OUTPUT);
  //Display OLED
  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(200); // wait for initializing
  oled.clearDisplay(); 
  // clear display

  oled.setTextSize(2);      
  // text size
  oled.setTextColor(WHITE); 
  // text color
  oled.setCursor(0, 10);    
  // position to display

  displayString.reserve(10); 
  // to avoid fragmenting memory when using String
}

void loop() {
  //INPUT
  //DHT22
  Humidity  = dht22.readHumidity();    // read humidity
  Temp = dht22.readTemperature(); // read temperature

  //LDR
  lightValue = analogRead(Light_intensity_A0);

  //mpu6050
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  int accel[] = {a.acceleration.x,a.acceleration.y,a.acceleration.z}; 
  int gyro[]  = {g.gyro.x,g.gyro.y,g.gyro.z};
  int mpu_temp = temp.temperature;

  //mpu6050 gyro Y as PWM
  currentPWM = gyro[1];
  currentPWM = map(currentPWM, -4,4,0,255);

  //Knob
  int newClk = digitalRead(Knob_CLK);
  if (newClk != lastClk) {
    // There was a change on the CLK pin
    lastClk = newClk;
    int dtValue = digitalRead(Knob_DT);
    if (newClk == LOW && dtValue == HIGH) {
      if(sensor_page < 11){
        sensor_page += 1;
      }
    }
    if (newClk == LOW && dtValue == LOW) {
      if(sensor_page > 1){
        sensor_page += -1;
      }
    }
  }

  //Dht22 Tempreture control. high temp fan on.
  if(Temp > 30){
    FanState = 1;
  }
  else{
    FanState = 0;
  }
  if(lightValue > 150){
    LightState = 1;
  }
  else{
    LightState = 0;
  }


  // if night/low light level outside.
  if(LightState == 1){
    //Button_LED
    if(digitalRead(LED_Button) == LOW){
      deviceState = 1;
    }
    if(deviceState == 1){
      LED_pwm = currentPWM;
    }
  }
  if(LightState == 0){
    LED_pwm = 0;
  }

  //if Tempreture is too hot
  if(FanState == 1){
    //Button_Motor
    if(digitalRead(DCMotor_Button) == LOW){
      deviceState = 2;
    }
    if(deviceState == 2){
      DC_Motor_pwm = currentPWM;
    }
  }
  if(FanState == 0){
    DC_Motor_pwm = 0;
  }

  

  //OUTPUT
  //LED
  analogWrite(LED, currentPWM);
  //Motor
  analogWrite(DCMotor, DC_Motor_pwm);
  //Display OLED
  switch(sensor_page){
    case 1:
      Sensor = "Tempreture";
      Reading = Temp;
      break;
    case 2:
      Sensor = "Humidity";
      Reading = Humidity;
      break;
    case 3: 
      Sensor = "Light";
      Reading = lightValue;
      break;
    case 4:
      Sensor = "AccelerometerX";
      Reading = accel[0];
      break;
    case 5:
      Sensor = "AccelerometerY";
      Reading = accel[1];
      break;
    case 6:
      Sensor = "AccelerometerZ";
      Reading = accel[2];
      break;
    case 7:
      Sensor = "GyroX";
      Reading = gyro[0];
      break;
    case 8:
      Sensor = "GyroY";
      Reading = gyro[1];
      break;
    case 9:
      Sensor = "GyroZ";
      Reading = gyro[2];
      break;
    case 10: 
      Sensor = "Mpu_Temp";
      Reading = mpu_temp;
      break;
    
  }

  String displayString = "";
    displayString += Sensor;
    displayString += ":    ";
    displayString += Reading;
    displayString += "   ";
    oledDisplayCenter(displayString); // display on OLED

  //debugging feature:
  Serial.println("");
  Serial.println("Temp : humi : Light : ax : ay: az: gx : gy : gz : mTemp : PWM : state");
  Serial.println("");
  Serial.print(Temp);
  Serial.print(" : ");
  Serial.print(Humidity);
  Serial.print(" : ");
  Serial.print(lightValue);
  Serial.print(" : ");
  Serial.print(accel[0]);
  Serial.print(" : ");
  Serial.print(accel[1]);
  Serial.print(" : ");
  Serial.print(accel[2]);
  Serial.print(" : ");
  Serial.print(gyro[0]);
  Serial.print(" : ");
  Serial.print(gyro[1]);
  Serial.print(" : ");
  Serial.print(gyro[2]);
  Serial.print(" : ");
  Serial.print(mpu_temp);
  Serial.print(" : ");
  Serial.print(currentPWM);
  Serial.print(" : ");
  Serial.print(deviceState);
  Serial.print(" : ");
  Serial.print(digitalRead(LED_Button));
  Serial.print(" : ");
  Serial.print(digitalRead(DCMotor_Button));
  Serial.println("");

  delay(100); 
}

void oledDisplayCenter(String text) {
  int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;

  oled.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);

  // display on horizontal and vertical center
  oled.clearDisplay(); // clear display
  oled.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);
  oled.println(text); // text to display
  oled.display();
}
