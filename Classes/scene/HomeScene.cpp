//
//  HomeScene.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/7.
//
//

#include "HomeScene.hpp"
#include "LogInScene.h"


HomeScene::HomeScene()
{
}
HomeScene::~HomeScene()
{
}


Scene* HomeScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = HomeScene::create();
    
    scene->addChild(layer);
    
    return scene;
    
}


bool HomeScene::init()
{
    if(!Layer::init())
    {
        return false;
    }

    /*获取屏幕大小*/
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    /**************加载UI***************/
    rootNode = cocos2d::CSLoader::createNode("csb/HomeScene.csb");
    //调整UI大小
    rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
    
    this->addChild(rootNode);
    
    auto exitButton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Button_exit"));

    exitButton->addTouchEventListener(this,toucheventselector(HomeScene::onExitClicked));
    
    
    return true;
}


void HomeScene::onExitClicked(Ref*,TouchEventType type)
{
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            break;
        case TouchEventType::TOUCH_EVENT_CANCELED:
            break;
        case TouchEventType::TOUCH_EVENT_ENDED:
            Director::getInstance()->replaceScene(LogInScene::createScene());//切换到登录页面
            break;
        case TouchEventType::TOUCH_EVENT_MOVED:
            break;
    }
    
}
