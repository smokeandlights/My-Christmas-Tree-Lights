#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 8

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_RGB + NEO_KHZ400);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  //#if defined (__AVR_ATtiny85__)
  //  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  // #endif
  // End of trinket special code


  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  //myChase(50);


  //pulseBright(strip.Color(255, 0, 0), 100); // Red
  //pulseBright(strip.Color(0, 255, 0), 100); // Green
  //pulseBright(strip.Color(0, 0, 255), 100); // Blue

  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 25); // Red
  delay(1500);
  WaxOff(strip.Color(127, 0, 127), 25); // Pink
  delay(1500);
  colorWipe(strip.Color(127, 127, 0), 25); // Yellow
  delay(1500);
  WaxOff(strip.Color(0, 255, 0), 25); // Green
  delay(1500);
  colorWipe(strip.Color(0, 127, 127), 25);//Light Blue
  delay(1500);
  WaxOff(strip.Color(0, 0, 255), 25); // Blue
  delay(1500);
  colorWipe(strip.Color(127, 127, 127), 25); // white
  delay(1500);
  WaxOff(strip.Color(0, 0, 0), 25); //Off




  racingDots(strip.Color(255, 0, 0), 40);
  reverseracingDots(strip.Color(255, 0, 0), 40);
  racingDots(strip.Color(0, 255, 0), 40);
  reverseracingDots(strip.Color(0, 255, 0), 40);
  racingDots(strip.Color(0, 0, 255), 40);
  reverseracingDots(strip.Color(0, 0, 255), 40);
  racingDots(strip.Color(0, 255, 255), 40);
  reverseracingDots(strip.Color(0, 255, 255), 40);
  racingDots(strip.Color(255, 0, 255), 40);
  reverseracingDots(strip.Color(255, 0, 255), 40);
  racingDots(strip.Color(255, 255, 0), 40);
  reverseracingDots(strip.Color(255, 255, 0), 40);
  racingDots(strip.Color(255, 255, 255), 40);
  reverseracingDots(strip.Color(255, 255, 255), 40);

  theaterChase(strip.Color(127, 127, 127), 100); // White
  theaterChase(strip.Color(255, 0, 0), 100); // Red
  theaterChase(strip.Color(127, 127, 0), 100); // Yellow
  theaterChase(strip.Color(0, 255, 0), 100); // Green
  theaterChase(strip.Color(0, 127, 127), 100);//Teal
  theaterChase(strip.Color(0, 0, 255), 100); // Blue
  theaterChase(strip.Color(127, 0, 127), 100); // Pink

 // rainbow(50);
  rainbowCycle(10);
  rainbowCycle(10);
  theaterChaseRainbow(100);

}
//WaxOff
void WaxOff(uint32_t c, uint8_t wait) {
  for (uint16_t i = strip.numPixels(); i > 0 ; i--) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
  {
    /* {
        strip.setPixelColor(i, 0);
        strip.show();
        delay(wait);
      }*/
  }
}
//solids
void solid(uint32_t c, uint8_t wait) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
  }
  delay(wait * 100);
}

void reverseSolid(uint32_t c, uint8_t wait) {
  for (int i = strip.numPixels(); i > 0; i--) {
    strip.setPixelColor(i, c);
    strip.show();
  }
  delay(wait * 100);
}

//mychase

void racingDots(uint32_t c, uint8_t wait) {

  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
    strip.setPixelColor(i, 0);
    strip.show();
  }
}

void reverseracingDots(uint32_t c, uint8_t wait) {

  for (int i = strip.numPixels(); i > 0 ; i--) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
    strip.setPixelColor(i, 0);
    strip.show();
  }
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++)
  {
    for (int q = 0; q < 5; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 5) {
        strip.setPixelColor(i + q, c);  //turn every fifth pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 5) {
        strip.setPixelColor(i + q, 0);      //turn every fifth pixel off
      }
    }
  }
}


//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 5; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 5) {
        strip.setPixelColor(i + q, Wheel( (i + j) % 255));
        //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 5) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
