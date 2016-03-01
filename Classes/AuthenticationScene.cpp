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
	/*获取屏幕大小*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/**************加载UI***************/
	rootNode = CSLoader::createNode("csb/AuthenticationScene.csb");

	//调整UI大小
	rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);

	this->addChild(rootNode);

	
	//获取翻页容器
	auto pageView = (PageView*)rootNode->getChildByName("PageView");

	//调整翻页灵敏度
	pageView->setCustomScrollThreshold(0.3);
	
	//按钮回调函数
	Button* giveUpbtn = (Button*)rootNode->getChildByName("Button_giveup");

	giveUpbtn->addTouchEventListener(this, toucheventselector(AuthenticationScene::clickGiveupCallback));

	Button* submitbtn = (Button*)rootNode->getChildByName("Button_submit");

	submitbtn->addTouchEventListener(this, toucheventselector(AuthenticationScene::clickSubmitCallback));

	childLayer = DialogLayer::create();

	childLayer->setVisible(false);

	this->addChild(childLayer);

	//获取五道题
	HttpUtility::getInstance(this)->loadQuestion(5);
	
	return true;
}

//题目更新
void AuthenticationScene::updateQuestion()
{

	//翻页容器
	auto pageView = (PageView*)rootNode->getChildByName("PageView");

	//问题vector
	std::vector<std::string> questionVector = question_answer.first;

	for (int i = 1; i <= questionVector.size(); ++i)
	{
		//获取其中一页
		char childName[30];
		sprintf(childName, "Panel_%d", i);
		auto page = pageView->getChildByName(childName);

		//获取问题文本
		sprintf(childName, "Text_Qestion%d", i);
		Text* questionText = (Text*)page->getChildByName(childName);

		//以下代码是设置自动换行
		questionText->setTextHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
		questionText->setTextVerticalAlignment(cocos2d::TextVAlignment::TOP);
		utility::setTextAuto(questionText);

		//将问题取出放到页面上
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
		cocos2d::Director::getInstance()->replaceScene(LogInScene::createScene());//切换到登录页面
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
}


//根据status弹出对应提示框
void AuthenticationScene::promptDialogBox(std::string str, AuthenticationScene::STATUS status)
{
	utility::setEnable(false, this);
	switch (status)
	{
	case AuthenticationScene::STATUS::LINK_ERROR:
		childLayer->setVisible(true);
		((DialogLayer*)childLayer)->setText(str);//输出文字
		break;
	case AuthenticationScene::STATUS::ANSWER_ERROR:
		childLayer->setVisible(true);
		((DialogLayer*)childLayer)->setText(str);//输出文字
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
		{//答案有误或为空
			this->promptDialogBox("The Answer is wrong!If you have any question, welcome to sent email to yk118921@outlook.com"
				, AuthenticationScene::STATUS::ANSWER_ERROR);//弹出对话框
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
	
	//翻页容器
	auto pageView = (PageView*)rootNode->getChildByName("PageView");

	//问题vector
	std::vector<std::string> answerVector = question_answer.second;

	if (answerVector.size() == 0) flag = false;//加载失败则为false

	for (int i = 1; i <= answerVector.size(); ++i)
	{
		//获取其中一页
		char childName[30];
		sprintf(childName, "Panel_%d", i);
		auto page = pageView->getChildByName(childName);

		//获取回答框
		sprintf(childName, "Panel_Answer%d", i);
		auto answerPanel = page->getChildByName(childName);

		//获取回答文本
		auto answertf = (TextField*)answerPanel->getChildByName("TextField_Answer");
		std::string player_answer = answertf->getStringValue();
		CCLOG("%s", player_answer.c_str());

		//将正确答案取出
		std::string answerStr = answerVector[i - 1];
		CCLOG("%s", answerStr.c_str());
		if (player_answer.length() == 0 || strcmp(player_answer.c_str(), answerStr.c_str()) != 0)
		{
			flag = false;
		}
	}
	return flag;
}
