#pragma once
/*
	◊¢≤·“≥√Ê
*/


#include "DialogLayer.h"

#include "../interface/Httpable.hpp"

using namespace cocos2d;
using namespace cocos2d::ui;



using namespace cocos2d;


class RegeditScene :public Httpable
{
public:
	RegeditScene();
	~RegeditScene();


	enum STATUS{
		ACCOUNTEXIST,//’À∫≈“—¥Ê‘⁄
		SUCCEED,//◊¢≤·≥…π¶
		LINK_ERROR//∑˛ŒÒ∆˜¡¨Ω”¥ÌŒÛ
	};


	static Scene* createScene();

	virtual bool init();

	// µœ÷ static create()∫Ø ˝µƒ∫Í
	CREATE_FUNC(RegeditScene);

    
    void onUpdateInfo() {};
    
    //弹出对话框
    void promptDialogBox(std::string str)
    {
        childLayer = DialogLayer::create();
        ((DialogLayer*)childLayer)->setText(str);//弹出对话框
        this->addChild((DialogLayer*)childLayer);
    }
    
    
private:
	struct
	{
		std::string account;
		std::string password;
		std::string name;
		bool role;
	}playerInfo;

	Node* rootNode,*childNode;//csb

	Button* karrybtn, *roybtn;

	void onClickBackCallback(Ref*, TouchEventType type);//∑µªÿº¸
	void onClickNextCallback(Ref*, TouchEventType type);//nextº¸
	void onClickKarryCallback(Ref*, TouchEventType type);//—°‘Òkarry
	void onClickRoyCallback(Ref*, TouchEventType type);//—°‘Òroy
	void onClickRegeditCallback(Ref*, TouchEventType type);//◊¢≤·º¸
    
    
    
    
    
    bool isRegeditLegal();
};

