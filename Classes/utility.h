#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"//UI��ص�ͷ�ļ� 

USING_NS_CC;
using namespace cocos2d::ui;


class utility
{
public:
	static bool isStringLegal(std::string str);//�˺������Ƿ�Ϸ�
	static bool isNameLegal(std::string str);//�ǳ��Ƿ�Ϸ�
	virtual ~utility();
	static void setTextAuto(Text* text);//�Զ�����
	static void setEnable(bool flag, Layer* layer);//�����¼�
private:
	utility();
};




