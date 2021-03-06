#include "DialogLayer.h"


#include "../utility/utility.h"

#include "../interface/Promptable.hpp"

#include "FoodScene.hpp"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;

//带type的构造
DialogLayer* DialogLayer::create(DialogType type)
{
    DialogLayer *pRet = new(std::nothrow) DialogLayer();
    if (pRet && pRet->init(type))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}


Scene* DialogLayer::createScene()
{
	auto scene = Scene::create();

	auto layer = DialogLayer::create();

	scene->addChild(layer);

	return scene;
}



bool DialogLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	/*ªÒ»°∆¡ƒª¥Û–°*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/**************º”‘ÿUI***************/
	rootNode = CSLoader::createNode("csb/DialogLayer.csb");

	//µ˜’˚UI¥Û–°
	rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
	CCLOG("%f %f %f %f", visibleSize.width, rootNode->getContentSize().width, visibleSize.height, rootNode->getContentSize().height);

	this->addChild(rootNode);

	auto aboutPanel = rootNode->getChildByName("Panel");

	Button* okbtn = (Button*)aboutPanel->getChildByName("Button_ok");

	okbtn->addTouchEventListener(this, toucheventselector(DialogLayer::clickCancelCallback));
    
    //吞噬下层事件
    auto callback = [](cocos2d::Touch * ,cocos2d::Event *)
    {
        return true;
    };
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = callback;
    listener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);

    return true;
}



//带类型的init
bool DialogLayer::init(DialogType type)
{
    if (!Layer::init())
    {
        return false;
    }
    /*获取大小*/
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /**************加载UI***************/
    rootNode = CSLoader::createNode("csb/DialogLayer.csb");
    
    //设置大小
    rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
    
    this->addChild(rootNode);
    
    auto aboutPanel = rootNode->getChildByName("Panel");
    
    Button* okbtn = (Button*)aboutPanel->getChildByName("Button_ok");
    Button* cancelbtn = (Button*)aboutPanel->getChildByName("Button_cancel");
    
    switch (type)
    {
        case DialogType::OKDIALOG :
            okbtn->addTouchEventListener(this, toucheventselector(DialogLayer::clickCancelCallback));
            okbtn->setVisible(true);
            cancelbtn->setVisible(false);
            okbtn->setPosition(Point(aboutPanel->getContentSize().width/2,okbtn->getPositionY()));
            break;

        case DialogType::OKCANCELDIALOG :
            okbtn->addTouchEventListener(this, toucheventselector(DialogLayer::clickOKCallback));
            cancelbtn->addTouchEventListener(this, toucheventselector(DialogLayer::clickCancelCallback));
            okbtn->setVisible(true);
            cancelbtn->setVisible(true);
            
            cancelbtn->setPosition(Point(aboutPanel->getContentSize().width/4,okbtn->getPositionY()));
            okbtn->setPosition(Point(aboutPanel->getContentSize().width*3/4,okbtn->getPositionY()));
            
        default:
            break;
    }
    
    //吞噬下层事件
    auto callback = [](cocos2d::Touch * ,cocos2d::Event *)
    {
        return true;
    };
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = callback;
    listener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    
    return true;
}



void DialogLayer::clickCancelCallback(Ref*, TouchEventType type)
{
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            break;
        case TouchEventType::TOUCH_EVENT_CANCELED:
            break;
        case TouchEventType::TOUCH_EVENT_ENDED:
            CCLOG("%s", "ok!!!!!!!!");
            if(this->getParent() != nullptr) this->getParent()->removeChild(this);
        break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}

}



void DialogLayer::clickOKCallback(Ref*, TouchEventType type)
{
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            break;
        case TouchEventType::TOUCH_EVENT_CANCELED:
            break;
        case TouchEventType::TOUCH_EVENT_ENDED:
            CCLOG("%s", "ok!!!!!!!!");
            if(this->getParent() != nullptr)
            {
                ((FoodScene*)(this->getParent()))->onClickOKCallback();
                this->getParent()->removeChild(this);
            }
            break;
        case TouchEventType::TOUCH_EVENT_MOVED:
            break;
    }
    
}



void DialogLayer::setText(std::string _text)
{
	auto scrollVeiw = rootNode->getChildByName("Panel")->getChildByName("ScrollView");

	Text* text = (Text*) scrollVeiw->getChildByName("Text");

	text->setText(_text);
	//◊‘∂Øªª––
	utility::setTextAuto(text);
	

	if (text->getVirtualRendererSize().height < scrollVeiw->getContentSize().height )
	{
		//»Ù“ª“≥ƒ‹œ‘ æÕÍ»´
		
		//Œƒ±ææ”÷–
		text->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
		text->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
		text->setPosition(Vec2(scrollVeiw->getContentSize().width / 2, scrollVeiw->getContentSize().height * 3 / 2 ));

	}else
	{
		//“ª“≥œ‘ æ≤ª¡À

		//Œƒ±ææ”◊Ûæ”…œ
		text->setTextVerticalAlignment(cocos2d::TextVAlignment::TOP);
		text->setTextHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
		text->setPosition(Vec2(scrollVeiw->getContentSize().width / 2, scrollVeiw->getContentSize().height));

	}
	
}






