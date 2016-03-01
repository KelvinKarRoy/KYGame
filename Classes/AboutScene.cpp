#include "AboutScene.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;

Scene* AboutScene::createScene()
{
	auto scene = Scene::create();
	
	auto layer = AboutScene::create();

	scene->addChild(layer);

	return scene;
}

bool AboutScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	/*��ȡ��Ļ��С*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/**************����UI***************/
	rootNode = CSLoader::createNode("csb/AboutScene.csb");
	
	//����UI��С
	rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
	
	this->addChild(rootNode);

	auto aboutPanel = rootNode->getChildByName("Panel_about");

	Button* backbtn = (Button*) aboutPanel->getChildByName("Button_back");

	backbtn->addTouchEventListener(this,toucheventselector(AboutScene::clickBackCallback));

	return true;
}

void AboutScene::clickBackCallback(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:	
		CCLOG("%s", "OK!!!!");
		this->setVisible(false);
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
}

