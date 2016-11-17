#include "Voter.h"
class VoterDatabase {
public:
	//default constructor
	VoterDatabase();
	VoterDatabase(int max);
	//~VoterDatabase();
	Voter* Login(string userid, string password);
	State getStateCode(string st);
	void Save(string file);
	void Load(string file);
	void Report();

	void add(Voter *v);
private:
	int size;
	int max;
	//since database is dynamically allocated
	//it has to be created with new
	//and therefore must be a pointer 
	Voter** database;
	Voter* _findUser(string userid);
};


