#ifndef SENTENCE_H
#define SENTENCE_H

class Sentence;

#include <iostream>
#include "Word.h"
#include "Paragraph.h"
#include <fstream>

using namespace std;

class Sentence {
public:
	Sentence();
	Sentence(string s);
	//Sentence(const Sentence &s);	
	void show() const;
	void save(ofstream& file);

	bool empty() const;
	~Sentence();


	Sentence &operator=(const Sentence &rightSentence);	//creates a deep copy
	//Sentence operator+(const Sentence &rightSentence) const;	//calls the assignment operator
	Sentence &operator++(int num);
	Sentence &operator--(int num);
	Sentence &operator+(int num);
	Sentence &operator++();
	Sentence &operator--();

	Word first() const;
	Sentence rest() const;

	friend ostream& operator<<(ostream &out, const Sentence &s);
	friend Sentence operator+(const Sentence &leftSentence, const Word &rightWord);
	friend Sentence operator+(const Word& leftWord, const Sentence& rightSentence);
	friend Sentence operator+(const Word& leftWord, const Word& rightWord);

	friend Paragraph operator+(const Paragraph& leftParagraph, const Paragraph& rightParagraph);
	friend Paragraph operator+(const Sentence& leftSentence, const Paragraph& rightParagraph);
	friend Paragraph operator+(const Paragraph& leftParagraph, const Sentence& rightSentence);
	friend Paragraph operator+(const Sentence& leftSentence, const Sentence& rightSentence);
private:	
	string endMark;
	Sentence* next; 
	Word* w;

	Word* stringParser(string s);
};
#endif