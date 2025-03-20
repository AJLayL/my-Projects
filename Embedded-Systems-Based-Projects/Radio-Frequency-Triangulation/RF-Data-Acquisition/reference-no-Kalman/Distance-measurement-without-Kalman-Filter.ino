void setup() {
    // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
  float read_data1 = analogRead(A1);
  float read_data2 = analogRead(A2);
  Serial.print(read_data1);
  Serial.print(",");
  Serial.println(read_data2);
  }
  