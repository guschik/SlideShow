// This file is part of CasaSoft Arduino SlideShow
// 
// CasaSoft Arduino SlideShow is free software: 
// you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// CasaSoft Arduino SlideShow is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with CasaSoft Arduino SlideShow.  
// If not, see <http://www.gnu.org/licenses/>.

#ifndef _LCD_UTILS_H_
#define _LCD_UTILS_H_

#include <Arduino.h>
#include <SPI.h>            // f.k. for Arduino-1.5.2
#define USE_SDFAT
#include <SdFat.h>             // Use the official SD library on hardware pins

#include <Adafruit_GFX.h>   // Hardware-specific library
#include <MCUFRIEND_kbv.h>
#include "TouchScreen_kbv.h" 

#define SD_CS     10
#define SPI_SPEED SD_SCK_MHZ(50)

extern MCUFRIEND_kbv tft;
extern TouchScreen_kbv ts;   
extern TSPoint_kbv tp; 
extern TSPoint_kbv point;
extern int XP;
extern int YP;
extern int XM;
extern int YM;
extern SdFat SD;

void lcd_setup();

#define BMPIMAGEOFFSET 54
#define PALETTEDEPTH   0     // do not support Palette modes
//#define PALETTEDEPTH   8     // support 256-colour Palette

#define BUFFPIXEL      20

uint16_t read16(File& f);
uint32_t read32(File& f);
uint8_t showBMP(char *nm, int x, int y);

void readResistiveTouch(void);
bool ISPRESSED(void);
void getPointXY(void);
boolean diagnose_pins(void);
#endif
