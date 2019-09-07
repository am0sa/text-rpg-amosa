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
	cout << "\n\tName: " << query.GetName();
	cout << "\tHealth: " << query.GetHealth();
	cout << "\tSpeed: " << query.GetSpeed();
	cout << "\tStrength: " << query.GetStrength();
	cout << "\tLuck: " << query.GetLuck();
	cout << endl << endl;
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
		PrintStats(player);
		PrintStats(being);
		PrintStats(being2);
		PrintStats(being3);
 
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
			else if (turnOrder[i].GetName() == being3.GetName())
			{
				being3.Attack(player);
			}
			else
			{
				int tempY = GetChoice("\nChoose an enemy to focus on this turn (1,2, or 3)\n", (turnOrder.size() - 1));
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
						if (player.Escape())
						{
							battleOver = true;
							Print("\n\nYou Escaped!!!\n");
							break;
						}

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
						if (player.Escape())
						{
							battleOver = true;
							Print("\n\nYou Escaped!!!\n");
							break;
						}

					default:
						break;
					}
					break;

				case 3:
					switch (tempX)
					{
					case 1:
						player.Attack(being3);
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
	
	//Being USED_ITEMS; //ALl used items are transferred to this stock

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
	cout << "Enter your name\n";
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
	PrintStats(player);

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

	Enemy spider1;
	spider1.SetHealth(175);
	spider1.SetSpeed(6);
	spider1.SetStrength(3);
	spider1.SetLuck(1);
	spider1.SetName("Spider 1");


	Enemy spider2;
	spider2.SetHealth(120);
	spider2.SetSpeed(8);
	spider2.SetStrength(3);
	spider2.SetLuck(2);
	spider2.SetName("Spider 2");

	Enemy spiderBoss;
	spiderBoss.SetHealth(400);
	spiderBoss.SetSpeed(2);	
	spiderBoss.SetStrength(7);
	spiderBoss.SetLuck(3);
	spiderBoss.SetName("Spider X");


	//ROOM 1 BEGINS HERE--------------------------------------------------------
	Print("You awaken in a strange room...\n");

	do
	{
		Print("\n\nWhere will you go\n\n");
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
					Print("\nGrants Luck +1 and Speed -1\n");
					cursedCandle.SetIsEquipped(true);
					player.SetLuck(player.GetLuck() + 1);
					player.SetSpeed(player.GetSpeed() - 1);
					break;

				case 2:
					player.AddItem(holyHelm, player.stock);
					Print("\nGrants strength +1, HP +10");
					holyHelm.SetIsEquipped(true);
					player.SetStrength(player.GetStrength() + 1);
					player.SetHealth(player.GetHealth() + 10);
					break;
				case 3:
					player.AddItem(presciousPendant, player.stock);
					Print("\The pendant may fetch a handome price at a merchant\n");
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
				Print("\n\nA neutral spirit appears!!!\nIt Says over and over...\n");
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
	exitRoom = false;
	for (int i = 0; i < 3; i++)	{ inRoomTracker[i] = false; }

	//ROOM 2 BEGINS HERE--------------------------------------------------------

	Print("As you step into the room, you see:\n");
	Print("(1) - A hallway to the left, full of hanging plants and vines...\n");
	Print("(2) - A dark hallway to the left. A dripping noise can be heard deep in the darkness...\n");
	Print("(3) - Straigh ahead, a pedestal in a ray of light...\n");

	do
	{
		Print("\nWhere will you go???\n\n");
		choice = GetChoice("(1) - To your left, towards the hallway of hanging plants...\n(2) - To your right, towards the dripping noise and darkness...\n(3) - Straight ahead, to the pedestal in the light...\n", 3);

		if (inRoomTracker[choice - 1] == false)
		{
			inRoomTracker[choice - 1] = true;

			switch (choice)
			{
			case 1:
				Print("\nBloody footprints lead you further into the forest of potted plants. Where they end, a satchel lies on the floor. It is covered in fresh blood...\n");
				Print("\n(1) - Take the satchel...\n(2) - Turn back...\n");
				choice2 = GetChoice("\n\nEnter 1 or 2", 2);

				switch (choice2)
				{
				case 1:
					for (int i = 0; i < 5; i++)
					{
						player.AddItem(healthPotion, player.stock);
					}
					break;
				case 2:
					Print("\nFearing a trap, you head back to the start of the room...\n");
					inRoomTracker[choice - 1] = false;
					break;

				default:
					break;
				}
				break;

			case 3:
				Print("\nYou approach the pedestal, and see an ornate ring resting atop it...\n");
				Print("\n(1) - Take the ring...\n(2) - Turn back...\n");
				choice2 = GetChoice("\n\nEnter 1 or 2", 2);

				switch (choice2)
				{
				case 1:
					Print("\nA dark spirit emerges from the pedestal!!!\n\n");

					wanderingGhost.SetHealth(175);
					wanderingGhost.SetSpeed(12);
					wanderingGhost.SetStrength(2);
					wanderingGhost.SetName("Dark Spirit");

					if (wanderingGhost.GetSpeed() >= (player.GetSpeed() + 4))
					{
						wanderingGhost.Attack(player);
					}

					Battle(player, wanderingGhost);
					if (player.GetHealth() <= 0) { return 0; }

					Print("\nYou defeated the dark spirit!!!\n");
					player.AddItem(warriorsRing, player.stock);
					Print("\nAcquired: Warrior's Ring\nThis ring grants +2 Strength and +1 Luck\n");

					choice1 = GetChoice("\nEquip Now?\n(1) - Yes\n(2) - No\n", 2);
					switch (choice1)
					{
					case 1:
						warriorsRing.SetIsEquipped(true);
						player.SetStrength(player.GetStrength() + 2);
						player.SetLuck(player.GetLuck() + 1);
						break;

					case 2:
						NULL;
						break;

					default:
						break;
					}
					
					break;
				case 2:
					Print("\nFearing a trap, you leave the ring alone...\n");
					break;

				default:
					break;
				}
				break;

			case 2:
				Print("\n\nYou draw closer to the sound, and the smell of blood fills the air...\n\n");
				system("PAUSE");
				Print("\n\nBefore you can turn back, three huge, hairy spiders surround you...\n");

				Battle(player, spider1, spider2, spiderBoss);
				if (player.GetHealth() <= 0) { return 0; }
				
				Print("\Victory has improved your skills!!!\nStrength +1, Speed +1");
				player.SetStrength(player.GetStrength() + 1);
				player.SetSpeed(player.GetSpeed() + 1);

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
	exitRoom = false;
	for (int i = 0; i < 3; i++) { inRoomTracker[i] = false; }

	//ROOM 3 BEGINS HERE--------------------------------------------------------

	do
	{
		break;
		if (inRoomTracker[0] + inRoomTracker[1] + inRoomTracker[2] >= 3)
		{
			exitRoom = true;
		}
	} while (!exitRoom);

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
