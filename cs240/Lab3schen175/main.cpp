//nested loop
	//the first loop is the top level menu
	//if a user logs in, call a function that holds the 2nd loop
		//the particular user/ voter should be passed by reference
		//by finding that voter in the voterDatabase
	//the 2nd loop contains the 2nd level menu
		//if a user types logout, then the function exits
		//and will go back to the first loop
	//if a user types quit in the 1st menu, main() will exit
#include <iostream>
#include "Voter.h"
#include "VoterDatabase.h"
#include <vector>
#include <map>

using namespace std;

vector<string> stateNames = {
	"PA", "NY", "ME", "NH", "VT", "MA", "RI", "CT", "NJ", "DE", "MD"
};
map<string, State> stateCode;

void prompt();
int retCommand(string s);
void Login(VoterDatabase &d);
void New(VoterDatabase &d);
void secondMenu(Voter &v);
void Report(VoterDatabase &d);
void Save(VoterDatabase &d);
void Load(VoterDatabase &d);

void Login(VoterDatabase &d) {
	string userid;
	string password;
	cout << "userid: ";
	cin >> userid;
	cout << "password: ";
	cin >> password;
	Voter* v = d.Login(userid, password);
	//check that v is not null
		//if not pass it by reference to 
		//a function that holds a loop
	if(v != NULL) {
		secondMenu(*v);
	} else {
		cout << "Incorrect Username or Password. Please Try Again" << endl;
	}
}
void Report(VoterDatabase &d) {
	d.Report();
}	
void New(VoterDatabase &d) {	//don't create copies when you can just pass references
	string last;
	string first;
	string userid;
	string password;
	int age;
	int strnum;
	string strname;
	string town;
	State state;
	string zip;

	cout << "Last Name: ";
	cin >> last;
	cout << "First Name: ";
	cin >> first;
	cout << "userid: ";
	cin >> userid;
	cout << "password: ";
	cin >> password;
	cout << "age: ";
	cin >> age;
	cout << "street number: ";
	cin >> strnum;
	cout << "street name: ";
	cin >> strname;
	cout << "town: ";
	cin >> town;
	cout << "state: ";
	string temp;
	cin >> temp;
	state = stateCode.find(temp)->second;
	cout << "zip code: " ;
	cin >> zip;

	Voter* voter = new Voter(last, first, userid, password, age, strnum, 
	 	strname, town, state, zip);
	d.add(voter);
}
void Save(VoterDatabase &d) {
	string input;
	cout << "Enter the name of the file to output Voter Database information to" << endl;
	cout << ": ";
	cin >> input;
	d.Save(input);
}
void Load(VoterDatabase &d) {
	string input;
	cout << "Enter the name of the file to retrieve Voter Database information from" << endl;
	cout << ": ";
	cin >> input;
	d.Load(input);
}
void secondMenu(Voter &v) {
	string command;
	int quit = 0;
	while(!quit) {
		cout << "Please type a command: Update, Passwd, View, Donate, Report, Logout" << endl;
		cout << ": ";
		cin >> command;
		if(command == "Update") {
			v.Update();
		} else if(command == "Passwd") {
			v.Passwd();
		} else if(command == "View") {
			v.View();
		} else if(command == "Donate") {
			v.Donate();
		} else if(command == "Report") {
			v.Report();
		} else if(command == "Logout") {
			quit = 1;
		}
	}
};
int main(int m, char** argv) {
	//max is required
	//argv[] is not
	VoterDatabase database(atoi(argv[1]));
	//find a better place to put this
	for(int i=PA; i != MD; i++) {
		stateCode.insert(pair<string, State>(stateNames[i], static_cast<State>(i)));
	}
	
	string command;
	//1st level menu
	while(true) {
		cout << "Enter a command." << endl;
		cout << "Choose from [\"Login\" \"New\" \"Save\" \"Load\" \"Report\" \"Quit\"]" << endl;
		cout << ": ";
		cin >> command;
		if(command == "Login") {
			Login(database);
		} else if(command == "New") {
			New(database);
		} else if(command == "Save") {
			Save(database);
		} else if(command == "Load") {
			Load(database);
		} else if(command == "Report") {
			Report(database);
		} else if(command == "Quit") {
			break;
		} else {
			cout << "Command not recognized. Please try again." << endl;
		}
	}
	return 0;
}
