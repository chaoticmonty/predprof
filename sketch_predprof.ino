#include <Servo.h>

Servo servo1, servo2;
int pho1 = A5, pho2 = A3, pho3 = A4, pho4 = A2;
int pov = 115;

void setup()
{
  pinMode(pho1, INPUT);
  pinMode(pho2, INPUT);
  pinMode(pho3, INPUT);
  pinMode(pho4, INPUT);
  servo1.attach(11);
  servo2.attach(12);
  Serial.begin(9600);
}
void loop()
{
  int west = analogRead(pho1);
  int east = analogRead(pho2);
  int middle1 = abs(west - east)
  
  if (west - east > 100 && middle1 - pov > 0)
  {
    servo1.write(180);
    delay(200);
    servo1.write(90);
    delay(1000);
  }
  if (east - west > 100 && middle1 - pov > 0)
  {
    servo1.write(0);
    delay(200);
    servo1.write(90);
    delay(1000);
  }

  if (abs(east - west) < 100 or middle1 - pov < 0)
  {
    delay(3000);
  }
  delay(1000);

  int south = analogRead(pho3);
  int north = analogRead(pho4);
  int middle2 = abs(south - north)
  
  if (south - north > 100 && middle2 - pov > 0)
  {
    servo2.write(180);
    delay(200);
    servo2.write(90);
    delay(1000);
  }
  if (north - south > 100 && middle2 - pov > 0)
  {
    servo2.write(0);
    delay(200);
    servo2.write(90);
    delay(1000);
  }

  if (abs(north - south) < 100 or middle2 - pov < 0)
  {
    delay(3000);
  }
}
