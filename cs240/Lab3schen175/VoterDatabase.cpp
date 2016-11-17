#include <iostream>
#include <fstream>
#include "Voter.h"
#include "VoterDatabase.h"

using namespace std;
//default constructor
VoterDatabase::VoterDatabase() {
	size = 0;
	max = 25;
	database = new Voter*[25];
};
VoterDatabase::VoterDatabase(int m) {
	size = 0;
	//cout <<  m << endl;
	if(m < 1000 && m > 1) { 
		max = m;
		database = new Voter*[max];
	} else {
		max = 25;
		database = new Voter*[25];
	}
};
Voter* VoterDatabase::Login(string u, string p) {
	Voter* v = NULL;
	if(_findUser(u) != NULL) {
		if(_findUser(u)->checkUser(u, p) ==  1) {
			v = _findUser(u);
		}
	}
	return v;
};
State VoterDatabase::getStateCode(string st) {
	if(st == "PA") {
		return PA;
	} else if(st == "NY") {
		return NY;
	} else if(st == "ME") {
		return ME;
	} else if(st == "NH") {
		return NH;
	} else if(st == "VT") {
		return VT;
	} else if(st == "MA") {
		return MA;
	} else if(st == "RI") {
		return RI;
	} else if(st == "CT") {
		return CT;
	} else if(st == "NJ") {
		return NJ;
	} else if(st == "DE") {
		return DE;
	} else if(st == "MD") {
		return MD;
	} else {
		return DNE;
	}
}
void VoterDatabase::Save(string file) {
	bool overwrite = false;
	ofstream out(file);
	string input;
	while(!overwrite) {
		if(!out.fail()) {
			cout << file << " already exists. Do you wish overwrite this file?" << endl;
			cout << "Enter \"Yes\" to overwrite or \"No\" to select a different file" << endl;
			cin >> input;
			if(input == "No") {
				cin >> input;
				ofstream out(input);
			} else {
				overwrite = true;
			}	
		} else {
			overwrite = true;
		}
	}
	out << size << endl;
	for(int i=0; i< size; i++) {
		out << *(*(database+i)) << endl;
	}
};
void VoterDatabase::Load(string file) {
	ifstream in(file);
	int new_size;
	in >> new_size;
	if(new_size > max) {
		cout << "Cannot load file. Database exceeds Voter count limit" << endl;
		return;
	}
	size = 0;
	database = new Voter*[max];
	for(int i=0; i< new_size; i++) {
		string Last;
		string First;
		string userid;
		string password;
		int age;
		int strNum;
		string strname;
		string town;
		string zip;
		string temp;
		State state;
		float donated;

		// getline(in, Last);
		// getline(in, First);
		// getline(in, userid);
		// getline(in, password);
		in >> Last;
		in >> First;
		in >> userid;
		in >> password;
		in >> age;
		in >> strNum;
		// getline(in, strname);
		// getline(in, town);
		// getline(in, zip);
		// getline(in, temp);
		in >> strname;
		in >> town;
		in >> zip;
		in >> temp;
		state = getStateCode(temp);
		in >> donated;
		Voter *v = new Voter(Last, First, userid, password, age, strNum, strname, town, state, zip);
		v->iFuckedUp(donated);

		add(v);
	}
};
void VoterDatabase::add(Voter *v) {
	//when adding a new voter check that another
	//voter with the same username does not exist
	//check that the size limit works
	if(size < max && _findUser(v->getUserId()) == NULL) {
		*(database+size) = v;
		//cout << *(database) << endl;
		size++;
		//cout << size << endl;
		cout << v->getUserId() << " added successfully" << endl;
	} else if(_findUser(v->getUserId()) != NULL){
		cout << v->getUserId() << " already exists" << endl;
		delete v;
		//calls destructor of VoterDatabase
	} else if(size >= max) {
		cout << "No more room in database" << endl;
		delete v;
	}
	
}
Voter* VoterDatabase::_findUser(string userid) {
	Voter* retVal = NULL;
	for(int i=0; i< size; i++) {
		if((*(database+i))->getUserId() == userid) {
			retVal = *(database+i);
		}
	}
	return retVal;
};
void VoterDatabase::Report() {
	float total;
	for(int i=0; i < size; i++) {
		total += (*(database+i))->getDonated();
	}
	cout << size << " Total Voters" << endl;
	cout << "Total Donations: ";
	cout << "$";
	cout << fixed;
    cout << setprecision(2);
    cout << total << endl;
}



