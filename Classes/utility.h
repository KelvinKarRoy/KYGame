#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"//UI相关的头文件 

USING_NS_CC;
using namespace cocos2d::ui;


class utility
{
public:
	static bool isStringLegal(std::string str);//账号密码是否合法
	static bool isNameLegal(std::string str);//昵称是否合法
	virtual ~utility();
	static void setTextAuto(Text* text);//自动换行
	static void setEnable(bool flag, Layer* layer);//屏蔽事件
private:
	utility();
};




