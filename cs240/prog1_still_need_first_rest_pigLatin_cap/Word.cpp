#include "Word.h"
#include <iostream>
#include <fstream>


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
void Word::save(ofstream& file) {
cout << "Entering function Word::save()" << endl;
	file << w;
	if(next != NULL) {
		file << " ";
		next->save(file);
	}
cout << "Leaving function Word::save()" << endl;	
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
	// Word *hw = NULL;
	// if(h != NULL) {
	// 	hw = w;
	// }
	if(this == &rightWord) return (*this);
	if(next != NULL) {
		delete next;
	}
	w = rightWord.w;
	cout << rightWord.w << endl;
	pigLatin = rightWord.pigLatin;
	next = NULL;
	if(rightWord.next != NULL) {
		Word* nextWord = new Word("dummy");
		next = nextWord;
		*nextWord = *(rightWord.next);	//sort of a recursive function
	}
	//if(hw != NULL) delete hw;
cout << "Leaving function Word::operator=(const Word &rightWord)" << endl;
	return (*this);
};	//creates a deep copy 	

Word& Word::operator++(int num) {
cout << "Entering function Word::operator++(int num)" << endl;
	//test nesting works
	w = w + "+";
	if(next != NULL) (*next)++;
cout << "Leaving function Word::operator++(int num)" << endl;
	return (*this);
};

Word& Word::operator--(int num) {
cout << "Entering function Word::operator--(int num)" << endl;
	w = w + "-";
	if(next != NULL) (*next)--;
cout << "Leaving function Word::operator--(int num)" << endl;
	return (*this);
};
Word& Word::operator+(int num) {
cout << "Entering function Word::operator+(int num)" << endl;
	w = w + "+1";
	if(next != NULL) (*next) + 1;
cout << "Leaving function Word::operator+(int num)" << endl;
	return (*this);
};	
Word& Word::operator++() {
cout << "Entering function Word::operator++()" << endl;
	w = "+" + w;
	if(next != NULL) ++(*next);
cout << "Leaving function Word::operator++()" << endl;
	return (*this);
};
Word& Word::operator--() {
cout << "Entering function Word::operator--()" << endl;
	w = "-" + w;
	if(next != NULL) --(*next);
cout << "Leaving function Word::operator--()" << endl;
	return (*this);
};

ostream& operator<<(ostream &out, const Word &word) {
//cout << "Entering function Word::operator<<(ostream &out, const Word &s)" << endl;
	out << word.w;
//cout << "Leaving function Word::operator<<(ostream &out, const Word &s)" << endl;
	return out;		//this is return by reference
};

