// 
// 
// 

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
	return false;
}
