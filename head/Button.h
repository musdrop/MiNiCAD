#pragma once
#include "Image.h"
#include "Text.h"
class Button : public UIElement
{
	//-------------基类公有成员变量
	// 位置position
	// 缩放scale
	// 宽度width
	// 高度height
	//------------
private:
	Image image;
	Text text;

public:
	Button();
	void Draw(Vector2 pos);
};
