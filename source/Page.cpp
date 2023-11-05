#include "Page.h"

Page::Page(float x,float y)
{
	positon.x = x;
	positon.y = y;
}

void Page::AddUIElement(UIElement* uielement)
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
