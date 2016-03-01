#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__
/*
	登录页面
*/

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI相关的头文件 
#include "cocostudio/CocoStudio.h"//在CocosStudio.h 头文件中已经包含了Studio所需要的各个头文件(除CocosGUI)因此我们使用Studio仅需要包含他就可以 

#include "cocos-ext.h"
//一些相关页面
#include "AboutScene.h"
#include "RegeditScene.h"
#include "AuthenticationScene.h"
#include "DialogLayer.h"
#include "HttpUtility.h"
#include "utility.h"
#include "StringUtility.h"


using namespace cocos2d::ui;

class LogInScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	//实现 static create()函数的宏
	CREATE_FUNC(LogInScene);

	void promptDialogBox(std::string strInfo);//弹出提示对话框

private:
	Node* rootNode;
	Layer* childLayer;//各种页面
	void clickAboutCallback(Ref*, TouchEventType type);//关于按钮回调函数
	void clickLoginCallback(Ref*, TouchEventType type);//登录按钮回调函数
	void clickRegeditCallback(Ref*, TouchEventType type);//注册按钮回调函数




	

};










#endif //__LOGIN_SCENE_H__


