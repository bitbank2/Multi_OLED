#define FONT_NORMAL 0
#define FONT_LARGE 1
#define FONT_SMALL 2

// OLED type for init function
enum {
  OLED_128x32 = 1,
  OLED_128x64,
  OLED_132x64,
  OLED_64x32
};

//
// Initializes the OLED controller(s) into "page mode"
//
void Multi_OLEDInit(uint8_t *iBus, uint8_t *iAddr, uint8_t *iType, uint8_t *bFlip, uint8_t *bInvert, uint8_t iBusCount);
//
// Sets the brightness (0=off, 255=brightest)
//
void Multi_OLEDSetContrast(uint8_t iBus, unsigned char ucContrast);
//
// Load a 128x64 1-bpp Windows bitmap
// Pass the pointer to the beginning of the BMP file
// First pass version assumes a full screen bitmap
//
int Multi_OLEDLoadBMP(uint8_t iBus, byte *pBMP);
//
// Power up/down the display
// useful for low power situations
//
void Multi_OLEDPower(uint8_t iBus, byte bOn);
//
// Draw a string of normal (8x8), small (6x8) or large (16x32) characters
// At the given col+row
//
int Multi_OLEDWriteString(uint8_t iBus, int x, int y, char *szMsg, int iSize, int bInvert);
//
// Fill the frame buffer with a byte pattern
// e.g. all off (0x00) or all on (0xff)
//
void Multi_OLEDFill(uint8_t iBus, unsigned char ucData);
//
// Set (or clear) an individual pixel
// The local copy of the frame buffer is used to avoid
// reading data from the display controller
// (which isn't possible in most configurations)
// This function needs the USE_BACKBUFFER macro to be defined
// otherwise, new pixels will erase old pixels within the same byte
//
int Multi_OLEDSetPixel(uint8_t iBus, int x, int y, unsigned char ucColor);

