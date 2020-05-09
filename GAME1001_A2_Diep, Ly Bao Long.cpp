////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// GAME1001_Assignment 2																																		////
//// Inventory Game																																				////
//// This assignment is done by Diep, Ly Bao Long (ID: 101277290) 																								////																																						////
////																																							////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;
// store
double itemCost;

class weapon
{
private:
	string Sound[9] = { "crack", "pew", "clash", "whizz", "bump", "whoosh", "clang", "bang", "squeak" };
	bool Flag = false;
	int ammo = 3;
public:
	string Item[9] = { "axe", "gun", "sword", "bow", "bomb", "lasso", "shield", "spade", "claw" };

	weapon() {};
	weapon(bool f)
	{
		Flag = f;
	}
	bool getFlag()
	{
		return Flag;
	}
	~weapon() {};
	void buyWeapon(string& itemName)
	{
		if (itemName == Item[0])
		{
			itemCost = 300;
			Sound[0];
		}

		else if (itemName == Item[1])
		{
			itemCost = 500;
			Sound[1];
		}

		else if (itemName == Item[2])
		{
			itemCost = 400;
			Sound[2];
		}
		else if (itemName == Item[3])
		{
			itemCost = 250;
			Sound[3];
		}
		else if (itemName == Item[4])
		{
			itemCost = 650;
			Sound[4];
		}
		else if (itemName == Item[5])
		{
			itemCost = 450;
			Sound[5];
		}
		else if (itemName == Item[6])
		{
			itemCost = 500;
			Sound[6];
		}
		else if (itemName == Item[7])
		{
			itemCost = 200;
			Sound[7];
		}
		else
		{
			itemName = Item[8];
			itemCost = 300;
			Sound[8];
		}
	}
	string useWeapon(string itemName[])
	{
		if (*itemName == Item[0])
		{
			return Sound[0];
		}

		else if (*itemName == Item[1])
		{
			return Sound[1];
		}

		else if (*itemName == Item[2])
		{
			return Sound[2];
		}
		else if (*itemName == Item[3])
		{
			return Sound[3];
		}
		else if (*itemName == Item[4])
		{
			return Sound[4];
		}
		else if (*itemName == Item[5])
		{
			return Sound[5];
		}
		else if (*itemName == Item[6])
		{
			return Sound[6];
		}
		else if (*itemName == Item[7])
		{
			return Sound[7];
		}
		else
		{
			return Sound[8];
		}
	}
	void setAmmo(int a)
	{
		ammo -= a;
	}
	int getAmmo()
	{
		return ammo;
	}
};



// menu system
int main()
{
	char opt;
	int n = 1;
	const int iSize = 10;

	string choice;

	double balance = 2500;

	// object arrays, slot
	weapon p1;
	weapon arrWeapon[iSize];
	string slot[11] = { "empty" };
	cout << "a. Buy Weapon" << endl << "b. Check Balance" << endl << "c. Exit Store" << endl << "Enter your option: ";
	cin >> opt;

	// check for having at least 1 item
	if (tolower(opt) == 'c')
	{
		if (slot[n - 1] == "empty")
		{
			cout << "You must buy at least 1 item" << endl;
			cout  << "a. Buy Weapon" << endl << "b. Check Balance" << endl << "c. Exit Store" << endl << "Enter your option: ";
			cin >> opt;
		}
	}

	if (tolower(opt) != 'a' && tolower(opt) != 'b' && tolower(opt) != 'c')
	{
		cout << "This option does not exist! Enter your option again!" << endl;
		cin >> opt;
	}
	while (tolower(opt) != 'c')
	{
		if (tolower(opt) == 'a')
		{
			cout << endl << "Your available budget: $" << balance << endl << endl;	
			cout << "the list of item: " << endl << endl;
			cout << "weapon: " << endl << "axe 300 gold" << endl << "gun 500 gold" << endl << "sword 400 gold" << endl << endl;
			cout << "bow 250 gold" << endl << "bomb 650 gold" << endl << "lasso 450 gold" << endl << endl;
			cout << "shield 500 gold" << endl << "spade 200 gold" << endl << "claw 300 gold" << endl << endl;
			cout << "Enter the name of item you want to buy: ";
			cin >> choice;
			p1.buyWeapon(choice);

			// check for possessed weapon
			for (int i = 1; i < iSize; i++)
			{
				while (arrWeapon[i].getFlag() == true && choice == slot[i])
				{
					cout << endl << "this item has been existed! choose again!" << endl << endl;
					cout << "slot " << i << ":" << slot[i] << endl << endl;
					cout << "weapon: " << endl << "axe 300 gold" << endl << "gun 500 gold" << endl << "sword 400 gold" << endl << endl;
					cout << "bow 250 gold" << endl << "bomb 650 gold" << endl << "lasso 450 gold" << endl << endl;
					cout << "shield 500 gold" << endl << "spade 200 gold" << endl << "claw 300 gold" << endl << endl;
					cout << "Enter the name of item you want to buy: ";
					cin >> choice;
					p1.buyWeapon(choice);
				}
			}
			if (arrWeapon[n].getFlag() == false)
			{
				//check for balance
				while (balance < itemCost)
				{
						cout << endl << "don't have enough money to buy the item!" << endl;
						cout << endl << "current balance: " << balance << endl << endl << "Choose another items!" << endl << endl;
						cout << "weapon: " << endl << "axe 300 gold" << endl << "gun 500 gold" << endl << "sword 400 gold" << endl << endl;
						cout << "bow 250 gold" << endl << "bomb 650 gold" << endl << "lasso 450 gold" << endl << endl;
						cout << "shield 500 gold" << endl << "spade 200 gold" << endl << "claw 300 gold" << endl << endl;
						cin >> choice;
						for (int i = 1; i < iSize; i++)
						{
							if (arrWeapon[i].getFlag() == true && choice == slot[i])
							{
								cout << "this item has been existed! choose another item fix your budget!" << endl << endl;
								cout << "slot " << i << ":" << slot[i] << endl << endl;
								cout << "weapon: " << endl << "axe 300 gold" << endl << "gun 500 gold" << endl << "sword 400 gold" << endl << endl;
								cout << "bow 250 gold" << endl << "bomb 650 gold" << endl << "lasso 450 gold" << endl << endl;
								cout << "shield 500 gold" << endl << "spade 200 gold" << endl << "claw 300 gold" << endl << endl;
								cin >> choice;
								p1.buyWeapon(choice);
							}
						}
				}		
				balance -= itemCost;
				p1 = weapon(true);
				arrWeapon[n] = { p1 };

				slot[n] = { choice };
				system("cls");
				//display weapon in slots
				for (int i = 1; i < iSize; i++)
				{
					cout << "slot " << i << ":" << slot[i] << endl;
				}
				n++;
				cout << endl << "your remained balance is: " << balance << endl << endl;

			}

		}

		// check balance
		else if (towlower(opt) == 'b')
		{
			cout << endl << "your balance: " << balance << endl <<endl;
		}
		cout << "a. Buy Weapon" << endl << "b. Check Balance" << endl << "c. Exit Store" << endl << "Enter your option: ";
		cin >> opt;
	}

	// Simulation stage
	while (tolower(opt) == 'c')
	{
		system("cls");
		cout << "a. Switch weapon" << endl << "b. Use weapon" << endl << endl << "Enter your option: ";
		cin >> opt;

		
		while (tolower(opt) != 'c')
		{	//switch weapon
			if (tolower(opt) == 'a')
			{
				system("cls");
				for (int i = 1; i < iSize; i++)
				{
					cout << "slot " << i << ":" << slot[i] << endl;
				}
				int index = 1, newindex = 1;
				cout << endl << "Enter [the slot number] to switch weapons between slots. " << endl << "Format (current SlotNum_new Slotnum): ";
				cin >> index >> newindex;

				//check for range of index (1-9)
				if (index > 9 || newindex > 9)
				{
					cout << endl << "You enter the unavailable index!" << " Enter from s1 to s9: " << endl;
					cin >> index >> newindex;

				}
				//switch weapons through the middle index of array
				if (slot[index] != slot[newindex])
				{
					slot[0] = slot[newindex];
					slot[newindex] = slot[index];
					slot[index] = slot[0];
					newindex = index;
				}
				else
				{
					slot[newindex] = slot[index];
				}
				cout << endl << "slot updated!" << endl <<endl;
				for (int i = 1; i < iSize; i++)
				{
					cout << "slot " << i << ":" << slot[i] << endl;
				}
			}

			//use weapon
			else if (tolower(opt) == 'b')
			{
				system("cls");
				for (int i = 1; i < iSize; i++)
				{
					cout << "slot " << i << ":" << slot[i] << endl;
				}
				int q = 1;
				int s;
				cout << endl << "Enter [the number] of the slot containing weapon to use the weapon: ";
				cin >> s;

				// use slo[10] as empty slot.
				if (slot[s] == slot[10])
				{
					cout << "there is no weapon in this slot!" << endl;
				}
				else
				{

					if (arrWeapon[s].getAmmo() <= 0)
					{
						cout << endl << slot[s] << " out of use!" << " choose another weapon to use!" << endl;
						slot[s] = slot[10];//set spent item to empty slot
					}
					else
					{
						// output the sound
						cout << endl << arrWeapon[s].useWeapon(&slot[s]) << "! " << arrWeapon[s].useWeapon(&slot[s]) << "! " << arrWeapon[s].useWeapon(&slot[s]) << "!" << endl;

						// decrement the ammo
						arrWeapon[s].setAmmo(q);
						cout << endl << slot[s] << " have " << arrWeapon[s].getAmmo() << " remained use(s)" << endl;
					}
				}
			}

			// exit the game
			else if (tolower(opt) == 'd')
			{
				cout << endl << "See you in the next game! ^^" << endl;
				system("pause");
				return 0;
			}
			// check for out of choice
			else
			{
				cout << endl << "This option does not exist!" <<endl;
			}
			cout  << endl << "a. Switch weapon" << endl << "b. Use weapon" << endl << "d. Exit the game" << endl << "Enter your option: ";
			cin >> opt;
		}
	}
	system("pause");
	return 0;
}


