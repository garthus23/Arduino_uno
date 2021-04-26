//www.elegoo.com
//2016.12.8

// define pins
#include "rgb.h"
#define	delayTime 10

void tricolore_melted()
{	
	int greenValue;
	int blueValue;
	int redValue;
	int i;

	// Star with Blue color

	blueValue = 255;
	greenValue = 0;
	redValue = 0;
	analogWrite(BLUE, blueValue);
	analogWrite(RED, redValue);
	analogWrite(GREEN, greenValue);

	delay(5000);

	// White color

	for (i=0; i < 255; i++)
	{
		greenValue += 1;
		redValue += 1;
		analogWrite(GREEN, greenValue);
		analogWrite(RED, redValue);
		delay(10);
	}

	delay(5000);
	
	// Red Color
	// cocorico !

	for (i=0; i < 255; i++)
	{
		blueValue -= 1;
		greenValue -= 1;
		analogWrite(BLUE, blueValue);
		analogWrite(GREEN, greenValue);
		delay(10);
	}

	delay(5000);

	// Return to the Blue

	for (i=0; i< 255; i++)
	{
		blueValue +=1;
		redValue -= 1;
		analogWrite(BLUE, blueValue);
		analogWrite(RED, redValue);
		delay(10);
	}

}
