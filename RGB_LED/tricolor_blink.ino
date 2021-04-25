//www.elegoo.com
//2016.12.8

// define pins
#include "rgb.h"
#define	delayTime 10

void tricolore_blink()
{
	int redValue;
	int greenValue;
	int blueValue;

	// Blue color

	redValue = 0;
	greenValue = 0;
	blueValue = 255;
	analogWrite(GREEN, greenValue);
	analogWrite(RED, redValue);
	analogWrite(BLUE, blueValue);

	delay(1000);

	// White color

	greenValue = 255;
	redValue = 255;
	analogWrite(GREEN, greenValue);
	analogWrite(RED, redValue);

	delay(1000);

	// Red Color
	// cocorico !

	blueValue = 0;
	greenValue = 0;
	analogWrite(BLUE, blueValue);
	analogWrite(GREEN, greenValue);

	delay(1000);

}
