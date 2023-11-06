#pragma once
#include "UIElement.h"
#include "easyx.h"
class Image : public UIElement
{
public:
	IMAGE *srcimg;
	Image(IMAGE &src, float x, float y)
	{
		this->srcimg = &src;
		position.x = x;
		position.y = y;
	}
	void Draw(Vector2 pos)
	{
		putimage(position.x + pos.x, position.y + pos.y, srcimg);
	}
};
