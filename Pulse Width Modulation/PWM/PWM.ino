//Pulse Width Modulation refers to changing the width of the pulse to change the power supplied to the connected device.

//We do not change the level of voltage supplied but the time for which that voltage is supplied.
//i.e  We reduce the energy supplied and thus the power supplied for a unit time.

//In this project, we take the input as an analog value of the potentiometer.
//This is converted to a digtal value(0- 255) by the inbuilt ADC.
//Depending on the value of the input, we change the time the output is on.(PWM)
// The output is binary digital (0 or 1) and the time it remains HIGH is proportional to the analog input value.

const int potIn = 14; //potIn is given a value of 14 which takes up some memory space.
#define motorOut 13 //where motor is a Macro which gets the Macro_value 13, during compile time and hence does not take up memory space.

int in;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(potIn, INPUT);
  pinMode(motorOut, OUTPUT);

  Serial.begin(9600);
  //This sets up a serial communication.
  //The USB is used to send the code to the microC
  //When the code is run, the microC interacts via the USB cable using serial communication to send values to the PC which you can see on the COMM port.
  
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(motorOut, analogRead(potIn)); 

}
