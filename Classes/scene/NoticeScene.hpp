//
//  NoticeScene.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/18.
//
//

#ifndef NoticeScene_hpp
#define NoticeScene_hpp

#include "../interface/Promptable.hpp"

#include "DialogLayer.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;



class NoticeScene :public Httpable
{
public:
    NoticeScene();
    ~NoticeScene();
    
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(NoticeScene);
    
    struct Notice
    {
        std::string m_title;
        std::string m_text;
        std::string m_time;
    };//公告结构体
    
    void setNotice(std::vector<Notice> notices){ this->notices = notices; }
    
    void updateNotice();
    
    void onUpdateInfo() {};
    
    //弹出对话框
    void promptDialogBox(std::string str)
    {
        childLayer = DialogLayer::create();
        ((DialogLayer*)childLayer)->setText(str);//弹出对话框
        this->addChild((DialogLayer*)childLayer);
    }
    
private:
    cocos2d::Node* rootNode;
    
    std::vector<Notice> notices;
    
    //back按钮回调
    void onBackClicked(Ref*,TouchEventType type);
    void clickBackCallback(Ref*, TouchEventType type);//点击layer的返回键
    //点击公告回调
    void clickNoticeCallback(Ref*,TouchEventType type);
    
};



#endif /* NoticeScene_hpp */
