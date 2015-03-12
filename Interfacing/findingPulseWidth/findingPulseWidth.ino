/* 
 Controlling a servo position using a potentiometer (variable resistor) 
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Knob
*/

//#include <Servo.h> 
 
//Servo myservo;  // create servo object to control a servo 
 
int potpin = 0;  // analog pin used to connect the potentiometer
int pulseWidth, val, angle;
int pin = 9;    // variable to read the value from the analog pin 
 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
 // myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  //val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  pulseWidth = map(val, 0, 1023, 600, 2400);
  Serial.println(pulseWidth);
  servoPulse(val, 9);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
} 

void servoPulse(int angle, int pin) 
{
  //Serial.println(pulseWidth);
  //pulseWidth = (angle * 11) + 500;     // converts angle to microseconds.
  digitalWrite(pin, HIGH);             // set servos high.
  //Serial.println("high");
  delayMicroseconds(pulseWidth);       // wait 
  //Serial.println("wait");
  digitalWrite(pin, LOW);              // set servos low.
  //Serial.println("low");
  delayMicroseconds(20000 - pulseWidth);
  //Serial.println("end servo pulse");
}
