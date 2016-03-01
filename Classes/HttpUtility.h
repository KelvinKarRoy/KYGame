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
		CHECKPASSWORD,//检查账号密码是否匹配
		LOADQUESTION,//加载问题
		CHECKVERSION,//检查是否为最新版
		LOADPLAYERINFO,//根据账号，加载用户信息
		REGEDITACCOUNT, //注册账号
		LOADACCOUNT,//加载用户信息
		LOADSTATUS//加载用户状态
	};

	bool flag;
	
	//实现 static create()函数的宏
	CREATE_FUNC(HttpUtility);

	static std::string ip;
	
	HttpUtility();

public:
	//获取单例类
	static HttpUtility* getInstance(Layer* callerLayer);//传入的是调用它的层
	static HttpUtility* getInstance();

	bool getFlag();
	
	~HttpUtility();



	void checkPassword(std::string account, std::string password);//检测账号密码
	void loadQuestion(int num_question);//加载验证问题
	
	//注册账号密码，不提供合法性检测，需在外层进行
	void regeditAccount(std::string account,//账号
		std::string password,//密码
		std::string name,//名字
		bool role//是否为凯
		);
	//bool checkVersion(std::string version);//检查版本

	//http回调
	void onHttpRequestCompleted(HttpClient *sender, HttpResponse *response);

	//登录时根据账号加载用户信息
	void loadPlayerInformation(std::string account);

	//通过id加载用户状态
	void loadPlayerStatus(int playerID);
};

