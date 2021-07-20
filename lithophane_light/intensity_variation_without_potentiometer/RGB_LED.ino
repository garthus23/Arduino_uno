//www.elegoo.com
//2016.12.8

// define pins
#define WHITE 5

void setup()
{
  pinMode(WHITE, OUTPUT);
  digitalWrite(WHITE, HIGH);
}

// define variables
int intensity;

// main loop
void loop()
{
#define delayTime 10 // fading time between colors

  intensity = 255; // choose a value between 1 and 255 to change the color.

  // this is unnecessary as we've either turned on RED in SETUP
  // or in the previous loop ... regardless, this turns RED off
  // analogWrite(RED, 0);
  // delay(1000);

  for (int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
  {
    intensity -= 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(RED, 255 - redValue);
    // analogWrite(GREEN, 255 - greenValue);
    analogWrite(WHITE, intensity);
    delay(delayTime);
  }

  for (int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
  {
    intensity += 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(GREEN, 255 - greenValue);
    // analogWrite(BLUE, 255 - blueValue);
    analogWrite(WHITE, intensity);
    delay(delayTime);
  }
}
