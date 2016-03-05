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
    
    enum HttpEnum
    {
        CHECKPASSWORD,
        LOADQUESTION,
        CHECKVERSION,
        LOADPLAYERINFO,
        REGEDITACCOUNT,
        LOADACCOUNT,
        LOADSTATUS
    };
    
    bool flag;
    
    
    CREATE_FUNC(HttpUtility);
    
    static std::string ip;
    
    HttpUtility();
    
public:
    
    //单例类获取
    static HttpUtility* getInstance(Layer* callerLayer);//调用它的对象
    static HttpUtility* getInstance();
    
    bool getFlag();
    
    ~HttpUtility();
    
    
    //检查密码是否正确
    void checkPassword(std::string account, std::string password);
    void onCheckPassword(HttpClient *sender, HttpResponse *response);

    
    //加载问题
    void loadQuestion(int num_question);
    void onLoadQuestion(HttpClient *sender, HttpResponse *response);

    
    //注册账号
    void regeditAccount(
                        std::string account,
                        std::string password,
                        std::string name,
                        bool role);
    void onRegeditAccount(HttpClient *sender, HttpResponse *response);
    
    //bool checkVersion(std::string version);
    
    void onHttpRequestCompleted(HttpClient *sender, HttpResponse *response);
    
    //加载玩家信息
    void loadPlayerInformation(std::string account);
    void onLoadPlayerInformation(HttpClient *sender, HttpResponse *response);

    
    //加载玩家状态
    void loadPlayerStatus(int playerID);
    void onLoadPlayerStatus(HttpClient *sender, HttpResponse *response);
};



#endif /* HttpUtility_h */
