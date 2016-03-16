#pragma once
/*
	注册页面
*/


#include "DialogLayer.h"

#include "../interface/Promptable.hpp"

using namespace cocos2d;
using namespace cocos2d::ui;



using namespace cocos2d;


class RegeditScene :public Promptable
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

