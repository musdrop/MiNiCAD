#pragma once
#include "easyx.h"
#include "Vector2.h"
class UIElement
{
public:
	Vector2 position; // 位置
	Vector2 scale;	  // 缩放
	float width;	  // 宽度
	float height;	  // 高度

public:
	virtual void Draw(Vector2 pos) = 0;
};
