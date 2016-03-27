//
//  HomeScene.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/7.
//
//

#include "HomeScene.hpp"
#include "LogInScene.h"
#include "MenuLayer.hpp"

#include "../model/Self.h"

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
    
    this->addChild(MenuLayer::create());//添加菜单layer
    
    
    //登出按钮及回调
    auto exitButton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Button_exit"));

    exitButton->addTouchEventListener(this,toucheventselector(HomeScene::onExitClicked));
    
    //加载玩家信息
    HttpUtility::getInstance(this)->loadPlayerInformation(Self::getInstance()->getPlayerID(), Self::getInstance());
    
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

//更新信息
void HomeScene::onUpdateInfo()
{
    //升级进度条
    auto expLoadingBar = static_cast<cocos2d::ui::LoadingBar*>(rootNode->getChildByName("LoadingBar_exp"));
    expLoadingBar->setPercent(100*Self::getInstance()->getExpRate());
   
    //填写对应信息
    char temp[40];
    sprintf(temp,"昵称:%s (%d)",Self::getInstance()->getName().c_str(),Self::getInstance()->getPlayerID());
    static_cast<Text*>(rootNode->getChildByName("Panel_info")->getChildByName("Text_name"))->setString(temp);
    
    sprintf(temp,"等级:%d",Self::getInstance()->getLevel());
    static_cast<Text*>(rootNode->getChildByName("Panel_info")->getChildByName("Text_level"))->setString(temp);
    
    sprintf(temp,"经验:%d",Self::getInstance()->getExp());
    static_cast<Text*>(rootNode->getChildByName("Panel_info")->getChildByName("Text_exp"))->setString(temp);
    
    sprintf(temp,"饥饿:%d",Self::getInstance()->getVP());
    static_cast<Text*>(rootNode->getChildByName("Panel_info")->getChildByName("Text_VP"))->setString(temp);
    
    sprintf(temp,"蟹圆币:%d",Self::getInstance()->getMoney());
    static_cast<Text*>(rootNode->getChildByName("Panel_info")->getChildByName("Text_money"))->setString(temp);
    
    
    
    
    
}
