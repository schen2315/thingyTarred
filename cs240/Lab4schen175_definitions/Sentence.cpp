#include "Sentence.h"

Sentence::Sentence() {

};
Sentence::Sentence(const Sentence &s) {

};	
void Sentence::show(){

};
bool Sentence::empty() const {
	return false;
};
int Sentence::sizeOf() const {
	return 0;
};
Sentence::~Sentence(){

};
Sentence& Sentence::operator=(const Sentence &rightSentence) {
	return (*this);
};	//creates a deep copy
Sentence Sentence::operator+(const Sentence &rightSentence) const {
	Sentence s;
	return s;
};	//calls the assignment operator
Sentence Sentence::operator+(const Word &rightWord) const {
	Sentence s;
	return s;
}; 	
Sentence& Sentence::operator++(int num) {
	return (*this);
};
Sentence& Sentence::operator--(int num) {
	return (*this);
};
Sentence& Sentence::operator+(int num) {
	return (*this);
};	
Sentence& Sentence::operator++() {
	return (*this);
};
Sentence& Sentence::operator--() {
	return (*this);
};

Word Sentence::first() const {
	Word w;
	return w;
};
Sentence Sentence::rest() const {
	Sentence s;
	return s;
};

ostream& operator<<(ostream &out, Sentence &s) {
	return out;
};
Sentence operator+(const Word& leftWord, const Sentence& rightSentence) {
	Sentence s;
	return s;
};
Sentence operator+(const Word& leftWord, const Word& rightWord) {
	Sentence s;
	return s;
};