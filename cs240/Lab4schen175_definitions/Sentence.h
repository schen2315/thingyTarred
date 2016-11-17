#ifndef SENTENCE_H
#define SENTENCE_H

#include <iostream>
#include "Word.h"

using namespace std;

class Sentence {
public:
	Sentence();
	Sentence(const Sentence &s);	
	void show();

	bool empty() const;
	int sizeOf() const;
	~Sentence();


	Sentence &operator=(const Sentence &rightSentence);	//creates a deep copy
	Sentence operator+(const Sentence &rightSentence) const;	//calls the assignment operator
	Sentence operator+(const Word &rightWord) const; 	
	Sentence &operator++(int num);
	Sentence &operator--(int num);
	Sentence &operator+(int num);
	Sentence &operator++();
	Sentence &operator--();

	Word first() const;
	Sentence rest() const;

	friend ostream& operator<<(ostream &out, Sentence &s);
	friend Sentence operator+(const Word& leftWord, const Sentence& rightSentence);
	friend Sentence operator+(const Word& leftWord, const Word& rightWord);
private:	
	int size;	//refers to # of words in this sentence
	Sentence* next; 
	Word* s;

};
#endif