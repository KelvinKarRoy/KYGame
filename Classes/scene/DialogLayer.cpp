#include "DialogLayer.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;





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

	okbtn->addTouchEventListener(this, toucheventselector(DialogLayer::clickOKCallback));

    return true;
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
            if (nextScene != nullptr)
            {
                //ÃÌº”¬ﬂº≠ πµ√Ã¯◊™nextScene
			
		}
		this->setVisible(false);
		//÷ÿ–¬º§ªÓœ¬≤„
		if(this->getParent() != nullptr) utility::setEnable(true, static_cast<Layer*>(this->getParent()));
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


