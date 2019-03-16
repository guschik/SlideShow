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

#ifndef _BUTTONS_h
#define _BUTTONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "lcd_utils.h"

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

