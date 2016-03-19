//
//  NoticeScene.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/18.
//
//

#include "../utility/HttpUtility.h"

#include "NoticeScene.hpp"
#include "HomeScene.hpp"


NoticeScene::NoticeScene()
{
}
NoticeScene::~NoticeScene()
{
}


Scene* NoticeScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = NoticeScene::create();
    
    scene->addChild(layer);
    
    return scene;
    
}


bool NoticeScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    /*获取屏幕大小*/
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    /**************加载UI***************/
    rootNode = cocos2d::CSLoader::createNode("csb/NoticeScene.csb");
    
    //调整UI大小
    rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
    
    this->addChild(rootNode);
    
    auto backButton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Button_back"));
    
    backButton->addTouchEventListener(this,toucheventselector(NoticeScene::onBackClicked));
    
    //获取公告
    HttpUtility::getInstance(this)->loadNotice();
    
    
    
    
    return true;
}



void NoticeScene::onBackClicked(Ref*,TouchEventType type)
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



//更新公告
void NoticeScene::updateNotice()
{
    //获取notice容器
    auto noticePanel = static_cast<cocos2d::ui::Layout*>(rootNode->getChildByName("Panel_notice"));
    
    auto noticeList = static_cast<cocos2d::ui::ListView*>(noticePanel->getChildByName("ListView_notice"));
    
    
    cocos2d::Size size = noticeList->getContentSize();
    
    float width = size.width,height = size.height;
    
    //设置间隔
    noticeList->setItemsMargin(height/20);
    
    //设置回弹
    noticeList->setBounceEnabled(true);
    
    for(int i=0;i<notices.size();++i)
    {
        //横向排列，这里类似Android里的线性布局
        noticeList->setLayoutType(LAYOUT_LINEAR_VERTICAL);
        
        cocos2d::ui::Button* noticeButton = cocos2d::ui::Button::create();
        
        noticeButton->setContentSize(cocos2d::Size(width,height/6));
        
        std::string str =notices[i].m_title + "    (" + notices[i].m_time + ")";
        
        noticeButton->setTitleText(str);
        
        noticeButton->setTitleColor(cocos2d::Color3B(100,200,200));
        
        noticeButton->setTitleFontName("wending.TTF");
        
        noticeButton->setTitleFontSize(height/15);
        
        noticeButton->setPressedActionEnabled(true);  //设置按钮是否启用点击缩放的效果
        noticeButton->setOpacity(100); //继承自node，设置node透明度，0完全透明，100完全不透明
        
        noticeButton->setColor(Color3B::BLUE);
        
        noticeList->addChild(noticeButton);
        
        //为按钮加个名字
        std::string buttonName = "notice";
        char temp[5];
        sprintf(temp,"%d", i);
        buttonName += temp;
        noticeButton->setName(buttonName);
        
        //为按钮设置回调
        noticeButton->addTouchEventListener(this,toucheventselector(NoticeScene::clickNoticeCallback));
    }

}


//点击layer的返回键
void NoticeScene::clickBackCallback(Ref*, TouchEventType type)
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
            this->removeChildByName("noticeTextLayer");
            break;
            
    }
}

//点击公告回调
void NoticeScene::clickNoticeCallback(Ref* caller,TouchEventType type)
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
            //获取公告内容
            std::string noticeName = static_cast<cocos2d::ui::Button*>(caller)->getName();
            int index = atoi(noticeName.c_str()+6);
            
            Notice notice = notices[index];
            //显示公告Layer
            /*获取屏幕大小*/
            cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
            cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
            
            /**************加载UI***************/
            auto noticeTextLayer = cocos2d::CSLoader::createNode("csb/NoticeTextLayer.csb");
            
            //调整UI大小
            noticeTextLayer->setScale(visibleSize.width / noticeTextLayer->getContentSize().width, visibleSize.height / noticeTextLayer->getContentSize().height);
            
            this->addChild(noticeTextLayer);
            
            noticeTextLayer->setName("noticeTextLayer");
            
            static_cast<cocos2d::ui::Text*>(static_cast<cocos2d::ui::Layout*>(noticeTextLayer->getChildByName("Panel"))->getChildByName("Text_title"))->setText(notice.m_title);
            
            static_cast<cocos2d::ui::Text*>(static_cast<cocos2d::ui::Layout*>(noticeTextLayer->getChildByName("Panel"))->getChildByName("Text_time"))->setText(notice.m_time);
            
            auto text = static_cast<cocos2d::ui::Text*>(static_cast<cocos2d::ui::ScrollView*>(static_cast<cocos2d::ui::Layout*>(noticeTextLayer->getChildByName("Panel"))->getChildByName("ScrollView_text"))->getChildByName("Text_text"));
            
            text->setString(std::string("    ")+notice.m_text);
            
            //滚动区域
            static_cast<cocos2d::ui::ScrollView*>(static_cast<cocos2d::ui::Layout*>(noticeTextLayer->getChildByName("Panel"))->getChildByName("ScrollView_text"))->setInnerContainerSize( cocos2d::Size( text->getContentSize().width,text->cocos2d::ui::Widget::getContentSize().height));
            
            text->setPositionY(static_cast<cocos2d::ui::ScrollView*>(static_cast<cocos2d::ui::Layout*>(noticeTextLayer->getChildByName("Panel"))->getChildByName("ScrollView_text"))->getInnerContainerSize().height-20);
            
            auto backButton = static_cast<cocos2d::ui::Button*>(noticeTextLayer->getChildByName("Button_back"));
            
            backButton->addTouchEventListener(this,toucheventselector(NoticeScene::clickBackCallback));
            
            //吞噬下层事件
            auto callback = [](cocos2d::Touch * ,cocos2d::Event *)
            {
                return true;
            };
            auto listener = cocos2d::EventListenerTouchOneByOne::create();
            listener->onTouchBegan = callback;
            listener->setSwallowTouches(true);
            _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,noticeTextLayer);
            
            
            break;
        
    }
    
}




