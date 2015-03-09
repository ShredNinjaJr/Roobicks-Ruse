//pins for servos
int frontPinch = 2;
int frontTwist = 3;
int backPinch = 4;
int backTwist = 5;
int leftPinch = 6;
int leftTwist = 7;
int rightPinch = 8;
int rightTwist = 9;

//assign angles for operations (TBD)
int openLeft;
int closeLeft;
int openRight;
int closeRight;
int openFront;
int closeFront;
int openBack;
int closeBack;

//90 deg turns
int cwise;
int cCwise;

int pulseWidth;     //time for non PWNM servo calculated in servoPulse
int operation = -1; //variable to store serial input

//attach servos to PWM pins and setup serial in
void setup()
{
  Serial.begin(9600);
  //initialize all servos for output
  pinMode(frontPinch, OUTPUT);
  pinMode(frontTwist, OUTPUT);
  pinMode(backPinch, OUTPUT);
  pinMode(backTwist, OUTPUT);
  pinMode(leftPinch, OUTPUT);
  pinMode(leftTwist, OUTPUT);
  pinMode(rightPinch, OUTPUT);
  pinMode(rightTwist, OUTPUT);
}

void loop()
{
  //once there is input..
  if (Serial.available() > 0)
  {
    //store input
    operation = Serial.read(); 
    //perform corresponding operation
    switch(operation)
    {
      case 0:
        clockwise(leftPinch, leftTwist, openLeft, closeLeft);
        break;
      case 1:
        counterClockwise(leftPinch, leftTwist, openLeft, closeLeft);
        break;
      case 2:
        clockwise(rightPinch, rightTwist, openRight, closeRight);
        break;
      case 3:
        counterClockwise(rightPinch, rightTwist, openRight, closeRight);
        break; 
      case 4:
        upCW();
        break;
      case 5:
        upCC();
        break;
      case 6:
        downCW();
        break;
      case 7:
        downCC();
        break;
      case 8:
        clockwise(frontPinch, frontTwist, openFront, closeFront);
        break;
      case 9:
        counterClockwise(frontPinch, front, openFront, closeFront);
        break;
      case 10:
        clockwise(backPinch, backTwist, openBack, closeBack);
        break; 
      case 11:
        counterClockwise(backPinch, backTwist, openBack, closeBack);
        break; 
      default:
        break; 
    }
  }
  //ready for next operation
  Serial.write("1 \n");
  delay(500);
}

void clockwise(int pinch, int twist, int openDeg, int closeDeg)
{
  servoPulse(cwise, twist);
  servoPulse(openDeg, pinch);
  servoPulse(cCwise, twist);
  servoPulse(closeDeg, pinch);
}

void counterClockWise(int pinch, int twist, int openDeg, int closeDeg)
{
  servoPulse(cCwise, twist);
  servoPulse(openDeg, pinch);
  servoPulse(cwise, twist);
  servoPulse(closeDeg, pinch);
}

void servoPulse(int angle, int pin) 
{
  pulseWidth = (angle * 10) + 600;     // converts angle to microseconds.
  digitalWrite(pin, HIGH);             // set servos high.
  delayMicroseconds(pulseWidth);       // wait 
  digitalWrite(pin, LOW);              // set servos low.
  delay(16);                           // wait 
  delayMicroseconds(4000-pulseWidth);
}
