//
//  FriendListScene.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/25.
//
//

#include "FriendListScene.hpp"

#include "../utility/HttpUtility.h"

#include "HomeScene.hpp"
#include "PropertyScene.hpp"

FriendListScene::FriendListScene()
{
    
}
FriendListScene::~FriendListScene()
{
    buttonPanel->release();
}


Scene* FriendListScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = FriendListScene::create();
    
    scene->addChild(layer);
    
    return scene;
    
}


bool FriendListScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    /*获取屏幕大小*/
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    /**************加载UI***************/
    rootNode = cocos2d::CSLoader::createNode("csb/FriendListScene.csb");
    
    //调整UI大小
    rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
    
    this->addChild(rootNode);
    
    auto backButton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Button_back"));
    
    backButton->addTouchEventListener(this,toucheventselector(FriendListScene::clickBackCallback));
    
    auto friendList = static_cast<cocos2d::ui::ListView*>(rootNode->getChildByName("ListView_friend"));
    buttonPanel = static_cast<cocos2d::ui::Layout*>(friendList->getChildByName("Panel_buttons"));
    
    //组合按钮的回调
    static_cast<Button*>(buttonPanel->getChildByName("Button_property"))->addTouchEventListener(this,toucheventselector(FriendListScene::clickPropertyCallback));
    
    //组合按钮移除
    friendList->removeChild(buttonPanel);
    buttonPanel->retain();
    
    
    //获取公告
    HttpUtility::getInstance(this)->loadFriends();
    
    return true;
}



void FriendListScene::clickBackCallback(Ref*,TouchEventType type)
{
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            break;
        case TouchEventType::TOUCH_EVENT_CANCELED:
            break;
        case TouchEventType::TOUCH_EVENT_ENDED:
            Director::getInstance()->replaceScene(HomeScene::createScene());//切换到主页面
            break;
        case TouchEventType::TOUCH_EVENT_MOVED:
            break;
    }
    
}



//更新friends列表
void FriendListScene::updateFriends()
{
    
    auto friendList = static_cast<cocos2d::ui::ListView*>(rootNode->getChildByName("ListView_friend"));
    //设置间隔
    friendList->setItemsMargin(5);
    //上面留点空间
    auto upocc = Layout::create();
    upocc->setVisible(false);
    upocc->setContentSize(Size(friendList->getContentSize().width,friendList->getContentSize().width/30));
    friendList->addChild(upocc);
    char temp[100];
    for(int index=0;index<friends.size();++index)
    {
        Button* afriendButton = Button::create();
        afriendButton->setContentSize(Size(friendList->getContentSize().width,friendList->getContentSize().height/8));
        afriendButton->setTitleFontSize(52);
        afriendButton->setTitleColor(Color3B(0, 200,180));
        afriendButton->setTitleFontName("wending.TTF");
        afriendButton->setTitleAlignment(TextHAlignment::CENTER,TextVAlignment::CENTER);
        sprintf(temp,"friend%d",friends[index].m_ID);
        afriendButton->setName(temp);
        afriendButton->addTouchEventListener(this,toucheventselector(FriendListScene::clickFriendCallback));
        friendList->addChild(afriendButton);
        sprintf(temp,"ID: %d\t 昵称:%s\t 等级:%d\t 荣誉:%d",friends[index].m_ID,friends[index].m_name.c_str(),friends[index].m_level,friends[index].m_honor);
        afriendButton->setTitleText(temp);
        
        
        //两个按钮间留点空间
        auto bocc = Layout::create();
        bocc->setVisible(false);
        bocc->setContentSize(Size(friendList->getContentSize().width,friendList->getContentSize().height/20));
        friendList->addChild(bocc);
        
    }
    
    
}


//点击friends回调
void FriendListScene::clickFriendCallback(Ref* caller,TouchEventType type)
{
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            break;
        case TouchEventType::TOUCH_EVENT_CANCELED:
            break;
        case TouchEventType::TOUCH_EVENT_MOVED:
            break;
        case TouchEventType::TOUCH_EVENT_ENDED:
            auto friendList = static_cast<cocos2d::ui::ListView*>(rootNode->getChildByName("ListView_friend"));
            auto callerButton = static_cast<Button*>(caller);
            std::string temp = callerButton->getName();
            int playerID = atoi(temp.substr(6,temp.size()-6).c_str());//点击的按钮对应的id
            if(friendList->getChildByName("Panel_buttons") != nullptr)
            {//如果已经存在
                friendList->removeChild(buttonPanel);
                if(showPlayerID != playerID)
                {//点击的是另一个按钮
                    friendList->insertCustomItem(buttonPanel, friendList->getIndex(callerButton)+1);
                    showPlayerID=playerID;
                }
                
            }else
            {//如果木有
                
                friendList->insertCustomItem(buttonPanel, friendList->getIndex(callerButton)+1);
                showPlayerID=playerID;
            }
         
            break;
            
    }
    
}


//点击查看属性
void FriendListScene::clickPropertyCallback(Ref*,TouchEventType type)
{
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            break;
        case TouchEventType::TOUCH_EVENT_CANCELED:
            break;
        case TouchEventType::TOUCH_EVENT_MOVED:
            break;
        case TouchEventType::TOUCH_EVENT_ENDED:
            auto layer = static_cast<PropertyScene*>(PropertyScene::create(showPlayerID));
            auto scene = Scene::create();
            scene->addChild(layer);
            Director::getInstance()->replaceScene(scene);//切换到属性页面
            break;
        
    }
}






