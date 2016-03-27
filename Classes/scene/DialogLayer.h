#pragma once
/*
	����ҳ���
*/
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI��ص�ͷ�ļ� 
#include "cocostudio/CocoStudio.h"//��CocosStudio.h ͷ�ļ����Ѿ�������Studio����Ҫ�ĸ���ͷ�ļ�(��CocosGUI)�������ʹ��Studio����Ҫ�������Ϳ��� 

#include "../utility/StringUtility.h"

using namespace cocos2d;
using namespace cocos2d::ui;


class DialogLayer :public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	//ʵ�� static create()�����ĺ�
	CREATE_FUNC(DialogLayer);

	//�����ı�
	void setText(std::string text);

	//����ok��ť�Ļص�����
	void setCallback(void(DialogLayer::*ptr)(Ref*, TouchEventType type));
	
	//��ok�ص�loginҳ��Ļص�����
	void clickOKCallbackBackToLogin(Ref*, TouchEventType type);

	void setNextScene(Scene* layer)
	{
		nextScene = layer;
	};


private:
    Layer* callerLayer;
    
	Node* rootNode;//���ص�ui

	Scene* nextScene;//��һ��Ҫȥ��ҳ��   ���Ϊnullprt����ת

	void clickOKCallback(Ref*, TouchEventType type);
};


