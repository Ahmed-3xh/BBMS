#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


class Donor
{


	int id=0; //automated in main function
	int i = 0; //disease array index
	int j = 0; //medicine array index
	string name;
	string mail;
	string password, pw2; //pw2 confirms password in register
	string age;
	string gender;
	string bloodType;
	string disease;
	string medicine;
	string date;
	int choice = 0; //disease switch case choice
	int choice2 = 0; //medicne switch case
	int choice3 = 0;
	ofstream file; //out file
	ifstream otherFile; //in file

public:
	struct memberStruct 
	{
		string name;
		string mail;
		string password, pw2; //pw2 confirms password in register
		string age;
		string gender;
		string bloodType;
		string disease;
		string medicine;
		string date;
		string id;
	};

	struct donationStruct
	{
		string name;
		string age;
		string bloodType;
		string disease;
		string medicine;

	};

	vector<memberStruct> dVector;
	vector <string> d2Vector;
	vector <string> d3Vector;
	queue<donationStruct> dQueue;

	void dRegister();
	void dLogin();
	void dFileToVec();
	void dFileToQueue();
	void dDonationReq();
	void dVecToFile();
	
	void dUpdate();
	void dDelete();

	

};

