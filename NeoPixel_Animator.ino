// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS, 6, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, 7, NEO_GRBW + NEO_KHZ800);

int delayval = 200 ; // default delay between animation frames
int woffset = 5;  // maximum offset 16 = zero offset
int boffset = 0;
int p[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

void setup() {

  for (int i = 0; i < 16; i++) { //set p[i] value to correspond to it's position
    p[i] = i;
  }

  for (int x = 0; x < NUMPIXELS; x++) { //if value exceeds numpixels, begin from zero
    if ((p[x] + woffset) >= NUMPIXELS) {
      p[x] = (p[x] - NUMPIXELS);
    }
  }

  for (int x = 0; x < NUMPIXELS; x++) { //if value exceeds numpixels, begin from zero
    if ((p[x] + boffset) >= NUMPIXELS) {
      p[x] = (p[x] - NUMPIXELS);
    }
  }

  pixels1.begin(); // This initializes the NeoPixel library.
  pixels2.begin();

}

void loop() {

  pixels1.setPixelColor(p[0] + woffset, 0, 0, 0);
  pixels1.setPixelColor(p[8] + woffset, 0, 0, 0);

  pixels2.setPixelColor(p[0] + boffset, 0, 100, 0);
  pixels2.setPixelColor(p[8] + boffset, 80, 80, 80);

  pixels1.show(); // This sends the updated pixel color to the hardware.
  pixels2.show();
  delay(delayval); // Delay for a period of time (in milliseconds)


  pixels1.setPixelColor(p[0] + woffset, 100, 0, 0);
  pixels1.setPixelColor(p[8] + woffset, 80, 80, 80);

  pixels2.setPixelColor(p[0] + boffset, 0, 0, 0);
  pixels2.setPixelColor(p[8] + boffset, 0, 0, 0);

  pixels1.show(); // This sends the updated pixel color to the hardware.
  pixels2.show();
  delay(delayval); // Delay for a period of time (in milliseconds)

}


