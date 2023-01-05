byte SpMaxL=220;
byte SpMaxR=220;

void setup() {
  Serial.begin(112500);
  pinMode(6, OUTPUT);//Set chan in1 cua DC A la output
  pinMode(7, OUTPUT);//Set chan in2 cua DC A la output
  pinMode(8, OUTPUT);//Set chan in1 cua DC B la output
  pinMode(9, OUTPUT);//Set chan in2 cua DC B la output
  pinMode(A0, INPUT);//Set chan cam bien 1 la input
  pinMode(A1, INPUT);//Set chan cam bien 2 la input
  pinMode(A2, INPUT);//Set chan cam bien 3 la input
  pinMode(A3, INPUT);//Set chan cam bien 4 la input
  pinMode(A4, INPUT);//Set chan cam bien 5 la input
}

void loop(){
  //Tien();
  //Lui();
  //Retrai();
  doline();
  //delay(1000);
  //Serial.println(trangThai5CamBien());
  //delay(1000);
}

void doline()
{
  switch (trangThai5CamBien())
    {
      case 200:
        //Tien(SpMaxL,SpMaxR-150);
        Lui(100,100);
        //Rephai();
        break;
      case 0:
        Tien(SpMaxL,SpMaxR);
        break;
      case 1:
        Tien(SpMaxL,SpMaxR-20);
        break;
      case 2:
        Tien(SpMaxL,SpMaxR-40);
        break;
      case 3:
        Tien(SpMaxL,0);
        break;
      case -1:
        Tien(SpMaxL-20,SpMaxR);
        break;
      case -2:
        Tien(SpMaxL-40,SpMaxR);
        break;
      case -3:
        Tien(0,SpMaxR);
        break;
      default:
        digitalWrite(6, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        digitalWrite(9, 0);
    }
}
boolean IFSensor (byte PinNumb)
{
  //Co line la 1
  return (!digitalRead (PinNumb));
}

int trangThai5CamBien ()
{
  /*
      Am la lech phai
      Duong la lech trai
      Muc do lech giam tang dan : 1 2 3
  */
  int sens1 = IFSensor(A0);
  int sens2 = IFSensor(A1);
  int sens3 = IFSensor(A2);
  int sens4 = IFSensor(A3);
  int sens5 = IFSensor(A4);
  switch (lechvach5mat())
  {
    case -3:
      return -3;
      break;
    case -2:
      return -2;
      break;
    case -1:
      return -1;
      break;
    case 0:
      if ( (abs(sens1) + abs(sens2) + abs(sens3) + abs(sens4) + abs(sens5)) == 0)
        return 200;
      else
        return 0;
      break;
    case 1:
      return 1;
      break;
    case 2:
      return 2;
      break;
    case 3:
      return 3;
      break;
  }  
}
int lechvach5mat()
{
  /*
   Am la lech phai
   Duong la lech trai
   Muc do lech giam tang dan : 1 3 2
   */
   int sens1 = IFSensor(A0);
   int sens2 = IFSensor(A1);
   int sens3 = IFSensor(A2);
   int sens4 = IFSensor(A3);
   int sens5 = IFSensor(A4);
   int lechvach = -2 * sens1 - sens2 + sens4 + 2 * sens5;
   switch (lechvach)
   {
      case -3://cai nay la do 2 mat bien deu cham vach 
        return -2;
        break;
      case -2:
        return -3;
        break;
      case -1:
        return -1;
        break;
      case 0:
        return 0;
        break;
      case 1:
        return 1;
        break;
      case 2:
        return 3;
        break;
      case 3:
        return 2;
        break;  
   }
}
void Tien( byte speedL, byte speedR)
{
  analogWrite(5, speedL);
  analogWrite(10, speedR);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
}
void Retrai()
{
  analogWrite(5, 255);
  analogWrite(10, 255);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
}
void Rephai()
{
  analogWrite(5, 255);
  analogWrite(10, 255);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
}
void Lui( byte SpeedL, byte SpeedR)
{
  analogWrite(5, SpeedL);
  analogWrite(10, SpeedR);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
