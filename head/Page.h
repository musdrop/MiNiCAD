#include <vector>
#include "Button.h"
#include "Image.h"
using namespace std;
#pragma once
class Page
{
private:
	Vector2 positon;
	float width;
	float height;
	vector<UIElement*> uielements;
public:
	Page(float x,float y);
	void AddUIElement(UIElement*uielement);
	void DrawPage();
	void Clear();
};

