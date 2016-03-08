//
//  HomeScene.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/7.
//
//

#ifndef HomeScene_hpp
#define HomeScene_hpp

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI读取类
#include "cocostudio/CocoStudio.h"//‘⁄CocosStudio.h

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;


class HomeScene :public Layer
{
public:
    HomeScene();
    ~HomeScene();
    
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(HomeScene);
    
    
private:
    cocos2d::Node* rootNode;
    //Ref Node Layer Scene
    
    //exit按钮回调
    void onExitClicked(Ref*,TouchEventType type);

    
};





#endif /* HomeScene_hpp */
