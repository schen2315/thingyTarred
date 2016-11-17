#ifndef VOTER_H
#define VOTER_H
#include <string>
#include <vector>
#include <ostream>
#include <iomanip>
#include <istream>

using namespace std;
enum State { PA, NY, ME, NH, VT, MA, RI, CT, NJ, DE, MD, DNE };

class Voter {
public:
	Voter(string L, string F, string usr, 
		string pass, int a, int n, string str, string t, State state,
		string z);
	~Voter();
	void Update();
	void Passwd();
	void View();
	void Donate();
	void Report();
	string getStateString(State st) const;
	State getStateCode(string st);
	string getUserId();
	float getDonated();
	int checkUser(string userid, string password);
	void iFuckedUp(float f);
private:
	string Last;
	string First;
	string userid;
	string password;
	int age;
	int strNum;
	string strname;
	string town;
	string zip;
	State state;
	float donated;
	//the calling function should use _isValid to check
	//if the user's info is valid
	//if not the calling function should undo any changes it made itself
	int _isValid();

	vector<string> commands = {"last", "first", "userid", "password", "age", "strnum", 
						"strname", "town", "state", "zip", "finish"
						};
	void _prompt();
	int _retCommand(string s);
	void _printDonated();
	friend ostream& operator<< (ostream& out, const Voter& v) {
		out << v.Last << endl << v.First << endl 
		<< v.userid << endl << v.password << endl << v.age << endl 
		<< v.strNum << endl << v.strname << endl << v.town << endl 
		<< v.zip << endl << v.getStateString(v.state) << endl << v.donated << endl;
		return out;
	}
};

#endif