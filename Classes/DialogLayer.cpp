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
	/*获取屏幕大小*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/**************加载UI***************/
	rootNode = CSLoader::createNode("csb/DialogLayer.csb");

	//调整UI大小
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
			//添加逻辑使得跳转nextScene
			
		}
		this->setVisible(false);
		//重新激活下层
		utility::setEnable(true, static_cast<Layer*>(this->getParent()));
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
	//自动换行
	utility::setTextAuto(text);
	

	if (text->getVirtualRendererSize().height < scrollVeiw->getContentSize().height )
	{
		//若一页能显示完全
		
		//文本居中
		text->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
		text->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
		text->setPosition(Vec2(scrollVeiw->getContentSize().width / 2, scrollVeiw->getContentSize().height * 3 / 2 ));

	}else
	{
		//一页显示不了

		//文本居左居上
		text->setTextVerticalAlignment(cocos2d::TextVAlignment::TOP);
		text->setTextHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
		text->setPosition(Vec2(scrollVeiw->getContentSize().width / 2, scrollVeiw->getContentSize().height));

	}
	
}


