#include <Servo.h>

#define WAIT 1500
#define INITWAIT 5000
#define SCANDELAY 1000
Servo frontPinch;
Servo frontTwist;
Servo backPinch;
Servo backTwist;
Servo leftPinch;
Servo leftTwist;
Servo rightPinch;
Servo rightTwist;
int frontPinchPin = 10;
int frontTwistPin = 11;
int backPinchPin = 4;
int backTwistPin = 5;
int leftPinchPin = 6;
int leftTwistPin = 7;
int rightPinchPin = 8;
int rightTwistPin = 9;

//assign angles for operations (TBD)
//black
int leftOpenMotionBig = 70;
int leftOpenMotionSmall = 82;
int leftOpenStationary = 50;
int leftClose = 120;

int leftTwistHome = 88;
int leftcCwise = 180;
int leftcwise = 0;
int leftcwisePart = 40;
int leftcCwisePart = 140;


int rightOpenStationary = 50;
int rightOpenMotionBig = 80;
int rightOpenMotionSmall = 110;
int rightClose = 140;

int rightcwisePart = 37;
int rightcCwisePart = 135;
int rightTwistHome = 88;
int rightcCwise = 172;
int rightcwise = 0;


int frontOpenStationary = 50;
int frontOpenMotionBig = 85;
int frontOpenMotionSmall = 98;
int frontClose = 140;

int frontcCwise = 172;
int frontcwise = 5;
int frontcwisePart = 45;
int frontcCwisePart = 150;
int frontTwistHome = 90;

int backOpenStationary = 50;
int backOpenMotionBig = 75;
int backOpenMotionSmall = 90;
int backClose = 130;

int backcCwise = 171;
int backcwise = 8;
int backcwisePart = 37;
int backcCwisePart = 135;
int backTwistHome = 91;

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
  leftTwist.write(leftTwistHome);
  frontTwist.write(frontTwistHome);
  backTwist.write(backTwistHome);
  delay(WAIT);
  rightPinch.write(rightOpenStationary);
  leftPinch.write(leftOpenStationary);
  frontPinch.write(frontOpenStationary);
  backPinch.write(backOpenStationary);
  delay(WAIT*3);
  
    rightPinch.write(rightClose);
    leftPinch.write(leftClose);
    frontPinch.write(frontClose);
    backPinch.write(backClose);
    
    delay(INITWAIT);
    front();
    left();
    right();
    frontPrime();
    leftPrime();
    rightPrime();
}

void loop()
{ /*
    rightPinch.write(rightClose);
    leftPinch.write(leftClose);
    frontPinch.write(frontClose);
    backPinch.write(backClose);
    
    delay(WAIT);
      left();*/
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
 leftTwist.write(leftTwistHome); 
 rightTwist.write(rightTwistHome); 
 frontTwist.write(frontTwistHome); 
 backTwist.write(backTwistHome); 
 delay(WAIT);
 //open all and wait 10s for us
 leftPinch.write(leftOpenStationary);
 rightPinch.write(rightOpenStationary);
 frontPinch.write(frontOpenStationary);
 backPinch.write(backOpenStationary);
 delay(INITWAIT);
 //close slowly so we can line it up
 for(int i = 1; i < 81; i+=10)
 {
   leftPinch.write(leftOpenStationary - i);
   rightPinch.write(rightOpenStationary - i);
   frontPinch.write(frontOpenStationary - i);
   backPinch.write(backOpenStationary - i);
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
  rightPinch.write(rightOpenMotionSmall);
  delay(WAIT);
  leftTwist.write(leftcwise);
  delay(WAIT);
  leftPinch.write(leftOpenMotionSmall);
  delay(WAIT);
  leftTwist.write(leftcwisePart);
  delay(WAIT);
  leftPinch.write(leftOpenMotionBig);
  delay(WAIT);
  leftTwist.write(leftTwistHome);
  delay(WAIT);
  leftPinch.write(leftClose);
  delay(WAIT);
  rightPinch.write(rightClose);
  delay(WAIT);
}  
//twist counter clockwise, open, twist back
void leftPrime()
{
  rightPinch.write(rightOpenMotionSmall);
  delay(WAIT);
  leftTwist.write(leftcCwise);
  delay(WAIT);
  leftPinch.write(leftOpenMotionSmall);
  delay(WAIT);
  leftTwist.write(leftcCwisePart);
  delay(WAIT);
  leftPinch.write(leftOpenMotionBig);
  delay(WAIT);
  leftTwist.write(leftTwistHome);
  delay(WAIT);
  leftPinch.write(leftClose);
  delay(WAIT);
  rightPinch.write(rightClose);
  delay(WAIT);
} 
void rightPrime()
{
  leftPinch.write(leftOpenMotionSmall);
  delay(WAIT);
  rightTwist.write(rightcCwise);
  delay(WAIT);
  rightPinch.write(rightOpenMotionSmall);
  delay(WAIT);
  rightTwist.write(rightcCwisePart);
  delay(WAIT);
  rightPinch.write(rightOpenMotionBig);
  delay(WAIT);
  rightTwist.write(rightTwistHome);
  delay(WAIT);
  rightPinch.write(rightClose);
  delay(WAIT);
  leftPinch.write(leftClose);
  delay(WAIT);
} 
void right()
{
  leftPinch.write(leftOpenMotionSmall);
  delay(WAIT);
  rightTwist.write(rightcwise);
  delay(WAIT);
  rightPinch.write(rightOpenMotionSmall);
  delay(WAIT);
  rightTwist.write(rightcwisePart);
  delay(WAIT);
  rightPinch.write(rightOpenMotionBig);
  delay(WAIT);
  rightTwist.write(rightTwistHome);
  delay(WAIT);
  rightPinch.write(rightClose);
  delay(WAIT);
  leftPinch.write(leftClose);
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
  backPinch.write(backOpenMotionSmall);
  delay(WAIT);
  frontTwist.write(frontcwise);
  delay(WAIT);
  frontPinch.write(frontOpenMotionSmall);
  delay(WAIT);
  frontTwist.write(frontcwisePart);
  delay(WAIT);
  frontPinch.write(frontOpenMotionBig);
  delay(WAIT);
  frontTwist.write(frontTwistHome);
  delay(WAIT);
  frontPinch.write(frontClose);
  delay(WAIT);
  backPinch.write(backClose);
  delay(WAIT);
} 
void frontPrime()
{
  backPinch.write(backOpenMotionSmall);
  delay(WAIT);
  frontTwist.write(frontcCwise);
  delay(WAIT);
  frontPinch.write(frontOpenMotionSmall+12);
  delay(WAIT);
  frontTwist.write(frontcCwisePart);
  delay(WAIT);
  frontPinch.write(frontOpenMotionBig-3);
  delay(WAIT);
  frontTwist.write(frontTwistHome);
  delay(WAIT);
  frontPinch.write(frontClose);
  delay(WAIT);
  backPinch.write(backClose);
  delay(WAIT);
} 
void back()
{
  frontPinch.write(frontOpenMotionSmall);
  delay(WAIT);
  backTwist.write(backcwise);
  delay(WAIT);
  backPinch.write(backOpenMotionSmall);
  delay(WAIT);
  backTwist.write(backcwisePart);
  delay(WAIT);
  backPinch.write(backOpenMotionBig);
  delay(WAIT);
  backTwist.write(backTwistHome);
  delay(WAIT);
  backPinch.write(backClose);
  delay(WAIT);
  frontPinch.write(frontClose);
  delay(WAIT);
} 
void backPrime()
{
  frontPinch.write(frontOpenMotionSmall);
  delay(WAIT);
  backTwist.write(backcCwise);
  delay(WAIT);
  backPinch.write(backOpenMotionSmall);
  delay(WAIT);
  backTwist.write(backcCwisePart);
  delay(WAIT);
  frontPinch.write(backOpenMotionBig);
  delay(WAIT);
  backTwist.write(backTwistHome);
  delay(WAIT);
  backPinch.write(backClose);
  delay(WAIT);
  frontPinch.write(frontClose);
  delay(WAIT);
} 
//front and back claws open, left and right turn
//the cube so the top is now in the front
void top2front()
{
  frontPinch.write(frontOpenStationary);
  backPinch.write(backOpenStationary);
  delay(WAIT);
  leftTwist.write(leftcwise);
  rightTwist.write(rightcCwise);
  delay(WAIT);
  frontPinch.write(frontClose);
  backPinch.write(backClose);
  delay(WAIT);
  leftPinch.write(leftOpenStationary);
  rightPinch.write(rightOpenStationary);
  delay(WAIT);
  leftTwist.write(leftTwistHome);
  rightTwist.write(rightTwistHome);
  delay(WAIT);
  leftPinch.write(leftClose);
  rightPinch.write(rightClose);
  delay(WAIT*2);
}  
//front and back claws open, left and right turn
//the cube so the bot is now in the front
void bot2front()
{
  frontPinch.write(frontOpenStationary);
  backPinch.write(backOpenStationary);
  delay(WAIT);
  leftTwist.write(leftcCwise);
  rightTwist.write(rightcwise);
  delay(WAIT);
  frontPinch.write(frontClose);
  backPinch.write(backClose);
  delay(WAIT);
  leftPinch.write(leftOpenMotionBig);
  rightPinch.write(rightOpenMotionBig);
  delay(WAIT);
  leftTwist.write(leftcwise);
  rightTwist.write(rightcCwise);
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
  leftPinch.write(leftOpenStationary);
  rightPinch.write(rightOpenStationary);
  delay(WAIT);
  backTwist.write(backcCwise);
  frontTwist.write(frontcwise);
  delay(WAIT);
  leftPinch.write(leftClose);
  rightPinch.write(rightClose);
  delay(WAIT);
  backPinch.write(backOpenStationary);
  frontPinch.write(frontOpenStationary);
  delay(WAIT);
  backTwist.write(backcwise);
  frontTwist.write(frontcCwise);
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
  leftPinch.write(leftOpenStationary);
  rightPinch.write(rightOpenStationary);
  delay(WAIT);
  backTwist.write(backcwise);
  frontTwist.write(frontcCwise);
  delay(WAIT);
  leftPinch.write(leftClose);
  rightPinch.write(rightClose);
  delay(WAIT);
  backPinch.write(backOpenMotionBig);
  frontPinch.write(frontOpenMotionBig);
  delay(WAIT);
  backTwist.write(backcCwise);
  frontTwist.write(frontcwise);
  delay(WAIT);
  backPinch.write(backClose);
  frontPinch.write(frontClose);
  delay(WAIT);
} 
