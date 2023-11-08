#pragma once
#include <vector>
#include "Button.h"
#include "Image.h"
using namespace std;
class Page
{
private:
	Vector2 positon;
	float width;
	float height;
	vector<UIElement *> uielements;

public:
	Page(float x, float y);
	void AddUIElement(UIElement *uielement);
	void DrawPage();
	void Clear();
};
Page::Page(float x, float y)
{
	positon.x = x;
	positon.y = y;
}
void Page::AddUIElement(UIElement *uielement)
{
	uielements.push_back(uielement);
}
void Page::DrawPage()
{
	for (int i = 0; i < uielements.size(); i++)
	{
		uielements[i]->Draw(positon);
	}
}
void Page::Clear()
{
}