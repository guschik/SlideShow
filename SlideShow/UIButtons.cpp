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
}
PlayPauseButtonClass PlayPauseButton;

void NextButtonClass::onClick()
{
}
NextButtonClass NextButton;

void RewindButtonClass::onClick()
{
}
RewindButtonClass RewindButton;

// -------------------------
// Buttons setup
void setupUIButtons()
{
	PlayPauseButton.init(200, 135, 240, 180);
	NextButton.init(200, 180, 240, 230);
	RewindButton.init(200, 85, 240, 135);
}

