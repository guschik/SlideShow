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

#include "Buttons.h"

// ------------------------------
// Generic class for buttons
void ButtonsClass::init()
{
}

bool ButtonsClass::isPressed()
{
	return false;
}

void ButtonsClass::onClick()
{
}

void ButtonsClass::handleClick()
{
	if (this->isPressed())
	{
		this->onClick();
	}
}


// ---------------------------
// TouchScreen buttons class
void TouchButtonsClass::init(uint16_t top, uint16_t left, uint16_t bottom, uint16_t right)
{
	this->top = top;
	this->left = left;
	this->bottom = bottom;
	this->right = right;
}

bool TouchButtonsClass::isPressed()
{
	return point.x > this->left && point.x < this->right && point.y > this->top && point.y < this->bottom;
}

void TouchButtonsClass::onClick()
{
	tft.setTextColor(TFT_YELLOW, TFT_NAVY);
	tft.setTextSize(3);
	tft.setCursor(10, this->top+3);
}
