#pragma once
/*
	�����֤ҳ��
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

	enum STATUS{
		LINK_ERROR,//�����������쳣
		ANSWER_ERROR//�𰸴���
	};

	//ʵ�� static create()�����ĺ�
	CREATE_FUNC(AuthenticationScene);

	void setQuestion(std::pair<std::vector<std::string>, std::vector<std::string>> question_answer)
	{
		this->question_answer = question_answer;
		this->updateQuestion();
	};

	void promptDialogBox(std::string str, AuthenticationScene::STATUS status);//������ʾ�򣬵ڶ�������Ϊ״̬

private:
	Layer* childLayer;//�Ӳ�
	void updateQuestion();
	Node* rootNode;
	std::pair<std::vector<std::string>, std::vector<std::string>> 
		question_answer;//��֤���⼰�� keyΪ�����vector valueΪ�𰸵�vector
	

	void clickGiveupCallback(Ref*, TouchEventType type);//������ť�ص�����
	void clickSubmitCallback(Ref*, TouchEventType type);//�ύ��ť�ص�����

	bool checkAnswer();//�����Ƿ���ȷ
};

