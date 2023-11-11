#pragma once
#include <vector>
#include "Button.h"
#include "Image.h"
using namespace std;
class Page
{
public:
	Vector2 position; // 页面位置
private:
	float width;					// 页面宽度
	float height;					// 页面高度
	vector<UIElement *> uielements; // UI元素容器
	HRGN rgn;						// 页面显示区域

public:
	Page(float x, float y, float width = getwidth(), float height = getheight());
	void AddUIElement(UIElement *uielement);
	void DrawPage();
	void Clear();
};
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