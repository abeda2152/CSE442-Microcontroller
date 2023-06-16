int out = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(out, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int detect = digitalRead(8);
  if(detect == LOW){
    digitalWrite(out, 1);
    Serial.println("Obstacle on the way");
  }else{
    digitalWrite(out, 0);
    Serial.println("All clear");
  }
  delay(300);
}
