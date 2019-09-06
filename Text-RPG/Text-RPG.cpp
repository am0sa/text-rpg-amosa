// Text-RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <iostream>
#include "player.h"
#include "stocked.h"
#include "enemy.h"


int main()
{
	//Gamewide Variables
	bool running = false; //DEBUG ONE LOOP
	enum GameState { RoomProgress, Battle, Choice, Menu };
	int gameState = Menu;
	
	//Gamewide Objects and Key Items
	Player player;
	
	cout << "Amosa's Text RPG!\n\n";






    do
    {
		//cout << player.GetHealth();

		switch (gameState)
        {
            case RoomProgress:
                //Test
                break;
                
            case Battle:
                //Test
                break;
                
            case Choice:
                //Test
                break;
                
            case Menu:
				cout << "Enum Test\n\n";
                break;
                
            default:
                break;
        }
        
        
    } while (running == true);
	return 0;
}


bool Room1()
{



	return true;
}

bool Room2()
{



	return true;
}

bool Room3()
{



	return true;
}

bool Room4()
{



	return true;
}







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
