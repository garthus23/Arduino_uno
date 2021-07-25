/* Potentiometer controlling lamp program */
// Constants
#include <Stepper.h>
#define DELAY 20 // Delay between two measurements in ms
#define MIN_RAW 0 // Analog minimum value
#define MAX_RAW 1023 // Analog maximum value
#define MIN_CMD 0 // Digital minimum value
#define MAX_CMD 200 // Digital maximum value

// Parameters
const int sensorPin = A0; // Pin connected to sensor
const int ledPin = 3; // Pin connected to sensor

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 15;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);


//Variables
int sensorVal; // Analog value from the sensor
int cmd; //Led command value

//Main
void setup(void) {
  Serial.begin(9600);
  myStepper.setSpeed(rolePerMinute);
  pinMode(ledPin,OUTPUT);
}

void loop(void) {
  Stepperloop();
  sensorVal = analogRead(sensorPin);
  cmd=sensorToLed(sensorVal);
  analogWrite(ledPin,cmd);
  delay(DELAY);
  Serial.print("Sensor : ");
  Serial.println(sensorVal);
  Serial.print("Command : ");
  Serial.println(cmd);
}

//Functions
int sensorToLed(int raw){
  int val = map(sensorVal, MIN_RAW, MAX_RAW, MIN_CMD, MAX_CMD);
  val=max(val,MIN_CMD);
  val=min(val,MAX_CMD);
  return val;
}
