#pragma once

#include "Player.h"
#include "../utility/HttpUtility.h"

/*�������������*/
class Self :public Player 
{
public:
	~Self();
	static Self* getInstance();//��ȡʵ��
	
	void loadInformationFromInternet();//�ӷ������ϼ����û���Ϣ
	void loadStatusFromInternet();//�ӷ������ϼ����û�״̬

	void saveStatusToInternet();//�ϴ��û���Ϣ��������

	//void loadInforamtionFromLocal();//�ӱ��ؼ����û���Ϣ


	//bool PKWithByID(int otherPlayerID);//ͨ��ID����һ���PK
	//bool PKWithByPlayer(Player otherPlayer);//ͨ��Player������һ���PK
	//void updateData();
private:
	Player* player;
	Self();
	static Self* self;
};

