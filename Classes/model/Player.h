//
//  Player.h
//  KYGame
//
//  Created by Kelvin on 16/3/6.
//
//

#ifndef Player_h
#define Player_h


#include "string"
#include "vector"
#include "map"

#include "cocos2d.h"

#include "../utility/GCCsvHelper.hpp"
#include "../utility/HttpUtility.h"


class Player : cocos2d::Node
{
public:
    Player();
    ~Player();
    
    //
    int getPlayerID(){ return playerID; }
    void setPlayerID(int playerID){ this->playerID = playerID; }
    
    std::string getName(){ return name; }
    void setName(std::string name){ this->name = name; }
    
    int getClothID(){ return clothID; }
    void setClothID(int clothID){ this->clothID = clothID; }
    
    int getMoney(){ return money; }
    void setMoney(int money){ this->money = money; }
    
    int getCardID(){ return cardID; }
    void setCardID(int cardID){ this->cardID = cardID; }
    
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
    
    
    //∏˜ Ù–‘÷µ√∂æŸ
    static enum ATTRIBUTE
    {
        BASE_POPULARITY,//
        BASE_BEAUTY,//
        BASE_BOYABLITY,//
        BASE_LEADERSHIP,//
        BASE_ACTION, //
        
        EXP_POPULARITY,//
        EXP_BEAUTY,//
        EXP_BOYABLITY,//
        EXP_LEADERSHIP,//
        EXP_ACTION //
    };
    std::map<Player::ATTRIBUTE, int> getAttributes(){ return attributes; }
    void setAttributes(std::map<Player::ATTRIBUTE, int> attributes){ this->attributes = attributes; }
    void expTolevel();
private:
    int playerID;//
    std::string name;//
    int clothID;//
    int money;//
    int cardID;//
    std::vector<int> skillsID;//
    int exp;//
    int level;//
    int cpID;//
    bool role;//
    bool top;//
    bool playable;//
    bool speakable;//
    int honor;//
    
    std::map<Player::ATTRIBUTE, int> attributes;//
    
    
    
    
};



#endif /* Player_h */
