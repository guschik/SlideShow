// This file is part of CasaSoft Arduino SlideShow
//
// copyright (c) 2019 Roberto Ceccarelli - Casasoft
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

class HWClass
{
private:
	uint16_t read16(File& f);
	uint32_t read32(File& f);
//	int XP = 8, XM = A2, YP = A3, YM = 9;

public:
	MCUFRIEND_kbv tft;
	TouchScreen_kbv ts;   //re-initialised after diagnose
	TSPoint_kbv tp;
	TSPoint_kbv point;
	SdFat SD;

	void init();
	uint8_t showBMP(char *nm, int x, int y);
	void getPointXY(void);
};

extern HWClass HW;

#define BMPIMAGEOFFSET 54
#define PALETTEDEPTH   0     // do not support Palette modes
//#define PALETTEDEPTH   8     // support 256-colour Palette

#define BUFFPIXEL      20

extern void showNextImage();
#endif
