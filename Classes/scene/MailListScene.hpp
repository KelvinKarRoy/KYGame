//
//  MailListScene.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/21.
//
//

#ifndef MailListScene_hpp
#define MailListScene_hpp

#include "../interface/Promptable.hpp"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;

class MailListScene : public Promptable
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
    
private:
    cocos2d::Node* rootNode;
    
    std::vector<Mail> mails;
    Mail* mail;//正在展示的mail
    //back按钮回调
    void onBackClicked(Ref*,TouchEventType type);
    void clickBackCallback(Ref*, TouchEventType type);//点击layer的返回键
    //点击mail回调
    void clickMailCallback(Ref*,TouchEventType type);
    void clickClothCallback(Ref*,TouchEventType type);//领取衣服
    void clickCardCallback(Ref*,TouchEventType type);//领取卡片
    void clickMoneyCallback(Ref*,TouchEventType type);//领取金钱
    
};

#endif /* MailListScene_hpp */
