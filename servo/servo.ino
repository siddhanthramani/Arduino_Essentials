//A servo motor is generally used in Robotic to rotate a mechanical arm.
//It consists of a motor and a potentiometer connected via a fededback system.
//The angle that the arm should be at is stored which is continuously checked against the motor angle.
//This is done by the use of a potentiometer.
//As the motor rotates, the pot rotates leading to a change in output voltage from the pot.
//This value is compared with already stored values of voltage(corresponding to different angles) and feedback is applied.
//
//The value which should be compared with is given by the programmer.
//Usually a current with a pulsewidth of 1ms =      0 degrees
//                                       1.5ms =   90 degrees
//                                       2ms =     180 degrees
// Total time period is usually 20ms.
// The current is given to a digital pwm pin.  I think it can be given to a normal digital pin also.
// Special functions are there like servo.write which converts angles to current and sends this to the digital pin

#include <Servo.h>             //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle = 0;    
 
void setup() 
{ 
  servo_test.attach(9);      // attach the signal pin of servo to pin9 of arduino
} 
  
void loop() 
{ 
  for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
 
  delay(1000);
  
  for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    delay(5);                       
  } 

    delay(1000);
}
