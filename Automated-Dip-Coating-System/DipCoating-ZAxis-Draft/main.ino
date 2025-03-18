#include <WiFi.h>
#include <WebServer.h>

//initialized html
//html 1
//html 2
#include "html_main_page.h"
#include "html_data_input.h"

// Replace with your network credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);



//Variables
int max_step = 0;
float desired_height;
float dip_speed;
float max_height = 100;//measure and input real world value of the max height of the machine
int desired_step;
int current_step = 0;
float stanby_position;
int stanby_position_step;
float clearance = 0;//in mm/cm.. as in not step. 
const unsigned long interval = 1000; // Interval for state transition, e.g., 1 second
unsigned long previous_millis = 0;
const unsigned long step_interval=0; // Interval between steps in milliseconds
unsigned long last_step_time = 0; // Tracks the last time the motor was stepped
int state = 1; //state 1: stanby mode, state 2: dipping mode
int button_map[4];
bool toggle = false;

// Variables to store setup values
String dippingHeight = "";
String dippingSpeed = "";

//pins
int DIR = 2; //motor direction pin
int STEP = 4; //motor step pin
int lower_limit = 18;
int upper_limit = 19;
int start_dipping_button_pin = 12;
int calibrate_button = 14;
int LED_dipping = 26;
int LED_calibrate = 27;


//html handler
void handleSetupPage() {
  server.send(200, "text/html", setupPage);
}

void handleDataPage() {
  server.send(200, "text/html", dataPage);
}

void handleSetupSubmit() {
  if (server.hasArg("height") && server.hasArg("speed")) {
    dippingHeight = server.arg("height");
    dippingSpeed = server.arg("speed");

    Serial.println("Setup Submission Received:");
    Serial.println("Dipping Height: " + dippingHeight);
    Serial.println("Dipping Speed: " + dippingSpeed);

    dippingHeight = dippingHeight.toFloat();
    dippingSpeed = dippingSpeed.toFloat();

    server.send(200, "text/html", "Setup submission received!");
  } else {
    server.send(400, "text/html", "Incomplete setup submission.");
  }
}

void handleDataSubmit() {
  if (server.hasArg("date") && server.hasArg("time") && server.hasArg("thicknessBefore") && server.hasArg("thicknessAfter")) {
    String date = server.arg("date");
    String time = server.arg("time");
    String thicknessBefore = server.arg("thicknessBefore");
    String thicknessAfter = server.arg("thicknessAfter");

    Serial.println("Data Submission Received:");
    Serial.println("Date: " + date);
    Serial.println("Time: " + time);
    Serial.println("Thickness Before: " + thicknessBefore);
    Serial.println("Thickness After: " + thicknessAfter);

    server.send(200, "text/html", "Data submission received!");
  } else {
    server.send(400, "text/html", "Incomplete data submission.");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(LED_dipping, OUTPUT);
  pinMode(LED_calibrate, OUTPUT);
  pinMode(lower_limit,INPUT);
  pinMode(upper_limit,INPUT);
  pinMode(start_dipping_button_pin,INPUT);
  pinMode(calibrate_button,INPUT);
  delay(10);

  if (max_height <= 0) {
    Serial.println("Error: max_height must be greater than zero.");
    max_height = 1; // set to default or error value
  }

  //setup wifi
    // Connect to Wi-Fi network with SSID and password
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  // Wait for the connection to establish
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  //html handler
  server.on("/", handleSetupPage);
  server.on("/data", handleDataPage);
  server.on("/submitSetup", handleSetupSubmit);
  server.on("/submitData", handleDataSubmit);

  server.begin();
  Serial.println("HTTP server started");
}

//a function to make sure we always have wifi. it will break the code if no wifi which is good
void reconnecting_to_wifi() { // Reconnect to Wi-Fi if disconnected
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reconnecting to WiFi...");
    WiFi.begin(ssid, password);
    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
      delay(500);
      Serial.print(".");
    }
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("Reconnected to WiFi");
    }
  }
}

void loop() {
  reconnecting_to_wifi();
  server.handleClient();
  unsigned long current_millis = millis();
  if (previous_millis == 0){
    previous_millis = current_millis;
  }
  button_map[0] = digitalRead(lower_limit);
  button_map[1] = digitalRead(upper_limit);
  button_map[2] = digitalRead(start_dipping_button_pin);
  button_map[3] = digitalRead(calibrate_button);
  
  if(max_step > 0){
    float desired_height = dippingHeight;//get desired height from html
    float dip_speed = dippingSpeed;// get dip spped from html
    stanby_position = math_standby_position(desired_height, clearance);
    stanby_position_step = math_desired_step(stanby_position, max_step, max_height);
    desired_step = math_desired_step(desired_height, max_step, max_height);
    
    if(button_map[2] == HIGH){ //dipping button
      state = 2; // dipping state
    }

    switch(state){
      case 1://stanby
        Serial.println("state1: Standby mode.");
        if(current_step != stanby_position_step){
          on_standby(stanby_position_step);
        }
        break;
      case 2://dipping
        Serial.println("state2: Dipping mode.");
        on_dipping(desired_step);
        if(current_millis - previous_millis >= interval){
          previous_millis = current_millis;
          state = 1;
        }
        break;
      default:
        Serial.println("Error: Unexpected state.");
        state = 1; // Reset to a known state
        break;
    }

    
    
  }
  else if(max_step == 0  && button_map[3]==HIGH){//calibrate button / get max step button
    get_max_step();
  }
  
}

int math_desired_step(float desired_height,int max_step, float max_height){
  return (desired_height * max_step)/max_height; 
}

float math_standby_position(float desired_height, float clearance){
  return desired_height + desired_height + clearance;
}

void on_standby(int stanby_position_step){
  desired_step = stanby_position_step;
  if(current_step > desired_step){
    set_motor_anticlockwise();
    move_motor(current_millis);;
    current_step--;
  }
  else if(current_step < desired_step){
    set_motor_clockwise();
    move_motor(current_millis);;
    current_step++;
  }
}

void on_dipping(int desired_step){
  if (desired_step < 0 || desired_step > max_step) {
    Serial.println("Error: desired_step is out of bounds.");
    return; // or handle as appropriate
  }
  if (current_step != desired_step){
    set_motor_anticlockwise();
    move_motor(current_millis);;
    current_step--;
  }
}

int get_max_step(){
  bool min_check = false;
  bool max_check = false;
  //go to lower limit button
  if(button_map[0] == LOW && !min_check){//limit switch / lower limit button
    set_motor_anticlockwise();
    move_motor(current_millis);;
  }
  else if(button_map[0] == HIGH && !min_check){
    current_step = 0;
    min_check = true;
  }
  //start counting step while going to max limit button.
  if(button_map[1] == LOW && !max_check && min_check){
    set_motor_clockwise();
    move_motor(current_millis);;
    current_step++;
  }
  else if(button_map[1] == HIGH && !max_check && min_check){
    max_step = current_step;
    max_check = true;
  }
  return max_step;
}



void set_motor_clockwise(){
  digitalWrite(DIR,HIGH);
}

void set_motor_anticlockwise(){
  digitalWrite(DIR,LOW);
}

void move_motor(unsigned long current_millis) {
  if (current_millis - last_step_time >= step_interval) {
    digitalWrite(STEP, toggle ? HIGH : LOW);
    toggle = !toggle;
    last_step_time = current_millis; // Update the last step time
  }
}
