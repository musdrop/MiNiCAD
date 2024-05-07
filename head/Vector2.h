#pragma once
#include <cmath>
#include <iostream>
//二维量
class Vector2
{
public:
	float x;
	float y;
	Vector2(float x=0, float y=0)
	{
		this->x = x;
		this->y = y;
	}
	Vector2(float x,float y,const Vector2& pagepos)//窗口坐标转换成页面坐标
	{
		this->x = x - pagepos.x;
		this->y = y - pagepos.y;
	}
	Vector2 operator+(Vector2& pos)
	{
		Vector2 res;
		res.x = x + pos.x;
		res.y = y + pos.y;
		return res;
	}
	Vector2 operator-(Vector2& pos)
	{
		Vector2 res;
		res.x = x - pos.x;
		res.y = y - pos.y;
		return res;
	}
	Vector2 operator/(float div)
	{
		Vector2 res;
		res.x = x/div;
		res.y = y/div;
		return res;
	}
	Vector2 operator+=(Vector2& pos)
	{
		this->x = x + pos.x;
		this->y = y + pos.y;
		return *this;
	}
	Vector2 operator+=(Vector2&& pos)
	{
		this->x = x + pos.x;
		this->y = y + pos.y;
		return *this;
	}
	float length()
	{
		return sqrtf(x * x + y * y);
	}
};

