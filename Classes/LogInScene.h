#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__
/*
	µ«¬º“≥√Ê
*/

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"//UI读取类
#include "cocostudio/CocoStudio.h"//‘⁄CocosStudio.h Õ∑Œƒº˛÷–“—æ≠∞¸∫¨¡ÀStudioÀ˘–Ë“™µƒ∏˜∏ˆÕ∑Œƒº˛(≥˝CocosGUI)“Ú¥ÀŒ“√« π”√StudioΩˆ–Ë“™∞¸∫¨À˚æÕø…“‘ 

#include "cocos-ext.h"
//“ª–©œ‡πÿ“≥√Ê
#include "AboutScene.h"
#include "RegeditScene.h"
#include "AuthenticationScene.h"
#include "DialogLayer.h"
#include "HttpUtility.h"
#include "utility.h"
#include "StringUtility.h"

#include "sqlite/sqlite3.h"


using namespace cocos2d::ui;

class LogInScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// µœ÷ static create()∫Ø ˝µƒ∫Í
	CREATE_FUNC(LogInScene);

	void promptDialogBox(std::string strInfo);//µØ≥ˆÃ· æ∂‘ª∞øÚ

private:
	Node* rootNode;
	Layer* childLayer;//∏˜÷÷“≥√Ê
	void clickAboutCallback(Ref*, TouchEventType type);//πÿ”⁄∞¥≈•ªÿµ˜∫Ø ˝
	void clickLoginCallback(Ref*, TouchEventType type);//µ«¬º∞¥≈•ªÿµ˜∫Ø ˝
	void clickRegeditCallback(Ref*, TouchEventType type);//◊¢≤·∞¥≈•ªÿµ˜∫Ø ˝




	

};










#endif //__LOGIN_SCENE_H__


