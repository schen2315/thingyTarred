#include "Voter.h"
#include <iostream>
using namespace std;


Voter::Voter(string L, string F, string usr, 
		string pass, int a, int n, string str, string t, State st,
		string z) {
	Last = L;
	First = F;
	userid = usr;
	password = pass;
	age = a;
	strNum = n;
	strname = str;
	town = t;
	state = st;
	zip = z;
	donated = 0.0;
}
Voter::~Voter() {
	//when called automatically calls the destructors for its
	//non-pointer data members
}
void Voter::iFuckedUp(float f) {
	donated = f;
}
void Voter::_printDonated() {
	cout << "$";
	cout << fixed;
    cout << setprecision(2);
    cout << donated;
}
//destructor goes here
void Voter::Update() {
	int finish = 0;
	string command;
	while(!finish) {
		cout << "Please choose a field to update: [\"Last\", \"First\", \"Age\", \"Street Number\", \"Street Name\", \"Town\", \"State\", \"Zip Code\"]";
		cout << endl;
		cout << "Or enter \"Finish\" to finish updating" << endl;
		cout << ": ";
		cin >> command;
		cout << endl;
		//do type checking
		if(command == "Last") {
			string input;
			cin >> input;
			string old_Last = Last;
			Last = input;
			if(_isValid() == 1) {
				cout << "Last name updated to " << Last << endl;	
			} else {
				Last = old_Last;
				cout << "Failed to update last name. Last name must contain only letters." << endl;
			}
		} else if(command == "First") {
			string input;
			cin >> input;
			string old_First = First;
			First = input;
			if(_isValid() == 1) {
				cout << "First name updated to " << First << endl;
			} else {
				First = old_First;
				cout << "Failed to update first name. First name must only contain letters" << endl;		
			}
		} else if(command == "Age") {
			int input;
			cout << "age: ";
			cin >> input;
			int old_age = age;
			age = input;
			if(_isValid() == 1) {
				cout << "age updated to " << age << endl;
			} else {
				age = old_age;
				cout << "Failed to update age. Thou must be at least 18." << endl;
			}
		} else if(command == "Street Number") {
			int input;
			cout << "Street Number: " << endl;
			cin >> input;
			int old_strNum = strNum;
			strNum = input;
			if(_isValid() == 1) {
				cout << "Street Number updated to" << strNum << endl;
			} else {
				strNum = old_strNum;
				cout << "Failed to update Street Number. Invalid Street Number." << endl;		
			}
		} else if(command == "Street Name") {
			string input;
			cout << "Street Name: " << endl;
			cin >> input;
			string old_strname = strname;
			strname = input;
			if(_isValid() == 1) {
				cout << "Street Name updated to " << strname << endl;
			} else {
				strname = old_strname;
				cout << "Failed to update Street Name. Invalid Street Name." << endl;	
			}
		} else if(command == "Town") {
			string input;
			cout << "Town: " << endl;
			cin >> input;
			string old_town = town;
			town = input;
			if(_isValid() == 1) {
				cout << "Town updated to " << town << endl;
			} else {
				town = old_town;
				cout << "Failed to update Town. Invalid Town name." << endl;
			}
		} else if(command == "State") {
			string input;
			cout << "State: " << endl;
			State old_state = state;
			cin >> input;
			state = getStateCode(input);
			if(_isValid() == 1) {
				cout << "State updated to " << state << endl;
			} else {
				state = old_state;
				cout << "Failed to update State. Invalid State Code. Only New Englanders allowed." << endl;
			}
		} else if(command == "Zip Code") {
			string input;
			cout << "Zip: " << endl;
			string old_zip = zip;
			cin >> input;
			zip = input;
			if(_isValid() == 1) {
				cout << "Zip Code updated to " << zip << endl; 
			} else {
				zip = old_zip;
				cout << "Invalid Zip Code. Zip Code must be exactly 5 digits." << endl;
			}
		} else if(command == "Finish") {
			finish = 1;
		} else {
			cout << "Error. Your imput did not match a command" << endl;
		}
	}
}
State Voter::getStateCode(string st) {
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
string Voter::getStateString(State st) const {
	switch(st) {
		case PA: {
			return "PA";
		}
		case NY: {
			return "NY";
		}
		case ME: {
			return "ME";
		}
		case NH: {
			return "NH";
		}
		case VT: {
			return "VT";
		}
		case MA: {
			return "MA";
		}
		case RI: {
			return "RI";
		}
		case CT: {
			return "CT";
		}
		case NJ: {
			return "NJ";
		}
		case DE: {
			return "DE";
		}
		case MD: {
			return "MD";
		}
		case DNE: {
			//it would be a bug for this case to ever happen.
			//But it needs to be here for the compiler to shut up.
			return "DNE";
		}
	}
};
string Voter::getUserId() {
	return userid;
}
int Voter::checkUser(string u, string p) {
	int retVal = 0;
	if(u == userid && p == password) {
		retVal = 1;
	}
	return retVal;
}

int Voter::_isValid() {
	//check that all fields are valid
	int valid = 1;
	for(int i=0; i < Last.length(); i++) {
		if((Last.at(i) <= 'A' && Last.at(i) >= 'Z')
			&& (Last.at(i) <= 'a' && Last.at(i) >= 'z')) {
			cout << "Invalid Last name, only letters allowed" << endl;
			cout << ": " ;
			valid = 0;
			break;
		} 
	}
	for(int i=0; i < First.length(); i++) {
		if((First.at(i) <= 'A' && First.at(i) >= 'Z')
			&& (First.at(i) <= 'a' && First.at(i) >= 'z')) {
			cout << "Invalid First name, only letters allowed" << endl;
			cout << ": " ;
			valid = 0;
			break;
		} 
	}
	if(userid.length() >= 5 && userid.length() <= 10) {
		for(int i=0; i < userid.length(); i++) {
			if((userid.at(i) <= 'A' && userid.at(i) >= 'Z')
				&& (userid.at(i) <= 'a' && userid.at(i) >= 'z') 
				&& (userid.at(i) <= '0' && userid.at(i) >= '9')) {	//if the character is not a letter or digit
				cout << "Invalid userid name, only letters and numbers allowed" << endl;
				cout << ": " ;
				valid = 0;
				break;
			} 
		}
	} else {
		valid = 0;
	}
	int specialChar = 0;
	int digit = 0;
	if(password.length() > 6) {
		for(int i=0; i < password.length(); i++) {
			if(password.at(i) >= '0' && password.at(i) <= '9') digit = 1;	//if we have at least 1 digit
			if((password.at(i) <= 'A' && password.at(i) >= 'Z') 
				&& (password.at(i) <= 'a' && password.at(i) >= 'z')
			 	&& (password.at(i) <= '0' && password.at(i) >= '9')) {
					specialChar = 1;	//at least one char not a letter or number
				}
		}
	} else {
		valid = 0;
	}
	if(specialChar != 1 || digit != 1) {
		valid = 0;
	}
	if (age < 18) {
		valid = 0;
		cout << "You are underage. Contact your parents" << endl;
	} 
	if(strNum < 0) {
		valid = 0;
	}
	if(state == DNE) {
		valid = 0;
	}
	if(zip.length() == 5) {
		for(int i=0; i< 5; i++) {
			if(userid.at(i) <= '0' || userid.at(i) >= '9') {
				valid = 0;
			}
		}
	} else {
		valid = 0;
	}
	if(donated < 0 || donated > 2700) {
		valid = 0;
	}
	//DNE is not a valid state
	return 1;
};


void Voter::View() {
	cout << Last << ", " << First << endl;
	cout << "age: " << age << endl;
	cout << strNum << " " << strname << endl;
	cout << town << ", " << getStateString(state) << " " << zip << endl;
}
void Voter::Donate() {
	float input;
	cout << "How much would thou like to donate? Thou total donation cannot exceed $2700" << endl;
	cout << ": " << endl;
	cin >> input;
	//type check info
	if(input > 0) {
		donated += input;
		if(donated > 2700) {
			donated -= input;
			cout << "Donation failed. Thou total donation cannot exceed $2700" << endl;
			cout << "Donation total is ";
			_printDonated();
			cout << endl;
		} else {
			cout << "Donation complete. New total donation is $";
			_printDonated();
			cout << endl;
		}
	} else {
		cout << "Donation failed. Donation amount must be a positive number." << endl;
		cout << "Donation total is ";
		_printDonated();
		cout << endl;
	}
}
void Voter::Report() {
	cout << Last << " ";
	_printDonated();
	cout << endl;
}
void Voter::Passwd() {
	string input;
	string input2;
	string input3;
	cout << "Please enter your current password" << endl;
	cout << ": ";
	cin >> input;
	if(input == password) {
		cout << "enter New Password" << endl;
		cout << ": ";
		cin >> input2;
		cout << "Please enter New Password again" << endl;
		cout << ": ";
		cin >> input3;
		if(input2 == input3) {
			string old_password = password;
			password = input2;
			if(_isValid() == 1) {
				cout << "Password successfully changed." << endl;
			} else {
				password = old_password;
				cout << "New Password is not a valid password. Password must contain at least 6 characters, including at least one digit and one character that is neither a letter nor a digit" << endl;
			}
		} else {
			cout << "New passwords do not match. Password change failed." << endl;
		}
	} else {
		cout << "Incorrect Password" << endl;
	}
}
float Voter::getDonated() {
	return donated;
}

//ask YuHeng if the user is allowed to update amount donated
