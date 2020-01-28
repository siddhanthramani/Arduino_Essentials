
// We use a HC-SR04 ultrasonic sensor for this project.
/*
When we send a pulse of width 10microseconds to the trigger pin, the sensor would send out 8 pulses at 40KHZ(ultrasonic as >20KHz).
At the same time, the echo pin goes high.
When the reflected wave is received, the echo pin goes low and thus the pulse width of the echo signal equals the time taken by the wave.

If no reflection occurs, the time returned is 38 ms (max range).

The math used for distance is speed (0.034cm/us) x (time/2)

CONNECT VIN to +5V (NOT +3V)


*/ 

const int triggerPin = 7;
const int echoPin = 6; 

long duration, distance, distance1, actual_distance, sp;

//where sp is the constant speed of the object the ultrasonic sensor is attached to

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  //the pulseIn measures the time it takes for a signal to transition from HIGH to LOW(If the parameter is HIGH, vice-versa if param LOW)

 
  distance = (duration/2) * 0.034;

  Serial.print(" The distance is ");
  Serial.print(distance);
  Serial.println(" cm");

  //IMPROVED SOLUTION FOR MOVING OBJECTS (with constant speed)

  //The distance calculated does not account for the distance moved by tirslk in the time taken for the ultrasonic signal to be received 
  
  distance1 = (duration/2) * 0.0344 - ( sp * duration/2 );

  //the distance1 accounts for the relative distance but reduces the true distance as the tirslk doesnt receive the echo signal at the same place 
  //where it starts and this subtracts a wrong extra distance equal to half of the distance between where the wave is sent and where it is received.
  //Thus we have to add the distance subtracted to get the true distance of TI-RSLK from the object. 
  
  actual_distance = (distance - distance1)/2 + distance1;
  
  if (actual_distance < 40){
    //do something
  }
  delay(1000);
  
}
