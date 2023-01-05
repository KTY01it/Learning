#define in1 6  //Right Motor MA1
#define in2 7  //Right Motor MA2
#define in3 8  //Left Motor MB1
#define in4 9  //Left Motor MB2
#define enA 5  //Right Motor Enable Pin EA
#define enB 10 //Left Motor Enable Pin EB

   int sensor0 = digitalRead(A0);
   int sensor1 = digitalRead(A1);
   int sensor2 = digitalRead(A2);
   int sensor3 = digitalRead(A3);
   int sensor4 = digitalRead(A4);

  int error = 0;
  
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

void doline()
{
switch (error)
    {
      case 103:
        //Tien(SpMaxL,SpMaxR-150);
        backward();
        //Rephai();
        break;
      case 0:
        forward();
        break;
      case 1:
        right1();
        break;
      case 2:
        right1();
        break;
      case 3:
        right1();
        break;
      case 4:
        right2();
        break;
      case -1:
        left1();
        break;
      case -2:
        left1();
        break;
      case -3:
        left1();
        break;
      case -4:
        left2();
        break;
      default:
        digitalWrite(6, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        digitalWrite(9, 0);
    }
}

//int trangThai5CamBien ()
//{
//  /*
//      Am la lech phai
//      Duong la lech trai
//      Muc do lech giam tang dan : 1 2 3
//  */
//  int sensor0 = digitalRead(A0);
//  int sensor1 = digitalRead(A1);
//  int sensor2 = digitalRead(A2);
//  int sensor3 = digitalRead(A3);
//  int sensor4 = digitalRead(A4);
//  switch (lechvach5mat())
//  {
//    case -4:
//      return -4;
//      break;
//    case -3:
//      return -3;
//      break;
//    case -2:
//      return -2;
//      break;
//    case -1:
//      return -1;
//      break;
//    case 0:
//      if ((sensor0 == 1) && (sensor1 == 1) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1))
//        return 103;
//      else
//        return 0;
//      break;
//    case 1:
//      return 1;
//      break;
//    case 2:
//      return 2;
//      break;
//    case 3:
//      return 3;
//      break;
//    case 4:
//      return 4;
//      break;
//  }  
//}
//int lechvach5mat()
//{
//  
//  /*
//   Am la lech phai
//   Duong la lech trai
//   Muc do lech giam tang dan : 1 3 2
//   */
//   int sensor0 = digitalRead(A0);
//   int sensor1 = digitalRead(A1);
//   int sensor2 = digitalRead(A2);
//   int sensor3 = digitalRead(A3);
//   int sensor4 = digitalRead(A4);
//   int lechvach = -2 * sensor0 - sensor1 + sensor3 + 2 * sensor4;
//   switch (error)
//   {
//      case -4:
//        return -4;
//        break;
//      case -3://cai nay la do 2 mat bien deu cham vach 
//        return -2;
//        break;
//      case -2:
//        return -3;
//        break;
//      case -1:
//        return -1;
//        break;
//      case 0:
//        return 0;
//        break;
//      case 1:
//        return 1;
//        break;
//      case 2:
//        return 3;
//        break;
//      case 3:
//        return 2;
//        break;
//      case 4:
//        return 4;
//        break;  
//   }
//}

void loop() {
  //Reading Sensor Values
  int error = 0; 
       if ((sensor0 == 1) && (sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0))       // lệch phải nhiều
    error = -4;
  else if ((sensor0 == 1) && (sensor1 == 1) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0))
    error = -3;
  else if ((sensor0 == 0) && (sensor1 == 1) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0))
    error = -2;
  else if ((sensor0 == 0) && (sensor1 == 1) && (sensor2 == 1) && (sensor3 == 0) && (sensor4 == 0))  // ko lệch
    error = -1;
  else if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 1) && (sensor3 == 0) && (sensor4 == 0))
    error = 0;
  else if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 0))
    error = 1;
  else if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 0) && (sensor3 == 1) && (sensor4 == 0))  // lệch trái nhiều
    error = 2;
  else if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 0) && (sensor3 == 1) && (sensor4 == 1))  // lệch trái nhiều
    error = 3;
  else if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 1))  // lệch trái nhiều
    error = 4;
  else if ((sensor0 == 1) && (sensor1 == 1) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 0)) // Turn robot left side
    error = 100;
  else if ((sensor0 == 0) && (sensor1 == 1) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1)) // Turn robot right side
    error = 101;
  else if ((sensor0 == 0) && (sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0)) // Make U turn
    error = 102;
  else if ((sensor0 == 1) && (sensor1 == 1) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1)) // Turn left side or stop
    error = 103;
}

void forward()
{

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);  
        analogWrite(enA, 250); //you can adjust the speed of the motors from 0-255
    analogWrite(enB, 250); //you can adjust the speed of the motors from 0-255
}

void backward()
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enA, 250);
analogWrite(enB, 250);
}

void right1()
{
 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0); //you can adjust the speed of the motors from 0-255
    analogWrite(enB, 250); //you can adjust the speed of the motors from 0-255
  }

void right2()
{
 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH); 
    analogWrite(enA, 0); //you can adjust the speed of the motors from 0-255
    analogWrite(enB, 250); //you can adjust the speed of the motors from 0-255
}

void left1()
{
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 250); //you can adjust the speed of the motors from 0-255
    analogWrite(enB, 0); //you can adjust the speed of the motors from 0-255
}  

void left2()
{

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
        analogWrite(enA, 250); //you can adjust the speed of the motors from 0-255
    analogWrite(enB, 0); //you can adjust the speed of the motors from 0-255
}

void left3()
{    

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
        analogWrite(enA, 250); //you can adjust the speed of the motors from 0-255
    analogWrite(enB, 0); //you can adjust the speed of the motors from 0-255
}

void right3()
{

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
        analogWrite(enA, 0); //you can adjust the speed of the motors from 0-255
    analogWrite(enB, 250); //you can adjust the speed of the motors from 0-255
}

void right4()
{

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);  
        analogWrite(enA, 0); //you can adjust the speed of the motors from 0-255
    analogWrite(enB, 250); //you can adjust the speed of the motors from 0-255
}

void left4()
{
 
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);  
       analogWrite(enA, 250); //you can adjust the speed of the motors from 0-255
    analogWrite(enB, 0); //you can adjust the speed of the motors from 0-255
}
