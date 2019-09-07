// Text-RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "player.h"
#include "stocked.h"
#include "enemy.h"


using namespace std;

inline void Print(string text) { cout << text; }

void PrintStats(Being& query)
{
	cout << "\nHealth: " << query.GetHealth();
	cout << "\nSpeed: " << query.GetSpeed();
	cout << "\nStrength: " << query.GetStrength();
	cout << "\nLuck: " << query.GetLuck();
	cout << endl;
}

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
	cout << endl << endl;
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

		if (enemiesAlive <= 0)
		{
			battleOver = true;
		}
		else
		{
			battleOver = false;
		}

		int i = 0;
		for (; i < turnOrder.size(); i++)
		{


			if (turnOrder[i].GetName() == enemy.GetName())
			{
				enemy.Attack(player);

				if (player.GetHealth() <= 0)
				{
					battleOver = true;
					Print("\n\n\t\tYou Died :(\n\t\tGAME OVER\n\n\n\n");
					break;
				}
				else
				{
					battleOver = false;
				}
			}
			else
			{
				int tempX = PlayerTurn();
				switch (tempX)
				{
				case 1:
					player.Attack(enemy);

					enemiesAlive = (enemy.GetHealth());

					if (enemiesAlive <= 0)
					{
						battleOver = true;
						break;
					}
					else
					{
						battleOver = false;
					}
					break;

				case 2:
					player.Heal();
					break;

				case 3:
					if (player.Escape())
					{
						battleOver = true;
						Print("\n\nYou Escaped!!!\n");
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
	/*Function Prototypes-------------------------------------------------------
	bool Room1();
	bool Room2();
	bool Room3();
	bool Room4();
	*/

	//Gamewide Variables
	bool running = false; //DEBUG ONE LOOP
	enum GameState { RoomProgress, InBattle, Choice, Menu };
	int gameState = Menu;
	int startingPoints = 5;
	int choice = NULL;
	int choice1 = NULL;
	int choice2 = NULL;
	bool inRoomTracker[3] = {false, false, false};
	bool exitRoom = false;

	string entryString = "";
	
	Being USED_ITEMS; //ALl used items are transferred to this stock

	//ITEM CREATION-------------------------------------------------------------
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

	
	//PLAYER CREATION-----------------------------------------------------------
	Player player;
	player.SetValue(1500);
	cout << "\nEnter your name\n";
	cin >> entryString;
	player.SetName(entryString);
	player.AddItem(healthPotion, player.stock);
	player.AddItem(healthPotion, player.stock);
	player.AddItem(healthPotion, player.stock);

	//Allow player customize attributes-----------------------------------------
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

	//ENEMY CREATION------------------------------------------------------------
	Enemy mimic;
	mimic.SetName("mimic");
	mimic.SetHealth(300);
	mimic.SetStrength(5);
	mimic.SetSpeed(1);
	mimic.SetLuck(10);

	Enemy wanderingGhost;
	wanderingGhost.SetName("Wandering Ghost");
	wanderingGhost.SetHealth(120);
	wanderingGhost.SetLuck(30);
	wanderingGhost.SetSpeed(10);



	//ROOM 1 BEGINS HERE--------------------------------------------------------
	Print("You awaken in a strange room...\n\n");

	do
	{
		Print("Where will you go\n\n");
		choice = GetChoice("(1) - To your left, where there is a treasure chest...\n(2) - To your right, where there is another treasure chest...\n(3) - A whitish haze that floats around in the middle of the room...\n", 3);

		if (inRoomTracker[choice - 1] == false)
		{
			inRoomTracker[choice - 1] = true;

			switch (choice)
			{
			case 1:
				Print("\nYou open the chest, but only have enough time to grab one item before it slams shut. You chose to take:\n");
				Print("\n1-Cursed Candle\n2-Holy Helm\n3-Prescious Pendant");
				choice2 = GetChoice("\n\nEnter 1 to 3",3);
				
				switch (choice2)
				{
				case 1:
					player.AddItem(cursedCandle, player.stock);
					break;
				case 2:
					player.AddItem(holyHelm, player.stock);
					break;
				case 3:
					player.AddItem(presciousPendant, player.stock);
					break;

				default:
					break;
				}
				break;

			case 2:
				if (player.GetLuck() >= 3)
				{
					player.AddItem(royalInvitation, player.stock);

					Print("\You obtained a 'Royal Invitation' \n(Passive: Speed + 2)");

					player.SetSpeed(player.GetSpeed() + 2);
					PrintStats(player);
				}
				else
				{
					Print("\nAs you open the chest, you feel a strange uneasiness. \nSuddenly, it bites you, injuring your arm (Strength -1)\n");
					Battle(player, mimic);		
					if (player.GetHealth() <= 0) { return 0; }
				}
				break;

			case 3:
				Print("\n\nA ghost materializes!!!\nIt Says over and over...\n");
				Print("\nThe Holy Knight stands in defiance of all enemies\nGreat treasure lies deep in accursed darkness\nGive an offering to the Lost Throne\n\n");
				choice1 = GetChoice("\n1-Leave\n2-Attack\n");

				switch (choice1)
				{
				case 1:
					"\n\nYou choose to leave the ghost and keep moving\n";
					break;

				case 2:
					player.Attack(wanderingGhost);
					Battle(player, wanderingGhost);
					if (player.GetHealth() <= 0) { return 0; }

					break;

				default:
					break;
				}
				break;

			default:
				break;
			}
		}
		else
		{
			Print("\nYou can't do this twice!!!\n\n");
		}
	
		if (inRoomTracker[0] + inRoomTracker[1] + inRoomTracker[2] >= 3)
		{
			exitRoom = true;
		}
	} while (!exitRoom);

	Print("\n\n You head into the next room...\n\n");

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
