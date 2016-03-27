#include "LogInScene.h"

#include "AboutScene.h"
#include "RegeditScene.h"
#include "AuthenticationScene.h"
#include "DialogLayer.h"
#include "PropertyScene.hpp"

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
	
    //获取account输入框
    auto accountField = static_cast<TextField*>(rootNode->getChildByName("Panel_1")->getChildByName("TextField_account"));
    
    //获取password输入框
    auto passwdField = static_cast<TextField*>(rootNode->getChildByName("Panel_2")->getChildByName("TextField_password"));
    
    loadPlayerAccount(accountField,passwdField);
    
   
	return true;
}


//从本地数据库读取账号
void LogInScene::loadPlayerAccount(TextField* accountField,TextField* passwdField)
{
    sqlite3 *pDB = NULL;//本地数据库对象
    std::string path= FileUtils::getInstance()->getWritablePath()+"db/KYGame.db";//获取本地数据库路径
    
    log("打开路径:%s",path.c_str());
    
    int rc = sqlite3_open(path.c_str(), &pDB);//打开数据库
    CCLOG("SQLITE连接状态rc = %d",rc);
    if( rc ){
        CCLOG("Can't open database: ");
        sqlite3_close(pDB);
        return;
    }
    
    std::string sql = "select * from information where name='account'";//查询账号
    char** re;//查询结果
    int r,c;//行、列
    rc = sqlite3_get_table(pDB, sql.c_str(), &re, &r, &c,nullptr);
    accountField->setString(re[1*c+1]);
    
    sql = "select * from information where name='passwd'";//查询密码
    rc = sqlite3_get_table(pDB, sql.c_str(), &re, &r, &c,nullptr);
    passwdField->setString(re[1*c+1]);
    
    sqlite3_close(pDB);//关闭数据库
}


void LogInScene::clickAboutCallback(Ref*, TouchEventType type)
{
	
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
    case TouchEventType::TOUCH_EVENT_MOVED:
        break;
            
    case TouchEventType::TOUCH_EVENT_ENDED:
	
		//添加about层
		auto aboutLayer = AboutScene::createScene(this);
        aboutLayer->setName("about");
		this->addChild(aboutLayer);
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


//账号密码正确，进入游戏主页面
void LogInScene::toHome()
{
    saveAccount();//记住账号密码
    //获取自己的账号信息
    HttpUtility::getInstance(this)->account2ID(((TextField*)rootNode->getChildByName("Panel_1")->getChildByName("TextField_account"))->getString());
}

//记住账号密码
void LogInScene::saveAccount()
{
    bool isPWSave = static_cast<CheckBox*> (rootNode->getChildByName("CheckBox_1"))->getSelectedState();//密码是否保存
    //bool isPWSave = true;
    //获取账号和密码
    auto account = static_cast<TextField*>(rootNode->getChildByName("Panel_1")->getChildByName("TextField_account"))->getString();
    auto passwd = static_cast<TextField*>(rootNode->getChildByName("Panel_2")->getChildByName("TextField_password"))->getString();;
    
    sqlite3* pDB = nullptr;//本地数据库
    std::string path= FileUtils::getInstance()->getWritablePath()+"db/KYGame.db";//获取本地数据库路径
    sqlite3_open(path.c_str(), &pDB);//打开数据库
    
    //保存账号信息
    std:string sql = "update information set value = '";
    sql += account+"' where name = 'account'";//添加语句
    sqlite3_exec(pDB, sql.c_str(), nullptr, nullptr, nullptr);
    
    //如果需要保存密码，保存密码信息
    if(isPWSave)
    {
        sql = "update information set value = '";
        sql += passwd+"' where name = 'passwd'";//添加语句
        log("%s",sql.c_str());
        sqlite3_exec(pDB, sql.c_str(), nullptr, nullptr, nullptr);
    }else
    {//不需要保存 将密码设为空
        sql = "update information set value = '' where name = 'passwd'";//添加语句
        sqlite3_exec(pDB, sql.c_str(), nullptr, nullptr, nullptr);
    }
    
}

