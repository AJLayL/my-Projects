//Kalman filter variables
float varVolt = 1.12184278324081E-05;  // variance determined using excel and reading samples of raw sensor data
float varProcess1 = 1e-11;
float varProcess2 = 1e-10;
float Pc1 = 0.0;
float Pc2 = 0.0;
float G = 0.0;
float P = 1.0;
float Xp1 = 0.0;
float Xp2 = 0.0;
float Zp1 = 0.0;
float Zp2 = 0.0;
float Xe1 = 0.0;
float Xe2 = 0.0;

float distance1;
float distance2;

float M1_set[] = {0.050887, 0.092751, 0.248114};
float M2_set[] = {0.084352, 0.262334, 0.352338};

float M1 = 0;
float M2 = 0;

float C1_set[] = {-18.8771,-35.2297,-96.7545};
float C2_set[] = {-29.7677,-94.6871,-127.688};

float C1 = 0;
float C2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float rfStrength1 = analogRead(A1);
  float rfStrength2 = analogRead(A2); 

//-----------------------------------------------------------------------------------  
//  // kalman process
//  Pc = P + varProcess;
//  G = Pc/(Pc + varVolt);    // kalman gain
//  P = (1-G)*Pc;
//  Xp1 = Xe1;
//  Xp2 = Xe2;
//  Zp1 = Xp1;
//  Zp2 = Xp2;
//  Xe1 = G*(voltage_1-Zp1)+Xp1;   // the kalman estimate of the sensor voltage_1
//  Xe2 = G*(voltage_2-Zp2)+Xp2;   // the kalman estimate of the sensor voltage_2
//------------------------------------------------------------------------------------

  // kalman process 1
  Pc1 = P + varProcess1;
  G = Pc1/(Pc1 + varVolt);    // kalman gain
  P = (1-G)*Pc1;
  Xp1 = Xe1;
  Zp1 = Xp1;
  Xe1 = G*(rfStrength1-Zp1)+Xp1;   // the kalman estimate of the sensor voltage_1

    // kalman process 2
  Pc2 = P + varProcess2;
  G = Pc2/(Pc2 + varVolt);    // kalman gain
  P = (1-G)*Pc2;
  Xp2 = Xe2;
  Zp2 = Xp2;
  Xe2 = G*(rfStrength2-Zp2)+Xp2;   // the kalman estimate of the sensor voltage_2
//------------------------------------------------------------------------------------
//  //Range 
  if  (Xe1 < 390){
    M1 = M1_set[0];
    C1 = C1_set[0];
  }
  else if  (Xe1 > 389 && Xe1 < 397){
    M1 = M1_set[1];
    C1 = C1_set[1];
  }
  else if  (Xe1 > 395){
    M1 = M1_set[2];
    C1 = C1_set[2];
  }
  
//   //Range
  if  (Xe2 < 364){
    M2 = M2_set[0];
    C2 = C2_set[0];
  }
  else if  (Xe2 > 364 && Xe2 < 367){
    M2 = M2_set[1];
    C2 = C2_set[1];
  }
  else if  (Xe2 > 366){
    M2 = M2_set[2];
    C2 = C2_set[2];
  }  
//-----------------------------------------------------
    M1 = 0.238671467;
    M2 = 0.082488834;
    C1 = -83.84108518;
    C2 = -27.94832558;
//  ----------------------------------------------------
//  Kalman Check
//
//  Serial.println(Xe1);
//  Serial.print(",");
//  Serial.println(Xe2);
//------------------------------------------------------
//  convert to distance
  distance1 = (M1*Xe1) + C1;
  distance2 = (M2*Xe2) + C2;
//------------------------------------------------------
//  print distance;
//
  Serial.print(distance1);
  Serial.print(",");
  Serial.println(distance2);
//-------------------------------------------------------

}
