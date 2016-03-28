#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__
/*
	µ«¬º“≥√Ê
*/


#include "cocos-ext.h"
//“ª–©œ‡πÿ“≥√Ê

#include "../utility/HttpUtility.h"
#include "../utility/utility.h"
#include "../utility/StringUtility.h"


#include "../interface/Httpable.hpp"

#include "DialogLayer.h"


#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "../sqlite/sqlite3.h"
#else
#include "sqlite3.h"
#endif

using namespace cocos2d::ui;



class LogInScene :public Httpable
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// µœ÷ static create()∫Ø ˝µƒ∫Í
	CREATE_FUNC(LogInScene);
    
    
    void onUpdateInfo() {};
    
    //弹出对话框
    void promptDialogBox(std::string str,DialogLayer::DialogType type =
                         DialogLayer::DialogType::OKDIALOG)
    {
        childLayer = DialogLayer::create();
        ((DialogLayer*)childLayer)->setText(str);//弹出对话框
        this->addChild((DialogLayer*)childLayer);
    }

	
private:
	Node* rootNode;
    
	void clickAboutCallback(Ref*, TouchEventType type);//πÿ”⁄∞¥≈•ªÿµ˜∫Ø ˝
	void clickLoginCallback(Ref*, TouchEventType type);//µ«¬º∞¥≈•ªÿµ˜∫Ø ˝
	void clickRegeditCallback(Ref*, TouchEventType type);//◊¢≤·∞¥≈•ªÿµ˜∫Ø ˝
    
    void loadPlayerAccount(TextField* accountField,TextField* passwdField);//从本地数据库读取账号
    void saveAccount();//记住账号密码

    void toHome();//账号密码正确，进入游戏主页面

    
    
    friend class HttpUtility;//设置友元 使得http工具类能访问toHome()等重要方法
};










#endif //__LOGIN_SCENE_H__


