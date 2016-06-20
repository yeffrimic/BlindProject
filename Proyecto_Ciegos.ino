/*
 * Blind project by yeffri Salazar
 * is an open source hardware project that wants to give to the
 * blind persons another sense or way to feel the world sorround
 * them using at this time an ultrasonic sensor and a vibrator motor
 * as actuator to interact with the body.
 *
 *
 */



#define button 2
#define VccUltrasonicSensor 0
#define iPinTrigger  3 //D1
#define iPinEcho  4 //D2
#define motor 1
void setup() {
  // put your setup code here, to run once:
  pinMode(iPinTrigger, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(iPinEcho, INPUT);
  pinMode(VccUltrasonicSensor, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(motor,LOW);
  digitalWrite(VccUltrasonicSensor,HIGH);
}

void loop() {
  int average= ultrasonicsensor();
  if (average < 100) {
    digitalWrite(motor, HIGH);
    delay(average);
    digitalWrite(motor, LOW);
    delay(average);
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

  return fDistance;
}
