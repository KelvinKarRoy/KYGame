#include "HttpUtility.h"


HttpClient* HttpUtility::httpClient = HttpClient::getInstance();
HttpUtility* HttpUtility::httpUtility = nullptr;
std::string HttpUtility::ip = "121.42.8.206";//服务器ip

HttpUtility::HttpUtility() {

}

HttpUtility* HttpUtility::getInstance(){

	if (httpUtility == nullptr)
	{
		httpUtility = new HttpUtility();
	}
	
	return httpUtility;
}


HttpUtility* HttpUtility::getInstance(Layer* callerLayer){
	
	if (httpUtility == nullptr)
	{
		httpUtility = new HttpUtility();
	}
	httpUtility->callerLayer = callerLayer;

	return httpUtility;
}

HttpUtility::~HttpUtility() {

}

void HttpUtility::checkPassword(std::string account, std::string password)
{
	HttpRequest * request = new HttpRequest();
	std::string url = "http://";
	url += ip + "/php/check_password.php";
	request->setUrl(url.c_str());
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(CC_CALLBACK_2(HttpUtility::onHttpRequestCompleted, this));
	std::string tag("%d", HttpEnum::CHECKPASSWORD);
	request->setTag(tag.c_str());

	std::string finalString = "account=\'";
	finalString = finalString + account + "\'&password=\'" + password + "\'&key=\'Kkdgx4cp\'";
	log("%s", finalString.c_str());
	request->setRequestData(finalString.c_str(), finalString.length() );
	this->httpClient->send(request);
	request->release();

}

//向服务器申请注册账号
void HttpUtility::regeditAccount(std::string account,//账号
	std::string password,//密码
	std::string name,//昵称
	bool role//是否为凯
	)
{
	HttpRequest * request = new HttpRequest();
	std::string url = "http://";
	url += ip + "/php/add_new_player.php";
	CCLOG("url = %s", url.c_str());
	request->setUrl(url.c_str());
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(CC_CALLBACK_2(HttpUtility::onHttpRequestCompleted, this));
	char tag[5];
	sprintf(tag, "%d", HttpEnum::REGEDITACCOUNT);
	CCLOG("%s", tag);
	request->setTag(tag);

	std::string finalString;
	char temp[100];
	sprintf(temp, "account=\'%s\'&password=\'%s\'&key=\'Kkdgx4cp\'&name=\'%s\'&role=%s",
		account.c_str(), password.c_str(), name.c_str(), role ? "true" : "false");
	finalString = temp;

	CCLOG("%s", finalString.c_str());
	request->setRequestData(finalString.c_str(), finalString.length());
	this->httpClient->send(request);
	request->release();
}

void HttpUtility::loadQuestion(int num_question)
{
	HttpRequest * request = new HttpRequest();
	std::string url = "http://";
	url += ip + "/php/load_question.php";
	CCLOG("url = %s", url.c_str());
	request->setUrl(url.c_str());
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(CC_CALLBACK_2(HttpUtility::onHttpRequestCompleted, this));
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
}


//登录时根据账号加载用户信息
void HttpUtility::loadPlayerInformation(std::string account)
{
	HttpRequest * request = new HttpRequest();
	std::string url = "http://";
	url += ip + "/php/account2information.php";
	request->setUrl(url.c_str());
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(CC_CALLBACK_2(HttpUtility::onHttpRequestCompleted, this));
	std::string tag("%d", HttpEnum::LOADACCOUNT);
	request->setTag(tag.c_str());

	std::string finalString = "account=\'";
	finalString = finalString + account + "\'&key=\'Kkdgx4cp\'";
	log("%s", finalString.c_str());
	request->setRequestData(finalString.c_str(), finalString.length());
	this->httpClient->send(request);
	request->release();
}

//通过id加载用户状态
void HttpUtility::loadPlayerStatus(int playerID)
{
	HttpRequest * request = new HttpRequest();
	std::string url = "http://";
	url += ip + "/php/load_player_status.php";
	request->setUrl(url.c_str());
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(CC_CALLBACK_2(HttpUtility::onHttpRequestCompleted, this));
	std::string tag("%d", HttpEnum::LOADSTATUS);
	request->setTag(tag.c_str());
	
	char temp[35];
	sprintf(temp,"account=\'%d\'&key=\'Kkdgx4cp\'");
	std::string finalString(temp);
	log("%s", finalString.c_str());
	request->setRequestData(finalString.c_str(), finalString.length());
	this->httpClient->send(request);
	request->release();
}


/******************http回调************/
void HttpUtility::onHttpRequestCompleted(HttpClient *sender, HttpResponse *response){

	if (!response) {
		return;
	}

	log("%s", response->getResponseHeader());

	int statusCode = response->getResponseCode();

	log("response code: %d", statusCode);

	if (!response->isSucceed()) {
		log("response failed");
		log("error buffer: %s", response->getErrorBuffer());
		((AuthenticationScene*) this->callerLayer)->promptDialogBox("there exist some error in Internet, please react"
			, AuthenticationScene::STATUS::LINK_ERROR);
		return;
	}

	__String *strTag = __String::create(response->getHttpRequest()->getTag());
	int tag = strTag->uintValue();
	log("request Action Code = %d", tag);

	std::vector<char> *responseData = response->getResponseData();
	std::string responseDataStr = std::string(responseData->begin(), responseData->end());
	log("%s", responseDataStr.c_str());

	switch (tag) {
		/**********************检验密码是否正确*********************/
	case HttpEnum::CHECKPASSWORD:
		if (statusCode == 200) {
			flag = DataUtility::decodeFlagData(responseDataStr);//密码是否正确
			flag ? log("password is true") : log("password is wrong");
			flag ? ((LogInScene*) this->callerLayer)->promptDialogBox("log in!!")
				: ((LogInScene*) this->callerLayer)->promptDialogBox("password is wrong");//使login页面弹出提示框
		}
		else {
			//服务器异常
			((LogInScene*) this->callerLayer)->promptDialogBox("there exist some error in Internet, please react");
		}
		break;
		/******************加载验证问题*****************************/
	case HttpEnum::LOADQUESTION:
		if (statusCode == 200) {
			//加载问题成功
			std::pair<std::vector<std::string>, std::vector<std::string>> question_answer 
				= DataUtility::decodeQuestionData(responseDataStr);//解析json格式的问题
			((AuthenticationScene*) this->callerLayer)->setQuestion(question_answer);//将问题和答案传给验证页面
		}
		else {
			//服务器异常
			((AuthenticationScene*) this->callerLayer)->promptDialogBox("there exist some error in Internet, please react"
				,AuthenticationScene::STATUS::LINK_ERROR);
		}
		break;
		/*****************************注册账号****************************/
	case HttpEnum::REGEDITACCOUNT:
		if (statusCode == 200) {
			flag = DataUtility::decodeFlagData(responseDataStr);//注册是否成功
			flag ? CCLOG("%s", "regedit succeed!") : CCLOG("%s", "regedit error!");
			if (flag)
			{//注册成功

				((RegeditScene*) this->callerLayer)->promptDialogBox("regedit suceed!",
					RegeditScene::STATUS::SUCCEED);//使login页面弹出提示框
			}
			else
			{//账号或昵称已存在
				((RegeditScene*) this->callerLayer)->promptDialogBox("there is the same account or name already",
					RegeditScene::STATUS::ACCOUNTEXIST);//使login页面弹出提示框

			}
		}
		else {
			//服务器异常
			((RegeditScene*) this->callerLayer)->promptDialogBox("there exist some error in Internet, please react",
				RegeditScene::STATUS::LINK_ERROR);
		}
		break;
	case HttpEnum::LOADACCOUNT : 
		if (statusCode == 200) {
			DataUtility::getInstance()->decodeInformation(responseDataStr);
		}
		else {
			//服务器异常
			((RegeditScene*) this->callerLayer)->promptDialogBox("there exist some error in Internet, please react",
				RegeditScene::STATUS::LINK_ERROR);
		}
		break;
	case HttpEnum::LOADSTATUS:
		if (statusCode == 200) {
			DataUtility::getInstance()->decodeStatus(responseDataStr);
		}
		else {
			//服务器异常
			((RegeditScene*) this->callerLayer)->promptDialogBox("there exist some error in Internet, please react",
				RegeditScene::STATUS::LINK_ERROR);
		}
		break;
	default:
		break;
	}
}



