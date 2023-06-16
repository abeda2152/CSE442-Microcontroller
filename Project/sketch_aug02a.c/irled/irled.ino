
int sensorPin = A0;
int out1 = 2; //r1
int out2 = 3; //g1
int outputValue = 0;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
  if(outputValue<200){
    analogWrite(out1, 255);
    analogWrite(out2, 0);
    Serial.println("Obstacle on the way");
  }else{
    analogWrite(out2, 255);
    analogWrite(out1, 0);
    Serial.println("All clear");
  }
  delay(600);
}
