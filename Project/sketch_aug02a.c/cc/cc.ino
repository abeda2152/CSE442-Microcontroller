
#include <Servo.h>

const int control = A0;
const int irsensor = A2;              
int servoPin = 9; 
int i = 0;  
int a = 0;
int onoff = 0;

Servo servo; 

void setup() {

  servo.attach(servoPin); 
}

void loop() {          

  onoff = analogRead(control);
  if(onoff < 600)
  {

    for (int i = 50; i<=130; i++) 
    {
      servo.write(i); 
      delay(25); 
      if(analogRead(irsensor) > 90) 
      {
        servo.write(i); 
        a = i; 
        while (analogRead(irsensor) > 90){
          servo.write(a);
        }
      }
    }

    for (int i = 130; i>=50; i--) 
    {
      servo.write(i); 
      delay(25); 
      if(analogRead(irsensor) > 90) 
      {
        servo.write(i); 
        a = i; 
        while (analogRead(irsensor) > 90){
          servo.write(a);
        }
      }
    }

  }
  while( onoff < 600)
  {
    servo.write(100);
  }


}



  }
  while( onoff < 600)
  {
    servo.write(100);
  }


}
