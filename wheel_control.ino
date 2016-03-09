#define LeftWheel 10
#define RightWheel 20

char i = 's';
int LeftSpeed = 0;
int RightSpeed = 0;

Dynamixel Dxl(1);

void setup(){
  Dxl.begin(3);
  Dxl.wheelMode(LeftWheel);
  Dxl.wheelMode(RightWheel);
  SerialUSB.attachInterrupt(usbInterrupt);
}

void usbInterrupt(byte* buffer, byte nCount){
  
  i =(char)buffer[0];  
    SerialUSB.println(i);
    
  switch (i) {
    //Stop
    case 's':
      LeftSpeed = 0;
      RightSpeed = 0;
      SerialUSB.print("LeftSpeed:");
      SerialUSB.println(LeftSpeed);
      SerialUSB.print("RightSpeed:");
      SerialUSB.println(RightSpeed);
      break;
      
    //Slow Forward
    case 'q':
      LeftSpeed = 250 | 0x400;
      RightSpeed = 250;
      SerialUSB.print("LeftSpeed:");
      SerialUSB.println(LeftSpeed);
      SerialUSB.print("RightSpeed:");
      SerialUSB.println(RightSpeed);
      break;
      
      //Forward
    case 'w':
      LeftSpeed = 500 | 0x400;
      RightSpeed = 500;
      SerialUSB.print("LeftSpeed:");
      SerialUSB.println(LeftSpeed);
      SerialUSB.print("RightSpeed:");
      SerialUSB.println(RightSpeed);
      break;
      
      //fast Forward
    case 'e':
      LeftSpeed = 1000 | 0x400;
      RightSpeed = 1000;
      SerialUSB.print("LeftSpeed:");
      SerialUSB.println(LeftSpeed);
      SerialUSB.print("RightSpeed:");
      SerialUSB.println(RightSpeed);
      break;
    //Pivot Left
    case 'a':
      LeftSpeed = 250 | 0x400;
      RightSpeed = 250 | 0x400;
      SerialUSB.print("LeftSpeed:");
      SerialUSB.println(LeftSpeed);
      SerialUSB.print("RightSpeed:");
      SerialUSB.println(RightSpeed);
      break;

    //Pivot Right
    case 'd':
      LeftSpeed = 250;
      RightSpeed = 250;
      SerialUSB.print("LeftSpeed:");
      SerialUSB.println(LeftSpeed);
      SerialUSB.print("RightSpeed:");
      SerialUSB.println(RightSpeed);
      break;
      
    //Reverse
    case 'x':
      LeftSpeed = 500;
      RightSpeed = 500 | 0x400;
      SerialUSB.print("LeftSpeed:");
      SerialUSB.println(LeftSpeed);
      SerialUSB.print("RightSpeed:");
      SerialUSB.println(RightSpeed);
      break;
    //Default to stop
    default:
      LeftSpeed = 0;
      RightSpeed = 0;
      SerialUSB.print("LeftSpeed:");
      SerialUSB.println(LeftSpeed);
      SerialUSB.print("RightSpeed:");
      SerialUSB.println(RightSpeed);
      break;
  }
}

void loop(){
  delay(100);
  Dxl.goalSpeed(LeftWheel,LeftSpeed);
  Dxl.goalSpeed(RightWheel,RightSpeed);  
}

