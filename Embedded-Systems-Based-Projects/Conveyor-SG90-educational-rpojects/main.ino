#include <Servo.h> 

int conveyor_running = 0;
int starting_speed = 75;
int speed_servo = 85;
int prepare_to_stop = 0;
int start_operation = 0;
int potentiometer = 0;
int potentiometer_reading = 0;

unsigned long record_time = 0;
unsigned long current_millis = 0;
const long interval = 2000;
unsigned long calculated_time = 0;
unsigned long stop_time = 0;
const long stop_interval = 5000;
int sensor[8];

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);

  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(A1, INPUT);
//  record_time = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  current_millis = millis();

//  //////////////////////////////////////////////////////////////////////
// reading potentiometer for speed variation
  for (int i = 1; i < 10; i++){
    potentiometer_reading = analogRead(A1);
    potentiometer = (potentiometer + potentiometer_reading)/i;
  }
//  Serial.println(potentiometer);

  if (digitalRead(10) == 0){
    myservo.write(85);
  }
//  /////////////////////////////////////////////////////////////////////
  //  Read Conveyor Sensor
  for (int i = 2; i < 6; i++){
    sensor[i] = digitalRead(i);  
    Serial.print(sensor[i]);  
    delay(10);
  }
  Serial.println("");
///////////////////////////////////////////////////////////////////////
// Start conveyor when booted
  if (conveyor_running == 0 && start_operation == 0){
    start_operation = 1;
    conveyor_on();
  } 
//////////////////////////////////////////////////////////////////////
// Stoppping Conveyor with timer so that the object stop at the end of the conveyor

  if (sensor[5] == 1){                             // detect object on conveyor
//    conveyor_off();
    prepare_to_stop = 1;
    record_time = millis();
//    Serial.println("1");
  }
  calculated_time = current_millis - record_time; // calculate the time different and zero-ing out the negative number
  if (calculated_time > 40000){
    calculated_time = 0;
  }
  
  if (prepare_to_stop == 1){                      // after some time(interval) the conveyor will be stopped
    if (calculated_time > interval){
      conveyor_off();
      prepare_to_stop = 0;
    }
  }
//////////////////////////////////////////////////////////////////////
// Start the conveyor again
  if (conveyor_running == 0){
    if (current_millis - stop_time > stop_interval && current_millis - stop_time < 40000){
      start_operation = 0;
    }
  }
}


void conveyor_on(){ // Starting the conveyor
  myservo.write(80);
  conveyor_running = 1;
//  Serial.println("Starting Conveyor!");
}
void conveyor_off(){ // Stopping the conveyor
  myservo.write(90);
  conveyor_running = 0;
  stop_time = millis();
//  Serial.println("Conveyor has stopped");
}