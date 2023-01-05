/*
 * Created by Lam Hong Duc
 * Date 17/11/2020
 */

int trig1 = A0;
int echo1 = A1;
int trig2 = A2;
int echo2 = A3;
int trig3 = A4;
int echo3 = A5;

int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
int ENA = 3;
int ENB = 11;
int LeftSpeed = 125;
int RightSpeed = 130;
long leftDistance = 0,middleDistance = 0,rightDistance = 0;
long pingTime,distance;
float speedSound = 0.0343;
int DIS = 25;

long leftMeasurement()
{
  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);
  pingTime = pulseIn(echo1,HIGH);
  distance = (pingTime/2)*speedSound;
  return(distance); 
}

long middleMeasurement()
{
  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);
  pingTime = pulseIn(echo2,HIGH);
  distance = (pingTime/2)*speedSound;
  return(distance); 
}

long rightMeasurement()
{
  digitalWrite(trig3,LOW);
  delayMicroseconds(2);
  digitalWrite(trig3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3,LOW);
  pingTime = pulseIn(echo3,HIGH);
  distance = (pingTime/2)*speedSound;
  return(distance); 
}

void setup()
{
  Serial.begin(9600);
  pinMode(trig1,OUTPUT);
  pinMode(trig2,OUTPUT);
  pinMode(trig3,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(echo2,INPUT);
  pinMode(echo3,INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  moveStop();
}

void loop()
{
  leftDistance = leftMeasurement();
  delay(10);
  middleDistance = middleMeasurement();
  delay(10);
  rightDistance = rightMeasurement();
  delay(10);
  Serial.print("leftDistance = ");
  Serial.print(leftDistance);
  Serial.print("cm /");
  Serial.print("middleDistance = ");
  Serial.print(middleDistance);
  Serial.print("cm /");
  Serial.print("rightDistance = ");
  Serial.print(rightDistance);
  Serial.println("cm");

  //  Obstacle on left side
  if(leftDistance < DIS && middleDistance > DIS && rightDistance > DIS)
  {
    turnRight();
    delay(25);  //  turn lightly right    
  }
  //  Obstacle on front
  else if(leftDistance > DIS && middleDistance < DIS && rightDistance > DIS)
  {
    if(leftDistance > rightDistance)
    {
      turnLeft();
      delay(400);  //  turn 90 degree left
    }
    if(leftDistance < rightDistance)
    {
      turnRight();
      delay(400);  //  turn 90 degree right
    }
  }
  //  Obstacle on right side
  else if(leftDistance > DIS && middleDistance > DIS && rightDistance < DIS)
  {
    turnLeft();
    delay(25);  //turn lightly left  
  }
  //  Obstacle on front & left side
  else if(leftDistance < DIS && middleDistance < DIS && rightDistance > DIS)
  {
    turnRight();
    delay(400);  //  turnRight 90 degree
  }
  //  Obstacle on front & right side
  else if(leftDistance > DIS && middleDistance < DIS && rightDistance < DIS)
  {
    turnLeft();
    delay(400);  //  turnLeft 90 degree
  }
  //  Obstacle on left & right side
  else if(leftDistance < DIS && middleDistance > DIS && rightDistance < DIS)
  {
    if(leftDistance > rightDistance)
    {
      turnLeft();
      delay(50);  //  shift left
    }
    if(leftDistance < rightDistance)
    {
      turnRight();
      delay(50);  //  shift right
    }
  }
  //  Obstacle on all 3 side
  else if(leftDistance < DIS && middleDistance < DIS && rightDistance < DIS)
  {
    moveStop();
    delay(1000);
    moveBackward();
    delay(1000);
    turnLeft();
    delay(800);  //turn 180 degrees
  }
  else
  {
    moveForward();
  }
}

void moveForward()
{
  Serial.println("Move Forward");
  analogWrite(ENA,LeftSpeed);
  analogWrite(ENB,RightSpeed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
}

void moveBackward()
{
  Serial.println("Move Backward");
  analogWrite(ENA,LeftSpeed);
  analogWrite(ENB,RightSpeed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
}

void turnRight()
{
  Serial.println("Turn Right");
  analogWrite(ENA,LeftSpeed);
  analogWrite(ENB,RightSpeed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft()
{
  Serial.println("Turn Left");
  analogWrite(ENA,LeftSpeed);
  analogWrite(ENB,RightSpeed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
}

void moveStop()
{
  Serial.println("Move Stop");
  analogWrite(ENA,LOW);
  analogWrite(ENB,LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
}
