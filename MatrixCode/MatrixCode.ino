#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR 
#endif

#define PIN 6

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,  
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + 
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG, 
  NEO_GRB + NEO_KHZ800);

const uint16_t redColor = matrix.Color(255, 0, 0);
const uint16_t greenColor = matrix.Color(0, 255, 0);
const uint16_t blueColor = matrix.Color(0, 0, 255);
  
void setup() 
{
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(redColor);
}

int x = matrix.width();

int teamChant = false;

void loop() 
{
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  if(teamChant)
  {
    matrix.print("WILDCAT ROBOTICS 3039");
  }
  else
  {
    switch(random(0, 4))
    {
      case 0:
        matrix.print("");
        break;
      case 1:
        matrix.print("");
        break;
      case 2:
        matrix.print("");
        break;
      case 3:
        matrix.print("");
        break;
      
    }
  }
  if(--x < -150)
  {
    x = matrix.width();
    teamChant = !teamChant;
  }
}
