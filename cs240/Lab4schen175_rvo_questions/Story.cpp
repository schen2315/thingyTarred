#include "Story.h"
//#include "Paragraph.h"
#include <iostream>

using namespace std;
Story::Story() {
cout << "Entering function Story::Story()" << endl;
	p = NULL;
cout << "Leaving function Story::Story()" << endl;	
}
Story::Story(string file) {
cout << "Entering function Story::Story(string file)" << endl;
cout << "Parameters: " << file << endl;
	p = NULL;	//work on this function later;
cout << "Leaving function Story::Story(string file)" << endl;	
}
void Story::show() const {
cout << "Entering function Story::show()" << endl;

cout << "Leaving function Story::show()" << endl;	
};
void Story::save(string file) {
cout << "Entering function Story::save(string file)" << endl;
cout << "Parameters: " << file << endl;
	
cout << "Leaving function Story::save(string file)" << endl;		
};
bool Story::empty() const {
cout << "Entering function Story::empty()" << endl;

cout << "Leaving function Story::empty()" << endl;	
	return true;
};
int Story::sizeOf() const {
cout << "Entering function Story::sizeOf()" << endl;

cout << "Leaving function Story::sizeOf()" << endl;	
	return 0;
};
Story::~Story() {
cout << "Entering function Story::~Story()" << endl;
	if(p != NULL) delete p;
cout << "Leaving function Story::~Story()" << endl;	
}
Story &Story::operator=(const Story &rightStory) {
cout << "Entering function Story::operator=(const Story &rightStory)" << endl;
	if(rightStory.p != NULL) {
		Paragraph *nP = new Paragraph();
		p = nP;
		*nP = *(rightStory.p);
	}
cout << "Leaving function Story::show()" << endl;	
	return (*this);
};
// Story Story::operator+(const Story &rightStory) const {
// 	cout << "Entering function Story::operator+(const Story &rightStory)" << endl;
// 	cout << "Parameters: " << rightStory << endl;

// 	Story s;
// 	cout << "Leaving function Story::operator+(const Story &rightStory)" << endl;
// 	return s;
// };
// Story Story::operator+(const Paragraph &para) const {
// 	cout << "Entering function Story::operator+(const Paragraph &para)" << endl;
// 	cout << "Parameters: " << para << endl;

// 	Story s;
// 	cout << "Leaving function Story::operator+(const Paragraph &para)" << endl;
// 	return s;
// };
//postfix
Story &Story::operator++(int num) {
	cout << "Entering function Story::operator++(int num)" << endl;
	cout << "Parameters: " << num << endl;

	cout << "Leaving function Story::operator++(int num)" << endl;	
	return (*this);
};
Story &Story::operator--(int num) {
	cout << "Entering function Story::operator--(int num)" << endl;
	cout << "Parameters: " << num << endl;

	cout << "Leaving function Story::operator--(int num)" << endl;	
	return (*this);
};
Story &Story::operator+(int num) {
	cout << "Entering function Story::operator+(int num)" << endl;
	cout << "Parameters: " << num << endl;

	cout << "Leaving function Story::operator+(int num)" << endl;	
	return (*this);
};
//prefix
Story &Story::operator++() {
	cout << "Entering function Story::operator++()" << endl;

	cout << "Leaving function Story::operator++()" << endl;	
	return (*this);
};
Story &Story::operator--() {
	cout << "Entering function Story::operator--()" << endl;

	cout << "Leaving function Story::operator--()" << endl;	
	return (*this);
};



Paragraph Story::first() const {
cout << "Entering function Story::first()" << endl;
	Paragraph p;
cout << "Leaving function Story::first()" << endl;
	return p;
};
Story Story::rest() const {
cout << "Entering function Story::rest()" << endl;
	Story s;
cout << "Leaving function Story::rest()" << endl;
	return s;
};


ostream& operator<<(ostream &out, const Story &s) {
cout << "Entering function operator<<(ostream &out, const Story &s)" << endl;
	s.show();
cout << "Leaving function Story::out()" << endl;
	return out;
};


Story operator+(const Story &leftStory, const Paragraph &rightParagraph) {
cout << "Entering function operator+(const Story &leftStory, const Paragraph &rightParagraph)" << endl;
	Story copy;
cout << "Leaving function operator+(const Story &leftStory, const Paragraph &rightParagraph)" << endl;
	return copy;
};
Story operator+(const Paragraph &leftParagraph, const Story &rightStory) {
cout << "Entering function operator+(const Paragraph &leftParagraph, const Story &rightStory)" << endl;
	Story copy;
	

cout << "Leaving function operator+(const Paragraph &leftParagraph, const Story &rightStory)" << endl;
	return copy;
};
Story operator+(const Story &leftStory, const Story &rightStory) {
cout << "Entering function operator+(const Story &leftStory, const Story &rightStory)" << endl;
	Story copy;

cout << "Leaving function operator+(const Story &leftStory, const Story &rightStory)" << endl;
	return copy;
};




