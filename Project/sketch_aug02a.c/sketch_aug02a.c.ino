const int analogInPin = A5;
int sensorValue = 0;
int outputValue = 0;
int out = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(out, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(analogInPin);
  //outputValue = map(sensorValue, 0, 1023, 0, 255);
  //analogWrite(out, outputValue);
  Serial.print("\nsensor = ");
  Serial.print(sensorValue);
  if(sensorValue<400){
    digitalWrite(out, 1);
    //Serial.print("\nObject Detected");
  }
  else{
    digitalWrite(out, 0);
    //Serial.print("\n No object in front");
  }
  delay(150);
}
