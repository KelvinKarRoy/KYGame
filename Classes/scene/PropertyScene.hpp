//
//  PropertyScene.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/1.
//
//  人物属性页面，气死了 本来年前就解决了的 妈蛋的！

#ifndef PropertyScene_hpp
#define PropertyScene_hpp


#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "../sqlite/sqlite3.h"
//#include "../sqlite/sqlite3.c"
#else
#include "sqlite3.h"
#endif

#include "../model/Player.h"
#include "../model/Self.h"

#include "../interface/Promptable.hpp"

using namespace cocos2d;
using namespace cocos2d::ui;



using namespace cocos2d;


class PropertyScene :public Promptable
{
public:
    PropertyScene();
    ~PropertyScene();
    
    static Scene* createScene();
    
    virtual bool init();
    
    void setPlayer(Player* player)
    {
        this->player = player;
    }
    Player* getPlayer() { return this->player; }
    
    CREATE_FUNC(PropertyScene);
    
    static PropertyScene* create(int playerID)
    {
        PropertyScene *pRet = new(std::nothrow) PropertyScene();
        if(Self::getInstance()->getPlayerID() == playerID)
        {
            pRet->setPlayer(Self::getInstance());
        }else
        {
            pRet->setPlayer(&onePlayer);
            onePlayer.setPlayerID(playerID);
        }
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }
    
    void redraw();//重绘
    
private:
    Layer* childLayer;//子层
    
    Node* rootNode;//csb
    
    Player* player;//要展示的人
    static Player onePlayer;//实例
    
    //各属性值
    std::map<Player::ATTRIBUTE,int> attributes;
    int id;
    int cpid;
    int cardid;
    int clothid;
    int exp;
    int honor;
    int level;
    int money;
    std::string name;
    bool role;
    bool top;
    
    void onBackClicked(Ref*, TouchEventType type);
    
    //读取各属性值
    void loadPeoperty();
    
    //填写属性
    void fillText();
    
    //画雷达图
    void drawRadar();
    
    //判断是否可以加点
    bool isAddable();
    
    //enable（参数为true）或unable（参数为false）加点按钮
    void enableAddButtons(bool isAddable);
    
    //判断是否有加点
    bool isPropertyChanged();
    
    //点击了加点按钮
    void onAddClicked(Ref*, TouchEventType type);

    //点击了加点确定按钮
    void onOKClicked(Ref*, TouchEventType type);
    
    //点击了加点取消按钮
    void onCancelClicked(Ref*, TouchEventType type);
};




#endif /* PropertyScene_hpp */
