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

#include "sqlite3.h"

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
    
    
};




#endif /* PropertyScene_hpp */
