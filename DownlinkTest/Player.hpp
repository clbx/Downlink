//
// Created by Clay Buxton on 7/26/2018.
//

#ifndef DOWNLINKTEST_PLAYER_HPP
#define DOWNLINKTEST_PLAYER_HPP


#include "Computer.hpp"

class Player
{
public:

	Player::Player(int level);
	int level;
	int money;

	//Network position
	Computer* currentPos;

private:


};


#endif //DOWNLINKTEST_PLAYER_HPP
