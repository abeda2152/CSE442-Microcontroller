#include<Servo.h>

Servo servo;

int sensorPin0 = A0;
int out2 = 2; //r1
int out3 = 3; //g1
int i = 0;
int outputValue0 = 0;
int sensorValue0 = 0;
int servopin = 9;
int servoValue1 = 0;
int servoValue0 = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(servopin);
  servo.write(0);
  delay(2000);
  
}

void loop() {
  sensorValue0 = analogRead(sensorPin0);
  Serial.println(sensorValue0);
  //outputValue0 = map(sensorValue0, 0, 1023, 0, 255);
  servoValue1 = map(sensorValue0, 0, 1023, 0, 179);
  servoValue0 = map(sensorValue0, 0, 1023, 0, 0);
  if(sensorValue0 < 300){
    servo.write(servoValue1);
    delay(15);
    /*for(int i=0; i<=130; i++){
      servo.write(i);
      delay(15);
      if(analogRead(sensorPin0) > 600){
        servo.write(i);
        delay(3000);
      }
    }*/
    //analogWrite(out2, 255);
    //analogWrite(out3, 0);
    Serial.println("Obstacle on the way");
  }else{
    /*for(int i=180; i>=0; i--){
      servo.write(i);
      delay(15);
      /*if(analogRead(sensorPin0) > 600){
        servo.write(i);
        delay(3000);
      }
    }*/
    servo.write(servoValue0);
    delay(15);
    //analogWrite(out3, 255);
    //analogWrite(out2, 0);
    Serial.println("All clear");
  }
  delay(600);
}
