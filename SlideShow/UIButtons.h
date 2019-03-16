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

class NextButtonClass : public TouchButtonsClass
{
public:
	virtual void onClick();
};
extern NextButtonClass NextButton;

class RewindButtonClass : public TouchButtonsClass
{
public:
	virtual void onClick();
};
extern RewindButtonClass RewindButton;

// buttons init
void setupUIButtons();
#endif

