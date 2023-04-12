/*
Arduino 16x2 LCD - Detect Buttons
modified on 18 Feb 2019
by Saeed Hosseini @ Electropeak
https://electropeak.com/learn/
*/

#include <LiquidCrystal.h>

// LCD pin assignment for the Arduino R3
const int pin_RS = 8;
const int pin_EN = 9;
const int pin_d4 = 4;
const int pin_d5 = 5;
const int pin_d6 = 6;
const int pin_d7 = 7;

float tempF = 21.12;

LiquidCrystal lcd( pin_RS, pin_EN, pin_d4, pin_d5, pin_d6, pin_d7 );

void setup()
{
	delay( 1000 );
	Serial.begin( 115200 );
	if( !Serial )
		delay( 1000 );
	Serial.println( "Setup has begun." );

	// Set the number of columns and rows.
	lcd.begin( 16, 2 );

	// Move the cursor to the first column and the first row.
	lcd.setCursor( 0, 0 );
	lcd.print( "AdamRules!" );
	// Move the cursor to the first column and the second row.
	lcd.setCursor( 0, 1 );
	lcd.print( "Temp F:" );
} // End of setup() function.

void loop()
{
	int analogKeypadReading = analogRead( 0 );

	if( analogKeypadReading < 60 )
	{
		tempF++;
		//		lcd.print( "Right " );
		Serial.println( "Right" );
	}
	else if( analogKeypadReading < 200 )
	{
		tempF++;
		//		lcd.print( "Up    " );
		Serial.println( "Up" );
	}
	else if( analogKeypadReading < 400 )
	{
		tempF--;
		//		lcd.print( "Down  " );
		Serial.println( "Down" );
	}
	else if( analogKeypadReading < 600 )
	{
		tempF--;
		//		lcd.print( "Left  " );
		Serial.println( "Left" );
	}
	else if( analogKeypadReading < 800 )
	{
		//		lcd.print( "Select" );
		Serial.println( "Select" );
	}
	Serial.println( tempF );
	lcd.setCursor( 10, 1 );
	lcd.print( tempF );
}
