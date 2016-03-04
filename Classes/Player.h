#pragma once
/*��Ҷ���*/
#include "string"
#include "vector"
#include "map"

#include "cocos2d.h"

class Player : cocos2d::Node
{
public:
	Player();
	~Player();

	//����д����get set����
	int getPlayerID(){ return playerID; }
	void setPlayerID(int playerID){ this->playerID = playerID; }

	std::string getName(){ return name; }
	void setName(std::string name){ this->name = name; }

	int getClothID(){ return clothID; }
	void setClothID(int clothID){ this->clothID = clothID; }

	int getMoney(){ return money; }
	void setMoney(int money){ this->money = money; }

	int getCardID(){ return cardID; }
	void setCardID(){ this->cardID = cardID; }

	std::vector<int> getSkillsID(){ return skillsID; }
	void setSkillsID(std::vector<int> skills){ this->skillsID = skillsID; }

	int getExp(){ return exp; }
	void setExp(int exp){ this->exp = exp; }

	int getLevel(){ return level; }
	void setLevel(int level){ this->level = level; }

	int getCpID(){ return cpID; }
	void setCpID(int cpID){ this->cpID = cpID; }

	bool getRole(){ return role; }
	void setRole(bool role){ this->role = role; }

	bool getTop(){ return top; }
	void setTop(bool top){ this->top = top; }

	bool getPlayable(){ return playable; }
	void setPlayable(bool playable){ this->playable = playable; }

	bool getSpeakable(){ return speakable; }
	void setSpeakable(bool speakable){ this->speakable = speakable; }

	int getHonor(){ return honor; }
	void setHonor(int honor){ this->honor = honor; }


	//������ֵö��
	static enum ATTRIBUTE
	{
		BASE_POPULARITY,//��������
		BASE_BEAUTY,//������ֵ
		BASE_BOYABLITY,//����������
		BASE_LEADERSHIP,//�����쵼��
		BASE_ACTION, //�����ж���

		EXP_POPULARITY,//��������
		EXP_BEAUTY,//������ֵ
		EXP_BOYABLITY,//����������
		EXP_LEADERSHIP,//�����쵼��
		EXP_ACTION //�����ж���
	};
	std::map<Player::ATTRIBUTE, int> getAttributes(){ return attributes; }
	void setAttributes(std::map<Player::ATTRIBUTE, int> attributes){ this->attributes = attributes; }

private:
	int playerID;//���ID
	std::string name;//����ǳ�
	int clothID;//��װID
	int money;//��Ǯ��
	int cardID;//��ƬID
	std::vector<int> skillsID;//�弶����ID
	int exp;//����ֵ
	int level;//��ҵȼ�
	int cpID;//cp��ID
	bool role;//�Ƿ�Ϊ��
	bool top;//�Ƿ�Ϊ��
	bool playable;//�Ƿ����������Ϸ
	bool speakable;//�Ƿ����˵��
	int honor;//����ֵ

	std::map<Player::ATTRIBUTE, int> attributes;//������ֵ����ѯ��ɫ�͵ȼ����
	
};

