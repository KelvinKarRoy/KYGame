//
//  MailListScene.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/21.
//
//

#include "MailListScene.hpp"
#include "../utility/HttpUtility.h"
#include "HomeScene.hpp"

MailListScene::MailListScene()
{
    
}
MailListScene::~MailListScene()
{
}


Scene* MailListScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MailListScene::create();
    
    scene->addChild(layer);
    
    return scene;
    
}


bool MailListScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    /*获取屏幕大小*/
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    /**************加载UI***************/
    rootNode = cocos2d::CSLoader::createNode("csb/MailListScene.csb");
    
    //调整UI大小
    rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
    
    this->addChild(rootNode);
    
    auto backButton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Button_back"));
    
    backButton->addTouchEventListener(this,toucheventselector(MailListScene::onBackClicked));
    
    //获取公告
    HttpUtility::getInstance(this)->loadMail();
    
    
    
    
    return true;
}



void MailListScene::onBackClicked(Ref*,TouchEventType type)
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



//更新邮件
void MailListScene::updateMails()
{
    //获取mails容器
    auto mailPanel = static_cast<cocos2d::ui::Layout*>(rootNode->getChildByName("Panel_mail"));
    
    auto mailList = static_cast<cocos2d::ui::ListView*>(mailPanel->getChildByName("ListView_mail"));
    
    //清空内容
    mailList->removeAllChildren();
    
    cocos2d::Size size = mailList->getContentSize();
    
    float width = size.width,height = size.height;
    
    //设置间隔
    mailList->setItemsMargin(height/18);
    
    //最前面加一点空白
    Text* whiteText = Text::create();
    whiteText->setString(" ");
    whiteText->cocos2d::Node::setContentSize(cocos2d::Size(width,height/18));
    mailList->addChild(whiteText);
    
    //设置回弹
    mailList->setBounceEnabled(true);
    
    for(int i=0;i<mails.size();++i)
    {
        //横向排列，这里类似Android里的线性布局
        mailList->setLayoutType(LAYOUT_LINEAR_VERTICAL);
        
        cocos2d::ui::Button* mailButton = cocos2d::ui::Button::create();
        
        mailButton->setContentSize(cocos2d::Size(width,height/6));
        
        std::string str =mails[i].m_title + "    (" + mails[i].m_time + ")";
        
        mailButton->setTitleText(str);
        
        mailButton->setTitleColor(cocos2d::Color3B(100,200,200));
        
        mailButton->setTitleFontName("wending.TTF");
        
        mailButton->setTitleFontSize(height/15);
        
        mailButton->setPressedActionEnabled(true);  //设置按钮是否启用点击缩放的效果
        mailButton->setOpacity(100); //继承自node，设置node透明度，0完全透明，100完全不透明
        
        mailButton->setColor(Color3B::BLUE);
        
        mailList->addChild(mailButton);
        
        //为按钮加个名字
        std::string buttonName = "mail";
        char temp[5];
        sprintf(temp,"%d", i);
        buttonName += temp;
        mailButton->setName(buttonName);
        
        //为按钮设置回调
        mailButton->addTouchEventListener(this,toucheventselector(MailListScene::clickMailCallback));
    }
    
}


//点击layer的返回键
void MailListScene::clickBackCallback(Ref*, TouchEventType type)
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
            this->removeChildByName("mailTextLayer");
            break;
            
    }
}

//点击公告回调
void MailListScene::clickMailCallback(Ref* caller,TouchEventType type)
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
            /*获取屏幕大小*/
            cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
            cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
            
            /**************加载UI***************/
            Node* childLayer = cocos2d::CSLoader::createNode("csb/MailTextLayer.csb");
            
            //调整UI大小
            childLayer->setScale(visibleSize.width / childLayer->getContentSize().width, visibleSize.height / childLayer->getContentSize().height);
            
            this->addChild(childLayer);
            
            //给mailLayer一个名字
            childLayer->setName("mailTextLayer");
            
            //获取按钮 绑定回调
            auto backButton = static_cast<cocos2d::ui::Button*>(childLayer->getChildByName("Panel_mail")-> getChildByName("Button_back"));
            
            backButton->addTouchEventListener(this,toucheventselector(MailListScene::clickBackCallback));

            auto sendButton = static_cast<cocos2d::ui::Button*>(childLayer->getChildByName("Panel_mail")->getChildByName("Button_send"));
            
            sendButton->setVisible(false);
            
            //这是第几个邮件
            char temp[20];
            
            strcpy(temp,static_cast<Node*>(caller)->getName().c_str());
            
            int index = atoi(temp+4);
            
            //获取mail
            mail = &mails[index];
            
            
            //获取并设置文本
            TextField* titleText = static_cast<TextField*>(childLayer->getChildByName("Panel_mail")->getChildByName("Panel_title")->getChildByName("TextField_title"));
            titleText->setEnabled(false);
            titleText->setString(mail->m_title);
            
            TextField* senderText = static_cast<TextField*>(childLayer->getChildByName("Panel_mail")->getChildByName("Panel_playerID")->getChildByName("TextField_playerID"));
            senderText->setEnabled(false);
            sprintf(temp, "%d",mail->m_senderID);
            senderText->setString(temp);
            
            TextField* textTF = static_cast<TextField*>(childLayer->getChildByName("Panel_mail")->getChildByName("Panel_text")->getChildByName("TextField_text"));
            textTF->setEnabled(false);
            textTF->setString(mail->m_text);
            
            /*********设置衣服 卡牌 钱按钮************/
            Button* clothButton = static_cast<Button*>(childLayer->getChildByName("Panel_mail")->getChildByName("Button_clothID"));
            //设置纹理
            sprintf(temp,"scloth%d.png",mail->m_clothID);
            clothButton->loadTextureNormal(temp);
            clothButton->loadTexturePressed(temp);
            if(mail->m_clothID == 0) clothButton->setEnabled(false);
            else clothButton->setEnabled(true);
            clothButton->addTouchEventListener(this,toucheventselector(MailListScene::clickGetCallback));
            
            Button* cardButton = static_cast<Button*>(childLayer->getChildByName("Panel_mail")->getChildByName("Button_cardID"));
            //设置纹理
            sprintf(temp,"scard%d.png",mail->m_cardID);
            cardButton->loadTextureNormal(temp);
            cardButton->loadTexturePressed(temp);
            if(mail->m_cardID == 0) cardButton->setEnabled(false);
            else cardButton->setEnabled(true);
            cardButton->addTouchEventListener(this,toucheventselector(MailListScene::clickGetCallback));
            
            
            Button* moneyButton = static_cast<Button*>(childLayer->getChildByName("Panel_mail")->getChildByName("Button_money"));
            //设置纹理
            moneyButton->loadTextureNormal("scard0.png");
            moneyButton->loadTexturePressed("scard0.png");
            moneyButton->loadTextureDisabled("scard0.png");
            sprintf(temp, "%d",mail->m_Money);
            if(mail->m_Money == 0) moneyButton->setEnabled(false);
            else moneyButton->setEnabled(true);
            moneyButton->setTitleText(temp);
            moneyButton->addTouchEventListener(this,toucheventselector(MailListScene::clickGetCallback));
            
            
            //吞噬下层事件
            auto callback = [](cocos2d::Touch * ,cocos2d::Event *)
            {
            return true;
            };
            auto listener = cocos2d::EventListenerTouchOneByOne::create();
            listener->onTouchBegan = callback;
            listener->setSwallowTouches(true);
            _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,childLayer);

            
            
            break;
            
    }
    
}

void MailListScene::clickGetCallback(Ref* callerButton,TouchEventType type)//领取衣服
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
            HttpUtility::getInstance(this)->getStuff(mail->m_clothID,mail->m_cardID,mail->m_Money,mail->m_mailID);
            mail->m_clothID=0;
            mail->m_cardID=0;
            mail->m_Money=0;
            break;
            
    }
}







