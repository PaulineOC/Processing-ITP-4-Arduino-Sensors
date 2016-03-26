#include <Servo.h>
Servo servoMain; // Define  Servo
void setup()
{
  Serial.begin(9600);
  servoMain.attach(A0); // servo on pin 7
  pinMode(A3, INPUT); //touch sensor input
  pinMode(1, INPUT);
  pinMode(2, OUTPUT);

  
  pinMode(3, OUTPUT); //LED game start
  pinMode(4, OUTPUT); //LED game over

  
}

void loop()
{
  int angle = 0;
  int stat = 3;
  for (int go = 0; go < 1000000;){
    delay(25);
    Serial.println(analogRead(A3));
    digitalWrite(3, HIGH);
    if (analogRead(A3) >= 5){
      angle++;
      digitalWrite(4, LOW);
    }
    else {
      angle--;
      digitalWrite(4, LOW);
    }
    if (angle < 30){
      angle = 30;
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
    }
    if (angle > 110){
      angle = 110;
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
    }
  servoMain.write(angle);

}

}

