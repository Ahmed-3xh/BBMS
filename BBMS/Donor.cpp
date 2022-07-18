#include "Donor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void Donor::dRegister()
{
	Donor d1;
	memberStruct r2;
	
	bool dis, med, valid = true;
	

	file.open("donor.txt", ios::app);

	cout << "Enter your name" << endl;
	cin >> d1.name;
	file << d1.name << endl;

	cout << "enter your email" << endl;
	cin >> d1.mail;
	file << d1.mail << endl;
	cout << "enter password" << endl;

	while (valid)
	{
		cin >> d1.password;
		

		cout << "confirm your password" << endl;
		cin >> d1.pw2;
		
		if (d1.pw2 == d1.password)
		{
			valid = false;
		}
		else (cout << "enter two matching passwords" << endl);
	}
	file << d1.password << endl;
    file << d1.pw2 << endl;

	cout << "enter your age" << endl;
	cin >> d1.age;
	file << d1.age << endl;
	
	
	do
	{	cout << "enter your gender\n(1) for male\n(2) for female" << endl;
		cin >> d1.choice2;
	}
	while (d1.choice2 != 1 && d1.choice2 != 2);
	
		if (d1.choice2 == 1) 
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
			d1.bloodType = "A";

			break;

		case 2:
			d1.bloodType = "B";

			break;

		case 3:
			d1.bloodType = "AB";

			break;
		case 4:
			d1.bloodType = "O";

			break;

		default:
			cout << "Invalid choice" << endl;
			break;
		}
		file << d1.bloodType << endl;

	cout << "Do you suffer from any diseases?(1/0)" << endl;
	cin >> dis;

	while (dis=1)
	{
		dis = 0;

		cout << "enter disease number:\n 1.Blood pressure disorder \n 2.Thyroid diseases \n 3.Diabetes \n 4.cancer \n 5.heart disorder \n 6.hepatites\n " << endl;
		cin >> choice;
		switch (choice) 
		{
			case 1:
				d1.disease = "Blood pressure disorder ";
				file << d1.disease;
				break;
			case 2:
				d1.disease = "Thyroid disease ";
				file << d1.disease;
				break;
			case 3:
				d1.disease = "Diabetes ";
				file << d1.disease;
				break;
			case 4:
				d1.disease = "Cancer ";
				file << d1.disease;
				break;
			case 5:
				d1.disease= "Heart disorder ";
				file << d1.disease;
				break;
			case 6:
				d1.disease = "Hepatites ";
				file << d1.disease;
				break;
			default:
				cout << "Invalid choice ";
				break;
		}

			cout << "do you suffer from any other diseases?(1/0)" << endl;
			cin >> dis;
			if (!dis)
			{
				break;
			}
				d1.i++;
	};
	file << endl;

		cout << "Do you take any medicine?(1/0)" << endl;
		cin >> med;

		while (med)
		{
			med = false;

			cout << "enter medicine name "<< endl;
			cin >> d1.medicine;
			file << d1.medicine<< "  ";
			cout << "do you take any other medicines?(0/1)" << endl;
			cin >> med;
			if (!med)
			{
				break;
			}
				d1.j++;
		};
		file << endl;
		

		cout << "enter your date of donation" << endl;
		cin >> d1.date;
		file << d1.date << endl;
		




		file.close();

		otherFile.open("donor.txt");

		memberStruct d2;
		

		int search = 0;

		while (otherFile.good())
		{
			otherFile >> d2.name;

			search++;
		};

		id = (search / 10);
		cout << "your id is " << id << endl;



		otherFile.close();


		file.open("donor.txt", ios::app);
		
		file << id << endl << endl;

		file.close();
}

void  Donor::dLogin()
{
	cout << "Recipient login function" << endl << endl;

	string dMail;
	string dPassword, passCheck;
	int j = 0;
	bool valid = 1;
	Donor d;
	d.dFileToVec();

	do
	{
		
		cout << "Enter your Email" << endl;
		cin >> dMail;
		cout << dVector.size() << endl;

		for (int i = 0;i < dVector.size();i++)
		{

			if (dMail == dVector[i].mail)
			{
				passCheck.assign(dVector[i].password);
				valid = 1;
				break;
			}

			j++;
			if (j >= dVector.size())
			{
				cout << "invalid email" << endl;
				valid = 0;
				break;
			}


		}


	} while (valid == 0);

	cout << "Enter your password" << endl;
	cin >> dPassword;

	while (passCheck != dPassword)
	{
		cout << "invalid password\nenter a valid password " << endl;
		cin >> dPassword;
	}
	int idd = 0;
	idd = j + 1;
	cout << "You are now logged in\nYour Id is: " << idd << endl;

}

void Donor::dFileToVec()
{
	otherFile.open("donor.txt");

	string str;
	int s1 = 0;
	while (otherFile.good())
	{
		getline(otherFile, str, '\n');
		d2Vector.push_back(str);
		s1++;
	}

	memberStruct d;

	int c = 0;
	int search = 0;
	int vecSize;
	vecSize = (d2Vector.size()-1);

	while (c < vecSize)
	{

		
		int cName = c;
		int cMail = c + 1;
		int cPassword = c + 2;
		int cPw2 = c + 3;
		int cAge = c + 4;
		int cGender = c + 5;
		int cBloodType = c + 6;
		int cDisease = c + 7;
		int cMedicine = c + 8;
		int cDate = c + 9;
		int cId = c + 10;
		
		
		d.name.assign(d2Vector[cName]);
		d.mail.assign(d2Vector[cMail]);
		d.password.assign(d2Vector[cPassword]);
		d.pw2.assign(d2Vector[cPw2]);
		d.age.assign(d2Vector[cAge]);
		d.gender.assign(d2Vector[cGender]);
		d.bloodType.assign(d2Vector[cBloodType]);
		d.disease.assign(d2Vector[cDisease]);
		d.medicine.assign(d2Vector[cMedicine]);
		d.date.assign(d2Vector[cDate]);
		d.id.assign(d2Vector[cId]);
		
		dVector.push_back(d);
		search++;
		
		c += 12;
	}
	
	
	otherFile.close();
}

void Donor::dDonationReq() 
{
	//bool dis, med;
	//int choise=0;
	donationStruct d;
	file.open("donations.txt", ios::app);


	int idd;

	cout << "Requesting a donation" << endl << endl;
	cout << "Enter yourr id" << endl;
	cin >> idd;
	

	for (int i = 1;i < dVector.size();i++)
	{
		if (i = idd)
		{
			i--;
			file << dVector[i].name << endl;
			file << dVector[i].age << endl;
			file << dVector[i].bloodType << endl;
			file << dVector[i].disease << endl;
			file << dVector[i].medicine << endl;
			file << endl;
			break;
		}
		i++;
	}
	if (i > dVector.size())
	{
		cout << "invalid id" << endl;
	}
	else
	{
		cout << "donation requested successfully" << endl;
	}


	file.close();
}

void Donor::dVecToFile()
{
	Donor d;
	int i = 0;
	file.open("donor.txt");

	for (int e = 0;e < dVector.size();e++)
	{
		
		
		file << dVector[i].name << endl;
		file << dVector[i].mail << endl;
		file << dVector[i].password << endl;
		file << dVector[i].pw2 << endl;
		file << dVector[i].age << endl;
		file << dVector[i].gender << endl;
		file << dVector[i].bloodType << endl;
		file << dVector[i].disease << endl;
		file << dVector[i].medicine << endl;
		file << dVector[i].date<< endl;
		file << dVector[i].id << endl;
		file << endl;
		i++;
	}

	file.close();

}

void Donor::dFileToQueue()
{

	otherFile.open("donations.txt");
	//d2Vector.clear();
	string str;
	int s1 = 0;
	while (otherFile.good())
	{

		getline(otherFile, str, '\n');

		d2Vector.push_back(str);
		s1++;

	}

	donationStruct q;

	int c = 0;
	int search = 0;
	int vecSize = (d2Vector.size() / 5);

	while (c < vecSize)
	{

		if (c > 0)
		{
			c--;
		}
		int cName = c;
		int cAge = c + 1;
		int cBloodType = c + 2;
		int cDisease = c + 3;
		int cMedicine = c + 4;



		q.name.assign(d2Vector[cName]);
		q.age.assign(d2Vector[cAge]);
		q.bloodType.assign(d2Vector[cBloodType]);
		q.disease.assign(d2Vector[cDisease]);
		q.medicine.assign(d2Vector[cMedicine]);


		dQueue.push(q);
		search++;
		c += 6;
	}
	otherFile.close();

}

void Donor::dDelete()
{
	int idDel = 0;
	Donor d;
	cout << "enter your id to delete your account" << endl;
	cin >> idDel;

	string del = "deleted";

	dVector[idDel].name.assign(del);
	dVector[idDel].mail.assign(del);
	dVector[idDel].password.assign(del);
	dVector[idDel].pw2.assign(del);
	dVector[idDel].age.assign(del);
	dVector[idDel].gender.assign(del);
	dVector[idDel].bloodType.assign(del);
	dVector[idDel].disease.assign(del);
	dVector[idDel].medicine.assign(del);
	dVector[idDel].date.assign(del);
	dVector[idDel].id.assign(del);
	cout << dVector[idDel].name << endl;

}

void Donor::dUpdate()
{

	//Recipient r;
	//r.rFileToVec();
	//r.r2Vector.clear();
	//r.rVector.clear();
	Donor d2;
	bool dis;
	bool med;
	bool editing = 1;
	bool passVerify = 0; //check pass before editing
	bool BloodCheck = 1; // switch case bloodtype
	bool hospitalCheck = 1;//switch case hospital
	bool docCheck = 1; //if function doctor name
	bool editCheck = 1; //switch case re-edit
	int id = 0;
	int choice1 = 0; //info to edit option
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
		if (edit_pass == dVector[id].password)
		{
			pass_valid = 1;
			while (editing)
			{




				cout << "name: " << dVector[id].name << endl;
				cout << "mail: " << dVector[id].mail << endl;
				cout << "age: " << dVector[id].age << endl;
				cout << "gender: " << dVector[id].gender << endl;
				cout << "blood type: " << dVector[id].bloodType << endl;
				cout << "diseases: " << dVector[id].disease << endl;
				cout << "medicines: " << dVector[id].medicine << endl << endl;

				cout << "choose info to edit:\n 1.name\n 2.password\n 3.mail\n 4.age\n 5.gender\n 6.blood type\n 7.diseases\n 8.medicines\n";
				cin >> choice1;

				switch (choice1)
				{

				case 1:

					cout << "current name: " << dVector[id].name << "\n";
					cout << "Enter new name" << endl;
					cin >> dVector[id].name;

					break;


				case 2:

					do
					{
						cout << "enter your current password";
						cin >> tempPass;
						if (dVector[id].password == tempPass)
						{
							passVerify = 1;
							cout << "enter new password";
							cin >> dVector[id].password;

						}
						else
						{
							cout << "invalid password try again\n";
						}

					} while (passVerify == 0);

					break;

				case 3:

					cout << "current mail: " << dVector[id].mail << endl;
					cout << "enter new mail: ";
					cin >> dVector[id].mail;

					break;

				case 4:

					cout << "current age: " << dVector[id].age << endl;
					cout << "enter new age: ";
					cin >> dVector[id].age;

					break;

				case 5:

					cout << "current gender: " << dVector[id].gender << endl;
					cout << "enter\n(1) for Male\n(2) for Female" << endl;
					cin >> choice2;

					while (choice2 != 1 && choice2 != 2)
					{
						cout << "enter a valid choise\n(1) for Male\n(2) for Female" << endl;
						cin >> choice2;
					} //checks if entered gender isn't valid, goes back to input gender

					if (choice2 == 1)
					{
						dVector[id].gender = "Male";
					}
					else
					{
						dVector[id].gender = "Female";
					}

					break;

				case 6:

					cout << "current blood type: " << dVector[id].bloodType << endl;
					cout << "enter new blood type:\n ";
					cout << "1 for A\n2 for B\n3 for AB\n4 for O" << endl;
					do
					{
						cin >> choice3;
						switch (choice3)
						{
						case 1:

							dVector[id].bloodType = "A";

							break;
						case 2:

							dVector[id].bloodType = "B";

							break;
						case 3:

							dVector[id].bloodType = "AB";

							break;
						case 4:

							dVector[id].bloodType = "O";

							break;
						default:

							cout << "Invalid choice!!\nPlease enter a valid choice" << endl;
							BloodCheck = 0;
							break;
						}
					} while (BloodCheck == 0);

					break;

				case 7:
					dVector[id].disease = " ";
					cout << "Do you suffer from any diseases?(1 for yes/0 for no)" << endl;
					cin >> dis;

					while (dis = 1)
					{
						dis = 0;

						cout << "enter disease number:\n 1.Blood pressure disorder \n 2.Thyroid diseases \n 3.Diabetes \n 4.cancer \n 5.heart disorder \n 6.hepatites\n " << endl;
						cin >> choice;
						switch (choice)
						{
						case 1:

							dVector[id].disease += "Blood pressure disorder ";
							break;
						case 2:

							dVector[id].disease += "Thyroid disease ";
							break;
						case 3:

							dVector[id].disease += "Diabetes ";
							break;
						case 4:

							dVector[id].disease += "Cancer ";
							break;
						case 5:

							dVector[id].disease += "Heart disorder ";
							break;
						case 6:
							dVector[id].disease += "Hepatites ";
							break;
						default:
							cout << "Invalid choice ";
							break;
						}

						cout << "do you suffer from any other diseases?(true/false)" << endl;
						cin >> dis;
						if (!dis)
						{
							break;
						}
						d2.i++;
					};
					break;
				case 8:
					dVector[id].medicine = " ";
					cout << "Do you take any medicine?(true/false)" << endl;
					cin >> med;

					while (med)
					{

						med = false;

						cout << "enter medicine name " << endl;
						cin >> d2.medicine;
						dVector[id].medicine += d2.medicine;
						cout << "do you take any other medicines?(0/1)" << endl;
						cin >> med;
						if (!med)
						{
							break;
						}
						d2.j++;
					};
					break;


				}
				cout << "name: " << dVector[id].name << endl;
				cout << "mail: " << dVector[id].mail << endl;
				cout << "age: " << dVector[id].age << endl;
				cout << "gender: " << dVector[id].gender << endl;
				cout << "blood type: " << dVector[id].bloodType << endl;
				cout << "diseases: " << dVector[id].disease << endl;
				cout << "medicines: " << dVector[id].medicine << endl;
				cout << "date: " << dVector[id].date << endl << endl;
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

