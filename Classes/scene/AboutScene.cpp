#include "AboutScene.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;

Scene* AboutScene::createScene(Layer* callerLayer)
{
	auto scene = Scene::create();
	
	auto layer = AboutScene::create();
    
    layer->callerLayer = callerLayer;

	scene->addChild(layer);

	return scene;
}

bool AboutScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	/*ªÒ»°∆¡ƒª¥Û–°*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/**************º”‘ÿUI***************/
	rootNode = CSLoader::createNode("csb/AboutScene.csb");
	
	//µ˜’˚UI¥Û–°
	rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
	
	this->addChild(rootNode);

	auto aboutPanel = rootNode->getChildByName("Panel_about");

	Button* backbtn = (Button*) aboutPanel->getChildByName("Button_back");

	backbtn->addTouchEventListener(this,toucheventselector(AboutScene::clickBackCallback));

    //吞噬下层事件
    auto callback = [](cocos2d::Touch * ,cocos2d::Event *)
    {
        return true;
    };
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = callback;
    listener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    
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
            this->callerLayer->removeChildByName("about");
            break;
        case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
}

