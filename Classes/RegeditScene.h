#pragma once
/*
	注册页面
*/
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI相关的头文件 
#include "cocostudio/CocoStudio.h"//在CocosStudio.h 头文件中已经包含了Studio所需要的各个头文件(除CocosGUI)因此我们使用Studio仅需要包含他就可以 

#include "DialogLayer.h"

using namespace cocos2d;
using namespace cocos2d::ui;



using namespace cocos2d;


class RegeditScene :
	public Layer
{
public:
	RegeditScene();
	~RegeditScene();


	enum STATUS{
		ACCOUNTEXIST,//账号已存在
		SUCCEED,//注册成功
		LINK_ERROR//服务器连接错误
	};


	static Scene* createScene();

	virtual bool init();

	//实现 static create()函数的宏
	CREATE_FUNC(RegeditScene);

	void promptDialogBox(std::string text,RegeditScene::STATUS status);

	void promptDialogBox(std::string str);
private:
	Layer* childLayer;//子页面

	struct
	{
		std::string account;
		std::string password;
		std::string name;
		bool role;
	}playerInfo;

	Node* rootNode,*childNode;//csb

	Button* karrybtn, *roybtn;

	void onClickBackCallback(Ref*, TouchEventType type);//返回键
	void onClickNextCallback(Ref*, TouchEventType type);//next键
	void onClickKarryCallback(Ref*, TouchEventType type);//选择karry
	void onClickRoyCallback(Ref*, TouchEventType type);//选择roy
	void onClickRegeditCallback(Ref*, TouchEventType type);//注册键

	bool isRegeditLegal();
};

