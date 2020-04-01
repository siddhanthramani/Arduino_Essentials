// A dht11 sensor is used to measure humidity and temperature values.
//Start pulsE:To start communication with DHT11, first we have to send the start pulse to the DHT11 sensor.To provide start pulse, 
//pull down the data pin minimum 18ms and then pull up, as shown in START-PULSE figure.
//Outputs:
//
//After getting start pulse from the controller, DHT11 sends the response pulse to the microcontroller which will indicate that DHT11 received start pulse.
//
//The response pulse is low for 54us and then goes high for 80us.
//
//After sending the response pulse, DHT11 sensor sends the data, which contains humidity and temperature value along with checksum. 
//The data frame is of total 40 bits long, it contains 5 segments (byte) and each segment is 8-bit long.In this 5 segments first 
//two segments content humidity value in decimal integer form. This Value gives us Relative Percentage Humidity. 1st 8-bits are integer part 
//and next 8 bits are fractional partNext two segment content temperature value in decimal integer form. This value gives us temperature in Celsius form.
//
//Last segment is the check sum which holds check sum of first four segment.Here checksum byte is direct addition of humidity and temperature value. 
//And we can verify it in microcontroller whether it is same as checksum value or not. If it is not equal, then there is some error in the data value otherwise the data is correct.Once microcontroller receives data, DHT11 pin goes in low power consumption mode until the microcontroller do not sends start pulse again.
//
//End-Pulse
//
//After sending 40-bit data, DHT11 sensor sends 54us low level and then goes high. After this DHT11 goes in sleep mode.


int gate=11; 
volatile unsigned long duration=0;
unsigned char i[5];
unsigned int j[40];
unsigned char value=0;
unsigned answer=0;
int z=0;


void setup() 
{
  Serial.begin(9600);
}
void loop() 
{

 delay(1000);
 while(1)
 {
  delay(1000);
  pinMode(gate,OUTPUT);
  digitalWrite(gate,LOW);//we make it low for min of 18ms
  delay(20);
  digitalWrite(gate,HIGH);//we then make it high
  pinMode(gate,INPUT_PULLUP);//by default it will become high due to internal pull up
 // delayMicroseconds(40);

  
  duration=pulseIn(gate, LOW); //we measure the duration for which pin remains low before turning high
  if(duration >= 72 && duration <= 84)//should be >=54, dont know why this is different
  {
      while(1)
      {
        duration=pulseIn(gate, HIGH);//we measure for how long pin remains high before turning low
        
        if(duration >= 20 && duration <= 26){
        value=0;}//signifies bit 0
        
        else if(duration >= 65 && duration <= 74){
        value=1;}//signifies bit 1
        
        else if(z==40){
        break;}
        
        i[z/8] |= value << (7- (z%8)); // every time we go to the loop, we left shift the value by the no.of spaces and or it to get the final 8 bit number
        j[z] = value;//stores all 80 bits in an array
        z++;  
      }
    }
answer=i[0]+i[1]+i[2]+i[3];

if(answer==i[4] && answer!=0) //checks parity 
{
  while(1){
    for(int k = 0; k < 5; k++){
      Serial.println(i[k]);
      delay(1000); 
    } 
  }
}

z=0;
i[0]=i[1]=i[2]=i[3]=i[4]=0;
 }
}
