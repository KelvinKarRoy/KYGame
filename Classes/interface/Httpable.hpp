//
//  Httpable.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/27.
//
//  实现这个接口一定要是Layer子类

#ifndef Httpable_hpp
#define Httpable_hpp


#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI读取类
#include "cocostudio/CocoStudio.h"//‘⁄CocosStudio.h Õ∑Œƒº˛÷–“—æ≠∞¸∫¨¡ÀStudioÀ˘–Ë“™µƒ∏˜∏ˆÕ∑Œƒº˛(≥˝CocosGUI)“Ú¥ÀŒ“√« π”√StudioΩˆ–Ë“™∞¸∫¨À˚æÕø…“‘

#include "LoadInfoable.hpp"
#include "Promptable.hpp"

class Httpable
:public LoadInfoable,public Promptable,public cocos2d::Layer
{
public:
    Httpable(){};
    virtual ~Httpable() {};
};



#endif /* Httpable_hpp */



