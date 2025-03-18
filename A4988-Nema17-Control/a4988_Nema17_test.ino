
//funtion to get distance
// this is the Initialis=zing phase of the dip coating machine.
// This will help us get the esp32 to  translate step to height.

//define pins
#define DIR 0
#define STEP 2
#define upperLimit 16
#define lowerLimit 17

//define var
int maxStep = 0;
int maxHeight = 100;// set this by manually measure your upperlimit to lower limit. (mm)
int desiredStep = 0;
int desiredHeight = 0;
int offsets = 0;
int stepCount = 0;

unsigned long previousMillis = 0; // Stores the last time the event was triggered
const long interval = 1000; // Interval at which to perform the action (e.g., 1000ms = 1 second)

// get Dip Speed
// get Dip Height
float dipSpeed = 5.5;
float dipHeight = 10.5;

// move to position
void moveMotor(){
  if(!swap){
      digitalWrite(STEP,HIGH);
      swap = !swap;
    }
    else{
      digitalWrite(STEP,LOW);
      swap = !swap;
    }
}

// go to lower limit with 'slow' speed.
void gotoLowerLimit(){
  //update motor to anticlockwise until reach lower limit button.
  if(!lowerLimit && loweringState){
    digitalWrite(DIR,LOW);
    moveMotor();
  }
  if(lowerLimit){
    loweringState = false;
  }
}

void countStep(){
  if(!upperlimit && goingUpState){
    digitalWrite(DIR,HIGH);
    moveMotor();
    stepCount++;
  }
  if(upperlimit){
    goingUpState = false;
  }
}

void desiredStepEquation(){
  maxStep = stepCount;
  desiredStep = (desiredHeight * maxStep) / maxHeight;
}

void gotoDesiredStep(){
  //get desiredStep
  desiredStep = desiredStepEquation();
  if (desiredStep != stepCount){
    if(stepCount <= desiredStep){
      digitalWrite(DIR,HIGH);
      moveMotor();
      stepCount++;
    }
    if(stepCount >= desiredStep){
      digitalWrite(DIR,LOW);
      moveMotor();
      stepCount--;
    }
  }
}

//function to StartDip process
void startDipProcess(){
  // if_start_State
  gotoDesiredStep();
  if(startDip && desiredStep == stepCount){                // go lower till reach height.
    digitalWrite(DIR,LOW);
    moveMotor();
    stepCount--;
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;                      // suspended for some time.
      gotoDesiredStep()                                    // go up to desired_position
      startDip = false;
    }
    
  }
}


void setup() {
  pinMode(DIR,OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(upperLimit,INPUT);
  pinMode(lowerLimit,INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if(button1){
   //start getting step
   loweringState = true;
  }
  switch(button):
  case 1:
  
  
  if(loweringState){
    gotoLowerLimit();
  }

}
