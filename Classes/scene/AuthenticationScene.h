#pragma once
/*
	身份验证页面
*/

#include "RegeditScene.h"
#include "../utility/HttpUtility.h"

#include "../interface/Promptable.hpp"

using namespace cocos2d;
using namespace cocos2d::ui;


class AuthenticationScene :public Promptable
{
public:
	static Scene* createScene();

	virtual bool init();

	
	//实现 static create()函数的宏
	CREATE_FUNC(AuthenticationScene);

	void setQuestion(std::pair<std::vector<std::string>, std::vector<std::string>> question_answer)
	{
		this->question_answer = question_answer;
		this->updateQuestion();
	};

	
private:
	void updateQuestion();
	Node* rootNode;
	std::pair<std::vector<std::string>, std::vector<std::string>> 
		question_answer;//验证问题及答案 key为问题的vector value为答案的vector
	

	void clickGiveupCallback(Ref*, TouchEventType type);//放弃按钮回调函数
	void clickSubmitCallback(Ref*, TouchEventType type);//提交按钮回调函数

	bool checkAnswer();//检查答案是否正确
};

