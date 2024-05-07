#include "Page.h"
Page::Page(float x, float y, float width, float height)
{
	position.x = x;
	position.y = y;
	this->width = width;
	this->height = height;
	rgn = CreateRectRgn(x, y, x + width, y + height);
	BeginBatchDraw();
}
void Page::AddUIElement(UIElement *uielement)
{
	uielements.push_back(uielement);
}
void Page::DrawPage()
{
	setcliprgn(rgn); // 使用页面显示区
	for (int i = 0; i < uielements.size(); i++)
	{
		if (uielements[i]->active)
			uielements[i]->Draw(position);
	}
	FlushBatchDraw();
	DeleteObject(rgn); // 清除页面显示区
}
void Page::Clear()
{
}