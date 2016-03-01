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
	/*��ȡ��Ļ��С*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/**************����UI***************/
	rootNode = CSLoader::createNode("csb/AuthenticationScene.csb");

	//����UI��С
	rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);

	this->addChild(rootNode);

	
	//��ȡ��ҳ����
	auto pageView = (PageView*)rootNode->getChildByName("PageView");

	//������ҳ������
	pageView->setCustomScrollThreshold(0.3);
	
	//��ť�ص�����
	Button* giveUpbtn = (Button*)rootNode->getChildByName("Button_giveup");

	giveUpbtn->addTouchEventListener(this, toucheventselector(AuthenticationScene::clickGiveupCallback));

	Button* submitbtn = (Button*)rootNode->getChildByName("Button_submit");

	submitbtn->addTouchEventListener(this, toucheventselector(AuthenticationScene::clickSubmitCallback));

	childLayer = DialogLayer::create();

	childLayer->setVisible(false);

	this->addChild(childLayer);

	//��ȡ�����
	HttpUtility::getInstance(this)->loadQuestion(5);
	
	return true;
}

//��Ŀ����
void AuthenticationScene::updateQuestion()
{

	//��ҳ����
	auto pageView = (PageView*)rootNode->getChildByName("PageView");

	//����vector
	std::vector<std::string> questionVector = question_answer.first;

	for (int i = 1; i <= questionVector.size(); ++i)
	{
		//��ȡ����һҳ
		char childName[30];
		sprintf(childName, "Panel_%d", i);
		auto page = pageView->getChildByName(childName);

		//��ȡ�����ı�
		sprintf(childName, "Text_Qestion%d", i);
		Text* questionText = (Text*)page->getChildByName(childName);

		//���´����������Զ�����
		questionText->setTextHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
		questionText->setTextVerticalAlignment(cocos2d::TextVAlignment::TOP);
		utility::setTextAuto(questionText);

		//������ȡ���ŵ�ҳ����
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
		cocos2d::Director::getInstance()->replaceScene(LogInScene::createScene());//�л�����¼ҳ��
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
}


//����status������Ӧ��ʾ��
void AuthenticationScene::promptDialogBox(std::string str, AuthenticationScene::STATUS status)
{
	utility::setEnable(false, this);
	switch (status)
	{
	case AuthenticationScene::STATUS::LINK_ERROR:
		childLayer->setVisible(true);
		((DialogLayer*)childLayer)->setText(str);//�������
		break;
	case AuthenticationScene::STATUS::ANSWER_ERROR:
		childLayer->setVisible(true);
		((DialogLayer*)childLayer)->setText(str);//�������
		break;
	default:
		break;
	}
}

void AuthenticationScene::clickSubmitCallback(Ref*, TouchEventType type)
{
	bool flag = checkAnswer();//�����Ƿ���ȷ
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		CCLOG("%s", "submit!!!!");
		if (flag)
		{//��֤�ɹ�
			CCLOG("%s", "success");
			Director::getInstance()->replaceScene(RegeditScene::createScene());
		}
		else
		{//�������Ϊ��
			this->promptDialogBox("The Answer is wrong!If you have any question, welcome to sent email to yk118921@outlook.com"
				, AuthenticationScene::STATUS::ANSWER_ERROR);//�����Ի���
		}
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
	
}

//�����Ƿ���ȷ
bool AuthenticationScene::checkAnswer()
{
	bool flag = true;
	
	//��ҳ����
	auto pageView = (PageView*)rootNode->getChildByName("PageView");

	//����vector
	std::vector<std::string> answerVector = question_answer.second;

	if (answerVector.size() == 0) flag = false;//����ʧ����Ϊfalse

	for (int i = 1; i <= answerVector.size(); ++i)
	{
		//��ȡ����һҳ
		char childName[30];
		sprintf(childName, "Panel_%d", i);
		auto page = pageView->getChildByName(childName);

		//��ȡ�ش��
		sprintf(childName, "Panel_Answer%d", i);
		auto answerPanel = page->getChildByName(childName);

		//��ȡ�ش��ı�
		auto answertf = (TextField*)answerPanel->getChildByName("TextField_Answer");
		std::string player_answer = answertf->getStringValue();
		CCLOG("%s", player_answer.c_str());

		//����ȷ��ȡ��
		std::string answerStr = answerVector[i - 1];
		CCLOG("%s", answerStr.c_str());
		if (player_answer.length() == 0 || strcmp(player_answer.c_str(), answerStr.c_str()) != 0)
		{
			flag = false;
		}
	}
	return flag;
}
