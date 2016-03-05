//
//  HttpUtility.h
//  KYGame
//
//  Created by Kelvin on 16/3/5.
//
//

#ifndef HttpUtility_h
#define HttpUtility_h

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
    Layer* callerLayer;//调用它的对象
    
    //flag枚举
    enum HttpEnum
    {
        CHECKPASSWORD,//检查账号密码是否匹配
        LOADQUESTION,//加载验证问题
        CHECKVERSION,//检查版本
        LOADPLAYERINFO,//加载用户账号信息
        REGEDITACCOUNT,//注册账号
        LOADACCOUNT,//加载账号
        LOADSTATUS//加载用户状态
    };
    
    bool flag;
    
    
    CREATE_FUNC(HttpUtility);
    
    static std::string ip;
    
    HttpUtility();
    
    //各种回调函数
    void onCheckPassword(HttpClient *sender, HttpResponse *response);
    void onLoadQuestion(HttpClient *sender, HttpResponse *response);
    void onRegeditAccount(HttpClient *sender, HttpResponse *response);
    void onLoadPlayerInformation(HttpClient *sender, HttpResponse *response);
    void onLoadPlayerStatus(HttpClient *sender, HttpResponse *response);
    
public:
    
    //单例类获取
    static HttpUtility* getInstance(Layer* callerLayer);//调用它的对象
    static HttpUtility* getInstance();
    
    bool getFlag();
    
    ~HttpUtility();
    
    
    
    void checkPassword(std::string account, std::string password);//检查密码是否正确
    void loadQuestion(int num_question);//加载问题
    void regeditAccount(
                        std::string account,
                        std::string password,
                        std::string name,
                        bool role);//注册账号
    void loadPlayerInformation(std::string account);//加载玩家信息
    void loadPlayerStatus(int playerID);//加载玩家状态
    
    //bool checkVersion(std::string version);
};



#endif /* HttpUtility_h */
