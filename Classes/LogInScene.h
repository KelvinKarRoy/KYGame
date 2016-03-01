#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__
/*
	��¼ҳ��
*/

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI��ص�ͷ�ļ� 
#include "cocostudio/CocoStudio.h"//��CocosStudio.h ͷ�ļ����Ѿ�������Studio����Ҫ�ĸ���ͷ�ļ�(��CocosGUI)�������ʹ��Studio����Ҫ�������Ϳ��� 

#include "cocos-ext.h"
//һЩ���ҳ��
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

	//ʵ�� static create()�����ĺ�
	CREATE_FUNC(LogInScene);

	void promptDialogBox(std::string strInfo);//������ʾ�Ի���

private:
	Node* rootNode;
	Layer* childLayer;//����ҳ��
	void clickAboutCallback(Ref*, TouchEventType type);//���ڰ�ť�ص�����
	void clickLoginCallback(Ref*, TouchEventType type);//��¼��ť�ص�����
	void clickRegeditCallback(Ref*, TouchEventType type);//ע�ᰴť�ص�����




	

};










#endif //__LOGIN_SCENE_H__


