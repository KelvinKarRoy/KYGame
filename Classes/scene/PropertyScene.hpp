//
//  PropertyScene.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/1.
//
//  人物属性页面，气死了 本来年前就解决了的 妈蛋的！

#ifndef PropertyScene_hpp
#define PropertyScene_hpp

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI读取类
#include "cocostudio/CocoStudio.h"//‘⁄CocosStudio.h

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "../sqlite/sqlite3.h"
//#include "../sqlite/sqlite3.c"
#else
#include "sqlite3.h"
#endif

#include "../model/Player.h"
#include "../model/Self.h"
using namespace cocos2d;
using namespace cocos2d::ui;



using namespace cocos2d;


class PropertyScene :
public Layer
{
public:
    PropertyScene();
    ~PropertyScene();
    
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(PropertyScene);
    
private:
    Layer* childLayer;//子层
    
    Node* rootNode;//csb
    
    Player* player;//要展示的人
    
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
    
    void setPlayer(Player* player)
    {
        this->player = player;
    }
    
    void onBackClicked(Ref*, TouchEventType type);
    
    //读取各属性值
    void loadPeoperty();
    
    //填写属性
    void fillText();
    
    //画雷达图
    void drawRadar();
    
};




#endif /* PropertyScene_hpp */
