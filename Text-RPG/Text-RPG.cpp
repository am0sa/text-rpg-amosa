// Text-RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "player.h"
#include "stocked.h"
#include "enemy.h"


using namespace std;

inline void Print(string text) { cout << text; }

int GetChoice(string text, int maxChoice = 3)
{
	int choice = NULL;
	int retry = 0;

	cout << text << endl;

	do
	{
		cout << "\nEnter a choice from 1 to " << maxChoice << endl;
		cin >> choice;
		retry = cin.fail();
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');

	} while (retry == 1 || choice > maxChoice || choice < 1);
	return choice;
}

int PlayerTurn()
{
	Print("\nChoose an action:\n");
	int choice = (GetChoice("\n1-Attack\n2-Heal\n3-Escape\n", 3));

	return choice;
}

void Battle(Player& player, Being& enemy)
{
	int enemiesAlive = NULL;
	bool battleOver = false;

	vector<Being> turnOrder;


	if (player.GetSpeed() > enemy.GetSpeed())
	{
		turnOrder.push_back(player);
		turnOrder.push_back(enemy);
	}
	else
	{
		turnOrder.push_back(enemy);
		turnOrder.push_back(player);
	}

	do
	{
		enemiesAlive = (enemy.GetHealth());

		if (enemiesAlive > 0)
		{
			battleOver = false;
		}
		else
		{
			battleOver = true;
		}

		int i = 0;
		for (; i < turnOrder.size(); i++)
		{
			if (turnOrder[i].GetName() == enemy.GetName())
			{
				enemy.Attack(player);
			}
			else
			{
				int tempX = PlayerTurn();
				switch (tempX)
				{
				case 1:
					player.Attack(enemy);
					break;

				case 2:
					player.Heal();
					break;

				case 3:
					player.Escape();
					break;

				default:
					break;
				}
			}
		}
	} while (!battleOver);
}

void Battle(Player& player, Being& being, Being& being2)
{
	int enemiesAlive = NULL;
	bool battleOver = false;

	vector<Being> turnOrder;


	if (player.GetSpeed() > being.GetSpeed())
	{
		if (player.GetSpeed() > being2.GetSpeed())
		{
			turnOrder.push_back(player);
			turnOrder.push_back(being2);
			turnOrder.push_back(being);

		}
		else
		{
			turnOrder.push_back(being2);
			turnOrder.push_back(player);
			turnOrder.push_back(being);
		}
	}
	else if (player.GetSpeed() > being2.GetSpeed())
	{
		if (player.GetSpeed() > being.GetSpeed())
		{
			turnOrder.push_back(player);
			turnOrder.push_back(being);
			turnOrder.push_back(being2);

		}
		else
		{
			turnOrder.push_back(being2);
			turnOrder.push_back(being);
			turnOrder.push_back(player);
		}
	}

	do
	{
		enemiesAlive = (being.GetHealth() + being2.GetHealth());

		if (enemiesAlive > 0)
		{
			battleOver = false;
		}
		else
		{
			battleOver = true;
		}

		int i = 0;
		for (; i < turnOrder.size(); i++)
		{
			if (turnOrder[i].GetName() == being.GetName())
			{
				being.Attack(player);
			}
			else if (turnOrder[i].GetName() == being2.GetName())
			{
				being2.Attack(player);

			}
			else
			{
				int tempY = GetChoice("Choose an enemy to focus on this turn", (turnOrder.size() - 1));
				int tempX = PlayerTurn();
				switch (tempY)
				{
				case 1:
					switch (tempX)
					{
					case 1:
						player.Attack(being);
						break;

					case 2:
						player.Heal();
						break;

					case 3:
						player.Escape();
						break;

					default:
						break;
					}
					break;

				case 2:
					switch (tempX)
					{
					case 1:
						player.Attack(being2);
						break;

					case 2:
						player.Heal();
						break;

					case 3:
						player.Escape();
						break;

					default:
						break;
					}
					break;

				default:
					break;
				}
				
			}
		}
	} while (!battleOver);
}

void Battle(Player& player, Being& being, Being& being2, Being& being3)
{
	int enemiesAlive = NULL;
	bool battleOver = false;

	vector<Being> turnOrder;


	if (player.GetSpeed() > being.GetSpeed())
	{
		if (player.GetSpeed() > being2.GetSpeed())
		{
			if (player.GetSpeed() > being3.GetSpeed())
			{
				turnOrder.push_back(player);
				turnOrder.push_back(being3);
				turnOrder.push_back(being2);
				turnOrder.push_back(being);
			}
			else
			{
				turnOrder.push_back(being3);
				turnOrder.push_back(player);
				turnOrder.push_back(being2);
				turnOrder.push_back(being);
			}
		}
		else
		{
			turnOrder.push_back(being3);
			turnOrder.push_back(being2);		
			turnOrder.push_back(player);
			turnOrder.push_back(being);
		}
	}
	else
	{
		if (player.GetSpeed() > being2.GetSpeed())
		{
			if (player.GetSpeed() > being3.GetSpeed())
			{
				turnOrder.push_back(being);
				turnOrder.push_back(player);
				turnOrder.push_back(being3);
				turnOrder.push_back(being2);
			}
			else
			{
				turnOrder.push_back(being2);
				turnOrder.push_back(being);
				turnOrder.push_back(player);
				turnOrder.push_back(being3);	
			}
		}
		else if (player.GetSpeed() > being3.GetSpeed())
		{
			turnOrder.push_back(being2);
			turnOrder.push_back(being);
			turnOrder.push_back(player);
			turnOrder.push_back(being3);
		}
		else
		{
			turnOrder.push_back(being2);
			turnOrder.push_back(being);
			turnOrder.push_back(being3);		
			turnOrder.push_back(player);
		}

	}

	do
	{
		enemiesAlive = (being.GetHealth() + being2.GetHealth() + being3.GetHealth());

		if (enemiesAlive > 0)
		{
			battleOver = false;
		}
		else
		{
			battleOver = true;
		}

		int i = 0;
		for (; i < turnOrder.size(); i++)
		{
			if (turnOrder[i].GetName() == being.GetName())
			{
				being.Attack(player);
			}
			else if (turnOrder[i].GetName() == being2.GetName())
			{
				being2.Attack(player);

			}
			else
			{
				int tempY = GetChoice("Choose an enemy to focus on this turn", (turnOrder.size() - 1));
				int tempX = PlayerTurn();
				switch (tempY)
				{
				case 1:
					switch (tempX)
					{
					case 1:
						player.Attack(being);
						break;

					case 2:
						player.Heal();
						break;

					case 3:
						player.Escape();
						break;

					default:
						break;
					}
					break;

				case 2:
					switch (tempX)
					{
					case 1:
						player.Attack(being2);
						break;

					case 2:
						player.Heal();
						break;

					case 3:
						player.Escape();
						break;

					default:
						break;
					}
					break;

				default:
					break;
				}

			}
		}
	} while (!battleOver);
}

int main()
{
	/*Function Prototypes----------------------------------------------------
	bool Room1();
	bool Room2();
	bool Room3();
	bool Room4();
	*/

	//Gamewide Variables
	bool running = false; //DEBUG ONE LOOP
	enum GameState { RoomProgress, Battle, Choice, Menu };
	int gameState = Menu;
	int startingPoints = 5;
	int choice = NULL;
	int choice1 = NULL;
	int choice2 = NULL;
	bool inRoomTracker[3] = {false, false, false};

	string entryString = "";
	
	Being USED_ITEMS; //ALl used items are transferred to this stock

	//ITEM CREATION----------------------------------------------------------
	//ITEM CREATION--------------------------------------------------------
	Item healthPotion;
	healthPotion.SetItemName("Health Potion");
	healthPotion.SetValue(100);

	Item cursedCandle;
	healthPotion.SetItemName("Health Potion");
	cursedCandle.SetKeyItem(true);

	Item holyHelm;
	holyHelm.SetItemName("Holy Helm");
	holyHelm.SetKeyItem(true);

	Item presciousPendant;
	presciousPendant.SetItemName("Prescious Pendant");
	presciousPendant.SetKeyItem(true);

	Item royalInvitation;
	royalInvitation.SetItemName("Royal Invitation");
	royalInvitation.SetKeyItem(true);

	Item ghostlyGarments;
	ghostlyGarments.SetValue(1000);
	ghostlyGarments.SetItemName("Ghostly Garments");

	Item warriorsRing;
	warriorsRing.SetItemName("Warrior's Ring");
	warriorsRing.SetValue(1200);

	Item gamblersRing;
	gamblersRing.SetItemName("Gambler's Ring");
	gamblersRing.SetValue(1000);

	Item crownOfIllusion;
	crownOfIllusion.SetItemName("Crown of Illusion");
	crownOfIllusion.SetKeyItem(true);

	Item fireBomb;
	fireBomb.SetItemName("Fire Bomb");
	fireBomb.SetValue(50);

	Item whiskey;
	whiskey.SetItemName("Whiskey");
	whiskey.SetValue(50);

	
	//PLAYER CREATION--------------------------------------------------------
	Player player;
	player.SetValue(1500);
	cout << "\nEnter your name\n";
	cin >> entryString;
	player.SetName(entryString);
	player.AddItem(healthPotion, player.stock);
	player.AddItem(healthPotion, player.stock);
	player.AddItem(healthPotion, player.stock);

	//Allow player customize attributes--------------------------------------
	while (startingPoints>0)
	{
		int choice = NULL;
		bool retry;

		cout << "\nYou have " << startingPoints << " skill points to allocate\nWhat will you level up?\nAttributes:\n\n";
		cout << "1-Health\n2-Speed\n3-Strength\n4-Luck\n";

		choice = GetChoice("\nWHat would you like to level up?\n", 4);

		switch (choice)
		{
		case 1: //Health
			player.SetHealth(player.GetHealth() + 10);
			break;

		case 2: //Speed
			player.SetSpeed(player.GetSpeed() + 1);
			break;

		case 3: //Strength
			player.SetStrength(player.GetStrength() + 1);
			break;

		case 4: //Luck
			player.SetLuck(player.GetLuck() + 1);
			break;

		default:
			continue;
		}

		startingPoints--;
	}	

	Print("You awaken in a strange room. To your left, you see a treasure chest (1)...\nTo your right, you see another treasure chest (2)...\n");
	Print("A light haze floats around in the middle of the room (3)...\n");

	GetChoice("Where will you go first", 3);

	do
	{
		switch (choice)
		{
		case 1:
			inRoomTracker[0] = true;
			break;

		case 2:
			inRoomTracker[1] = true;
			break;

		case 3:
			inRoomTracker[2] = true;
			break;

		default:
			break;
		}

	} while (inRoomTracker > 0);

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

				break;
                
            default:
                break;
        }
        
        
    } while (running == true);
	return 0;
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
