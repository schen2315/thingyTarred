#ifndef PARAGRAPH_H
#define PARAGRAPH_H

class Paragraph;

#include <iostream>
#include "Story.h"
#include "Sentence.h"

using namespace std;

class Paragraph {
public:
	Paragraph();
	Paragraph(const Paragraph &p);	
	void show() const;

	bool empty() const;
	int sizeOf() const;
	~Paragraph();


	Paragraph &operator=(const Paragraph &rightParagraph);	//creates a deep copy
	//Paragraph operator+(const Paragraph &rightParagraph) const;	//calls the assignment operator
	//Paragraph operator+(const Sentence &rightSentence) const; 	
	Paragraph &operator++(int num);
	Paragraph &operator--(int num);
	Paragraph &operator+(int num);
	Paragraph &operator++();
	Paragraph &operator--();

	Sentence first() const;
	Paragraph rest() const;

	friend ostream& operator<<(ostream &out, const Paragraph &p);
	friend Paragraph operator+(const Sentence& leftSentence, const Paragraph& rightParagraph);
	friend Paragraph operator+(const Paragraph& leftParagraph, const Sentence& rightSentence);
	friend Paragraph operator+(const Sentence& leftSentence, const Sentence& rightSentence);
	friend Paragraph operator+(const Paragraph& leftParagraph, const Paragraph& rightParagraph);

	friend Story operator+(const Paragraph &leftParagraph, const Story &rightStory);
	friend Story operator+(const Story &leftStory, const Paragraph &rightParagraph);
	friend Story operator+(const Story &leftStory, const Story &rightStory);
private:	
	Paragraph* next; 
	Sentence* s;

};

#endif