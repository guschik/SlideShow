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

#include "UI.h"

char ui[] = "/UI/navbar.bmp";

ButtonsClass* UIClass::Buttons[] = {
	&PlayPauseButton, &NextButton, &RewindButton
};

void UIClass::init()
{
	RewindButton.init(200, 85, 240, 135);
	PlayPauseButton.init(200, 135, 240, 180);
	NextButton.init(200, 180, 240, 230);
}

void UIClass::handleClick()
{
	for (uint8_t j = 0; j < sizeof(Buttons) / sizeof(Buttons[0]); j++) {
		Buttons[j]->handleClick();
	}
}

void UIClass::showNavBar()
{
	showBMP(ui, 0, 200);
}


UIClass UI;

