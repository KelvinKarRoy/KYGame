//
//  FriendListScene.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/25.
//
//

#ifndef FriendListScene_hpp
#define FriendListScene_hpp

#include "../interface/Promptable.hpp"

using namespace cocos2d;
using namespace cocos2d::ui;

class FriendListScene : public Promptable
{
public:
    FriendListScene();
    ~FriendListScene();
    
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(FriendListScene);
    
    struct Friend
    {
        int m_ID;//玩家ID
        int m_level;//玩家等级
        int m_honor;//玩家荣誉
        std::string m_name;//玩家昵称
    };//friend结构体
    
    
    void setFriends(std::vector<Friend> friends){ this->friends = friends; }
    
    void updateFriends();
    
private:
    cocos2d::Node* rootNode;
    
    cocos2d::ui::Layout* buttonPanel;
    
    int showPlayerID;//展示的playerID
    
    
    std::vector<Friend> friends;
    //back按钮回调
    void clickBackCallback(Ref*,TouchEventType type);
    
    //点击friend回调
    void clickFriendCallback(Ref*,TouchEventType type);
    
    //点击查看属性
    void clickPropertyCallback(Ref*,TouchEventType type);
    
};




#endif /* FriendListScene_hpp */
