#include "Word.h"
#include <iostream>

Word::Word(string word) {
cout << "Entering function Word::Word()" << endl;
	//check that word is not empty
	w = word;
	pigLatin = false;
	next = NULL;
cout << "Leaving function Word::Word()" << endl;
};
/*
Word::Word(const Word &rightWord) {
cout << "Entering function Word::Word(const Word &w)" << endl;
//cout << "Parameters: " << w << endl;
	//w = rightWord.w;
	//pigLatin = rightWord.pigLatin;
	//next = rightWord.next;
cout << "Leaving function Word::Word(const Word &w)" << endl;
};	
*/
void Word::show(){
//cout << "Entering function Word::show()" << endl;
	cout << w;
	if(next != NULL) {
		cout << " ";
		next->show();
	}
//cout << "Leaving function Word::show()" << endl;
};
bool Word::empty() const {
// cout << "Entering function Word::empty()" << endl;
	
// cout << "Leaving function Word::empty()" << endl;
	return false;
};
void Word::convert() {
cout << "Entering function Word::convert()" << endl;

cout << "Leaving function Word::convert()" << endl;
}
Word::~Word(){
cout << "Entering function Word::~Word()" << endl;
	if(next != NULL) {
		//cout << "true" << endl;
		delete next;
	}
cout << "Leaving function Word::~Word()" << endl;
};
Word& Word::operator=(const Word &rightWord) {	
cout << "Entering function Word::operator=(const Word &rightWord)" << endl;
//cout << "this: " << *this << " Parameter: " << rightWord << endl;
	//cout << rightWord.w << endl;
	//(*this).w = "blah";
	w = rightWord.w;
	pigLatin = rightWord.pigLatin;
	next = NULL;
	if(rightWord.next != NULL) {
		Word* nextWord = new Word("dummy");
		next = nextWord;
		*nextWord = *(rightWord.next);	//sort of a recursive function
	}
cout << "Leaving function Word::operator=(const Word &rightWord)" << endl;
	return (*this);
};	//creates a deep copy 	
Word& Word::operator++(int num) {
cout << "Entering function Word::operator++(int num)" << endl;
cout << "this: " << *this << " Parameter: " << num << endl;

cout << "Leaving function Word::operator++(int num)" << endl;
	return (*this);
};
Word& Word::operator--(int num) {
cout << "Entering function Word::operator--(int num)" << endl;
cout << "Parameters: " << num << endl;

cout << "Leaving function Word::operator--(int num)" << endl;
	return (*this);
};
Word& Word::operator+(int num) {
cout << "Entering function Word::operator+(int num)" << endl;
cout << "Parameters: " << num << endl;

cout << "Leaving function Word::operator+(int num)" << endl;
	return (*this);
};	
Word& Word::operator++() {
cout << "Entering function Word::operator++()" << endl;

cout << "Leaving function Word::operator++()" << endl;
	return (*this);
};
Word& Word::operator--() {
cout << "Entering function Word::operator--()" << endl;

cout << "Leaving function Word::operator--()" << endl;
	return (*this);
};

ostream& operator<<(ostream &out, const Word &word) {
//cout << "Entering function Word::operator<<(ostream &out, const Word &s)" << endl;
	out << word.w;
//cout << "Leaving function Word::operator<<(ostream &out, const Word &s)" << endl;
	return out;		//this is return by reference
};

