#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include <iostream>
#include "Sentence.h"

using namespace std;

class Paragraph {
public:
	Paragraph();
	Paragraph(const Paragraph &p);	
	void show();

	bool empty() const;
	int sizeOf() const;
	~Paragraph();


	Paragraph &operator=(const Paragraph &rightParagraph);	//creates a deep copy
	Paragraph operator+(const Paragraph &rightParagraph) const;	//calls the assignment operator
	Paragraph operator+(const Sentence &rightSentence) const; 	
	Paragraph &operator++(int num);
	Paragraph &operator--(int num);
	Paragraph &operator+(int num);
	Paragraph &operator++();
	Paragraph &operator--();

	Sentence first() const;
	Paragraph rest() const;

	friend ostream& operator<<(ostream &out, Paragraph &p);
	friend Paragraph operator+(const Sentence& leftSentence, const Paragraph& rightParagraph);

private:	
	int size;
	Paragraph* next; 
	Sentence* s;

};

#endif