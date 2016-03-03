#include "HttpUtility.h"


HttpClient* HttpUtility::httpClient = HttpClient::getInstance();
HttpUtility* HttpUtility::httpUtility = nullptr;
std::string HttpUtility::ip = "121.42.8.206";//我的服务器ip

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

//œÚ∑˛ŒÒ∆˜…Í«Î◊¢≤·’À∫≈
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


//µ«¬º ±∏˘æ›’À∫≈º”‘ÿ”√ªß–≈œ¢
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

//Õ®π˝idº”‘ÿ”√ªß◊¥Ã¨
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


/******************httpªÿµ˜************/
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
		/**********************检查密码是否正确*********************/
	case HttpEnum::CHECKPASSWORD:
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
		break;
		/******************加载验证问题*****************************/
	case HttpEnum::LOADQUESTION:
		if (statusCode == 200) {
			//º”‘ÿŒ Ã‚≥…π¶
			std::pair<std::vector<std::string>, std::vector<std::string>> question_answer 
				= DataUtility::decodeQuestionData(responseDataStr);//Ω‚Œˆjson∏Ò ΩµƒŒ Ã‚
			((AuthenticationScene*) this->callerLayer)->setQuestion(question_answer);//Ω´Œ Ã‚∫Õ¥∞∏¥´∏¯—È÷§“≥√Ê
		}
		else {
			//∑˛ŒÒ∆˜“Ï≥£
			((AuthenticationScene*) this->callerLayer)->promptDialogBox("服务器连接异常，请倒立十分钟后重试"
				,AuthenticationScene::STATUS::LINK_ERROR);
		}
		break;
		/*****************************注册账号****************************/
	case HttpEnum::REGEDITACCOUNT:
		if (statusCode == 200) {
			flag = DataUtility::decodeFlagData(responseDataStr);//是否注册成功
			flag ? CCLOG("%s", "regedit succeed!") : CCLOG("%s", "regedit error!");
			if (flag)
			{//注册成功

				((RegeditScene*) this->callerLayer)->promptDialogBox("注册成功，欢迎进入这个大家庭",
					RegeditScene::STATUS::SUCCEED);//弹出对话框并进行回调
			}
			else
			{//注册失败
				((RegeditScene*) this->callerLayer)->promptDialogBox("账号或昵称已存在（至于究竟是账号存在还是昵称已存在，开发者觉得判断实在是太麻烦了ZZZ）",
					RegeditScene::STATUS::ACCOUNTEXIST);//弹出对话框并进行回调

			}
		}
		else {
			//服务器连接异常
			((RegeditScene*) this->callerLayer)->promptDialogBox("网络有屎，请倒立十分钟后重试",
				RegeditScene::STATUS::LINK_ERROR);
		}
		break;
	case HttpEnum::LOADACCOUNT : 
		if (statusCode == 200) {
			DataUtility::getInstance()->decodeInformation(responseDataStr);
		}
		else {
			//∑˛ŒÒ∆˜“Ï≥£
			((RegeditScene*) this->callerLayer)->promptDialogBox("网络有屎，请倒立十分钟后重试",
				RegeditScene::STATUS::LINK_ERROR);
		}
		break;
	case HttpEnum::LOADSTATUS:
		if (statusCode == 200) {
			DataUtility::getInstance()->decodeStatus(responseDataStr);
		}
		else {
			//∑˛ŒÒ∆˜“Ï≥£
			((RegeditScene*) this->callerLayer)->promptDialogBox("网络有屎，请倒立十分钟后重试",
				RegeditScene::STATUS::LINK_ERROR);
		}
		break;
	default:
		break;
	}
}



