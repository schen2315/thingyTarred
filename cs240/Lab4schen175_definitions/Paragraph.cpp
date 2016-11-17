#include "Paragraph.h"
#include <iostream>
#include "Story.h"
#include "Sentence.h"

Paragraph::Paragraph() {

};
Paragraph::Paragraph(const Paragraph &p) {

};	
void Paragraph::show() {

};

bool Paragraph::empty() const {
	return true;
};
int Paragraph::sizeOf() const {
	return 0;
};
Paragraph::~Paragraph() {

};


Paragraph &Paragraph::operator=(const Paragraph &rightParagraph) {
	return (*this);
};	//creates a deep copy
Paragraph Paragraph::operator+(const Paragraph &rightParagraph) const {
	Paragraph p;
	return p;
};	//calls the assignment operator
Paragraph Paragraph::operator+(const Sentence &rightSentence) const {
	Paragraph p;
	return p;
}; 	
Paragraph &Paragraph::operator++(int num) {
	return (*this);
};
Paragraph &Paragraph::operator--(int num) {
	return (*this);
};
Paragraph &Paragraph::operator+(int num) {
	return (*this);
};
Paragraph &Paragraph::operator++() {
	return (*this);
};
Paragraph &Paragraph::operator--() {
	return (*this);
};

Sentence Paragraph::first() const {
	Sentence s;
	return s;
};
Paragraph Paragraph::rest() const {
	Paragraph p;
	return p;
};

ostream& operator<<(ostream &out, Paragraph &p) {
	return out;
};
Paragraph operator+(const Sentence& leftSentence, const Paragraph& rightParagraph) {
	Paragraph p;
	return p;
};

