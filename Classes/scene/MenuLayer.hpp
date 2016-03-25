//
//  MenuLayer.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/17.
//
//

#ifndef MenuLayer_hpp
#define MenuLayer_hpp

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UIœ‡πÿµƒÕ∑Œƒº˛
#include "cocostudio/CocoStudio.h"//‘⁄CocosStudio.h Õ∑Œƒº˛÷–“—æ≠∞¸∫¨¡ÀStudioÀ˘–Ë“™µƒ∏˜∏ˆÕ∑Œƒº˛(≥˝CocosGUI)“Ú¥ÀŒ“√« π”√StudioΩˆ–Ë“™∞¸∫¨À˚æÕø…“‘


using namespace cocos2d;
using namespace cocos2d::ui;


class MenuLayer :public Layer
{
public:
    static Scene* createScene();
    
    MenuLayer();
    ~MenuLayer();
    
    virtual bool init();
    
    CREATE_FUNC(MenuLayer);
    
    void clickPropertyCallback(Ref*, TouchEventType type);//点击属性按钮
    void clickNoticeCallback(Ref*, TouchEventType type);//点击公告按钮
    void clickMailCallback(Ref*, TouchEventType type);//点击邮件按钮
    void clickFriendCallback(Ref*, TouchEventType type);//点击好友按钮
    
private:
    Node* rootNode;
    
    
};




#endif /* MenuLayer_hpp */
