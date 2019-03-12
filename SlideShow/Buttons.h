// Buttons.h

#ifndef _BUTTONS_h
#define _BUTTONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ButtonsClass
{
 protected:


 public:
	void init();
};

extern ButtonsClass Buttons;

#endif

