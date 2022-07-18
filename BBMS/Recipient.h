#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;



class Recipient
{

	
		int id = 1; 
		string name;
		string mail;
		string password;
		string pw2; //to confirm the password in register
		string age ;
		string gender ;
		string bloodType;
		string hospital;
		string doctor;

	int choice2 = 0;
	int choice3 = 0;
	ofstream file; //output file
	ifstream otherFile; //input file

	
	string loginM;
	string loginP;

	
	


public:
	struct memberStruct 
	{
		
		
		string name;
		string mail;
		string password;
		string pw2; //to confirm the password in register
		string age;
		string gender;
		string bloodType;
		string hospital;
		string doctor;
		string id;
		
	};

	Recipient();
	vector <string> r2Vector;
	vector<memberStruct> rVector;
	void rRegister();
	void rLogin();
	void rFileToVec();
	void rVecToFile();
	void rUpdate();
	void rDelete();
	void rSearch();
	void rDisplay();
	void rReqBloodType();
	~Recipient();

	
	



};

