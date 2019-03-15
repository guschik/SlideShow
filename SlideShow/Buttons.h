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
	virtual bool isPressed();
	virtual void onClick();

	void handleClick();
};

class TouchButtonsClass : public ButtonsClass
{
protected:
	uint16_t top;
	uint16_t left;
	uint16_t bottom;
	uint16_t right;

public:
	void init(uint16_t top,	uint16_t left, uint16_t bottom,	uint16_t right);
	virtual bool isPressed();

};
#endif

