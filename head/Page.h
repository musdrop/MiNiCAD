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