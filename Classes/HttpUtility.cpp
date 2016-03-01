#include "HttpUtility.h"


HttpClient* HttpUtility::httpClient = HttpClient::getInstance();
HttpUtility* HttpUtility::httpUtility = nullptr;
std::string HttpUtility::ip = "121.42.8.206";//������ip

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

//�����������ע���˺�
void HttpUtility::regeditAccount(std::string account,//�˺�
	std::string password,//����
	std::string name,//�ǳ�
	bool role//�Ƿ�Ϊ��
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


//��¼ʱ�����˺ż����û���Ϣ
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

//ͨ��id�����û�״̬
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


/******************http�ص�************/
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
		/**********************���������Ƿ���ȷ*********************/
	case HttpEnum::CHECKPASSWORD:
		if (statusCode == 200) {
			flag = DataUtility::decodeFlagData(responseDataStr);//�����Ƿ���ȷ
			flag ? log("password is true") : log("password is wrong");
			flag ? ((LogInScene*) this->callerLayer)->promptDialogBox("log in!!")
				: ((LogInScene*) this->callerLayer)->promptDialogBox("password is wrong");//ʹloginҳ�浯����ʾ��
		}
		else {
			//�������쳣
			((LogInScene*) this->callerLayer)->promptDialogBox("there exist some error in Internet, please react");
		}
		break;
		/******************������֤����*****************************/
	case HttpEnum::LOADQUESTION:
		if (statusCode == 200) {
			//��������ɹ�
			std::pair<std::vector<std::string>, std::vector<std::string>> question_answer 
				= DataUtility::decodeQuestionData(responseDataStr);//����json��ʽ������
			((AuthenticationScene*) this->callerLayer)->setQuestion(question_answer);//������ʹ𰸴�����֤ҳ��
		}
		else {
			//�������쳣
			((AuthenticationScene*) this->callerLayer)->promptDialogBox("there exist some error in Internet, please react"
				,AuthenticationScene::STATUS::LINK_ERROR);
		}
		break;
		/*****************************ע���˺�****************************/
	case HttpEnum::REGEDITACCOUNT:
		if (statusCode == 200) {
			flag = DataUtility::decodeFlagData(responseDataStr);//ע���Ƿ�ɹ�
			flag ? CCLOG("%s", "regedit succeed!") : CCLOG("%s", "regedit error!");
			if (flag)
			{//ע��ɹ�

				((RegeditScene*) this->callerLayer)->promptDialogBox("regedit suceed!",
					RegeditScene::STATUS::SUCCEED);//ʹloginҳ�浯����ʾ��
			}
			else
			{//�˺Ż��ǳ��Ѵ���
				((RegeditScene*) this->callerLayer)->promptDialogBox("there is the same account or name already",
					RegeditScene::STATUS::ACCOUNTEXIST);//ʹloginҳ�浯����ʾ��

			}
		}
		else {
			//�������쳣
			((RegeditScene*) this->callerLayer)->promptDialogBox("there exist some error in Internet, please react",
				RegeditScene::STATUS::LINK_ERROR);
		}
		break;
	case HttpEnum::LOADACCOUNT : 
		if (statusCode == 200) {
			DataUtility::getInstance()->decodeInformation(responseDataStr);
		}
		else {
			//�������쳣
			((RegeditScene*) this->callerLayer)->promptDialogBox("there exist some error in Internet, please react",
				RegeditScene::STATUS::LINK_ERROR);
		}
		break;
	case HttpEnum::LOADSTATUS:
		if (statusCode == 200) {
			DataUtility::getInstance()->decodeStatus(responseDataStr);
		}
		else {
			//�������쳣
			((RegeditScene*) this->callerLayer)->promptDialogBox("there exist some error in Internet, please react",
				RegeditScene::STATUS::LINK_ERROR);
		}
		break;
	default:
		break;
	}
}



