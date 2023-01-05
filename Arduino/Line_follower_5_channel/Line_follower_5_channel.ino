#define in1 6  //Right Motor MA1
#define in2 7  //Right Motor MA2
#define in3 8  //Left Motor MB1
#define in4 9  //Left Motor MB2
#define enA 5  //Right Motor Enable Pin EA
#define enB 10 //Left Motor Enable Pin EB

//**********5 Channel IR Sensor Connection**********//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
//*************************************************//

int M1_Speed = 70; // speed of motor 1
int M2_Speed = 70; // speed of motor 2
int LeftRotationSpeed = 255; // Left Rotation Speed
int RightRotationSpeed = 255; // Right Rotation Speed

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}

void loop() {
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

  //cảm biến giữa phát hiện đường màu trắng
  if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 0) && (s5 == 0))
  {
    forward();
  }

  //chỉ 1 cảm biến bên trái phát hiển đường màu trắng
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    left1();
  }
  //cảm biến xa nhất bên trái phát hiện màu trắng
  if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    left2();
//    left1();
  }
  //cảm biến bên phải phát hiện màu trắng
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    right1();
  }
  //cảm biến bên phải ngoài cùng phát hiện màu trắng
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  {
    right2();
//    right1();
  }
  //giữa và bên phải phát hiện màu trắng
  if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    right3();
  }

  //giữa và bên trái phát hiện màu trắng
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0))
  {
    left3();
  }
  //giữa, trái và trái ngoài cùng phát hiện màu trắng
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0))
  {
    left4();
  }
  //giữa, phải và phải ngoài cùng phát hiện màu trắng
  if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  { 
    right4();
  }

  //tất cả đều trắng
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  
//  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
//  {
//    delay(200);
//    backward();
//   
//  }
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
