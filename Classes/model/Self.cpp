#include "Self.h"

Self* Self::self = nullptr;

Self::Self()
{
	
	//∂¡»°”√ªß◊ ¡œ
	std::map<Player::ATTRIBUTE, int> attribute;
	attribute[Player::ATTRIBUTE::BASE_ACTION] = 110;
	attribute[Player::ATTRIBUTE::BASE_BEAUTY] = 110;
	attribute[Player::ATTRIBUTE::BASE_BOYABLITY] = 110;
	attribute[Player::ATTRIBUTE::BASE_LEADERSHIP] = 40;
	attribute[Player::ATTRIBUTE::BASE_POPULARITY] = 60;
	attribute[Player::ATTRIBUTE::EXP_ACTION] = 30;
	attribute[Player::ATTRIBUTE::EXP_BEAUTY] = 40;
	attribute[Player::ATTRIBUTE::EXP_BOYABLITY] = 50;
	attribute[Player::ATTRIBUTE::EXP_LEADERSHIP] = 20;
	attribute[Player::ATTRIBUTE::EXP_POPULARITY] = 30;

	setAttributes(attribute);

	setHonor(50);
    setExp(5450);
    expTolevel();
	setPlayerID(921118);
	setName("Kelvin");
	setCpID(1642127033);
}

Self::~Self()
{

}

Self* Self::getInstance()
{
	if (self == nullptr)
	{
		self = new Self();
	}
	return self;
}
/*
bool Self::PKWithByID(int otherPlayerID)
{
	//œ»Õ®π˝IDµ√µΩPlayer¿‡
	Player otherPlayer = HttpUtility::getInstance()->getPlayerByID(otherPlayerID);

	return PKWithByPlayer(otherPlayer);


	
}

bool Self::PKWithByPlayer(Player otherPlayer)
{
	//¡Ω’ﬂæˆ∂∑
	return true;
}

 */

//¥”∑˛ŒÒ∆˜…œº”‘ÿ”√ªß–≈œ¢
void Self::loadInformationFromInternet()
{
	
}

//¥”∑˛ŒÒ∆˜…œº”‘ÿ”√ªß◊¥Ã¨
void loadStatusFromInternet()
{

}

//…œ¥´”√ªß–≈œ¢µΩ∑˛ŒÒ∆˜
void saveStatusToInternet()
{

}
