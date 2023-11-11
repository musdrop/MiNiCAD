#include <iostream>
#include <vector>
#include "Page.h"
using namespace std;
ExMessage msg = {0};
int main()
{
	initgraph(320, 568, EX_SHOWCONSOLE);
	setbkcolor(RGB(85, 177, 85));
	cleardevice();
	setbkmode(TRANSPARENT);

	Page page1(10, 84, 300, 300);
	IMAGE img2;
	loadimage(&img2, _T("../assets/ty.png"), 50, 50);

	// 创建 200x200 的 img 对象
	IMAGE img3(200, 200);
	// 设置绘图目标为 img 对象
	SetWorkingImage(&img3);
	// 以下绘图操作都会绘制在 img 对象上面
	setlinecolor(RGB(255, 0, 0));
	line(0, 100, 250, 100);
	line(100, 0, 100, 200);
	circle(100, 100, 50);
	fillcircle(100, 100, 25);
	// 设置绘图目标为绘图窗口
	SetWorkingImage();

	Image im1("../assets/plane.jpg", getwidth() / 2, getheight() / 2);
	Image im2(img2, 34, 27);
	Image im3(img3, 10, 10);
	im3.SetisSrc(false);
	page1.AddUIElement(&im1);
	page1.AddUIElement(&im2);
	page1.AddUIElement(&im3);
	while (true)
	{
		peekmessage(&msg, EX_MOUSE | EX_KEY);
		Vector2 msgpos(msg.x, msg.y, page1.position);
		im2.position += (msgpos - im2.position) / 1000;
		page1.DrawPage();
	}

	getchar();
}