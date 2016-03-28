//
//  HomeScene.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/7.
//
//

#ifndef HomeScene_hpp
#define HomeScene_hpp

#include "../interface/Httpable.hpp"
#include "DialogLayer.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;

class HomeScene :public Httpable
{
public:
    HomeScene();
    ~HomeScene();
    
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(HomeScene);
    
    void onUpdateInfo();
    
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
    
    //exit按钮回调
    void onExitClicked(Ref*,TouchEventType type);
};





#endif /* HomeScene_hpp */
