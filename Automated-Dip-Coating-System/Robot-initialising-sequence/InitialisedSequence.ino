// this is the Initializing phase of the dip coating machine.
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
void setup() {
  // put your setup code here, to run once:
  pinMode(DIR,OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(upperLimit,INPUT);
  pinMode(lowerLimit,INPUT);
  Serial.begin(115200);

}

void loop() {
  //To calculate our height to Step ratio, get the maxStep of the robot/nema17.
  digitalWrite(DIR,HIGH);
  while(!lowerLimit){
    digitalWrite(STEP,HIGH);
    delay(1);//shud change to millis type delay
    digitalWrite(STEP,LOW);
    delay(1);
    stepCount++;
  }
  maxStep = stepCount;
  desiredStep = (desiredHeight * maxStep) / maxHeight;

  
  for(int i=0;i <= desiredStep;i++){
    digitalWrite(DIR,LOW);
    digitalWrite(STEP,HIGH);
    delay(1);
    digitalWrite(STEP,LOW);
    delay(1);
  }
} 
