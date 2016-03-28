//
//  MailListScene.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/21.
//
//

#ifndef MailListScene_hpp
#define MailListScene_hpp

#include "../interface/Httpable.hpp"

#include "DialogLayer.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;

class MailListScene :public Httpable
{
public:
    MailListScene();
    ~MailListScene();
    
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(MailListScene);
    
    struct Mail
    {
        std::string m_title;
        std::string m_text;
        std::string m_time;
        int m_senderID;
        int m_Money;
        int m_clothID;
        int m_cardID;
        int m_mailID;
    };//mail结构体
    
    void setMail(std::vector<Mail> mails){ this->mails = mails; }
    
    void updateMails();
    
    void onUpdateInfo() {};
    
    //弹出对话框
    void promptDialogBox(std::string str,DialogLayer::DialogType type =
                         DialogLayer::DialogType::OKDIALOG)
    {
        childLayer = DialogLayer::create();
        ((DialogLayer*)childLayer)->setText(str);//弹出对话框
        this->addChild((DialogLayer*)childLayer);
    }
    
private:
    cocos2d::Node* rootNode;
    
    
    std::vector<Mail> mails;
    Mail* mail;//正在展示的mail
    //back按钮回调
    void onBackClicked(Ref*,TouchEventType type);
    void clickBackCallback(Ref*, TouchEventType type);//点击layer的返回键
    //点击mail回调
    void clickMailCallback(Ref*,TouchEventType type);
    void clickGetCallback(Ref*,TouchEventType type);//领取衣服.卡片，金钱
};

#endif /* MailListScene_hpp */
