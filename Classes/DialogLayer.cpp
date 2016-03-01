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
	/*��ȡ��Ļ��С*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/**************����UI***************/
	rootNode = CSLoader::createNode("csb/DialogLayer.csb");

	//����UI��С
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
			//����߼�ʹ����תnextScene
			
		}
		this->setVisible(false);
		//���¼����²�
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
	//�Զ�����
	utility::setTextAuto(text);
	

	if (text->getVirtualRendererSize().height < scrollVeiw->getContentSize().height )
	{
		//��һҳ����ʾ��ȫ
		
		//�ı�����
		text->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
		text->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
		text->setPosition(Vec2(scrollVeiw->getContentSize().width / 2, scrollVeiw->getContentSize().height * 3 / 2 ));

	}else
	{
		//һҳ��ʾ����

		//�ı��������
		text->setTextVerticalAlignment(cocos2d::TextVAlignment::TOP);
		text->setTextHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
		text->setPosition(Vec2(scrollVeiw->getContentSize().width / 2, scrollVeiw->getContentSize().height));

	}
	
}


