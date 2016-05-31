/*
 * Blind project by yeffri Salazar
 * is an open source hardware project that wants to give to the
 * blind persons another sense or way to feel the world sorround 
 * them using at this time an ultrasonic sensor and a vibrator motor 
 * as actuator to interact with the body.
 * 
 * 
 */




#define iPinTrigger  1 //D1
#define iPinEcho  2 //D2
#define motor 0
void setup() {
  // put your setup code here, to run once:
 pinMode(iPinTrigger,OUTPUT);
 pinMode(motor,OUTPUT);
 pinMode(iPinEcho,INPUT);
}

void loop() {
  int distance = ultrasonicsensor();
if(distance<100){
  digitalWrite(motor,HIGH);
  delay(distance);
  digitalWrite(motor,LOW);
  delay(distance);
}
}

int ultrasonicsensor() {

  digitalWrite(iPinTrigger, LOW);
  digitalWrite(iPinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(iPinTrigger, LOW);


  //Read the data from the sensor
  double fTime = pulseIn(iPinEcho, HIGH);
  //convert to seconds
  fTime = fTime / 1000000;
  double fSpeed = 347.867;
  //Get the distance in meters
  double fDistance = fSpeed * fTime;
  //Convert to centimeters;
  fDistance = fDistance * 100;
  //Get one way distance
  fDistance = fDistance / 2;

  delay(100);
  return fDistance;
}
