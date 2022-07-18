#include "Recipient.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include"Donor.h"

using namespace std;

Recipient::Recipient()
{

}


void  Recipient::rRegister()
{

	memberStruct r2;
	Recipient r1;
	
	bool  valid = true;
	int doc_choice;

	
	
	file.open("recipient.txt", ios::app);
	
	cout << "Enter your name" << endl;
	cin >> r2.name;
	file << r2.name <<" " << endl;

	cout << "enter your email" << endl;
	cin >> r2.mail;
	file << r2.mail << endl;
	

	cout << "enter password" << endl;

	while (valid)
	{
		cin >> r2.password;
		file << r2.password << endl;

		cout << "confirm your password" << endl;
		cin >> r2.pw2;
		file << r2.pw2 << endl;
		if (r2.pw2 == r2.password) {
			valid = false;
		}
		else (cout << "enter two matching passwords" << endl);
	}

	cout << "enter your age" << endl;
	cin >> r2.age;
	file << r2.age << endl;

	do
	{
		cout << "enter\n(1) for Male\n(2) for Female" << endl;
		cin >> r2.gender;
	}
	while (r2.gender != "1" && r2.gender != "2"); //checks if entered gender isn't valid, goes back to input gender

	if (r2.gender == "1")
	{
		file << "Male" << endl;
	}
	else
	{
		file << "Female" << endl;
	}


	cout << "pick the blood type  \n 1) A\n 2) B \n 3) AB\n 4) O \n ";
	cin >> choice3;
	switch (choice3)
	{
	case 1:
		r2.bloodType = "A";
		
		break;

	case 2:
		r2.bloodType = "B";
		
		break;

	case 3:
		r2.bloodType = "AB";
		
		break;
	case 4:
		r2.bloodType = "O";
		
		break;

	default:
		cout << "Invalid choice" << endl;
		break;
	}
	file << r2.bloodType << endl;
	
	cout<< "pick the hospital \n 1) ASU Hospital\n 2) GUC Hospital\n 3) AUC Hospital\n ";
	cin >> choice2;
	switch (choice2)
	{
	case 1:
		r2.hospital = "ASU hospital";
		break;

	case 2:
		r2.hospital = "GUC hospital";
		break;

	case 3:
		r2.hospital = "AUC hospital";
		break;

	default:
		cout << "Invalid choice" << endl;
		break;
	}  //switch case picks between the avaliable hospitals



	if (r2.hospital == "ASU hospital") 
	{
		file << r2.hospital << endl;
		cout << "choose doctor\n1)Dr Ahmed\n2)Dr Hossam\n";
		cin >> doc_choice;
		if (doc_choice == 1)
		{
			r2.doctor="Dr_Ahmed";
			file << r2.doctor << endl;
		}
		else if (doc_choice == 2)
		{
			r2.doctor="Dr_Hossam";
			file << r2.doctor << endl;
		}
		else
		{
			cout << "invalid";
		}
	}
	else if (r2.hospital == "GUC hospital")
	{
		file << r2.hospital << endl;
		cout << "choose doctor\n1)Dr Karim\n2)Dr Nour\n";
		cin >> doc_choice;
		if (doc_choice == 1)
		{
			r2.doctor="Dr_Karim";
			file << r2.doctor << endl;
		}
		else if (doc_choice == 2)
		{
			r2.doctor="Dr_Nour";
			file << r2.doctor << endl;
		}
		else
		{
			cout << "invalid";
		}
	}
	else if (r2.hospital == "AUC hospital")
	{
		file << r2.hospital << endl;
		cout << "choose doctor\n1)Dr Mostafa\n2)Dr Zohirey\n";
		cin >> doc_choice;
		if (doc_choice == 1)
		{
			r2.doctor="Dr_Mostafa";
			file << r2.doctor << endl;
		}
		else if (doc_choice == 2)
		{
			r2.doctor="Dr_Zohirey";
			file << r2.doctor << endl;
		}
		else
		{
			cout << "invalid";
		}

	}
	



		file.close();
		
		otherFile.open("recipient.txt");



		int search = 0;
		
		while (otherFile.good())
		{
			otherFile >> r2.name;

			search++;
		};
		
		id = (search / 10);
		cout << "your id is " << id<< endl;
		


		otherFile.close();

		file.open("recipient.txt", ios::app);

		file << id << endl;
		file << endl;
		file.close();
}


void Recipient::rFileToVec()
{
	otherFile.open("recipient.txt");

	string str;
	int s1=0;
	while (otherFile.good())
	{
		getline(otherFile, str, '\n');
		r2Vector.push_back(str);
		s1++;
	}
	
	memberStruct r;

	int c = 0;
	int search = 0;
	//for (int i = 0;i < r2Vector.size();i+=9)
	int vecSize = (r2Vector.size()-1);
	
	while (c < vecSize)
	{

		int cName = c;
		int cMail = c + 1;
		int cPassword = c + 2;
		int cPw2 = c + 3;
		int cAge = c + 4;
		int cGender = c + 5;
		int cBloodType = c + 6;
		int cHospital = c + 7;
		int cDoctor = c + 8;
		int cId = c + 9;

		r.name.assign(r2Vector[cName]);
		r.mail.assign(r2Vector[cMail]);
		r.password.assign(r2Vector[cPassword]);
		r.pw2.assign(r2Vector[cPw2]);
		r.age.assign(r2Vector[cAge]);
		r.gender.assign(r2Vector[cGender]);
		r.bloodType.assign(r2Vector[cBloodType]);
		r.hospital.assign(r2Vector[cHospital]);
		r.doctor.assign(r2Vector[cDoctor]);
		r.id.assign(r2Vector[cId]);
		rVector.push_back(r);
		search++;

		c+=11;
	}

	
	
	//cout << rVector[2].id << endl;
	otherFile.close();
}


void  Recipient::rLogin()
{
	

	string rMail;
	string rPassword,passCheck;
	int j=0,idd=0;
	bool valid=1;
	Recipient r;
	r.rFileToVec();

	do
	{

		cout << "Enter your Email" << endl;
		cin >> rMail;
		cout << rVector.size() << endl;
	
		for (int i = 0;i < rVector.size();i++)
		{

			if (rMail == rVector[i].mail)
			{
				passCheck.assign(rVector[i].password);
				valid = 1;
				break;
			}

			j++;
			if (j >= rVector.size())
			{
				cout << "invalid email" << endl;
				valid = 0;
				break;
			}
			
			
		}
		

	} while (valid == 0);
	
	cout << "Enter your password" << endl;
	cin >> rPassword;

	while (passCheck != rPassword)
	{
		cout << "invalid password\nenter a valid password " << endl;
		cin >> rPassword;
	}
	cout << "You are now logged in" << endl;
	idd = j +1;
	cout << "your id is : " << idd << endl;

}


void Recipient::rVecToFile()
{
	Recipient r;
	int i = 0;
	file.open("recipient.txt");

	for (int e = 0;e < rVector.size();e++)
	{

		file << rVector[i].name << endl;
		file << rVector[i].mail << endl;
		file << rVector[i].password << endl;
		file << rVector[i].pw2 << endl;
		file << rVector[i].age << endl;
		file << rVector[i].gender << endl;
		file << rVector[i].bloodType << endl;
		file << rVector[i].hospital << endl;
		file << rVector[i].doctor << endl;
		file << rVector[i].id << endl;
		file << endl;
		i++;
	}
	

	file.close();

}


void Recipient::rDelete()
{
	int idDel =0;
	Recipient r;
	cout << "enter your id to delete your account" << endl;
	cin >> idDel;

	string del = "deleted";

	rVector[idDel].name.assign(del);
	rVector[idDel].mail.assign(del);
	rVector[idDel].password.assign(del);
	rVector[idDel].pw2.assign(del);
	rVector[idDel].age.assign(del);
	rVector[idDel].gender.assign(del);
	rVector[idDel].bloodType.assign(del);
	rVector[idDel].hospital.assign(del);
	rVector[idDel].doctor.assign(del);
	rVector[idDel].id.assign(del);
	cout << rVector[idDel].name << endl;

}


void Recipient::rUpdate()
{
	//Recipient r;
	//r.rFileToVec();
	//r.r2Vector.clear();
	//r.rVector.clear();

	bool editing = 1;
	bool passVerify = 0; //check pass before editing
	bool BloodCheck=1; // switch case bloodtype
	bool hospitalCheck = 1;//switch case hospital
	bool docCheck = 1; //if function doctor name
	bool editCheck = 1; //switch case re-edit
	int id = 0;
	int choice1=0; //info to edit option
	int choice2 = 0; //gender option
	int choice3 = 0;//bloodtype option
	int choice4 = 0; //hospital option
	int choice5 = 0; //doctor option
	int choice6 = 1; //switch case edit again
	string edit_pass;
	bool pass_valid = 0;
	string tempPass; 

	cout << "enter ID\t";
	cin >> id;
	id -= 1;
	cout << endl;
	
	while (!pass_valid) 
	{

		cout << "enter your password  ";
		cin >> edit_pass;
		cout << endl;
		if (edit_pass == rVector[id].password)
		{
			pass_valid = 1;
			while (editing)
			{




				cout << "name: " << rVector[id].name << endl;
				cout << "mail: " << rVector[id].mail << endl;
				cout << "age: " << rVector[id].age << endl;
				cout << "gender: " << rVector[id].gender << endl;
				cout << "blood type: " << rVector[id].bloodType << endl;
				cout << "hospital: " << rVector[id].hospital << endl;
				cout << "doctor: " << rVector[id].doctor << endl << endl;

				cout << "choose info to edit:\n 1.name\n 2.password\n 3.mail\n 4.age\n 5.gender\n 6.blood type\n 7.hospital&doctor\n\n";
				cin >> choice1;

				switch (choice1)
				{

				case 1:

					cout << "current name: " << rVector[id].name << "\n";
					cout << "Enter new name" << endl;
					cin >> rVector[id].name;

					break;


				case 2:

					do
					{
						cout << "enter your current password";
						cin >> tempPass;
						if (rVector[id].password == tempPass)
						{
							passVerify = 1;
							cout << "enter new password";
							cin >> rVector[id].password;

						}
						else
						{
							cout << "invalid password try again\n";
						}

					} while (passVerify == 0);

					break;

				case 3:

					cout << "current mail: " << rVector[id].mail << endl;
					cout << "enter new mail: ";
					cin >> rVector[id].mail;

					break;

				case 4:

					cout << "current age: " << rVector[id].age << endl;
					cout << "enter new age: ";
					cin >> rVector[id].age;

					break;

				case 5:

					cout << "current gender: " << rVector[id].gender << endl;
					cout << "enter\n(1) for Male\n(2) for Female" << endl;
					cin >> choice2;

					while (choice2 != 1 && choice2 != 2)
					{
						cout << "enter a valid choise\n(1) for Male\n(2) for Female" << endl;
						cin >> choice2;
					} //checks if entered gender isn't valid, goes back to input gender

					if (choice2 == 1)
					{
						rVector[id].gender = "Male";
					}
					else
					{
						rVector[id].gender = "Female";
					}

					break;

				case 6:

					cout << "current blood type: " << rVector[id].bloodType << endl;
					cout << "enter new blood type:\n ";
					cout << "1 for A\n2 for B\n3 for AB\n4 for O" << endl;
					do
					{
						cin >> choice3;
						switch (choice3)
						{
						case 1:

							rVector[id].bloodType = "A";

							break;
						case 2:

							rVector[id].bloodType = "B";

							break;
						case 3:

							rVector[id].bloodType = "AB";

							break;
						case 4:

							rVector[id].bloodType = "O";

							break;
						default:

							cout << "Invalid choice!!\nPlease enter a valid choice" << endl;
							BloodCheck = 0;
							break;
						}
					} while (BloodCheck == 0);

					break;

				case 7:

					do
					{
						cout << "pick the hospital \n 1) ASU Hospital\n 2) GUC Hospital\n 3) AUC Hospital\n ";
						cin >> choice4;
						switch (choice4)
						{
						case 1:
							rVector[id].hospital = "ASU hospital";

							break;

						case 2:
							rVector[id].hospital = "GUC hospital";

							break;

						case 3:
							rVector[id].hospital = "AUC hospital";

							break;

						default:
							cout << "Invalid choice\nPlease enter a valid choice " << endl;
							hospitalCheck = 0;
							break;
						}
					} while (hospitalCheck == 0);




					if (rVector[id].hospital == "ASU hospital")
					{

						cout << "choose doctor\n1)Dr Ahmed\n2)Dr Hossam\n";
						do
						{
							cin >> choice5;
							if (choice5 == 1)
							{
								rVector[id].doctor = "Dr_Ahmed";

							}
							else if (choice5 == 2)
							{
								rVector[id].doctor = "Dr_Hossam";

							}
							else
							{
								cout << "invalid choice\nplease enter a valid choice";
								docCheck = 0;
							}
						} while (docCheck == 0);
					}
					else if (rVector[id].hospital == "GUC hospital")
					{

						cout << "choose doctor\n1)Dr Karim\n2)Dr Nour\n";
						do
						{
							cin >> choice5;
							if (choice5 == 1)
							{
								rVector[id].doctor = "Dr_Karim";

							}
							else if (choice5 == 2)
							{
								rVector[id].doctor = "Dr_Nour";

							}
							else
							{
								cout << "invalid choice\nplease enter a valid choice";
								docCheck = 0;
							}
						} while (docCheck == 0);
					}
					else if (rVector[id].hospital == "AUC hospital")
					{

						cout << "choose doctor\n1)Dr Mostafa\n2)Dr Zohirey\n";
						do
						{
							cin >> choice5;
							if (choice5 == 1)
							{
								rVector[id].doctor = "Dr_Mostafa";

							}
							else if (choice5 == 2)
							{
								rVector[id].doctor = "Dr_Zohirey";

							}
							else
							{
								cout << "invalid choice\nplease enter a valid choice";
								docCheck = 0;
							}
						} while (docCheck == 0);

						break;
					}
					cout << endl;



				}
				cout << "name: " << rVector[id].name << endl;
				cout << "mail: " << rVector[id].mail << endl;
				cout << "age: " << rVector[id].age << endl;
				cout << "gender: " << rVector[id].gender << endl;
				cout << "blood type: " << rVector[id].bloodType << endl;
				cout << "hospital: " << rVector[id].hospital << endl;
				cout << "doctor: " << rVector[id].doctor << endl << endl;

				cout << "do you want to edit anything else?(1 for yes/2 for no)" << endl;
				do
				{
					cin >> choice6;
					switch (choice6)
					{
					case 1:

						editing = 1;

						break;

					case 2:

						editing = 0;
						break;
					default:
						cout << "invalid option\nenter a valid option" << endl;
						editCheck = 0;

						break;
					}
				} while (editCheck = 0);
			}
		}
			else 
			{
				cout << "invalid password \n please try again" << endl;
			}
	}

	//r.rVecToFile();
}


void Recipient::rSearch()
{
	Donor d1;
	d1.dFileToQueue();
	string blood_search=" ";
	bool avaliable = 0;
	int choice = 0; //switch case option
	bool valid = true;

	do
	{
		cout << "choose bloodtype\n1.A\n2.B\n3.AB\n4.O " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			blood_search.assign("A");
			valid = true;
			break;
		case 2:
			blood_search.assign("B");
			valid = true;
			break;
		case 3:
			blood_search.assign("AB");
			valid = true;
			break;
		case 4:
			blood_search.assign("O");
			valid = true;
			break;
		default:
			cout << "invalid input" << endl;
			valid = false;
			break;
		}
	} while (valid == false);
	
	
	do
	{
		for (int i = 2;i <= d1.d2Vector.size();i+=6) //dQueue.size()
		{
			
			if (blood_search == d1.d2Vector[i])
			{
				cout << "avaliable" << endl;
				avaliable = 1;
				break;
			}
			else if (i== (d1.d2Vector.size()-5) && avaliable==0)
			{
				
					cout << "unavaliable" << endl;
					avaliable = 0;
				
				
			}
			
		}

	} while (avaliable = 0);
}

void Recipient::rDisplay()
{
	cout << "Display Blood data function" << endl;
}


void Recipient::rReqBloodType()
{
	cout << "Request blood type and quantity needed and confirm about the hospital" << endl;
}


Recipient::~Recipient()
{

}

