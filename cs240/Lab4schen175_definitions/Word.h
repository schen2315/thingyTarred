#ifndef WORD_H
#define WORD_H

#include <iostream>

using namespace std;

class Word {
public:
	Word();
	Word(const Word &s);	
	void show();

	bool empty() const;
	int sizeOf() const;
	bool isPigLatin() const;
	void convert();
	~Word();


	Word &operator=(const Word &rightWord);	//creates a deep copy	
	Word &operator++(int num);
	Word &operator--(int num);
	Word &operator+(int num);
	Word &operator++();
	Word &operator--();


	friend ostream& operator<<(ostream &out, Word &s);
private:	
	Word* next; 
	string w;
	bool PigLatin;
};

#endif