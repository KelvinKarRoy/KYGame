#include "LogInScene.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;

Scene* LogInScene::createScene()
{
	auto scene = Scene::create();

	auto layer = LogInScene::create();

	scene->addChild(layer);

	return scene;
}

bool LogInScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	/*获取屏幕大小*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	/**************加载UI***************/
	rootNode = CSLoader::createNode("csb/LogInScene.csb");
	//调整UI大小
	rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
	
	this->addChild(rootNode);
	//关于按钮
	Button* aboutbtn = (Button*) rootNode->getChildByName("Button_about");
	
	aboutbtn->addTouchEventListener(this,toucheventselector(LogInScene::clickAboutCallback));
	//登录按钮
	Button* loginbtn = (Button*)rootNode->getChildByName("Button_login");

	loginbtn->addTouchEventListener(this, toucheventselector(LogInScene::clickLoginCallback));
	//注册按钮
	Button* regeditbtn = (Button*)rootNode->getChildByName("Button_regedit");

	regeditbtn->addTouchEventListener(this, toucheventselector(LogInScene::clickRegeditCallback));
	
	return true;
}

void LogInScene::clickAboutCallback(Ref*, TouchEventType type)
{
	
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	
		//添加about层
		childLayer = AboutScene::create();
		//将about层设为不可见
		childLayer->setVisible(false);

		this->addChild(childLayer);

		//关于页面可见
		childLayer->setVisible(true);
		
		this->setTouchEnabled(false);
		
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}

}

void LogInScene::clickLoginCallback(Ref*, TouchEventType type)
{
	TextField* accounttf = (TextField*)rootNode->getChildByName("Panel_1")->getChildByName("TextField_account");
	TextField* passwordtf = (TextField*)rootNode->getChildByName("Panel_2")->getChildByName("TextField_password");

	std::string account = accounttf->getString();
	std::string password = passwordtf->getString();
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
    case TouchEventType::TOUCH_EVENT_MOVED:
        break;
    case TouchEventType::TOUCH_EVENT_ENDED:
		CCLOG("%s", "login!!!!!!!!!!!!!!");
		if (utility::isStringLegal(account) && utility::isStringLegal(password))
		{//输入合法
			CCLOG("%s", "input is legal!!!!!!!!!!!!");
			HttpUtility::getInstance(this)->checkPassword(account, password);
		}else{//输入非法
            CCLOG("%s", "input is illegal!!!!!!!!!!!!!");
			//提示对话框
			this->promptDialogBox("输入了非法的账号或密码!(只能包括数字、字母、@和.)且最低不能少于六位");
        }
            
        sqlite3 *pDB = NULL;//本地数据库对象
        int rc = sqlite3_open("db/KYGame.db", &pDB);
        CCLOG("SQLITE连接状态rc = %d",rc);
        if( rc ){
            CCLOG("Can't open database: ");
            sqlite3_close(pDB);
        }
        break;
    
	}
}


void LogInScene::clickRegeditCallback(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		CCLOG("%s", "rededit!!!!!!!!!!!!!!");
		cocos2d::Director::getInstance()->replaceScene(AuthenticationScene::createScene());//切换到验证页面
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	}
}

void LogInScene::promptDialogBox(std::string strInfo)
{
	childLayer = DialogLayer::create();
	((DialogLayer*)childLayer)->setText(strInfo);//弹出对话框
	this->addChild((DialogLayer*)childLayer);
	utility::setEnable(false, this);
}

