#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}


void Player::expTolevel()
{//经验值转化为等级
    GCCsvHelper *csv = new GCCsvHelper();
    csv->openAndResolveFile("db/exp.csv");
    
    for (int i = 0; i < csv->getRowLength(); ++i) {
        if(atoi(csv->getData(i, 1))>this->exp)
        {
            this->level = i;
            break;
        }
    }
    
    delete csv;
    
}
