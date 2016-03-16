#include "HttpUtility.h"

#include "../model/Player.h"
#include "../scene/LogInScene.h"
#include "../scene/AuthenticationScene.h"
#include "../scene/RegeditScene.h"
#include "../scene/PropertyScene.hpp"

HttpClient* HttpUtility::httpClient = HttpClient::getInstance();
HttpUtility* HttpUtility::httpUtility = nullptr;
std::string HttpUtility::ip = "121.42.8.206";//我的服务器ip

HttpUtility::HttpUtility() {
    player = nullptr;
}



HttpUtility* HttpUtility::getInstance(Promptable* callerLayer){
	
	if (httpUtility == nullptr)
	{
		httpUtility = new HttpUtility();
	}
	httpUtility->callerLayer = callerLayer;

	return httpUtility;
}

HttpUtility* HttpUtility::getInstance(){
    
    if (httpUtility == nullptr)
    {
        httpUtility = new HttpUtility();
    }
    
    return httpUtility;
}

HttpUtility::~HttpUtility() {

}

Player* HttpUtility::getPlayer(){
    return player;
}

/******************检查账号密码是否正确****************/
void HttpUtility::checkPassword(std::string account, std::string password)
{
	HttpRequest * request = new HttpRequest();
	std::string url = "http://";
	url += ip + "/php/check_password.php";
	request->setUrl(url.c_str());
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(CC_CALLBACK_2(HttpUtility::onCheckPassword, this));
	std::string tag("%d", HttpEnum::CHECKPASSWORD);
	request->setTag(tag.c_str());

	std::string finalString = "account=\'";
	finalString = finalString + account + "\'&password=\'" + password + "\'&key=\'Kkdgx4cp\'";
	log("%s", finalString.c_str());
	request->setRequestData(finalString.c_str(), finalString.length() );
	this->httpClient->send(request);
	request->release();
    
    //加入等待转圈Layer，并吞噬下层事件
    auto scene = WaitLayer::create();
    callerLayer->addChild(scene);
    scene->setName("WaitLayer");
    
}

//checkPassword的回调函数
void HttpUtility::onCheckPassword(HttpClient *sender, HttpResponse *response)
{
    //去掉WaitLayer
    callerLayer->removeChildByName("WaitLayer");
    
    
    if (!response) {
        return;
    }
    
    int statusCode = response->getResponseCode();
    
    log("response code: %d", statusCode);
    
    if (!response->isSucceed()) {
        log("response failed");
        log("error buffer: %s", response->getErrorBuffer());
        ((AuthenticationScene*) this->callerLayer)->promptDialogBox("网络有屎，请倒立十分钟后连接"
                                                                    , AuthenticationScene::STATUS::LINK_ERROR);
        return;
    }
    
    __String *strTag = __String::create(response->getHttpRequest()->getTag());
    int tag = strTag->uintValue();
    log("request Action Code = %d", tag);
    
    std::vector<char> *responseData = response->getResponseData();
    std::string responseDataStr = std::string(responseData->begin(), responseData->end());
    
    //以上为公共部分
    
    if (statusCode == 200) {
        flag = DataUtility::decodeFlagData(responseDataStr);//解析返回的flag
        flag ? log("password is true") : log("password is wrong");
        if(flag)
        {//登录成功
            ((LogInScene*) this->callerLayer)->toHome();//密码正确，进入主页
        }else
        {//密码有误
            ((LogInScene*) this->callerLayer)->promptDialogBox("密码有误，请核对后输入");
        }
    }
    else {
        //服务器异常
        ((LogInScene*) this->callerLayer)->promptDialogBox("服务器连接异常，请倒立十分钟后重试");
    }
    
}




/*******************注册账号********************/
void HttpUtility::regeditAccount(std::string account,//’À∫≈
	std::string password,//√‹¬Î
	std::string name,//Í«≥∆
	bool role// «∑ÒŒ™ø≠
	)
{
	HttpRequest * request = new HttpRequest();
	std::string url = "http://";
	url += ip + "/php/add_new_player.php";
	CCLOG("url = %s", url.c_str());
	request->setUrl(url.c_str());
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(CC_CALLBACK_2(HttpUtility::onRegeditAccount, this));
	char tag[5];
	sprintf(tag, "%d", HttpEnum::REGEDITACCOUNT);
	CCLOG("%s", tag);
	request->setTag(tag);

	std::string finalString;
	char temp[100];
	sprintf(temp, "account=\'%s\'&password=\'%s\'&key=\'Kkdgx4cp\'&name=\'%s\'&role=\'%s\'",
		account.c_str(), password.c_str(), name.c_str(), role ? "1" : "0");
	finalString = temp;

	log("%s", finalString.c_str());
	request->setRequestData(finalString.c_str(), finalString.length());
	this->httpClient->send(request);
	request->release();
    
    
    //加入等待转圈Layer，并吞噬下层事件
    auto scene = WaitLayer::create();
    callerLayer->addChild(scene);
    scene->setName("WaitLayer");
    log("%s",scene->getName().c_str());
    scene->setVisible(true);
}

//regeditAccount的回调函数
void HttpUtility::onRegeditAccount(HttpClient *sender, HttpResponse *response)
{
    //去掉WaitLayer
    callerLayer->removeChildByName("WaitLayer");
    
    if (!response) {
        return;
    }
    
    int statusCode = response->getResponseCode();
    
    log("response code: %d", statusCode);
    
    if (!response->isSucceed()) {
        log("response failed");
        log("error buffer: %s", response->getErrorBuffer());
        ((AuthenticationScene*) this->callerLayer)->promptDialogBox("网络有屎，请倒立十分钟后连接"
                                                                    , AuthenticationScene::STATUS::LINK_ERROR);
        return;
    }
    
    __String *strTag = __String::create(response->getHttpRequest()->getTag());
    int tag = strTag->uintValue();
    log("request Action Code = %d", tag);
    
    std::vector<char> *responseData = response->getResponseData();
    std::string responseDataStr = std::string(responseData->begin(), responseData->end());
    
    //以上为公共部分
    
    if (statusCode == 200) {
        flag = DataUtility::decodeFlagData(responseDataStr);//是否注册成功
        if (flag)
        {//注册成功
            auto scene = Scene::create();
            
            auto layer = LogInScene::create();
            
            scene->addChild(layer);
            
            cocos2d::Director::getInstance()->replaceScene(scene);//转到登录页面
            ((LogInScene*) layer)->promptDialogBox("注册成功，欢迎进入这个大家庭");//弹出对话框
        }
        else
        {//注册失败
            ((RegeditScene*) this->callerLayer)->promptDialogBox("账号或昵称已存在（至于究竟是账号存在还是昵称已存在，开发者觉得判断实在是太麻烦了ZZZ）");//弹出对话框并进行回调
            
        }
    }
    else {
        //服务器连接异常
        ((RegeditScene*) this->callerLayer)->promptDialogBox("网络有屎，请倒立十分钟后重试");
    }
    
}


/******************加载验证问题*****************/
void HttpUtility::loadQuestion(int num_question)
{
	HttpRequest * request = new HttpRequest();
	std::string url = "http://";
	url += ip + "/php/load_question.php";
	CCLOG("url = %s", url.c_str());
	request->setUrl(url.c_str());
	request->setRequestType(HttpRequest::Type::POST);
    request->setResponseCallback(CC_CALLBACK_2(HttpUtility::onLoadQuestion, this));
	char tag[5];
	sprintf(tag,"%d", HttpEnum::LOADQUESTION);
	CCLOG("%s", tag);
	request->setTag(tag);

	char temp[60];
	std::string finalString = "num_question=";
	sprintf(temp, "%s%d&key=\'Kkdgx4cp\'", finalString.c_str(), num_question);
	finalString = temp;
	CCLOG("%s", finalString.c_str());
	request->setRequestData(finalString.c_str(), finalString.size()/sizeof(char));
	this->httpClient->send(request);
	request->release();
    
    
    //加入等待转圈Layer，并吞噬下层事件
    auto scene = WaitLayer::create();
    callerLayer->addChild(scene);
    scene->setName("WaitLayer");
    scene->setVisible(true);
}

//loadQuestion的回调函数
void HttpUtility::onLoadQuestion(HttpClient *sender, HttpResponse *response)
{
    //去掉WaitLayer
    callerLayer->removeChildByName("WaitLayer");
    
    if (!response) {
        return;
    }
    
    int statusCode = response->getResponseCode();
    
    log("response code: %d", statusCode);
    
    if (!response->isSucceed()) {
        log("response failed");
        log("error buffer: %s", response->getErrorBuffer());
        ((AuthenticationScene*) this->callerLayer)->promptDialogBox("网络有屎，请倒立十分钟后连接"
                                                                    , AuthenticationScene::STATUS::LINK_ERROR);
        return;
    }
    
    __String *strTag = __String::create(response->getHttpRequest()->getTag());
    int tag = strTag->uintValue();
    log("request Action Code = %d", tag);
    
    std::vector<char> *responseData = response->getResponseData();
    std::string responseDataStr = std::string(responseData->begin(), responseData->end());
    
    //以上为公共部分
    
    if (statusCode == 200) {
        //连接成功
        std::pair<std::vector<std::string>, std::vector<std::string>> question_answer
        = DataUtility::decodeQuestionData(responseDataStr);//解析问题
        ((AuthenticationScene*) this->callerLayer)->setQuestion(question_answer);//设置问题
    }
    else {
        //连接异常
        ((AuthenticationScene*) this->callerLayer)->promptDialogBox("服务器连接异常，请倒立十分钟后重试"
                                                                    ,AuthenticationScene::STATUS::LINK_ERROR);
    }

}


/*****************读取玩家信息******************/
void HttpUtility::loadPlayerInformation(int playerID,Player* player)
{
    setPlayer(player);
    HttpRequest * request = new HttpRequest();
    std::string url = "http://";
    url += ip + "/php/load_player_information.php";
    CCLOG("url = %s", url.c_str());
    request->setUrl(url.c_str());
    request->setRequestType(HttpRequest::Type::POST);
    request->setResponseCallback(CC_CALLBACK_2(HttpUtility::onLoadPlayerInformation, this));
    char tag[5];
    sprintf(tag,"%d", HttpEnum::LOADPLAYERINFO);
    CCLOG("%s", tag);
    request->setTag(tag);
    
    char temp[60];
    std::string finalString = "id=";
    sprintf(temp, "%s'%d'&key=\'Kkdgx4cp\'",finalString.c_str(), playerID);
    finalString = temp;
    CCLOG("%s", finalString.c_str());
    request->setRequestData(finalString.c_str(), finalString.size()/sizeof(char));
    this->httpClient->send(request);
    request->release();
    
    
    //加入等待转圈Layer，并吞噬下层事件
    auto scene = WaitLayer::create();
    callerLayer->addChild(scene);
    scene->setName("WaitLayer");
    scene->setVisible(true);
}

//loadPlayerInformation的回调函数
void HttpUtility::onLoadPlayerInformation(HttpClient *sender, HttpResponse *response)
{
    //去掉WaitLayer
    callerLayer->removeChildByName("WaitLayer");
    
    if (!response) {
        return;
    }
    
    int statusCode = response->getResponseCode();
    
    log("response code: %d", statusCode);
    
    if (!response->isSucceed()) {
        log("response failed");
        log("error buffer: %s", response->getErrorBuffer());
        ((AuthenticationScene*) this->callerLayer)->promptDialogBox("网络有屎，请倒立十分钟后连接"
                                                                    , AuthenticationScene::STATUS::LINK_ERROR);
        return;
    }
    
    __String *strTag = __String::create(response->getHttpRequest()->getTag());
    int tag = strTag->uintValue();
    log("request Action Code = %d", tag);
    
    std::vector<char> *responseData = response->getResponseData();
    std::string responseDataStr = std::string(responseData->begin(), responseData->end());
    
    //以上为公共部分
    
    if (statusCode == 200) {
        //连接成功
        DataUtility::decodeInformation(responseDataStr);
        if(typeid(LogInScene) == typeid(*callerLayer))
        {//如果调用它的是登录页面
            cocos2d::Director::getInstance()->replaceScene(PropertyScene::createScene());//切换到属性页面
        }
    }
    else {
        //连接异常
        ((AuthenticationScene*) this->callerLayer)->promptDialogBox("服务器连接异常，请倒立十分钟后重试"
                                                                    ,AuthenticationScene::STATUS::LINK_ERROR);
    }

}



/*****************账号转ID******************/
void HttpUtility::account2ID(std::string account)
{
    HttpRequest * request = new HttpRequest();
    std::string url = "http://";
    url += ip + "/php/account2id.php";
    CCLOG("url = %s", url.c_str());
    request->setUrl(url.c_str());
    request->setRequestType(HttpRequest::Type::POST);
    request->setResponseCallback(CC_CALLBACK_2(HttpUtility::onAccount2ID, this));
    char tag[5];
    sprintf(tag,"%d", HttpEnum::LOADACCOUNT);
    CCLOG("%s", tag);
    request->setTag(tag);
    
    char temp[60];
    std::string finalString = "account=";
    sprintf(temp, "%s'%s'&key=\'Kkdgx4cp\'",finalString.c_str(), account.c_str());
    finalString = temp;
    CCLOG("%s", finalString.c_str());
    request->setRequestData(finalString.c_str(), finalString.size()/sizeof(char));
    this->httpClient->send(request);
    request->release();
    
    
    //加入等待转圈Layer，并吞噬下层事件
    auto scene = WaitLayer::create();
    callerLayer->addChild(scene);
    scene->setName("WaitLayer");
    scene->setVisible(true);
}

//loadPlayerInformation的回调函数
void HttpUtility::onAccount2ID(HttpClient *sender, HttpResponse *response)
{
    //去掉WaitLayer
    callerLayer->removeChildByName("WaitLayer");
    
    if (!response) {
        return;
    }
    
    int statusCode = response->getResponseCode();
    
    log("response code: %d", statusCode);
    
    if (!response->isSucceed()) {
        log("response failed");
        log("error buffer: %s", response->getErrorBuffer());
        ((AuthenticationScene*) this->callerLayer)->promptDialogBox("网络有屎，请倒立十分钟后连接"
                                                                    , AuthenticationScene::STATUS::LINK_ERROR);
        return;
    }
    
    __String *strTag = __String::create(response->getHttpRequest()->getTag());
    int tag = strTag->uintValue();
    log("request Action Code = %d", tag);
    
    std::vector<char> *responseData = response->getResponseData();
    std::string responseDataStr = std::string(responseData->begin(), responseData->end());
    
    //以上为公共部分
    
    if (statusCode == 200) {
        setPlayer(Self::getInstance());
        //连接成功
        DataUtility::decodePlayerID(responseDataStr);
        
        //以此ID加载用户其他信息
        loadPlayerInformation(player->getPlayerID(),Self::getInstance());
        
    }
    else {
        //连接异常
        ((AuthenticationScene*) this->callerLayer)->promptDialogBox("服务器连接异常，请倒立十分钟后重试"
                                                                    ,AuthenticationScene::STATUS::LINK_ERROR);
    }
    
}

/*****************存储用户信息到服务器******************/
void HttpUtility::saveStatus()
{
    HttpRequest * request = new HttpRequest();
    std::string url = "http://";
    url += ip + "/php/save_player_status.php";
    CCLOG("url = %s", url.c_str());
    request->setUrl(url.c_str());
    request->setRequestType(HttpRequest::Type::POST);
    request->setResponseCallback(CC_CALLBACK_2(HttpUtility::onSaveStatus, this));
    char tag[5];
    sprintf(tag,"%d", HttpEnum::LOADACCOUNT);
    CCLOG("%s", tag);
    request->setTag(tag);
    
    char temp[1000];
    Player* player=Self::getInstance();
    auto attributes = player->getAttributes();
    auto skills = player->getSkillsID();
    log("%lu",skills.size());
    sprintf(temp, "query='UPDATE player_status SET money = \134\047%d\134\047, experiense = \134\047%d\134\047, popularity = \134\047%d\134\047, beauty = \134\047%d\134\047, boyablity = \134\047%d\134\047, leadership = \134\047%d\134\047, action = \134\047%d\134\047, clothID = \134\047%d\134\047, cardID = \134\047%d\134\047, honor = \134\047%d\134\047, skill_1_ID = \134\047%d\134\047, skill_2_ID = \134\047%d\134\047, skill_3_ID = \134\047%d\134\047, skill_4_ID = \134\047%d\134\047, skill_5_ID = \134\047%d\134\047, cpID = \134\047%d\134\047, top = \134\047%d\134\047 WHERE playerID = \134\047%d\134\047 '",
            player->getMoney(),player->getExp(),
            attributes[Player::ATTRIBUTE::BASE_POPULARITY]+attributes[Player::ATTRIBUTE::EXP_POPULARITY],
            attributes[Player::ATTRIBUTE::BASE_BEAUTY]+attributes[Player::ATTRIBUTE::EXP_BEAUTY],
            attributes[Player::ATTRIBUTE::BASE_BOYABLITY]+attributes[Player::ATTRIBUTE::EXP_BOYABLITY],
            attributes[Player::ATTRIBUTE::BASE_LEADERSHIP]+attributes[Player::ATTRIBUTE::EXP_LEADERSHIP],
            attributes[Player::ATTRIBUTE::BASE_ACTION]+attributes[Player::ATTRIBUTE::EXP_ACTION],
            player->getClothID(),player->getCardID(),player->getHonor(),
            skills.size()<=0?0:skills[0],skills.size()<=1?0:skills[1],skills.size()<=2?0:skills[2],skills.size()<=3?0:skills[3],skills.size()<=4?0:skills[4],
            player->getCpID(),player->getTop(),player->getPlayerID() );
    std::string finalString = temp;
    CCLOG("%s", finalString.c_str());
    request->setRequestData(finalString.c_str(), finalString.size()/sizeof(char));
    this->httpClient->send(request);
    request->release();
    
    
    //加入等待转圈Layer，并吞噬下层事件
    auto scene = WaitLayer::create();
    callerLayer->addChild(scene);
    scene->setName("WaitLayer");
    scene->setVisible(true);
}

//saveStatus的回调
void HttpUtility::onSaveStatus(HttpClient *sender, HttpResponse *response)
{
    //去掉WaitLayer
    callerLayer->removeChildByName("WaitLayer");
    
    if (!response) {
        return;
    }
    
    int statusCode = response->getResponseCode();
    
    log("response code: %d", statusCode);
    
    if (!response->isSucceed()) {
        log("response failed");
        log("error buffer: %s", response->getErrorBuffer());
        ((Promptable*) this->callerLayer)->promptDialogBox("网络有屎，请倒立十分钟后连接");
        return;
    }
    
    __String *strTag = __String::create(response->getHttpRequest()->getTag());
    int tag = strTag->uintValue();
    log("request Action Code = %d", tag);
    
    std::vector<char> *responseData = response->getResponseData();
    std::string responseDataStr = std::string(responseData->begin(), responseData->end());
    
    //以上为公共部分
    
    if (statusCode == 200) {
        //连接成功
        bool flag = DataUtility::decodeFlagData(responseDataStr);
        if(!flag)
        {//连接服务器失败
            static_cast<Promptable*>(callerLayer)->promptDialogBox("网络或服务器有屎，请倒立十分钟后重试");
        }
    }
    else {
        //连接异常
        ((Promptable*) this->callerLayer)->promptDialogBox("服务器连接异常，请倒立十分钟后重试");
    }
}


