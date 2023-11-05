#pragma once
#include "UIElement.h"
#include <easyx.h>
class Image:public UIElement
{
public:
	IMAGE *srcimg;
	Image(IMAGE &src,float x,float y);
	void Draw(Vector2 pos);

};

