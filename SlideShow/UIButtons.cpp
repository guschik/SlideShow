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

#include "UIButtons.h"
#include "UI.h"

void PlayPauseButtonClass::onClick()
{
	TouchButtonsClass::onClick();
	HW.tft.print("Play");
	paused = 0;
}
PlayPauseButtonClass PlayPauseButton;

void NextButtonClass::onClick()
{
	TouchButtonsClass::onClick();
	HW.tft.print("Next");
	showNextImage();
	UI.showNavBar();
}
NextButtonClass NextButton;

void RewindButtonClass::onClick()
{
	TouchButtonsClass::onClick();
	HW.tft.print("Rewind");
	paused = 0;
	root.rewindDirectory();
}
RewindButtonClass RewindButton;
