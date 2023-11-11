#pragma once
#include "UIElement.h"
class Text : public UIElement
{
    //-------------基类公有成员变量
    // 位置position
    // 缩放scale
    // 宽度width
    // 高度height
    //------------
    public:
        void Draw(Vector2 pagepos);
};
void Text::Draw(Vector2 pagepos)
{
    
}