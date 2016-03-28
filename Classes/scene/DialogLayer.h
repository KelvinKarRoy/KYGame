#pragma once
/*
	πÿ”⁄“≥√Ê≤„
*/
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UIœ‡πÿµƒÕ∑Œƒº˛ 
#include "cocostudio/CocoStudio.h"//‘⁄CocosStudio.h Õ∑Œƒº˛÷–“—æ≠∞¸∫¨¡ÀStudioÀ˘–Ë“™µƒ∏˜∏ˆÕ∑Œƒº˛(≥˝CocosGUI)“Ú¥ÀŒ“√« π”√StudioΩˆ–Ë“™∞¸∫¨À˚æÕø…“‘ 

#include "../utility/StringUtility.h"

using namespace cocos2d;
using namespace cocos2d::ui;


class DialogLayer :public Layer
{
public:
    enum DialogType
    {
        OKDIALOG,
        OKCANCELDIALOG
    };
    
	static Scene* createScene();

	virtual bool init();
    //带类型的init
    bool init(DialogType type);
    
    // µœ÷ static create()∫Ø ˝µƒ∫Í
    CREATE_FUNC(DialogLayer);
    static DialogLayer* create(DialogType type);
    
	//…Ë÷√Œƒ±æ
	void setText(std::string text);

	//…Ë÷√ok∞¥≈•µƒªÿµ˜∫Ø ˝
	void setCallback(void(DialogLayer::*ptr)(Ref*, TouchEventType type));
	
	
    
	void setNextScene(Scene* layer)
	{
		nextScene = layer;
	};


private:
    Layer* callerLayer;
    
	Node* rootNode;//º”‘ÿµƒui

	Scene* nextScene;//œ¬“ª∏ˆ“™»•µƒ“≥√Ê   »Áπ˚Œ™nullprt‘Ú≤ªÃ¯◊™

	void clickCancelCallback(Ref*, TouchEventType type);
    void clickOKCallback(Ref*, TouchEventType type);
    
    
};


