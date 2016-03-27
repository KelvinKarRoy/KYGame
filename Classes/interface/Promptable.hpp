//
//  Promptable.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/16.
//
//  可以弹出对话框的接口


#ifndef Promptable_hpp
#define Promptable_hpp

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI读取类
#include "cocostudio/CocoStudio.h"//‘⁄CocosStudio.h Õ∑Œƒº˛÷–“—æ≠∞¸∫¨¡ÀStudioÀ˘–Ë“™µƒ∏˜∏ˆÕ∑Œƒº˛(≥˝CocosGUI)“Ú¥ÀŒ“√« π”√StudioΩˆ–Ë“™∞¸∫¨À˚æÕø…“‘

class Promptable
{
public:
    virtual void promptDialogBox(std::string strInfo) = 0;//弹出对话框
    Promptable() {};
    virtual ~Promptable() {};
    cocos2d::Layer* childLayer;//子层
};

#endif /* Promptable_hpp */
