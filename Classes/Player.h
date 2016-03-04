#pragma once
/*玩家对象*/
#include "string"
#include "vector"
#include "map"

#include "cocos2d.h"

class Player : cocos2d::Node
{
public:
	Player();
	~Player();

	//下面写各种get set方法
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


	//各属性值枚举
	static enum ATTRIBUTE
	{
		BASE_POPULARITY,//基础人气
		BASE_BEAUTY,//基础颜值
		BASE_BOYABLITY,//基础男友力
		BASE_LEADERSHIP,//基础领导力
		BASE_ACTION, //基础行动力

		EXP_POPULARITY,//附加人气
		EXP_BEAUTY,//附加颜值
		EXP_BOYABLITY,//附加男友力
		EXP_LEADERSHIP,//附加领导力
		EXP_ACTION //附加行动力
	};
	std::map<Player::ATTRIBUTE, int> getAttributes(){ return attributes; }
	void setAttributes(std::map<Player::ATTRIBUTE, int> attributes){ this->attributes = attributes; }

private:
	int playerID;//玩家ID
	std::string name;//玩家昵称
	int clothID;//服装ID
	int money;//金钱数
	int cardID;//卡片ID
	std::vector<int> skillsID;//五级技能ID
	int exp;//经验值
	int level;//玩家等级
	int cpID;//cp的ID
	bool role;//是否为凯
	bool top;//是否为攻
	bool playable;//是否允许进入游戏
	bool speakable;//是否可以说话
	int honor;//荣誉值

	std::map<Player::ATTRIBUTE, int> attributes;//各属性值，查询角色和等级获得
	
};

