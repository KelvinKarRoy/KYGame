#pragma once
/*
	ע��ҳ��
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
		ACCOUNTEXIST,//�˺��Ѵ���
		SUCCEED,//ע��ɹ�
		LINK_ERROR//���������Ӵ���
	};


	static Scene* createScene();

	virtual bool init();

	//ʵ�� static create()�����ĺ�
	CREATE_FUNC(RegeditScene);

    
private:
	Layer* childLayer;//��ҳ��

	struct
	{
		std::string account;
		std::string password;
		std::string name;
		bool role;
	}playerInfo;

	Node* rootNode,*childNode;//csb

	Button* karrybtn, *roybtn;

	void onClickBackCallback(Ref*, TouchEventType type);//���ؼ�
	void onClickNextCallback(Ref*, TouchEventType type);//next��
	void onClickKarryCallback(Ref*, TouchEventType type);//ѡ��karry
	void onClickRoyCallback(Ref*, TouchEventType type);//ѡ��roy
	void onClickRegeditCallback(Ref*, TouchEventType type);//ע���

	bool isRegeditLegal();
};

