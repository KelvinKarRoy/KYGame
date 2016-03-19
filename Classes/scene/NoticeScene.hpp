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

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;



class NoticeScene :public Promptable
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
