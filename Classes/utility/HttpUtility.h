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
#include "../scene/WaitLayer.hpp"

class Player;

using namespace cocos2d;
using namespace cocos2d::network;

class HttpUtility
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
        LOADACCOUNT,//账号转ID
    };
    
    bool flag;
    
    static std::string ip;
    
    HttpUtility();
    
    Player* player;
    //各种回调函数
    void onCheckPassword(HttpClient *sender, HttpResponse *response);//检查账号密码是否匹配
    void onLoadQuestion(HttpClient *sender, HttpResponse *response);//加载验证问题
    void onRegeditAccount(HttpClient *sender, HttpResponse *response);//注册账号
    void onLoadPlayerInformation(HttpClient *sender, HttpResponse *response);//加载用户信息
    void onAccount2ID(HttpClient *sender, HttpResponse *response);//账号转化成id
    
public:
    
    //单例类获取
    static HttpUtility* getInstance(Layer* callerLayer);//调用它的对象
    static HttpUtility* getInstance();
    
    bool getFlag();
    
    ~HttpUtility();
    
    Player* getPlayer();
    void setPlayer(Player* player){ this->player = player; }
    
    void checkPassword(std::string account, std::string password);//检查密码是否正确
    void loadQuestion(int num_question);//加载问题
    void regeditAccount(
                        std::string account,
                        std::string password,
                        std::string name,
                        bool role);//注册账号
    void loadPlayerInformation(int playerID,Player* player);//加载玩家信息
    void account2ID(std::string account);//account转id
    
    //bool checkVersion(std::string version);
};



#endif /* HttpUtility_h */