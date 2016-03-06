#pragma once

#include "Player.h"
#include "../utility/HttpUtility.h"

/*玩家自身，单例类*/
class Self :public Player 
{
public:
	~Self();
	static Self* getInstance();//获取实例
	
	void loadInformationFromInternet();//从服务器上加载用户信息
	void loadStatusFromInternet();//从服务器上加载用户状态

	void saveStatusToInternet();//上传用户信息到服务器

	//void loadInforamtionFromLocal();//从本地记载用户信息


	//bool PKWithByID(int otherPlayerID);//通过ID与另一玩家PK
	//bool PKWithByPlayer(Player otherPlayer);//通过Player类与另一玩家PK
	//void updateData();
private:
	Player* player;
	Self();
	static Self* self;
};

