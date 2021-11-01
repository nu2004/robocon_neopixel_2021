#include <Conceptinetics.h>
#include <Adafruit_NeoPixel.h>

#define START_CHANNEL 1
#define SLAVE_CHANNELS 3
#define PIN        2
#define LED_COUNT 600

Adafruit_NeoPixel pixels(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
DMX_Slave dmx_slave(SLAVE_CHANNELS);
int step_num = 0;
int delta = 1;
int color[] = {255, 255, 0};

void setup() {
  pixels.begin();
  dmx_slave.enable();
  dmx_slave.setStartAddress(START_CHANNEL);
}

void loop() {
  int data = dmx_slave.getChannelValue(1);
  if (data > 0 && data <= 25) {
    pixels.clear();
    for(int i=0; i<pixels.numPixels()-450; i++) {
      int pixelHue = step_num + (i * 65536L / pixels.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    }
    for(int i=150; i<LED_COUNT-300; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 128)); // blue
    }
    for(int i=300; i<LED_COUNT-150; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 128)); // blue
    }
    for(int i=450; i<pixels.numPixels(); i++) {
      int pixelHue = step_num + (i * 65536L / pixels.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    }
    pixels.show();
    step_num += 256;
    if (step_num == 65536) {
      step_num = 0;
    }  
    
  } else if (data > 25 && data <= 50){  
    pixels.clear();
    for(int i=0; i<LED_COUNT-450; i++) {
      pixels.setPixelColor(i, pixels.Color(128, 0, 0)); // red
    }
    for(int i=150; i<pixels.numPixels()-300; i++) {
      int pixelHue = step_num + (i * 65536L / pixels.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    }
    for(int i=300; i<pixels.numPixels()-150; i++) {
      int pixelHue = step_num + (i * 65536L / pixels.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    }
    for(int i=450; i<LED_COUNT; i++) {
      pixels.setPixelColor(i, pixels.Color(128, 0, 0)); // red
    }
    pixels.show();
    step_num += 256;
    if (step_num == 65536) {
      step_num = 0;
    }
    
  } else if (data > 50 && data <= 75){
    pixels.clear();
    for(int i=0; i<LED_COUNT-450; i++) {
      pixels.setPixelColor(i, pixels.Color(128, 0, 0)); // red
    }
    for(int i=150; i<LED_COUNT-300; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 128)); // blue
    }
    for(int i=300; i<LED_COUNT-150; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 128)); // blue
    }
    for(int i=450; i<LED_COUNT; i++) {
      pixels.setPixelColor(i, pixels.Color(128, 0, 0)); // red
    }
    pixels.show();
    delay(200);
    pixels.clear();
    for(int i=150; i<LED_COUNT-300; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 128)); // blue
    }
    for(int i=300; i<LED_COUNT-150; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 128)); // blue
    }
    pixels.show();
    delay(200);
    
  } else if (data > 75 && data <= 100){
    for(int i=0; i<LED_COUNT-450; i++) {
      pixels.setPixelColor(i, pixels.Color(128, 0, 0)); // red
    }
    for(int i=150; i<LED_COUNT-300; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 128)); // blue
    }
    for(int i=300; i<LED_COUNT-150; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 128)); // blue
    }
    for(int i=450; i<LED_COUNT; i++) {
      pixels.setPixelColor(i, pixels.Color(128, 0, 0)); // red
    }
    pixels.show();
    delay(200);
    pixels.clear();
    for(int i=0; i<LED_COUNT-450; i++) {
      pixels.setPixelColor(i, pixels.Color(128, 0, 0)); // red
    }
    for(int i=450; i<LED_COUNT; i++) {
      pixels.setPixelColor(i, pixels.Color(128, 0, 0)); // red
    }
    pixels.show();
    delay(200);

   } else if (data > 100 && data <= 200) {
    pixels.clear();
    for(int i=0; i<pixels.numPixels(); i++) {
      int pixelHue = step_num + (i * 65536L / pixels.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    } 
    pixels.show();
    step_num += 256;
    if (step_num == 65536) {
      step_num = 0;
    }    
  
   } else  if (data > 200 && data <=255) {
    //for(int i=0; i<LED_COUNT+50; i++) {
      for(int i=0; i<LED_COUNT-450; i++) {
        pixels.setPixelColor(i, pixels.Color(128, 0, 0)); // red
      }
      for(int i=150; i<LED_COUNT-300; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 128)); // blue
      }
      for(int i=300; i<LED_COUNT-150; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 128)); // red
      }
      for(int i=450; i<LED_COUNT; i++) {
        pixels.setPixelColor(i, pixels.Color(128, 0, 0)); // blue
      }
      /* 
      pixels.setPixelColor(i, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-1, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-2, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-3, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-4, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-5, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-6, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-7, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-8, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-9, pixels.Color(128, 128, 128)); // white
   
      pixels.setPixelColor(i-20, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-21, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-22, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-23, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-24, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-25, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-26, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-27, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-28, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-29, pixels.Color(128, 128, 128)); // white 

      pixels.setPixelColor(i-40, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-41, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-42, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-43, pixels.Color(128, 128, 128)); // white 
      pixels.setPixelColor(i-44, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-45, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-46, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-47, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-48, pixels.Color(128, 128, 128)); // white
      pixels.setPixelColor(i-49, pixels.Color(128, 128, 128)); // white
      */
      pixels.show();
   // }
  }
}
