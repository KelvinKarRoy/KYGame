#pragma once
/*
	身份验证页面
*/
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI相关的头文件 
#include "cocostudio/CocoStudio.h"//在CocosStudio.h 头文件中已经包含了Studio所需要的各个头文件(除CocosGUI)因此我们使用Studio仅需要包含他就可以 

#include "RegeditScene.h"
#include "../utility/HttpUtility.h"

using namespace cocos2d;
using namespace cocos2d::ui;


class AuthenticationScene :public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	enum STATUS{
		LINK_ERROR,//服务器连接异常
		ANSWER_ERROR//答案错误
	};

	//实现 static create()函数的宏
	CREATE_FUNC(AuthenticationScene);

	void setQuestion(std::pair<std::vector<std::string>, std::vector<std::string>> question_answer)
	{
		this->question_answer = question_answer;
		this->updateQuestion();
	};

	void promptDialogBox(std::string str, AuthenticationScene::STATUS status);//弹出提示框，第二个参数为状态

private:
	Layer* childLayer;//子层
	void updateQuestion();
	Node* rootNode;
	std::pair<std::vector<std::string>, std::vector<std::string>> 
		question_answer;//验证问题及答案 key为问题的vector value为答案的vector
	

	void clickGiveupCallback(Ref*, TouchEventType type);//放弃按钮回调函数
	void clickSubmitCallback(Ref*, TouchEventType type);//提交按钮回调函数

	bool checkAnswer();//检查答案是否正确
};

