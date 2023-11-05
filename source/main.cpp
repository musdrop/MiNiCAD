#include <iostream>
#include <vector>
#include "Page.h"
using namespace std;
ExMessage msg = { 0 };
int main()
{
	initgraph(320, 568, EX_SHOWCONSOLE);
	setbkcolor(RGB(85, 177, 85));
	cleardevice();
	setbkmode(TRANSPARENT);

	IMAGE img1,img2;
	loadimage(&img1,"");
	loadimage(&img2, "../assets/qq.jpg",20,30);

	Image im1(img1, 0, 0);
	Image im2(img2, 34, 27);
	Page page1(4,20);
	page1.AddUIElement(&im1);
	page1.AddUIElement(&im2);
	while (true)
	{
		peekmessage(&msg, EX_MOUSE | EX_KEY);
		Vector2 msgpos(msg.x,msg.y);
		im2.position += (msgpos-im2.position)/10000;
		page1.DrawPage();
	}
	
	getchar();
}