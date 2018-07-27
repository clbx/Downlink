//
// Created by Clay Buxton on 7/26/2018.
//

#include <iostream>
#include <string>

#ifndef DOWNLINKTEST_COMPUTER_HPP
#define DOWNLINKTEST_COMPUTER_HPP

using namespace std;

class Computer
{
public:
    Computer::Computer(int level, bool hidden, string name, int money);
    void setPos(Computer* up, Computer* right, Computer* down, Computer * left);

    int level;
    bool hidden;
    string name;
    int money = 0;

    Computer* up = nullptr;
    Computer* down = nullptr;
    Computer* right = nullptr;
    Computer* left = nullptr;

private:
};


#endif //DOWNLINKTEST_COMPUTER_HPP
