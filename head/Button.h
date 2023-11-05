#include "UIElement.h"
#pragma once
class Button:public UIElement
{
private:
public:
	Button();
	void Draw(Vector2 pos);
};

