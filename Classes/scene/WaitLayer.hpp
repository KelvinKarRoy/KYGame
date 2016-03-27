//
//  WaitLayer.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/5.
//
//

#ifndef WaitLayer_hpp
#define WaitLayer_hpp

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI读取类
#include "cocostudio/CocoStudio.h"//‘⁄CocosStudio.h



class WaitLayer : public cocos2d::Layer
{

public:
    WaitLayer();
    ~WaitLayer();
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(WaitLayer);
    
private:
    
    Node* rootNode;//csb



};



#endif /* WaitLayer_hpp */
