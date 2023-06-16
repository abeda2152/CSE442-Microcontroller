#include<Servo.h>

Servo servo;

int sensorPin0 = A0;    //irsensor
int sensorPin1 = A1;    //irsensor
int sensorPin2 = A2;    //irsensor
int sensorPin3 = A3;    //irsensor
int out2 = 2; //r1
int out3 = 3; //g1
int out4 = 4; //r2
int out5 = 5; //g2
int i = 0;
int sensorValue0 = 0;
int sensorValue1 = 0;
int outputValue2 = 0;
int sensorValue2 = 0;
int outputValue3 = 0;
int sensorValue3 = 0;
int servopin = 9;       //servo
int servoValue1 = 0;    //servo
int servoValue0 = 0;    //servo

void setup() {
  Serial.begin(9600);
  servo.attach(servopin);
  servo.write(0);
  delay(2000);
  
}

void loop() {
  sensorValue0 = analogRead(sensorPin0);  //servo
  sensorValue1 = analogRead(sensorPin1);  //servo
  sensorValue2 = analogRead(sensorPin2);  //led
  sensorValue3 = analogRead(sensorPin3);  //led
  Serial.println(sensorValue0);
  outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
  outputValue3 = map(sensorValue3, 0, 1023, 0, 255);
  servoValue1 = map(sensorValue0, 0, 1023, 0, 179);
  servoValue0 = map(sensorValue0, 0, 1023, 0, 0);
  if(sensorValue0 < 300){
    servo.write(servoValue1);
    delay(15);
    Serial.println("Obstacle on the way");
  }else{
    servo.write(servoValue0);
    delay(15);
    Serial.println("All clear");
  }
  if(sensorValue2 < 200){
    analogWrite(2, 255);
    analogWrite(3, 0);
    //Serial.println("Obstacle on the way");
  }else{
    analogWrite(3, 255);
    analogWrite(2, 0);
    //Serial.println("All clear");
  }
  if(sensorValue3 < 200){
    analogWrite(4, 255);
    analogWrite(5, 0);
    //Serial.println("Obstacle on the way");
  }else{
    analogWrite(5, 255);
    analogWrite(4, 0);
    //Serial.println("All clear");
  }
  delay(600);
}
