#include <Servo.h>

//create the 6 servos
Servo botPinch;
Servo botTwist;
Servo leftPinch;
Servo leftTwist;
Servo rightPinch;
Servo rightTwist;

//assign angles for operations (TBD)
int openDeg;
int closeDeg;
int cwise;
int cCwise;
//variable to store serial input
int operation = -1;

//attach servos to PWM pins and setup serial in
void setup()
{
  botPinch.attach(3);
  botTwist.attach(5);
  leftPinch.attach(6);
  leftTwist.attach(9);
  rightPinch.attach(10);
  rightTwist.attach(11);
  Serial.begin(9600);
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
      case '0':
        //left();
        openn();
        break;
      case '1':
        //right();
        closee();
        break;
      case '2':
        up();
        break;
      case '3':
        down();
        break; 
      case '4':
        front();
        break;
      case '5':
        back();
        break;  
      default:
        break; 
    }
  }
  
  Serial.write("1");
  Serial.write("\n");
  delay(500);
}

void openn()
{
  botPinch.write(90);
}  
void closee()
{
  botPinch.write(35); 
} 

//every open has a close, every cwise has a cCwise
//this ensures we maintain our home position
//by Rubik notation, each operation is a clockwise turn

// 'L' operation
void left()
{
  botPinch.write(openDeg);
  leftTwist.write(cwise);
  botPinch.write(closeDeg);
  leftPinch.write(openDeg);
  leftTwist.write(cCwise);
  leftPinch.write(closeDeg);
}

// 'R' operation
void right()
{
  botPinch.write(openDeg);
  rightTwist.write(cwise);
  botPinch.write(closeDeg);
  rightPinch.write(openDeg);
  rightTwist.write(cCwise);
  rightPinch.write(closeDeg);
} 

// 'U' operation
void up()
{
  top2bot();
  down();
  top2bot();
} 

// 'D' operation
void down()
{
  botTwist.write(cwise);
  botPinch.write(openDeg);
  botTwist.write(cCwise);
  botPinch.write(closeDeg);
}
 
// 'F' operation
void front()
{
  front2bot();
  down();
  bot2front();
}

// 'B' operation
void back()
{
  bot2front();
  down();
  front2bot();
}

//rotate front face to bottom (for F and B)
void front2bot()
{
  botPinch.write(openDeg);
  rightPinch.write(openDeg);
  leftTwist.write(cwise);
  rightPinch.write(closeDeg);
  leftPinch.write(openDeg);
  leftTwist.write(cCwise);
  leftPinch.write(closeDeg);
  botPinch.write(closeDeg);
}

//rotate bottom face to front (for F and B)
void bot2front()
{
  botPinch.write(openDeg);
  rightPinch.write(openDeg);
  leftTwist.write(cCwise);
  rightPinch.write(closeDeg);
  leftPinch.write(openDeg);
  leftTwist.write(cwise);
  leftPinch.write(closeDeg);
  botPinch.write(closeDeg);
}  

//rotate cube so top face is on bottom (for U)
//4 lines less than front2bot twice
void top2bot()
{
  botPinch.write(openDeg);
  rightPinch.write(openDeg);
  leftTwist.write(cwise);
  rightPinch.write(closeDeg);
  leftPinch.write(openDeg);
  leftTwist.write(cCwise);
  rightTwist.write(cCwise);
  leftPinch.write(closeDeg);
  rightPinch.write(openDeg);
  rightTwist.write(cwise);
  rightPinch.write(closeDeg);
  botPinch.write(closeDeg);
}  
