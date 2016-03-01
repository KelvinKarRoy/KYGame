#pragma once

#include "cocos2d.h"
#include "network/HttpClient.h"
#include "cstdio"

#include "json/rapidjson.h"
#include "DataUtility.h"
#include "LogInScene.h"
#include "AuthenticationScene.h"
#include "RegeditScene.h"
#include "Player.h"

using namespace cocos2d;
using namespace cocos2d::network;

class HttpUtility : public Node
{
private:
	static HttpClient* httpClient;
	static HttpUtility* httpUtility;
	Layer* callerLayer;

	enum HttpEnum
	{
		CHECKPASSWORD,//����˺������Ƿ�ƥ��
		LOADQUESTION,//��������
		CHECKVERSION,//����Ƿ�Ϊ���°�
		LOADPLAYERINFO,//�����˺ţ������û���Ϣ
		REGEDITACCOUNT, //ע���˺�
		LOADACCOUNT,//�����û���Ϣ
		LOADSTATUS//�����û�״̬
	};

	bool flag;
	
	//ʵ�� static create()�����ĺ�
	CREATE_FUNC(HttpUtility);

	static std::string ip;
	
	HttpUtility();

public:
	//��ȡ������
	static HttpUtility* getInstance(Layer* callerLayer);//������ǵ������Ĳ�
	static HttpUtility* getInstance();

	bool getFlag();
	
	~HttpUtility();



	void checkPassword(std::string account, std::string password);//����˺�����
	void loadQuestion(int num_question);//������֤����
	
	//ע���˺����룬���ṩ�Ϸ��Լ�⣬����������
	void regeditAccount(std::string account,//�˺�
		std::string password,//����
		std::string name,//����
		bool role//�Ƿ�Ϊ��
		);
	//bool checkVersion(std::string version);//���汾

	//http�ص�
	void onHttpRequestCompleted(HttpClient *sender, HttpResponse *response);

	//��¼ʱ�����˺ż����û���Ϣ
	void loadPlayerInformation(std::string account);

	//ͨ��id�����û�״̬
	void loadPlayerStatus(int playerID);
};

