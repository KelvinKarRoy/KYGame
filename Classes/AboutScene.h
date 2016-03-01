#pragma once
/*
	关于页面层
*/
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI相关的头文件 
#include "cocostudio/CocoStudio.h"//在CocosStudio.h 头文件中已经包含了Studio所需要的各个头文件(除CocosGUI)因此我们使用Studio仅需要包含他就可以 


using namespace cocos2d;
using namespace cocos2d::ui;


class AboutScene :public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	//实现 static create()函数的宏
	CREATE_FUNC(AboutScene);

private:
	Node* rootNode;//csb

	void clickBackCallback(Ref*, TouchEventType type);
};

