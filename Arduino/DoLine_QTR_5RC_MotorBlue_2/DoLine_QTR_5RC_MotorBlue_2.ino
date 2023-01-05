///////////// Search Line Car - QTR - 5RC - PID - Blue Motor  //////////
/////////////       10-3-2021           //////////////
  
#include <QTRSensors.h>

#define Kp 0.02       //0.03  //0.016 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd 0.38       //0.2   //0.34  // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define MaxSpeed 220    // max speed of the robot
#define BaseSpeed 84    //35    // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  5  // number of sensors used

#define speedturn  110 //180

#define rightMotor1   6
#define rightMotor2   7
#define rightMotorPWM 5 //5
#define leftMotor1    8
#define leftMotor2    9
#define leftMotorPWM  10 //6

#define L_led 11  // Đèn si nhan trai ////////////             
#define R_led 12  // Đèn si nhan phai ////////////

//QTRSensorsRC qtrrc((unsigned char[]) {2,3,4,5,6,7,8,9} ,NUM_SENSORS, 2500, QTR_NO_EMITTER_PIN);
QTRSensorsRC qtrrc((unsigned char[]) {14,15,16,17,18} ,NUM_SENSORS, 2500, QTR_NO_EMITTER_PIN);

unsigned int sensorValues[NUM_SENSORS];

void setup()
{
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);

  pinMode(L_led, OUTPUT); ////////////////
  pinMode(R_led, OUTPUT); ////////////////
  
  delay(2000);
  Serial.begin(112500);

  Init1(); ///////////
  
  wait();
  delay(3000); // wait for 2s to position the bot before entering the main loop 
}  

int lastError = 0;
unsigned int sensors[5];
int position = 2000;  //= qtrrc.readLine(sensors);
int motorSpeed;
int rightMotorSpeed;
int leftMotorSpeed;
  
void loop()
{  
  position = qtrrc.readLine(sensors); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.

  int error = position - 2000;
  Serial.println(position);
  
    //////////////////////////////////////////////////
    motorSpeed = Kp * error + Kd * (error - lastError);
    lastError = error;

    rightMotorSpeed = BaseSpeed - motorSpeed; ///// +
    leftMotorSpeed  = BaseSpeed + motorSpeed; ///// -
  
    if (rightMotorSpeed > MaxSpeed )  rightMotorSpeed = MaxSpeed; // prevent the motor from going beyond max speed
    if (leftMotorSpeed > MaxSpeed )   leftMotorSpeed = MaxSpeed;  // prevent the motor from going beyond max speed
    if (rightMotorSpeed < 0)  rightMotorSpeed = 0;    
    if (leftMotorSpeed < 0)   leftMotorSpeed  = 0;
    
    move(1, rightMotorSpeed, 1);  //motor derecho hacia adelante
    move(0, leftMotorSpeed, 0);   //motor izquierdo hacia adelante  
  
  
  if (leftMotorSpeed > rightMotorSpeed)//////////////////////////
  {
    digitalWrite(L_led, HIGH); digitalWrite(R_led, LOW);
    //Serial.println("Right ...");
  }
  else
  if (leftMotorSpeed < rightMotorSpeed)//////////////////////////
  {
    digitalWrite(L_led, LOW); digitalWrite(R_led, HIGH);
    //Serial.println("Left ...");
  }
   

}
  
void wait(){
//  digitalWrite(motorPower, LOW);
}

void move(int motor, int speed, int direction){
//  digitalWrite(motorPower, HIGH); //disable standby

  boolean inPin1=LOW;  //HIGH
  boolean inPin2=HIGH; //LOW
  
  if(direction == 1){
    inPin1 = LOW;    //HIGH
    inPin2 = HIGH;   //LOW
  }  
  if(direction == 0){
    inPin1 = HIGH; //LOW
    inPin2 = LOW;  //HIGH
  }

  if(motor == 0){
    digitalWrite(leftMotor1, inPin1);
    digitalWrite(leftMotor2, inPin2);
    analogWrite(leftMotorPWM, speed);
  }
  if(motor == 1){
    digitalWrite(rightMotor1, inPin1);
    digitalWrite(rightMotor2, inPin2);
    analogWrite(rightMotorPWM, speed);
  }  
}

void Init1()
{
  for (int i = 0; i < 100; i++) // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead
  {
   //comment this part out for automatic calibration 
    if ( i  < 25 || i >= 75 )   // turn to the left and right to expose the sensors to the brightest and darkest readings that may be encountered
    {
      move(1, 88, 1); //motor derecho hacia adelante
      move(0, 88, 0); //motor izquierdo hacia atras 
    }
    else
    {
      move(1, 88, 0); //motor derecho hacia atras
      move(0, 88, 1); //motor izquierdo hacia adelante  
    }
    
    qtrrc.calibrate();   
    delay(20);
  }  
}

void Init2()
{
  for (int i = 0; i < 110; i++) // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead
  {
   //comment this part out for automatic calibration 
    if ( i  < 55 )   // turn to the left and right to expose the sensors to the brightest and darkest readings that may be encountered
    {
      move(1, 80, 1); //motor derecho hacia adelante
      move(0, 80, 1); //motor izquierdo hacia atras 
    }
    else
    {
      move(1, 80, 0); //motor derecho hacia atras
      move(0, 80, 0); //motor izquierdo hacia adelante  
    }
    
    qtrrc.calibrate();   
    delay(20);
  }  
}

void stop_(int delay_)
{
  move(1, 0, 0);  //motor derecho hacia adelante
  move(0, 0, 0);   //motor izquierdo hacia adelante    
  delay(delay_);
}


void return_header()
{
  for (int i=0;i<15;i++)
  {
    move(1, 110, 0);    //R
    delay(10);
    move(0, 110, 1);    //L
    delay(10);
  }
}


void loop_()
{
    for (int i = 0; i < 100; i++) // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead
    {
    if ( i  < 25 || i >= 75 )   // turn to the left and right to expose the sensors to the brightest and darkest readings that may be encountered
    {
      move(1, 82, 1); //motor derecho hacia adelante
      move(0, 82, 0); //motor izquierdo hacia atras 
    }
    else
    {
      move(1, 82, 0); //motor derecho hacia atras
      move(0, 82, 1); //motor izquierdo hacia adelante  
    }
    
    delay(200);
  }     
}

//////////////////////////////////////
void loop__()
{
  //Tien toi - forward:
   move(1, 150, 0); //1  //motor derecho hacia adelante
   move(0, 150, 0); //0    

   digitalWrite(L_led, HIGH);
   digitalWrite(R_led, LOW);  delay(50);  
   
   digitalWrite(L_led, LOW);
   digitalWrite(R_led, HIGH); delay(50);  
   delay(100);  
}
