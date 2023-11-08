#include <iostream>
#include <vector>
#include "Page.h"
using namespace std;
ExMessage msg = {0};
int main()
{
	initgraph(320, 568, 0);
	initgraph(320, 568, EX_SHOWCONSOLE);
	setbkcolor(RGB(85, 177, 85));
	cleardevice();
	setbkmode(TRANSPARENT);

	IMAGE img1, img2;
	loadimage(&img1,_T("../assets/plane.jpg"));
	loadimage(&img2,_T("../assets/qq.jpg"),20,30);

	//Image im1(img1, getwidth()/2, getheight()/2);
	Image im2(img2, 34, 27);
	Image im3("../assets/plane.jpg", 0, 0);
	Page page1(0,0);
	page1.AddUIElement(&im3);
	page1.AddUIElement(&im2);
	page1.DrawPage();
	while (true)
	{
		peekmessage(&msg, EX_MOUSE | EX_KEY);
		Vector2 msgpos(msg.x, msg.y);
		im2.position += (msgpos - im2.position) / 10000;
		page1.DrawPage();
	}

	getchar();
}