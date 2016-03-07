//
//  Self.h
//  KYGame
//
//  Created by Kelvin on 16/3/7.
//
//

#ifndef Self_h
#define Self_h



#include "Player.h"

/*单例类，玩家自身*/
class Self :
    public Player
{
public:
    ~Self();
    static Self* getInstance();//ªÒ»° µ¿˝
    
    //void loadInformationFromInternet();//¥”∑˛ŒÒ∆˜…œº”‘ÿ”√ªß–≈œ¢
    //void loadStatusFromInternet();//¥”∑˛ŒÒ∆˜…œº”‘ÿ”√ªß◊¥Ã¨
    
    //void saveStatusToInternet();//…œ¥´”√ªß–≈œ¢µΩ∑˛ŒÒ∆˜
    
    //void loadInforamtionFromLocal();//¥”±æµÿº«‘ÿ”√ªß–≈œ¢
    
    
    //bool PKWithByID(int otherPlayerID);//Õ®π˝ID”Î¡Ì“ªÕÊº“PK
    //bool PKWithByPlayer(Player otherPlayer);//Õ®π˝Player¿‡”Î¡Ì“ªÕÊº“PK
    //void updateData();
private:
    Player* player;
    Self();
    static Self* self;
};



#endif /* Self_h */
