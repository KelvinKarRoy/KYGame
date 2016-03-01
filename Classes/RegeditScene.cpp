#include "RegeditScene.h"


RegeditScene::RegeditScene()
{
}


RegeditScene::~RegeditScene()
{
}


Scene* RegeditScene::createScene()
{
	auto scene = Scene::create();

	auto layer = RegeditScene::create();

	scene->addChild(layer);

	return scene;
}

bool RegeditScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	/*��ȡ��Ļ��С*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/**************����UI***************/
	rootNode = CSLoader::createNode("csb/RegeditScene.csb");

	//����UI��С
	rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);

	this->addChild(rootNode);

	//��ȡ��ť�󶨻ص�
	auto backbtn = (Button*) rootNode->getChildByName("Button_back");

	backbtn->addTouchEventListener(this, toucheventselector(RegeditScene::onClickBackCallback));

	auto nextbtn = (Button*)rootNode->getChildByName("Button_Regedit");

	nextbtn->addTouchEventListener(this, toucheventselector(RegeditScene::onClickNextCallback));
	
	//�����Ӳ�
	childNode = CSLoader::createNode("csb/RoleSelectScene.csb");

	//����UI��С
	childNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);

	childNode->setVisible(false);

	//�󶨰�ť�ص�����
	karrybtn = (Button*)childNode->getChildByName("Button_Karry");

	karrybtn->addTouchEventListener(this, toucheventselector(RegeditScene::onClickKarryCallback));

	roybtn = (Button*)childNode->getChildByName("Button_Roy");

	roybtn->addTouchEventListener(this, toucheventselector(RegeditScene::onClickRoyCallback));

	backbtn = (Button*)childNode->getChildByName("Button_Back");

	backbtn->addTouchEventListener(this, toucheventselector(RegeditScene::onClickBackCallback));

	auto regeditbtn = (Button*)childNode->getChildByName("Button_Regedit");

	regeditbtn->addTouchEventListener(this, toucheventselector(RegeditScene::onClickRegeditCallback));

	this->addChild(childNode);

	return true;
}

void RegeditScene::promptDialogBox(std::string text, RegeditScene::STATUS status)
{
	Scene* scene;
	switch (status)
	{
	case RegeditScene::STATUS::LINK_ERROR:
		childLayer = DialogLayer::create();
		((DialogLayer*)childLayer)->setText(text);//�������
		this->addChild(childLayer);
		break;
	case RegeditScene::STATUS::ACCOUNTEXIST:
		childLayer = DialogLayer::create();
		((DialogLayer*)childLayer)->setText(text);//�������
		this->addChild(childLayer);
		break;
	case RegeditScene::STATUS::SUCCEED:
		childLayer = DialogLayer::create();
		scene = LogInScene::createScene();
		((DialogLayer*)childLayer)->setText(text);//�������
		scene->addChild(childLayer);
		Director::getInstance()->replaceScene(scene);//ת����¼ҳ��
		break;
	default:
		break;
	}

}

void RegeditScene::onClickBackCallback(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		CCLOG("%s", "back!!!!!!!!");

		if (childNode->isVisible())
		{
			childNode->setVisible(false);
			this->setTouchEnabled(true);
		}else Director::getInstance()->replaceScene(LogInScene::createScene());
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
}

void RegeditScene::onClickRegeditCallback(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		CCLOG("%s", "regedit!!!!!!!!");
		if (isRegeditLegal())
		{//����Ϸ�
			HttpUtility::getInstance(this)->regeditAccount(playerInfo.account,
				playerInfo.password, playerInfo.name, playerInfo.role);
		}
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
}


void RegeditScene::onClickNextCallback(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		CCLOG("%s", "regedit!!!!!!!!");
		this->setTouchEnabled(false);
		childNode->setVisible(true);
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
}

void RegeditScene::onClickKarryCallback(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		playerInfo.role = true;
		karrybtn->setEnabled(false);
		roybtn->setEnabled(true);
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
}

void RegeditScene::onClickRoyCallback(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		CCLOG("%s", "roy!!!!!!!!");
		playerInfo.role = false;
		roybtn->setEnabled(false);
		karrybtn->setEnabled(true);
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
}


bool RegeditScene::isRegeditLegal()
{
	playerInfo.account = ((TextField*)rootNode->getChildByName("Panel_account")
		->getChildByName("Panel")->getChildByName("TextField"))->getString();
	
	playerInfo.password = ((TextField*)rootNode->getChildByName("Panel_password1")
		->getChildByName("Panel")->getChildByName("TextField"))->getString();
	
	playerInfo.name = ((TextField*)rootNode->getChildByName("Panel_name")
		->getChildByName("Panel")->getChildByName("TextField"))->getString();

	if (playerInfo.password != ((TextField*)rootNode->getChildByName("Panel_password2")
		->getChildByName("Panel")->getChildByName("TextField"))->getString())
	{//�������벻һ��
		this->promptDialogBox("password input different!");//�����Ի���
		return false;
	}

	if (!utility::isStringLegal(playerInfo.account))
	{//�˺Ų��Ϸ�
		this->promptDialogBox("your account is illegal!(it only can include letter, number,@ and .)it can not be less than 6 bit");//�����Ի���
		return false;
	}

	if (!utility::isStringLegal(playerInfo.password))
	{//���벻�Ϸ�
		this->promptDialogBox("your password is illegal!(it only can include letter, number,@ and .)it can not be less than 6 bit");//�����Ի���
		return false;
	}

	if (!(roybtn->isEnabled() ^ karrybtn->isEnabled()))
	{//δѡ���ɫ
		this->promptDialogBox("Whitch one do you want to be? Karry or Roy?");//�����Ի���
		return false;
	}

	if (!utility::isNameLegal(playerInfo.name))
	{//���ֲ��Ϸ�
		this->promptDialogBox("your name is illegal, me me da");//�����Ի���
		return false;
	}

	return true;
}

void RegeditScene::promptDialogBox(std::string str)
{
	childLayer = DialogLayer::create();
	((DialogLayer*)childLayer)->setText(str);//�������
	this->addChild(childLayer);
}