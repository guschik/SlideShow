/*
 Name:		SlideShow.ino
 Created:	11/03/2019 21:07:17
 Author:	rober
*/

#include "Buttons.h"
#include  "lcd_utils.h"


#define NAMEMATCH ""        // "" matches any name
//#define NAMEMATCH "tiger"   // *tiger*.bmp
char namebuf[32] = "/";   //BMP files in root directory
//char namebuf[32] = "/bitmaps/";  //BMP directory e.g. files in /bitmaps/*.bmp
char ui[] = "/UI/navbar.bmp";

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

	tft.fillScreen(0);
	tft.setCursor(10, 100);
	tft.setTextSize(3);
	tft.print(namebuf);
	ret = showBMP(namebuf, 0, 0);
	tft.setTextSize(2);
	tft.setCursor(10, 130);
	switch (ret) {
	case 0:
		break;
	case 1:
		tft.println(F("bad position"));
		break;
	case 2:
		tft.println(F("bad BMP ID"));
		break;
	case 3:
		tft.println(F("wrong number of planes"));
		break;
	case 4:
		tft.println(F("unsupported BMP format"));
		break;
	case 5:
		tft.println(F("unsupported palette"));
		break;
	default:
		tft.println(F("unknown"));
		break;
	}
}


// ------------------------------------------
// Basic Arduino functions

// the setup function runs once when you press reset or power the board
void setup() {
	diagnose_pins();
	lcd_setup();

	root = SD.open(namebuf);
	pathlen = strlen(namebuf);

	timer_setup();
}

uint8_t paused = 0;

// the loop function runs over and over again until power down or reset
void loop() {
	if (show_image_event == 1 && paused == 0) {
		showNextImage();
		show_image_event = 0;
	}

	if (ISPRESSED() && paused == 0) {
		paused = 1;
		showBMP(ui, 0, 200);
	}
}
