/*
 ******************************
 **      blind Project       **
 **                          **
 ******************************
 *by Yeffri Salazar
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
  pinMode(button, INPUT_PULLUP);
  digitalWrite(motor, LOW);
  digitalWrite(VccUltrasonicSensor, HIGH);
}

void loop() {
  if (digitalRead(button) == LOW) {
    digitalWrite(VccUltrasonicSensor, LOW);
    delay(10000);
    digitalWrite(VccUltrasonicSensor, HIGH);
  }
  int average = ultrasonicsensor();
  if (average < 100) {
    digitalWrite(motor, HIGH);
    delay((average * 3));
    digitalWrite(motor, LOW);
    delay((average * 3));
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
  delay(10);
  return fDistance;
}


