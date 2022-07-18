#include <iostream>
#include <string>
#include <fstream>
#include"Donor.h"
#include"Recipient.h"
#include <vector>




using namespace std;

int main()
{
	Recipient r;
	Donor d;
	r.rFileToVec();//reads recipient previous saved data from the file into a vector
	d.dFileToVec();//reads donor previous saved data from the file into a vector
	
	
	
	int choice1 = 0; //Donor or Recipient
	int choice2 = 0; //Register or login
	int choice3 = 0; //Donor donation Request
	int choice3Valid = 0;
	int ddelete = 0;
	int rdelete = 0;
	int end = 0;
	int endloop = 0;
	
	cout << "Welcome to our Blood Bank" << endl << endl;
	cout << "A place for helping patients especially at emergent cases." << endl;
	cout << "Blood donation has a great importance in helping to save people's lives..." << endl << endl;

	cout << "Press 1 if you're a Donor, press 2 you're a Recipient " << endl;
	cin >> choice1;

	while (choice1 != 1 && choice1 != 2)
	{
		cout << "Please enter a valid choise" << endl;
		cout << "Press 1 if you're a Donor, press 2 you're a Recipient " << endl;
		cin >> choice1;
	}
	if (choice1 == 1)//Donor account
	{
		cout << "Press 1 if you're a new user, press 2 if you already have an account " << endl;
		cin >> choice2;
		while (choice1 != 1 && choice1 != 2)
		{
			cout << "Press 1 if you're a new user, press 2 if you already have an account " << endl;
			cin >> choice2;
		}
		if (choice2 == 1)
		{
			d.dRegister();
		}
		else
		{
			d.dLogin();
		}
		do
		{
			endloop = 0;
			do
			{
				cout << "Press 1 if you want to Request a Donation" << endl;
				cout << "Press 2 if you want to update your account info" << endl;
				cout << "Press 3 if you want to delete your account" << endl;

				cin >> choice3;
				switch (choice3)
				{
				case 1:
					d.dDonationReq();
					

					break;
				case 2:
					d.dUpdate();
					break;
				case 3:
					cout << "are you sure you want to delete your account?(1 for yes /2 for no)" << endl;
					cin >> ddelete;

					if (ddelete == 1)
					{
						d.dDelete();
					}
					break;
				default:
					cout << "invalid option" << endl;
					choice3Valid = 1;
					break;
				}
			} while (choice3Valid == 1);

			cout << "Press 1 to end program  \nPress 2 to go back to menu" << endl;
			cin >> end;
			if (end != 1)
			{
				endloop = 1;
			}

		} while (endloop == 1);
	}
	else
	{
		cout << "Press 1 if you're a new user, press 2 if you already have an account " << endl;
		cin >> choice2;
		while (choice1 != 1 && choice1 != 2)
		{
			cout << "Press 1 if you're a new user, press 2 if you already have an account " << endl;
			cin >> choice2;
		}
		if (choice2 == 1)
		{
			r.rRegister();
		}
		else
		{
			r.rLogin();
		}
		do
		{
			endloop = 0;
			do
			{
				cout << "Press 1 if you want to Update your account" << endl;
				cout << "Press 2 if you want to Search for avaliability of a blood type" << endl;
				cout << "Press 3 if you want to delete your account" << endl;
				cout << "Press 4 to display all blood data" << endl;
				cout << "Press 5 to request a blood type ad confirm about the hospital" << endl << endl;


				cin >> choice3;
				switch (choice3)
				{
				case 1:
					r.rUpdate();
					break;
				case 2:
					r.rSearch();
					break;
				case 3:
					cout << "are you sure you want to delete your account?(1 for yes /2 for no)" << endl;
					cin >> rdelete;

					if (rdelete == 1)
					{
						r.rDelete();
					}
					break;
				case 4:
					r.rDisplay();
					break;
				case 5:
					r.rReqBloodType();
					break;
				default:
					cout << "invalid option" << endl;
					choice3Valid = 1;
					break;
				}
			} while (choice3Valid == 1);

			cout << "Press 1 to end program  \nPress 2 to go back to menu " << endl;
			cin >> end;
			if (end != 1)
			{
				endloop = 1;
			}

		} while (endloop == 1);
	}
	
	

	

	
	r.rVecToFile();

	d.dVecToFile();
	
	
	return 0;
};

