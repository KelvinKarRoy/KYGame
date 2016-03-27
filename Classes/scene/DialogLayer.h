#pragma once
/*
	关于页面层
*/
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI相关的头文件 
#include "cocostudio/CocoStudio.h"//在CocosStudio.h 头文件中已经包含了Studio所需要的各个头文件(除CocosGUI)因此我们使用Studio仅需要包含他就可以 

#include "../utility/StringUtility.h"

using namespace cocos2d;
using namespace cocos2d::ui;


class DialogLayer :public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	//实现 static create()函数的宏
	CREATE_FUNC(DialogLayer);

	//设置文本
	void setText(std::string text);

	//设置ok按钮的回调函数
	void setCallback(void(DialogLayer::*ptr)(Ref*, TouchEventType type));
	
	//按ok回到login页面的回调函数
	void clickOKCallbackBackToLogin(Ref*, TouchEventType type);

	void setNextScene(Scene* layer)
	{
		nextScene = layer;
	};


private:
    Layer* callerLayer;
    
	Node* rootNode;//加载的ui

	Scene* nextScene;//下一个要去的页面   如果为nullprt则不跳转

	void clickOKCallback(Ref*, TouchEventType type);
};


