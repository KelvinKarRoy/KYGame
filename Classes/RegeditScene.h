#pragma once
/*
	ע��ҳ��
*/
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI��ص�ͷ�ļ� 
#include "cocostudio/CocoStudio.h"//��CocosStudio.h ͷ�ļ����Ѿ�������Studio����Ҫ�ĸ���ͷ�ļ�(��CocosGUI)�������ʹ��Studio����Ҫ�������Ϳ��� 

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
		ACCOUNTEXIST,//�˺��Ѵ���
		SUCCEED,//ע��ɹ�
		LINK_ERROR//���������Ӵ���
	};


	static Scene* createScene();

	virtual bool init();

	//ʵ�� static create()�����ĺ�
	CREATE_FUNC(RegeditScene);

	void promptDialogBox(std::string text,RegeditScene::STATUS status);

	void promptDialogBox(std::string str);
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

