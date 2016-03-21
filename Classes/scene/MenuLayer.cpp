//
//  MenuLayer.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/17.
//
//

#include "MenuLayer.hpp"
#include "PropertyScene.hpp"
#include "NoticeScene.hpp"
#include "MailListScene.hpp"


MenuLayer::MenuLayer()
{
}


MenuLayer::~MenuLayer()
{
}


cocos2d::Scene* MenuLayer::createScene()
{
    auto scene = cocos2d::Scene::create();
    
    auto layer = MenuLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool MenuLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    /*获取大小*/
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    /**************读取UI***************/
    rootNode = cocos2d::CSLoader::createNode("csb/MenuLayer.csb");
    
    //设置UI大小
    rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
    
    addChild(rootNode);
    
    //菜单按钮回调
    auto propertyButton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Panel_menu")->getChildByName("Button_property"));
    propertyButton->addTouchEventListener(this,toucheventselector(MenuLayer::clickPropertyCallback));
    
    auto noticeButton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Panel_menu")->getChildByName("Button_notice"));
    noticeButton->addTouchEventListener(this,toucheventselector(MenuLayer::clickNoticeCallback));
    
    auto mailButton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Panel_menu")->getChildByName("Button_mail"));
    mailButton->addTouchEventListener(this,toucheventselector(MenuLayer::clickMailCallback));
    
    return true;
}



//点击属性按钮
void MenuLayer::clickPropertyCallback(Ref*, TouchEventType type)
{
    
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            break;
        case TouchEventType::TOUCH_EVENT_CANCELED:
            break;
        case TouchEventType::TOUCH_EVENT_ENDED:
            cocos2d::Director::getInstance()->replaceScene(PropertyScene::createScene());//切换到属性页面
            break;
        case TouchEventType::TOUCH_EVENT_MOVED:
            break;
    }
    
}

//点击公告按钮
void MenuLayer::clickNoticeCallback(Ref*, TouchEventType type)
{
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            break;
        case TouchEventType::TOUCH_EVENT_CANCELED:
            break;
        case TouchEventType::TOUCH_EVENT_ENDED:
            cocos2d::Director::getInstance()->replaceScene(NoticeScene::createScene());//切换到公告页面
            break;
        case TouchEventType::TOUCH_EVENT_MOVED:
            break;
    }
}


//点击邮件按钮
void MenuLayer::clickMailCallback(Ref*, TouchEventType type)
{
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            break;
        case TouchEventType::TOUCH_EVENT_CANCELED:
            break;
        case TouchEventType::TOUCH_EVENT_ENDED:
            cocos2d::Director::getInstance()->replaceScene(MailListScene::createScene());//切换到邮件页面
            break;
        case TouchEventType::TOUCH_EVENT_MOVED:
            break;
    }
}