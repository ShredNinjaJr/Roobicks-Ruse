#include <Servo.h>

#define WAIT 500
#define INITWAIT 10000
Servo frontPinch;
Servo frontTwist;
Servo backPinch;
Servo backTwist;
Servo leftPinch;
Servo leftTwist;
Servo rightPinch;
Servo rightTwist;
int frontPinchPin = 2;
int frontTwistPin = 3;
int backPinchPin = 4;
int backTwistPin = 5;
int leftPinchPin = 6;
int leftTwistPin = 7;
int rightPinchPin = 8;
int rightTwistPin = 9;
//assign angles for operations (TBD)
//black
int leftOpen = 50;
int leftClose = 130;
//green
int rightOpen = 80;
int rightClose = 160;
int frontOpen;
int frontClose;
int backOpen;
int backClose;

//90 deg turns
int cwise = 180;
int cCwise = 0;
int twistHome = 90;

int wait = 1000;

int operation = -1; //variable to store serial input

//attach servos to PWM pins and setup serial in
void setup()
{
  Serial.begin(9600);
  frontPinch.attach(frontPinchPin);
  frontTwist.attach(frontTwistPin);
  backPinch.attach(backPinchPin);
  backTwist.attach(backTwistPin);
  leftPinch.attach(leftPinchPin);
  leftTwist.attach(leftTwistPin);
  rightPinch.attach(rightPinchPin);
  rightTwist.attach(rightTwistPin);
  
  initialize();
  showCube();
}

void loop()
{ 
  //once there is input..
  if (Serial.available() > 0)
  {
    //store input
    operation = Serial.read(); 
    Serial.println(operation);
    //perform corresponding operation
    switch(operation)
    {
      //U
      case 0:
        up();
        break;
      //U'  
      case 1:
        upPrime();
        break;
      //U2  
      case 2:
        up();
        up();
        break;
      //D  
      case 3:
        down();
        break; 
      //D'  
      case 4:
        downPrime();
        break;
      //D2  
      case 5:
        down();
        down();
        break;
      //F 
      case 6:
        front();
        break;
      //F'  
      case 7:
        frontPrime();
        break;
      //F2  
      case 8:
        front();
        front();
        break;
      //B  
      case 9:
        back();
        break;
      //B'  
      case 10:
        backPrime();
        break; 
      //B2  
      case 11:
        back();
        back();
        break; 
      //L
      case 12:
        left();
        break;
      //L'
      case 13:
        leftPrime();
        break;
      //L2
      case 14:
        left();
        left();
        break;
      //R
      case 15:
        right();
        break;
      //R'
      case 16:
        rightPrime();
        break;
      //R2
      case 17:
        right();
        right();
        break;  
      default:
        break; 
    }
  }
  //ready for next operation
  Serial.write("1 \n");
  delay(500);
}

void initialize()
{
  //position to hold cube
 leftTwist.write(twistHome); 
 rightTwist.write(twistHome); 
 frontTwist.write(twistHome); 
 backTwist.write(twistHome); 
 delay(WAIT);
 //open all and wait 10s for us
 leftPinch.write(leftOpen);
 rightPinch.write(rightOpen);
 frontPinch.write(frontOpen);
 backPinch.write(backOpen);
 delay(INITWAIT);
 //close slowly so we can line it up
 for(int i = 1; i < 81; i+=10)
 {
   leftPinch.write(leftOpen - i);
   rightPinch.write(rightOpen - i);
   frontPinch.write(frontOpen - i);
   backPinch.write(backOpen - i);
   delay(WAIT);
 }  
 delay(WAIT);
}  

void showCube()
{
  
}  
//twist clockwise, open, twist back
void left()
{
  leftTwist.write(cwise);
  delay(WAIT);
  leftPinch.write(leftOpen);
  delay(WAIT);
  leftTwist.write(twistHome);
  delay(WAIT);
  leftPinch.write(leftClose);
  delay(WAIT);
}  
//twist counter clockwise, open, twist back
void leftPrime()
{
  leftTwist.write(cCwise);
  delay(WAIT);
  leftPinch.write(leftOpen);
  delay(WAIT);
  leftTwist.write(twistHome);
  delay(WAIT);
  leftPinch.write(leftClose);
  delay(WAIT);
} 
void right()
{
  rightTwist.write(cwise);
  delay(WAIT);
  rightPinch.write(rightOpen);
  delay(WAIT);
  rightTwist.write(twistHome);
  delay(WAIT);
  rightPinch.write(rightClose);
  delay(WAIT);
} 
void rightPrime()
{
  rightTwist.write(cCwise);
  delay(WAIT);
  rightPinch.write(rightOpen);
  delay(WAIT);
  rightTwist.write(twistHome);
  delay(WAIT);
  rightPinch.write(rightClose);
  delay(WAIT);
}
//calls helper to turn the top face to the front
//calls function to turn front
//then helper to turn the cube back
void up()
{
  top2front();
  front();
  bot2front(); 
}
void upPrime()
{
  top2front();
  frontPrime();
  bot2front();
}
//calls helper to turn the bot face to the front
//calls function to turn bot
//then helper to turn the cube back
void down()
{
  bot2front();
  front();
  top2front();
}
void downPrime()
{
  bot2front();
  frontPrime();
  top2front(); 
}  
void front()
{
  frontTwist.write(cwise);
  delay(WAIT);
  frontPinch.write(leftOpen);
  delay(WAIT);
  frontTwist.write(twistHome);
  delay(WAIT);
  frontPinch.write(leftClose);
  delay(WAIT);
} 
void frontPrime()
{
  frontTwist.write(cCwise);
  delay(WAIT);
  frontPinch.write(frontOpen);
  delay(WAIT);
  frontTwist.write(twistHome);
  delay(WAIT);
  frontPinch.write(frontClose);
  delay(WAIT);
} 
void back()
{
  backTwist.write(cwise);
  delay(WAIT);
  backPinch.write(backOpen);
  delay(WAIT);
  backTwist.write(twistHome);
  delay(WAIT);
  backPinch.write(backClose);
  delay(WAIT);
} 
void backPrime()
{
  backTwist.write(cCwise);
  delay(WAIT);
  backPinch.write(backOpen);
  delay(WAIT);
  backTwist.write(twistHome);
  delay(WAIT);
  backPinch.write(backClose);
  delay(WAIT);
} 
//front and back claws open, left and right turn
//the cube so the top is now in the front
void top2front()
{
  frontPinch.write(frontOpen);
  backPinch.write(backOpen);
  delay(WAIT);
  leftTwist.write(cwise);
  rightTwist.write(cCwise);
  delay(WAIT);
  frontPinch.write(frontClose);
  backPinch.write(backClose);
  delay(WAIT);
  leftPinch.write(leftOpen);
  rightPinch.write(rightOpen);
  delay(WAIT);
  leftTwist.write(cCwise);
  rightTwist.write(cwise);
  delay(WAIT);
  leftPinch.write(leftClose);
  rightPinch.write(rightClose);
  delay(WAIT);
}  
//front and back claws open, left and right turn
//the cube so the bot is now in the front
void bot2front()
{
  frontPinch.write(frontOpen);
  backPinch.write(backOpen);
  delay(WAIT);
  leftTwist.write(cCwise);
  rightTwist.write(cwise);
  delay(WAIT);
  frontPinch.write(frontClose);
  backPinch.write(backClose);
  delay(WAIT);
  leftPinch.write(leftOpen);
  rightPinch.write(rightOpen);
  delay(WAIT);
  leftTwist.write(cwise);
  rightTwist.write(cCwise);
  delay(WAIT);
  leftPinch.write(leftClose);
  rightPinch.write(rightClose);
  delay(WAIT);
}  
//left and right claws open, front and back turn
//the cube so the left is now on the top
//this is for mapping the colors
void left2top()
{
  leftPinch.write(leftOpen);
  rightPinch.write(rightOpen);
  delay(WAIT);
  backTwist.write(cCwise);
  frontTwist.write(cwise);
  delay(WAIT);
  leftPinch.write(leftClose);
  rightPinch.write(rightClose);
  delay(WAIT);
  backPinch.write(backOpen);
  frontPinch.write(frontOpen);
  delay(WAIT);
  backTwist.write(cwise);
  frontTwist.write(cCwise);
  delay(WAIT);
  backPinch.write(backClose);
  frontPinch.write(frontClose);
  delay(WAIT);
} 
//left and right claws open, front and back turn
//the cube so the right is now on the top
//this is for mapping the colors
void right2top()
{
  leftPinch.write(leftOpen);
  rightPinch.write(rightOpen);
  delay(WAIT);
  backTwist.write(cwise);
  frontTwist.write(cCwise);
  delay(WAIT);
  leftPinch.write(leftClose);
  rightPinch.write(rightClose);
  delay(WAIT);
  backPinch.write(backOpen);
  frontPinch.write(frontOpen);
  delay(WAIT);
  backTwist.write(cCwise);
  frontTwist.write(cwise);
  delay(WAIT);
  backPinch.write(backClose);
  frontPinch.write(frontClose);
  delay(WAIT);
} 
