#pragma once
#include "UIElement.h"
class Image : public UIElement
{
	//-------------基类公有成员变量
	// 位置position
	// 缩放scale
	// 宽度width
	// 高度height
	//------------
private:
	LPCTSTR imgsrcpath; // 绑定的图片资源文件路径
	IMAGE *srcimg;		// 图片文件指针
	bool issrc = true;
	float realwidth;
	float realheight;

public:
	Image(const char path[], float x = 0, float y = 0, float width = 0, float height = 0);
	Image(const char path[], Vector2 position, float width = 0, float height = 0);
	Image(IMAGE &src, float x = 0, float y = 0, float width = 0, float height = 0);
	Image(IMAGE &src, Vector2 position, float width = 0, float height = 0);
	void Resize(float width, float height);			   // 重设宽度高度
	void Setscale(float scalex = 1, float scaley = 1); // 设置缩放
	void SetisSrc(bool issrc);
	void Draw(Vector2 pagepos); // 绘制图片
};