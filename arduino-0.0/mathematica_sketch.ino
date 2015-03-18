/*ARDUINO DRIVER FIRMWARE FILE
AUTHOR: IAN JOHNSON, WOLFRAM RESEARCH, INC.
This file is to be uploaded to the Arduino before usage of the Mathematica driver functionality.
The accompanying mathematica package is found at: https://download.wolfram.com/?key=BHKAM9
This file should be uploadable to any Arduino supported by the Aruino 1.0.5-r2 software release.
VERSION: 0.0.0
*/


//this is the global device execute value
double deviceExecuteReturnValue;


int localEchoPin;
int localTriggerPin;

int globalTriggerPin;
int globalEchoPin;

boolean outputMode = false; //this stores whether we need to output any of the values
int pin; //int for storing which pin to change
int mode; //int for storing which mode to change the pin to

char invalid[5] ="qqqq";


//the following ints are for reading the analog output digit input from serial
int val1;
int val2;
int val3;

//the following ints are for ascii conversion from numbers split by their digits
int digit1=0;
int digit2=0;
int digit3=0;

//the following booles are for whether or not their values should be read from and printed off during the output sequence
boolean d0in = false, d1in = false, d2in = false, d3in = false, d4in = false, d5in = false, d6in = false, d7in = false, 
d8in = false, d9in = false, d10in = false, d11in = false, d12in = false, d13in = false, a0in = false, a1in = false, 
a2in = false, a3in = false, a4in = false, a5in = false, deviceExecute = false;



//these booleans are for whether the analog in pins are configured for analog input, or digital input, true = analog input, false = digital input
boolean a0analogIn = false, a1analogIn = false, a2analogIn = false, a3analogIn = false, a4analogIn = false, a5analogIn = false;



void setup()
{
  for(int i=2;i<=13;i++)
  {
    pinMode(i,INPUT);
  }
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  Serial.begin(115200);
  delay(1000);
  Serial.println("Device starting normally, all pins set to input");
}

double ultrasonicRead(int echoPin, int triggerPin)
{
  switch (echoPin)
  {
    case 97:
      localEchoPin=0;
      break;
    case 98:
      localEchoPin=1;
      break;
    case 99:
      localEchoPin=2;
      break;
    case 100:
      localEchoPin=3;
      break;
    case 101:
      localEchoPin=4;
      break;
    case 102:
      localEchoPin=6;
      break;
    case 103:
      localEchoPin=7;
      break;
    case 104:
      localEchoPin=8;
      break;
    case 105:
      localEchoPin=9;
      break;
    case 106:
      localEchoPin=10;
      break;
    case 107:
      localEchoPin=11;
      break;
    case 108:
      localEchoPin=12;
      break;
    case 109:
      localEchoPin=13;
      break;
    case 110:
      localEchoPin=A0;
      break;
    case 111:
      localEchoPin=A1;
      break;
    case 112:
      localEchoPin=A2;
      break;
    case 113:
      localEchoPin=A3;
      break;
    case 114:
      localEchoPin=A4;
      break;
    case 115:
      localEchoPin=A5;
      break;
    case 116:
      break;
    case 117:
      break;
    case 118:
      break;
    case 119:
      break;
    case 120:
      break;
    case 121:
      break;
    case 122:
      break;
    default:
      break;
  }
  switch (triggerPin)
  {
    case 97:
      localTriggerPin=0;
      break;
    case 98:
      localTriggerPin=1;
      break;
    case 99:
      localTriggerPin=2;
      break;
    case 100:
      localTriggerPin=3;
      break;
    case 101:
      localTriggerPin=4;
      break;
    case 102:
      localTriggerPin=6;
      break;
    case 103:
      localTriggerPin=7;
      break;
    case 104:
      localTriggerPin=8;
      break;
    case 105:
      localTriggerPin=9;
      break;
    case 106:
      localTriggerPin=10;
      break;
    case 107:
      localTriggerPin=11;
      break;
    case 108:
      localTriggerPin=12;
      break;
    case 109:
      localTriggerPin=13;
      break;
    case 110:
      localTriggerPin=A0;
      break;
    case 111:
      localTriggerPin=A1;
      break;
    case 112:
      localTriggerPin=A2;
      break;
    case 113:
      localTriggerPin=A3;
      break;
    case 114:
      localTriggerPin=A4;
      break;
    case 115:
      localTriggerPin=A5;
      break;
    case 116:
      break;
    case 117:
      break;
    case 118:
      break;
    case 119:
      break;
    case 120:
      break;
    case 121:
      break;
    case 122:
      break;
    default:
      break;
  }
  
  digitalWrite(localTriggerPin,HIGH);
  delayMicroseconds(5);
  digitalWrite(localTriggerPin,LOW);
  return ((pulseIn(localEchoPin,HIGH,16000))/58);
}


int numberConverter(int first, int second, int third)
{
digit1=first-48;
digit2=second-48;
digit3=third-48;
return (100*digit1)+(10*digit2)+digit3;
}


void asciiConverter(int code, int code2)
{
  switch(code)
  {
        case 97:
          Serial.println("Error, pin needed for Serial communication");
/*          switch (code2)
          {
            case 97:
              pinMode(0,OUTPUT);
              digitalWrite(0,HIGH);
              break;
            case 98:
              pinMode(0,OUTPUT);
              digitalWrite(0,LOW);
              break;
            case 99:
              pinMode(0,INPUT);
              break;
            case 100:
              pinMode(0,INPUT);
              break;
          }
*/
          break;
        case 98:
          //do stuff
          Serial.println("Error, pin needed for Serial communication");
/*          switch (code2)
          {
            case 97:
              pinMode(1,OUTPUT);
              digitalWrite(1,HIGH);
              break;
            case 98:
              pinMode(1,OUTPUT);
              digitalWrite(1,LOW);
              break;
            case 99:
              pinMode(1,INPUT);
              break;
            case 100:
              pinMode(1,INPUT);
              break;
          }
*/
          break;
        case 99:
          if (!outputMode)
          {
            Serial.print("pin 2 ");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d2in = false;
              pinMode(2,OUTPUT);
              digitalWrite(2,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d2in = false;
              pinMode(2,OUTPUT);
              digitalWrite(2,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d2in = true;
              pinMode(2,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d2in = true;
              pinMode(2,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 100:
          if (!outputMode)
          {
            Serial.println("pin 3 ");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d3in = false;
              pinMode(3,OUTPUT);
              digitalWrite(3,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d3in = false;
              pinMode(3,OUTPUT);
              digitalWrite(3,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d3in = true;
              pinMode(3,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d3in = true;
              pinMode(3,INPUT);
              break;
            case 101:
              if (!outputMode)
              {
                Serial.print("analogOuput of ");
              }
              val1=Serial.read();
              delay(10);
              val2=Serial.read();
              delay(10);
              val3=Serial.read();
              analogWrite(3,numberConverter(val1,val2,val3));
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 101:
          if (!outputMode)
          {
            Serial.println("pin 4 ");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d4in = false;
              pinMode(4,OUTPUT);
              digitalWrite(4,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d4in = false;
              pinMode(4,OUTPUT);
              digitalWrite(4,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d4in = true;
              pinMode(4,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d4in = true;
              pinMode(4,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 102:
          if (!outputMode)
          {
            Serial.println("pin 5 ");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d5in = false;
              pinMode(5,OUTPUT);
              digitalWrite(5,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d5in = false;
              pinMode(5,OUTPUT);
              digitalWrite(5,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d5in = true;
              pinMode(5,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d5in = true;
              pinMode(5,INPUT);
              break;
            case 101:
              if (!outputMode)
              {
                Serial.print("analogOuput of ");
              }
              val1=Serial.read();
              delay(10);
              val2=Serial.read();
              delay(10);
              val3=Serial.read();
              analogWrite(5,numberConverter(val1,val2,val3));
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 103:
          if (!outputMode)
          {
            Serial.println("pin 6 ");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d6in = false;
              pinMode(6,OUTPUT);
              digitalWrite(6,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d6in = false;
              pinMode(6,OUTPUT);
              digitalWrite(6,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d6in = true;
              pinMode(6,INPUT);
              break;
            case 100: 
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d6in = true;
              pinMode(6,INPUT);
              break;
            case 101:
              if (!outputMode)
              {
                Serial.print("analogOuput of ");
              }
              val1=Serial.read();
              delay(10);
              val2=Serial.read();
              delay(10);
              val3=Serial.read();
              analogWrite(6,numberConverter(val1,val2,val3));
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 104:
          if (!outputMode)
          {
            Serial.print("pin 7 ");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d7in = false;
              pinMode(7,OUTPUT);
              digitalWrite(7,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d7in = false;
              pinMode(7,OUTPUT);
              digitalWrite(7,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d7in = true;
              pinMode(7,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d7in = true;
              pinMode(7,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 105:
          if (!outputMode)
          {
            Serial.print("pin 8 ");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d8in = false;
              pinMode(8,OUTPUT);
              digitalWrite(8,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d8in = false;
              pinMode(8,OUTPUT);
              digitalWrite(8,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d8in = true;
              pinMode(8,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d8in = true;
              pinMode(8,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 106:
          if (!outputMode)
          {
          Serial.print("pin 9 ");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d9in = false;
              pinMode(9,OUTPUT);
              digitalWrite(9,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d9in = false;
              pinMode(9,OUTPUT);
              digitalWrite(9,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d9in = true;
              pinMode(9,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d9in = true;
              pinMode(9,INPUT);
              break;
            case 101:
              if (!outputMode)
              {
                Serial.print("analogOuput of ");
              }
              val1=Serial.read();
              delay(10);
              val2=Serial.read();
              delay(10);
              val3=Serial.read();
              analogWrite(9,numberConverter(val1,val2,val3));
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 107:
          if (!outputMode)
          {
            Serial.print("pin 10 ");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d10in = false;
              pinMode(10,OUTPUT);
              digitalWrite(10,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d10in = false;
              pinMode(10,OUTPUT);
              digitalWrite(10,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d10in = true;
              pinMode(10,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d10in = true;
              pinMode(10,INPUT);
              break;
            case 101:
              if (!outputMode)
              {
                Serial.print("analogOuput of ");
              }
              val1=Serial.read();
              delay(10);
              val2=Serial.read();
              delay(10);
              val3=Serial.read();
              analogWrite(10,numberConverter(val1,val2,val3));
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 108:
          if (!outputMode)
          {
            Serial.print("pin 11 ");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d11in = false;
              pinMode(11,OUTPUT);
              digitalWrite(11,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d11in = false;
              pinMode(11,OUTPUT);
              digitalWrite(11,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d11in = true;
              pinMode(11,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d11in = true;
              pinMode(11,INPUT);
              break;
            case 101:
              if (!outputMode)
              {
                Serial.print("analogOuput of ");
              }
              val1=Serial.read();
              delay(10);
              val2=Serial.read();
              delay(10);
              val3=Serial.read();
              analogWrite(11,numberConverter(val1,val2,val3));
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 109:
          if (!outputMode)
          {
            Serial.print("pin 12 ");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d12in = false;
              pinMode(12,OUTPUT);
              digitalWrite(12,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d12in = false;
              pinMode(12,OUTPUT);
              digitalWrite(12,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d12in = true;
              pinMode(12,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d12in = true;
              pinMode(12,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 110:
          if (!outputMode)
          {
            Serial.print("pin 13");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              d13in = false;
              pinMode(13,OUTPUT);
              digitalWrite(13,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              d13in = false;
              pinMode(13,OUTPUT);
              digitalWrite(13,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              d13in = true;
              pinMode(13,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("Error, pin not Analog pin, configured as digital input instead");
              }
              outputMode = true;
              d13in = true;
              pinMode(13,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 111:
          if (!outputMode)
          {
            Serial.print("pin A0");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              a0in = false;
              pinMode(A0,OUTPUT);
              digitalWrite(A0,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              a0in = false;
              pinMode(A0,OUTPUT);
              digitalWrite(A0,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              a0in = true;
              a0analogIn = false;
              pinMode(A0,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("analogInput");
              }
              outputMode = true;
              a0in = true;
              a0analogIn = true;
              pinMode(A0,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 112:
          if (!outputMode)
          {
            Serial.print("pin A1");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              a1in = false;
              pinMode(A1,OUTPUT);
              digitalWrite(A1,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              a1in = false;
              pinMode(A1,OUTPUT);
              digitalWrite(A1,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              a1in = true;
              a1analogIn = false;
              pinMode(A1,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("analogInput");
              }
              outputMode = true;
              a1in = true;
              a1analogIn = true;
              pinMode(A1,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 113:
          if (!outputMode)
          {
            Serial.print("pin A2");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              a2in = false;
              pinMode(A2,OUTPUT);
              digitalWrite(A2,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              a2in = false;
              pinMode(A2,OUTPUT);
              digitalWrite(A2,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              a2in = true;
              a2analogIn = false;
              pinMode(A2,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("analogInput");
              }
              outputMode = true;
              a2in = true;
              a2analogIn = true;
              pinMode(A2,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 114:
          if (!outputMode)
          {
            Serial.print("pin A3");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              a3in = false;
              pinMode(A3,OUTPUT);
              digitalWrite(A3,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              a3in = false;
              pinMode(A3,OUTPUT);
              digitalWrite(A3,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              a3in = true;
              a3analogIn = false;
              pinMode(A3,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("analogInput");
              }
              outputMode = true;
              a3in = true;
              a3analogIn = true;
              pinMode(A3,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 115:
          if (!outputMode)
          {
            Serial.print("pin A4");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              a4in = false;
              pinMode(A4,OUTPUT);
              digitalWrite(A4,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              a4in = false;
              pinMode(A4,OUTPUT);
              digitalWrite(A4,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              a4in = true;
              a4analogIn = false;
              pinMode(A4,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("analogInput");
              }
              outputMode = true;
              a4in = true;
              a4analogIn = true;
              pinMode(A4,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 116:
          if (!outputMode)
          {
            Serial.print("pin A5");
          }
          switch (code2)
          {
            case 97:
              if (!outputMode)
              {
                Serial.println("on");
              }
              a5in = false;
              pinMode(A5,OUTPUT);
              digitalWrite(A5,HIGH);
              break;
            case 98:
              if (!outputMode)
              {
                Serial.println("off");
              }
              a5in = false;
              pinMode(A5,OUTPUT);
              digitalWrite(A5,LOW);
              break;
            case 99:
              if (!outputMode)
              {
                Serial.println("digitalInput");
              }
              outputMode = true;
              a5in = true;
              a5analogIn = false;
              pinMode(A5,INPUT);
              break;
            case 100:
              if (!outputMode)
              {
                Serial.println("analogInput");
              }
              outputMode = true;
              a5in = true;
              a5analogIn = true;
              pinMode(A5,INPUT);
              break;
            default:
              Serial.println("Error mode out of range");
              break;
          }
          break;
        case 117:
          Serial.println("Error pin out of range");
          break;
        case 118:
          Serial.println("Error pin out of range");
          break;
        case 119:
          Serial.println("Error pin out of range");
          break;
        case 120:
          Serial.println("Error pin out of range");
          break;
        case 121:
          if (!outputMode)
          {
            Serial.print("Special Device Execute");
          }
          deviceExecute=true;
          globalTriggerPin=Serial.read();
          delay(10);
          globalEchoPin=Serial.read();
          deviceExecuteReturnValue=ultrasonicRead(globalEchoPin,globalTriggerPin);
          break;
        case 122:
          Serial.println("Special code: TURNING ALL SERIAL OUTPUT OFF!");
          outputMode=false;
          break;
        default:
          Serial.println("Error pin not in range");
          break;
    }
}

  
void loop()
{
  if (outputMode)
  {
      Serial.print(",,,");
      if (d0in)
      {
        Serial.print(digitalRead(0));
      }
      else 
      {
        Serial.print(invalid);
      }
      Serial.print(",,,");
      if (d1in)
      {
        Serial.print(digitalRead(1));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d2in)
      {
        Serial.print(digitalRead(2));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d3in)
      {
        Serial.print(digitalRead(3));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d4in)
      {
        Serial.print(digitalRead(4));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d5in)
      {
        Serial.print(digitalRead(5));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d6in)
      {
        Serial.print(digitalRead(6));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d7in)
      {
        Serial.print(digitalRead(7));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d8in)
      {
        Serial.print(digitalRead(8));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d9in)
      {
        Serial.print(digitalRead(9));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d10in)
      {
        Serial.print(digitalRead(10));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d11in)
      {
        Serial.print(digitalRead(11));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d12in)
      {
        Serial.print(digitalRead(12));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (d13in)
      {
        Serial.print(digitalRead(13));
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (a0in)
      {
        if (a0analogIn)
        {
          Serial.print(analogRead(A0));
        }
        else 
        {
          Serial.print(digitalRead(A0));
        }
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (a1in)
      {
        if (a1analogIn)
        {
          Serial.print(analogRead(A1));
        }
        else 
        {
          Serial.print(digitalRead(A1));
        }
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (a2in)
      {
        if (a2analogIn)
        {
          Serial.print(analogRead(A2));
        }
        else 
        {
          Serial.print(digitalRead(A2));
        }
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (a3in)
      {
        if (a3analogIn)
        {
          Serial.print(analogRead(A3));
        }
        else 
        {
          Serial.print(digitalRead(A3));
        }
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (a4in)
      {
        if (a4analogIn)
        {
          Serial.print(analogRead(A4));
        }
        else 
        {
          Serial.print(digitalRead(A4));
        }
      }
      else 
      {
        Serial.print(invalid);
      }  
      Serial.print(",,,");
      if (a5in)
      {
        if (a5analogIn)
        {
          Serial.print(analogRead(A5));
        }
        else 
        {
          Serial.print(digitalRead(A5));
        }
      }
      else 
      {
        Serial.print(invalid);
      }
      /*if (deviceExecute)
      {
        Serial.print(deviceExecuteReturnValue);
      }
      else
      {
        Serial.print(invalid);
      }*/
      Serial.println(",,,XXXX");
    }
  if (Serial.available()>0) //if we have data to read
  {
    pin=Serial.read();//first character is pin
    delay(10);
    mode=Serial.read();//second character is mode
    delay(10);
    //Serial.print("mode is ");
    //Serial.println(mode);
    if (mode != -1)
    {
      asciiConverter(pin,mode);
    }
  }
}
