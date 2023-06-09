//seeed rp2040 RGB LED and neopixel exsample

#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 1
int Power = 11;
int PIN = 12;
int count = 1;
int Luminance = 125;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  Serial.println("hello im xiao rp2040!");
  pixels.begin();
  pinMode(Power, OUTPUT);
  digitalWrite(Power, HIGH);
}

void bootLed(int r, int g, int b, int d) {
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(r, g, b));
  pixels.show();
  delay(d);
}

void loop() {
  if (count >= Luminance) {
    while (true) {
      if (count <= 0) break;
      bootLed(count, 0, count, 10);
      count -= 1;
    }
  } else {
    bootLed(count, 0, count, 10);
    count += 1;
  }
}