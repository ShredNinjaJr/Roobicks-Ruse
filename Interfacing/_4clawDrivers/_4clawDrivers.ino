#include <Servo.h>

#define WAIT 1500
#define INITWAIT 10000
#define SCANDELAY 1000
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
int leftOpenMotionBig = 70;
int leftOpenMotionSmall = 82;
int leftOpenStationary = 50;
int leftClose = 130;

int rightOpenStationary = 50;
int rightOpenMotion = 100;
int rightOpen = 50;
int rightClose = 150;

int frontOpen;
int frontOpenStationary = 50;
int frontOpenMotion = 82;
int frontClose = 150;

int backOpen;
int backOpenStationary = 50;
int backOpenMotion = 90;
int backClose;

//50 deg turns
int cwisePart = 140;
int cCwisePart = 40;
//90 deg turns
int cwise = 180;
int cCwise = 0;
int twistHome = 90;
int rightTwistHome = 96;

int wait = 1000;

char operation; //variable to store serial input

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
  rightTwist.write(rightTwistHome);
  delay(WAIT);
  //rightPinch.write(rightOpenMotion);
  leftTwist.write(twistHome);
  delay(WAIT);
  leftPinch.write(leftClose);
  rightPinch.write(rightClose);
  frontPinch.write(frontClose);
  delay(WAIT);
  left();
  /*frontTwist.write(90);
  backTwist.write(90);*/
 /* leftTwist.write(twistHome);
  rightTwist.write(rightTwistHome);
  delay(WAIT);
  leftPinch.write(leftClose);
  rightPinch.write(rightClose);*/
  //frontPinch.write(leftClose);
 // backPinch.write(130);
  //top2front();
  
  //initialize();
  //showCube();
}

void loop()
{ 
  /*if (Serial.available() > 0)
  {
    leftPinch.write(leftOpen);
    rightPinch.write(rightOpen);
  }*/
  /*top2front();
leftPinch.write(leftOpen);
rightPinch.write(rightOpen);;
delay(7000);
leftPinch.write(leftClose);
  rightPinch.write(leftClose);
  
  //once there is input..
  if (Serial.available() > 0)
  {
    //store input
    operation = Serial.read(); 
    //perform corresponding operation
    switch(operation)
    {
      //U
      case 'a':
        up();
        break;
      //U'  
      case 'b':
        upPrime();
        break;
      //U2  
      case 'c':
        up();
        up();
        break;
      //D  
      case 'd':
        down();
        break; 
      //D'  
      case 'e':
        downPrime();
        break;
      //D2  
      case 'f':
        down();
        down();
        break;
      //F 
      case 'g':
        front();
        break;
      //F'  
      case 'h':
        frontPrime();
        break;
      //F2  
      case 'i':
        front();
        front();
        break;
      //B  
      case 'j':
        back();
        break;
      //B'  
      case 'k':
        backPrime();
        break; 
      //B2  
      case 'l':
        back();
        back();
        break; 
      //L
      case 'm':
        left();
        break;
      //L'
      case 'n':
        leftPrime();
        break;
      //L2
      case 'o':
        left();
        left();
        break;
      //R
      case 'p':
        right();
        break;
      //R'
      case 'q':
        rightPrime();
        break;
      //R2
      case 'r':
        right();
        right();
        break;  
      default:
        break; 
    }
  }
  //ready for next operation
  //Serial.write("1 \n");
 // delay(500);*/
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
  leftPinch.write(leftOpenMotionSmall);
  delay(WAIT);
  leftTwist.write(cwisePart);
  delay(WAIT);
  leftPinch.write(leftOpenMotionBig);
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
  leftTwist.write(twistHome);
  rightTwist.write(twistHome+4);
  delay(WAIT);
  leftPinch.write(leftClose);
  rightPinch.write(rightClose);
  delay(WAIT*2);
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
