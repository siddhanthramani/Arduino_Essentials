//PS2- 2axis joystick

//The joystick has two pots for each axis. As we rotate the joysticks, the pots rotate and the values of the analog output of 
//the pots will change. Both the pots can change value at the same time due to the gimabl mechanism (internal hardware build)
//Since, the arduino has a 10bit adc, we get values from 0-1023
//A value of 512,512 from the pots of both the axes represent the center of the joystick


//The joystick has VCC to 5
//ground to ground
//Vx which provides analog x axis values
//Vy which provides analog y axis values
//Sw which provides value of switch which is pullup. Therefore a digital input of 0 corresponds to switch press.

// Arduino pin numbers
const int SW_pin = 8; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
//0 or 1 instead of A) or A! also works, dont know why


void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print(" | ");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print(" | ");
  Serial.print("Y-axis: ");
  Serial.print(analogRead(Y_pin));
  Serial.println(" | ");
  delay(200);
}
