#include <iostream>
#include <easyx.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
ExMessage msg = { 0 };

//判断鼠标是否在按钮里面
bool inArea(int x, int y, int rx, int ry, int w, int h)
{
	if (x > rx && x<rx + w && y>ry && y < ry + h)
		return true;
	return false;
}

//制作一个按钮
bool button(int x, int y, int w, int h, const char* text)
{
	//按钮颜色
	if (inArea(msg.x, msg.y, x, y, w, h))
	{
		setfillcolor(RGB(93, 107, 153));
	}
	else
	{
		setfillcolor(RGB(230, 231, 232));
	}
	//绘制按钮
	fillroundrect(x, y, x + w, y + h, 5, 5);
	//绘制按钮文本
	int hSpace = (w - textwidth(text)) / 2;
	int vSpace = (h - textheight(text)) / 2;
	settextcolor(BLACK);
	outtextxy(x + hSpace, y + vSpace, text);
	//判断按钮是否被点击
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h))
	{
		return true;
	}
	return false;
}

int main()
{
	//播放音乐
	mciSendString("open  assets/planemusic2.wav alias bgm", NULL, 0, NULL);
	mciSendString("play bgm", NULL, 0, NULL);
	mciSendString("setaudio bgm volume to 50", NULL, 0, NULL);

	initgraph(320, 568, EX_SHOWCONSOLE| EX_DBLCLKS);
	setbkcolor(RGB(85, 177, 85));
	cleardevice();
	setbkmode(TRANSPARENT);

	const int frameDelay =50;
	int frameStart = 0;
	int frameTime = 0;

	while (true)
	{
		frameStart = clock();

		if (peekmessage(&msg, EX_MOUSE | EX_KEY))
		{
		}

		//双缓冲区域，绘图语句写在这里面
		BeginBatchDraw();
		cleardevice();

		//载入图片
		IMAGE img_mm;
		loadimage(&img_mm, "assets/plane.jpg");
		putimage(0, 0, &img_mm);


		if (button(80,250, 150, 35, "Start Game"))
		{
			cout << "Start Game" << endl;
			//加入要执行的函数
		}
		if (button(80,300, 150, 35, "menus"))
		{
			cout << "menus" << endl;
			//加入要执行的函数
		}
		if (button(80, 350, 150, 35, "End Game"))
		{
			cout << "End Game" << endl;
			//加入要执行的函数
		}
		EndBatchDraw();

		frameTime = clock() - frameStart;
		if (frameDelay - frameTime > 0)
		{
			Sleep(frameDelay - frameTime);
		}
		msg.message = 0;
	}
	getchar();
	return 0;
}
