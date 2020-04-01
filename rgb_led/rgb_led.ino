//a rgb_led can be of two types
//Common cathode(-) and common anode(+)
//
//The longest terminal is the common cathode or anode terminal.
//The other three form the terminals of the rgb colors
//Connect EACH terminal of RGB to a 220 ohm resistor

//the rgb led we have is common anode. So connect it to +5V
//In common cathode mode, larger the value of pwm, brighter that color 
//and in common anode, lower the value, brighter that color

const int red_led = 9;
#define green_led 10
#define blue_led  11 


void setup() {
  
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  
}

void loop() {

  for(int i = 0; i <= 255 ; i++){
    for(int j = 0; j <= 255 ; j++){
      for(int k = 0; k <= 255 ; k++){
        analogWrite(red_led, i);
        analogWrite(green_led, j);
        analogWrite(blue_led, k);
        delay(2);     
      }
    }
  }
  
}
