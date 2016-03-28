#pragma once
/*
	…Ì∑›—È÷§“≥√Ê
*/

#include "RegeditScene.h"
#include "../utility/HttpUtility.h"

#include "../interface/Httpable.hpp"

using namespace cocos2d;
using namespace cocos2d::ui;


class AuthenticationScene :public Httpable
{
public:
	static Scene* createScene();

	virtual bool init();

	
	// µœ÷ static create()∫Ø ˝µƒ∫Í
	CREATE_FUNC(AuthenticationScene);

	void setQuestion(std::pair<std::vector<std::string>, std::vector<std::string>> question_answer)
	{
		this->question_answer = question_answer;
		this->updateQuestion();
	};
    

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
    void updateQuestion();
    Node* rootNode;
    
    std::pair<std::vector<std::string>, std::vector<std::string>>
    question_answer;//—È÷§Œ Ã‚º∞¥∞∏ keyŒ™Œ Ã‚µƒvector valueŒ™¥∞∏µƒvector
    
    
    void clickGiveupCallback(Ref*, TouchEventType type);//∑≈∆˙∞¥≈•ªÿµ˜∫Ø ˝
	void clickSubmitCallback(Ref*, TouchEventType type);//Ã·Ωª∞¥≈•ªÿµ˜∫Ø ˝

	bool checkAnswer();//ºÏ≤È¥∞∏ «∑Ò’˝»∑
};

