#include "Word.h"
#include <iostream>

Word::Word() {

};
Word::Word(const Word &w) {

};	
void Word::show(){

};
bool Word::empty() const {
	return false;
};
int Word::sizeOf() const {
	return 0;
};
void Word::convert() {
	
}
Word::~Word(){

};
Word& Word::operator=(const Word &rightWord) {
	return (*this);
};	//creates a deep copy 	
Word& Word::operator++(int num) {
	return (*this);
};
Word& Word::operator--(int num) {
	return (*this);
};
Word& Word::operator+(int num) {
	return (*this);
};	
Word& Word::operator++() {
	return (*this);
};
Word& Word::operator--() {
	return (*this);
};

ostream& operator<<(ostream &out, Word &s) {
	return out;
};

