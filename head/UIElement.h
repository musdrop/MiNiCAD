#pragma once
#include "Vector2.h"
class UIElement
{
public:
	Vector2 position;
	virtual void Draw(Vector2 pos)=0;
};

