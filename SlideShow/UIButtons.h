// UIButtons.h

#ifndef _UIBUTTONS_h
#define _UIBUTTONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Buttons.h"

class PlayPauseButtonClass : public TouchButtonsClass
{
public:
	virtual void onClick();
};

extern PlayPauseButtonClass PlayPauseButton;

// buttons init
void setupUIButtons();
#endif

