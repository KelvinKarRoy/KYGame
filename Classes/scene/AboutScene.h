#pragma once
/*
	����ҳ���
*/
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI��ص�ͷ�ļ� 
#include "cocostudio/CocoStudio.h"//��CocosStudio.h ͷ�ļ����Ѿ�������Studio����Ҫ�ĸ���ͷ�ļ�(��CocosGUI)�������ʹ��Studio����Ҫ�������Ϳ��� 


using namespace cocos2d;
using namespace cocos2d::ui;


class AboutScene :public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	//ʵ�� static create()�����ĺ�
	CREATE_FUNC(AboutScene);

private:
	Node* rootNode;//csb

	void clickBackCallback(Ref*, TouchEventType type);
};

