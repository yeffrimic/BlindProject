
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
if(ultrasonicsensor()<100){
  digitalWrite(motor,HIGH);
  delay(ultrasonicsensor());
  digitalWrite(motor,LOW);
  delay(ultrasonicsensor());
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
