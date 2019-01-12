#include <Multi_BitBang.h>
#include <Multi_OLED.h>

//
// Simple demo to demonstrate line drawing on MCUs with enough RAM to hold
// backing buffers for each display
//
// For this demo, the 2 displays are 1.3" SH1106 controllers with each
// set to a unique address and running from the same I2C bus
//
#define NUM_DISPLAYS 2
#define NUM_BUSES 1
// I2C bus info
uint8_t scl_list[NUM_BUSES] = {5};
uint8_t sda_list[NUM_BUSES] = {6};
int32_t speed_list[NUM_BUSES] = {1000000L};
// OLED display info
uint8_t bus_list[NUM_DISPLAYS] = {0,0}; // can be multiple displays per bus
uint8_t addr_list[NUM_DISPLAYS] = {0x3c, 0x3d};
uint8_t type_list[NUM_DISPLAYS] = {OLED_132x64, OLED_132x64};
uint8_t flip_list[NUM_DISPLAYS] = {0,0};
uint8_t invert_list[NUM_DISPLAYS] = {0,0};

void setup() {
  // put your setup code here, to run once:
  Multi_I2CInit(sda_list, scl_list, speed_list, NUM_BUSES);
  Multi_OLEDInit(bus_list, addr_list, type_list, flip_list, invert_list, NUM_DISPLAYS);
}

void loop() {
  // put your main code here, to run repeatedly:
int i, x1, y1, x2, y2;

  Multi_OLEDFill(0, 0);
  Multi_OLEDFill(1, 0);
  for (i=0; i<128; i++)
  {
    Multi_OLEDDrawLine(0, i, 0, 127-i, 63);
    // draw random lines on the second display
    x1 = random(128);
    x2 = random(128);
    y1 = random(64);
    y2 = random(64);
    Multi_OLEDDrawLine(1, x1, y1, x2, y2);
  }
  delay(2000);
}
