//
//  FoodScene.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/27.
//
//

#ifndef FoodScene_hpp
#define FoodScene_hpp

#include "DialogLayer.h"

#include "../interface/Httpable.hpp"

#include "../model/Player.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;

class FoodScene :public Httpable
{
public:
    FoodScene();
    ~FoodScene();
    
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(FoodScene);
    
    static FoodScene* create(int playerID);
    
    struct Food
    {
        int m_id;
        int m_vp;
        int m_exp;
        int m_honor;
        int m_money;
        std::string m_name;
        std::string m_brief;
    };
    
    vector<Food> foods;
    
    void onUpdateInfo();
    
    //弹出对话框
    void promptDialogBox(std::string str)
    {
        childLayer = DialogLayer::create();
        ((DialogLayer*)childLayer)->setText(str);//弹出对话框
        this->addChild((DialogLayer*)childLayer);
    }
    
    void setPlayer(Player* player) { this->player = player; }
    Player* getPlayer() { return player; }
    
    
private:
    cocos2d::Node* rootNode;
    
    Player* player;
    static Player onePlayer;//实例
    //back按钮回调
    void clickBackCallback(Ref*, TouchEventType type);
    
    void drawFoods();//画那些食物
};


#endif /* FoodScene_hpp */
