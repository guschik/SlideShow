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

#include "lcd_utils.h"
#include "UIButtons.h"
#include "UI.h"

#define NAMEMATCH ""        // "" matches any name
//#define NAMEMATCH "tiger"   // *tiger*.bmp
char namebuf[32] = "/";   //BMP files in root directory
//char namebuf[32] = "/bitmaps/";  //BMP directory e.g. files in /bitmaps/*.bmp

File root;
int pathlen;

// -------------------------------------------------
// timer manager
// preload timer 65536-16MHz/1024
#define TIMER_PRELOAD 49911
uint8_t volatile timer_ticks = 0;
uint8_t volatile timer_delay = 5;
uint8_t volatile show_image_event = 1;

void timer_setup() {
	// initialize timer1 
	TIMSK1 &= ~(1 << TOIE1);            // disable interrupts
	TCCR1A &= ~((1 << WGM11) | (1 << WGM10));  // mode normal
	TCCR1B &= ~((1 << WGM12) | (1 << WGM13));  // mode normal 
	TIMSK1 &= ~(1 << OCIE1A);

	// 1024 prescaler
	TCCR1B |= (1 << CS12) | (1 << CS10);  // setta "1" nei bit CS10 e CS12
	TCCR1B &= ~(1 << CS11);              // setta "0" nel bit CS11  

	TCNT1 = TIMER_PRELOAD;            // preload timer 
	timer_ticks = 0;
	TIMSK1 |= (1 << TOIE1);              // enable interrupts
}

ISR(TIMER1_OVF_vect)          // timer compare interrupt service routine
{
	TCNT1 = TIMER_PRELOAD;            // preload timer 
	timer_ticks++;

	if (timer_ticks > timer_delay) {
		timer_ticks = 0;
		show_image_event = 1;
	}
}


// ---------------------------------
// images management

void showNextImage() {
	char *nm = namebuf + pathlen;
	File f = root.openNextFile();
	if (f == NULL) {
		root.rewindDirectory();
		f = root.openNextFile();
	}
#ifdef USE_SDFAT
	f.getName(nm, 32 - pathlen);
#else
	strcpy(nm, (char *)f.name());
#endif
	f.close();
	strlwr(nm);
	if (strstr(nm, ".bmp") != NULL && strstr(nm, NAMEMATCH) != NULL) {
		showImage(namebuf);
	}
}

void showImage(char *nm) {
	uint8_t ret;

	HW.tft.fillScreen(0);
	HW.tft.setCursor(10, 100);
	HW.tft.setTextSize(3);
	HW.tft.print(namebuf);
	ret = HW.showBMP(namebuf, 0, 0);
	HW.tft.setTextSize(2);
	HW.tft.setCursor(10, 130);
	switch (ret) {
	case 0:
		break;
	case 1:
		HW.tft.println(F("bad position"));
		break;
	case 2:
		HW.tft.println(F("bad BMP ID"));
		break;
	case 3:
		HW.tft.println(F("wrong number of planes"));
		break;
	case 4:
		HW.tft.println(F("unsupported BMP format"));
		break;
	case 5:
		HW.tft.println(F("unsupported palette"));
		break;
	default:
		HW.tft.println(F("unknown"));
		break;
	}
}


// ------------------------------------------
// Basic Arduino functions

// the setup function runs once when you press reset or power the board
void setup() {
	HW.init();

	root = HW.SD.open(namebuf);
	pathlen = strlen(namebuf);

	timer_setup();
	UI.init();
}

uint8_t paused = 0;

// the loop function runs over and over again until power down or reset
void loop() {
	if (paused == 0) {
		if (show_image_event == 1) {
			showNextImage();
			show_image_event = 0;
		}
		if (HW.ts.ISPRESSED()) {
			paused = 1;
			UI.showNavBar();
		}
	}
	else if (HW.ts.ISPRESSED()) {
		HW.getPointXY();
		UI.handleClick();
	}
}

