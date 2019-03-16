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

#include "UIButtons.h"

void PlayPauseButtonClass::onClick()
{
	TouchButtonsClass::onClick();
	tft.print("Play");
	paused = 0;
}
PlayPauseButtonClass PlayPauseButton;

void NextButtonClass::onClick()
{
	TouchButtonsClass::onClick();
	tft.print("Next");
	showNextImage();
	showNavBar();
}
NextButtonClass NextButton;

void RewindButtonClass::onClick()
{
	TouchButtonsClass::onClick();
	tft.print("Rewind");
	paused = 0;
	root.rewindDirectory();
}
RewindButtonClass RewindButton;

// -------------------------
// Buttons setup
void setupUIButtons()
{
	RewindButton.init(200, 85, 240, 135);
	PlayPauseButton.init(200, 135, 240, 180);
	NextButton.init(200, 180, 240, 230);
}

