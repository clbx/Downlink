#include <iostream>
#include "Player.hpp"
#include "Computer.hpp"

using namespace std;

int main()
{
	std::cout << "Welcome to the Matrix" << std::endl;

	Player player = Player::Player(1);
	player.money = 500;

	/*
	 * |----------|---------|---------|
	 * | RealEste2| Bnk Cor4| Trsury5 |
	 * |----------|---------|---------|
	 * | Neighbr1 | Bnkbran3|         |
	 * |----------|---------|---------|
	 * |  Gateway0|Supermkt1| Corpor2 |
	 * |----------|---------|---------|
	 *
	 */


    //Creating computers in network
    Computer gateway = Computer::Computer(0,false,"Gateway", 0);
    Computer neighbor = Computer::Computer(1,false,"Neighbors House",50);
	Computer supermarket = Computer::Computer(1,false,"Dwarf Supermarket 45th Street",150);
	Computer superCorp = Computer::Computer(2,false,"Dwarf Supermarket Corporate",200);
	Computer realEstate = Computer::Computer(2,false,"Ferkbire Nathaway Real Estate",200);
	Computer bank = Computer::Computer(3,false,"Peoples 1st Bank, 45th Street",300);
	Computer bankCorp = Computer::Computer(4,false,"Peoples 1st Bank Corporate",400);
	Computer treasury = Computer::Computer(5,false,"United States Treasury",500);


	//Networking them
	gateway.setPos(&neighbor,&supermarket, nullptr, nullptr);
	neighbor.setPos(&realEstate,&bank,&gateway, nullptr);
	supermarket.setPos(&bank,&superCorp, nullptr,&gateway);
	superCorp.setPos(nullptr, nullptr, nullptr,&supermarket);
	realEstate.setPos(nullptr,&bankCorp,&neighbor, nullptr);
	bank.setPos(&bankCorp, nullptr,&supermarket,&neighbor);
	bankCorp.setPos(nullptr,&treasury,&bank,&realEstate);
	treasury.setPos(nullptr, nullptr, nullptr,&bankCorp);





	player.currentPos = &gateway;


	int quit = true;
	string choice;

	while(quit)
	{
	    cout << endl;
		std::cout << "Enter Command: ";
		cin >> choice;
		cout << endl;

		//HELP

		if(choice == "help"){
			cout << "Valid Commands:" << endl;
			cout << "help                  this command" << endl;
			cout << "scan                  displays the surrounding network and their security level" << endl;
			cout << "hack [direction]      attempts to hack the specifed computer" << endl;
			cout << "connect [direction]   attempst to connect to the specified computer" << endl;
			cout << "disconnect            returns to your gateway" << endl;
			cout << "collect               collects all the money in the computer you're currently connected too" << endl;
			cout << "upgrade               upgrades your 1337 hax" << endl;
			cout << "money                 tells you how much money you have" << endl;
			cout << "level                 tells you the level of your 1337 hax" << endl;
			cout << "quit                  quits the game" << endl;
		}

		//SCAN

		else if(choice == "scan"){

		    cout << "Currently at " << player.currentPos->name << endl;
		    cout << "Found $"<<player.currentPos->money << " attatched to accounts." << endl << endl;

		    cout << "Up: ";
		    if(player.currentPos->up != nullptr)
		        cout << player.currentPos->up->name << " [" << player.currentPos->up->level << "] " << endl;
		    else
		        cout << "none" << endl;

		    cout << "Right: ";
		    if(player.currentPos->right != nullptr)
		        cout << player.currentPos->right->name << " [" << player.currentPos->right->level << "] "  << endl;
		    else
		        cout << "none" << endl;

		    cout << "Down: ";
		    if(player.currentPos->down != nullptr)
		        cout << player.currentPos->down->name << " [" << player.currentPos->down->level << "] "  << endl;
		    else
		        cout << "none" << endl;

		    cout << "Left: ";
		    if(player.currentPos->left != nullptr)
		        cout << player.currentPos->left->name << " [" << player.currentPos->left->level << "] " << endl;
		    else
		        cout << "none" << endl;
		}

		//HACK

		else if(choice == "hack"){
		    cin >> choice;

		    if(choice == "up" && player.currentPos->up != nullptr){
                if(player.level >= player.currentPos->up->level){
                    cout << "Hack Successful, security removed" << endl;
                    player.currentPos->up->level = 0;
                }
                else
                    cout << "Hack Unsuccessful, security too strong" << endl;
            }

            else if(choice == "down" && player.currentPos->down != nullptr){
                if(player.level >= player.currentPos->down->level){
                    cout << "Hack Successful, security removed" << endl;
                    player.currentPos->down->level = 0;
                }
                else
                    cout << "Hack Unsuccessful, security too strong" << endl;
            }
            else if(choice == "right" && player.currentPos->right != nullptr){
                if(player.level >= player.currentPos->right->level){
                    cout << "Hack Successful, security removed" << endl;
                    player.currentPos->right->level = 0;
                }
                else
                    cout << "Hack Unsuccessful, security too strong" << endl;
            }

            else if(choice == "left" && player.currentPos->left != nullptr){
                if(player.level >= player.currentPos->left->level){
                    cout << "Hack Successful, security removed" << endl;
                    player.currentPos->left->level = 0;
                }
                else
                    cout << "Hack Unsuccessful, security too strong" << endl;
            } else
                cout << "Invalid Option" << endl;

		}

		//CONNECT

		else if(choice == "connect"){
		    cin >> choice;
		    if(choice == "up" && player.currentPos->up != nullptr){
		        if(player.currentPos->up->level == 0){
		            cout << "Moving to: " << player.currentPos->up->name << endl;
		            player.currentPos = player.currentPos->up;
		        }
		        else{
		            cout << "Security is enabled on " << player.currentPos->up->name << endl;
		        }
		    }

            else if(choice == "down" && player.currentPos->down != nullptr){
                if(player.currentPos->down->level == 0){
                    cout << "Moving to: " << player.currentPos->down->name << endl;
                    player.currentPos = player.currentPos->down;
                }
                else{
                    cout << "Security is enabled on " << player.currentPos->down->name << endl;
                }
            }

            else if(choice == "right" && player.currentPos->right != nullptr){
                if(player.currentPos->right->level == 0){
                    cout << "Moving to: " << player.currentPos->right->name << endl;
                    player.currentPos = player.currentPos->right;
                }
                else{
                    cout << "Security is enabled on " << player.currentPos->right->name << endl;
                }
            }

            else if(choice == "left" && player.currentPos->left != nullptr){
                if(player.currentPos->left->level == 0){
                    cout << "Moving to: " << player.currentPos->left->name << endl;
                    player.currentPos = player.currentPos->left;
                }
                else{
                    cout << "Security is enabled on " << player.currentPos->up->name << endl;
                }
            }
            else
                cout << "Invalid Option" << endl;
		}

		//DISCONNECT

		else if(choice == "disconnect")
		    player.currentPos = &gateway;

		//COLLECT

		else if(choice == "collect"){
		    cout << "Collected $" << player.currentPos->money << endl;
		    player.money += player.currentPos->money;
		    player.currentPos->money = 0;
		}

		//UPGRADE

		else if(choice == "upgrade"){
		    cout << "You currently have a level " << player.level << " hacking tool" << endl;
		    cout << "Would you like to buy a level " << player.level+1 << " hacking tool for " << (player.level+1) * 100 << "? (y/n)" << endl;
		    cin >> choice;
		    if(choice == "y" && player.money >= (player.level+1)*100){
		        player.level++;
		        player.money -= player.level*100;
		        cout << "Your hacking tool is now " << player.level << ". You have $"<< player.money << endl;
		    }
		    else
		        cout << "You either said no, put something wrong or didnt have enough cash, I'm too lazy to write proper validation" << endl;
		}

		//MONEY

		else if(choice == "money"){
		    cout << "You have $" << player.money << endl;
		}

		//LEVEL

		else if(choice == "level"){
		    cout << "You hacking tool is level " << player.level << endl;
		}

		//QUIT

		else if(choice == "quit"){
		    cout << "Goodbyte" << endl;
		    quit = false;
		}


		else{
			cout << "Invalid Command" << endl;
		}



	}









	return 0;
}