#include "AuthenticationScene.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;

Scene* AuthenticationScene::createScene()
{
	auto scene = Scene::create();

	auto layer = AuthenticationScene::create();

	scene->addChild(layer);

	return scene;
}

bool AuthenticationScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	/*ªÒ»°∆¡ƒª¥Û–°*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/**************º”‘ÿUI***************/
	rootNode = CSLoader::createNode("csb/AuthenticationScene.csb");

	//µ˜’˚UI¥Û–°
	rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);

	this->addChild(rootNode);

	
	//ªÒ»°∑≠“≥»›∆˜
	auto pageView = (PageView*)rootNode->getChildByName("PageView");

	//µ˜’˚∑≠“≥¡È√Ù∂»
	pageView->setCustomScrollThreshold(0.3);
	
	//∞¥≈•ªÿµ˜∫Ø ˝
	Button* giveUpbtn = (Button*)rootNode->getChildByName("Button_giveup");

	giveUpbtn->addTouchEventListener(this, toucheventselector(AuthenticationScene::clickGiveupCallback));

	Button* submitbtn = (Button*)rootNode->getChildByName("Button_submit");

	submitbtn->addTouchEventListener(this, toucheventselector(AuthenticationScene::clickSubmitCallback));

	childLayer = DialogLayer::create();

	childLayer->setVisible(false);

	this->addChild(childLayer);

	//ªÒ»°ŒÂµ¿Ã‚
	HttpUtility::getInstance(this)->loadQuestion(5);
	
	return true;
}

//Ã‚ƒø∏¸–¬
void AuthenticationScene::updateQuestion()
{

	//∑≠“≥»›∆˜
	auto pageView = (PageView*)rootNode->getChildByName("PageView");

	//Œ Ã‚vector
	std::vector<std::string> questionVector = question_answer.first;

	for (int i = 1; i <= questionVector.size(); ++i)
	{
		//ªÒ»°∆‰÷–“ª“≥
		char childName[30];
		sprintf(childName, "Panel_%d", i);
		auto page = pageView->getChildByName(childName);

		//ªÒ»°Œ Ã‚Œƒ±æ
		sprintf(childName, "Text_Qestion%d", i);
		Text* questionText = (Text*)page->getChildByName(childName);

		//“‘œ¬¥˙¬Î «…Ë÷√◊‘∂Øªª––
		questionText->setTextHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
		questionText->setTextVerticalAlignment(cocos2d::TextVAlignment::TOP);
		utility::setTextAuto(questionText);

		//Ω´Œ Ã‚»°≥ˆ∑≈µΩ“≥√Ê…œ
		std::string questionStr = questionVector[i - 1];
		questionText->setText(questionStr);
	}

}

void AuthenticationScene::clickGiveupCallback(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		CCLOG("%s", "give up!!!!");
		cocos2d::Director::getInstance()->replaceScene(LogInScene::createScene());//«–ªªµΩµ«¬º“≥√Ê
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
}


//∏˘æ›statusµØ≥ˆ∂‘”¶Ã· æøÚ
void AuthenticationScene::promptDialogBox(std::string str, AuthenticationScene::STATUS status)
{
	utility::setEnable(false, this);
	switch (status)
	{
	case AuthenticationScene::STATUS::LINK_ERROR:
		childLayer->setVisible(true);
		((DialogLayer*)childLayer)->setText(str);// ‰≥ˆŒƒ◊÷
		break;
	case AuthenticationScene::STATUS::ANSWER_ERROR:
		childLayer->setVisible(true);
		((DialogLayer*)childLayer)->setText(str);// ‰≥ˆŒƒ◊÷
		break;
	default:
		break;
	}
}

void AuthenticationScene::clickSubmitCallback(Ref*, TouchEventType type)
{
	bool flag = checkAnswer();//检查答案是否正确
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		CCLOG("%s", "submit!!!!");
		if (flag)
		{//验证成功
			CCLOG("%s", "success");
			Director::getInstance()->replaceScene(RegeditScene::createScene());
		}
		else
		{//回答错误
			this->promptDialogBox("回答错误!如果你有任何疑问,欢迎寄件给yk118921@outlook.com"
				, AuthenticationScene::STATUS::ANSWER_ERROR);//µØ≥ˆ∂‘ª∞øÚ
		}
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
	
}

//检查答案是否正确
bool AuthenticationScene::checkAnswer()
{
	bool flag = true;
	
	//∑≠“≥»›∆˜
	auto pageView = (PageView*)rootNode->getChildByName("PageView");

	//Œ Ã‚vector
	std::vector<std::string> answerVector = question_answer.second;

	if (answerVector.size() == 0) flag = false;//º”‘ÿ ß∞‹‘ÚŒ™false

	for (int i = 1; i <= answerVector.size(); ++i)
	{
		//ªÒ»°∆‰÷–“ª“≥
		char childName[30];
		sprintf(childName, "Panel_%d", i);
		auto page = pageView->getChildByName(childName);

		//ªÒ»°ªÿ¥øÚ
		sprintf(childName, "Panel_Answer%d", i);
		auto answerPanel = page->getChildByName(childName);

		//ªÒ»°ªÿ¥Œƒ±æ
		auto answertf = (TextField*)answerPanel->getChildByName("TextField_Answer");
		std::string player_answer = answertf->getString();
		CCLOG("%s", player_answer.c_str());

		//Ω´’˝»∑¥∞∏»°≥ˆ
		std::string answerStr = answerVector[i - 1];
		CCLOG("%s", answerStr.c_str());
		if (player_answer.length() == 0 || strcmp(player_answer.c_str(), answerStr.c_str()) != 0)
		{
			flag = false;
		}
	}
	return flag;
}
