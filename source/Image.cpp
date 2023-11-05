#include "Image.h"

Image::Image(IMAGE &src,float x,float y)
{
	this->srcimg = &src;
	position.x = x;
	position.y = y;
}

void Image::Draw(Vector2 pos)
{
	putimage(position.x+pos.x, position.y+pos.y, srcimg);
}
