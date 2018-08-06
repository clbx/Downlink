//
// Created by Tyler McLemore on 7/26/2018.
//

#include "Computer.hpp"

///
/// \param level: The level of the computer to be hacked
/// \param hidden: Whether or not it's hidden
/// \param name: The display name of the computer
/// \param money: The amount of money held in that computer. Fight me
Computer::Computer(int level, bool hidden, string name, int money)
{
	this->hidden = hidden;
	this->level = level;
	this->name = name;
	this->money = money;
}

///
/// \param up
/// \param right
/// \param down
/// \param left
void Computer::setPos(Computer* up, Computer* right, Computer* down, Computer * left)
{
	this->up = up;
	this->down = down;
	this->right = right;
	this->left = left;
}

