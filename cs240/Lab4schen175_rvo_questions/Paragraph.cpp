#include "Paragraph.h"
#include <iostream>
//#include "Story.h"
//#include "Sentence.h"

Paragraph::Paragraph() {
cout << "Entering function Paragraph::Paragraph()" << endl;
	next = NULL;
	s = NULL;
cout << "Leaving function Paragraph::Paragraph()" << endl;
};
Paragraph::Paragraph(const Paragraph &p) {
	cout << "Entering function Paragraph::Paragraph(const Paragraph &p)" << endl;
	next = p.next;
	s = p.s;
	cout << "Leaving function Paragraph::Paragraph(const Paragraph &p)" << endl;
};	
void Paragraph::show() const {
cout << "Entering function Paragraph::show()" << endl;
	
	if(s != NULL) {
		cout << "	";
		s->show();
	} else {
		cout << "no words in paragraph" << endl;
	}
cout << "Leaving function Paragraph::show()" << endl;
};

bool Paragraph::empty() const {
cout << "Entering function Paragraph::empty()" << endl;

cout << "Leaving function Paragraph::empty()" << endl;
	return true;
};
int Paragraph::sizeOf() const {
cout << "Entering function Paragraph::sizeOf()" << endl;

cout << "Leaving function Paragraph::sizeOf()" << endl;
	return 0;
};
Paragraph::~Paragraph() {
cout << "Entering function Paragraph::~Paragraph()" << endl;
	if(s != NULL) delete s;
	if(next != NULL) {
		delete next;
	}
cout << "Leaving function Paragraph::~Paragraph()" << endl;
};


Paragraph &Paragraph::operator=(const Paragraph &rightParagraph) {
cout << "Entering function Paragraph::operator=(const Paragraph &rightParagraph)" << endl;
	if(rightParagraph.s != NULL) {
		Sentence* nS = new Sentence();
		s = nS;
		*nS = *(rightParagraph.s);
	}
	//after finishing Story:
	if(rightParagraph.next != NULL) {
		Paragraph* nP = new Paragraph();
		next = nP;
		*nP = *(rightParagraph.next);
	}

cout << "Leaving function Paragraph::operator=(const Paragraph &rightParagraph)" << endl;
	return (*this);
};	
// Paragraph Paragraph::operator+(const Paragraph &rightParagraph) const {
// 	cout << "Entering function Paragraph::operator+(const Paragraph &rightParagraph)" << endl;
// 	cout << "Parameters:" << rightParagraph << endl;
// 	Paragraph p;
// 	cout << "Leaving function Paragraph::operator+(const Paragraph &rightParagraph)" << endl;
// 	return p;
// };	//calls the assignment operator
// Paragraph Paragraph::operator+(const Sentence &rightSentence) const {
// 	cout << "Entering function Paragraph::operator+(const Sentence &rightSentence)" << endl;
// 	cout << "Parameters: " << rightSentence << endl;
// 	Paragraph p;
// 	cout << "Leaving function Paragraph::operator+(const Sentence &rightSentence)" << endl;
// 	return p;
// }; 	
Paragraph &Paragraph::operator++(int num) {
	cout << "Entering function Paragraph::operator++(int num)" << endl;
	cout << "Parameters: " << num << endl;
	
	cout << "Leaving function Paragraph::operator++(int num)" << endl;
	return (*this);
};
Paragraph &Paragraph::operator--(int num) {
	cout << "Entering function Paragraph::operator--(int num)" << endl;
	cout << "Parameters: " << num << endl;
	
	cout << "Leaving function Paragraph::operator--(int num)" << endl;
	return (*this);
};
Paragraph &Paragraph::operator+(int num) {
	cout << "Entering function Paragraph::operator+(int num)" << endl;
	cout << "Parameters: " << num << endl;
	
	cout << "Leaving function Paragraph::operator+(int num)" << endl;
	return (*this);
};
Paragraph &Paragraph::operator++() {
	cout << "Entering function Paragraph::operator++()" << endl;
	
	cout << "Leaving function Paragraph::operator++()" << endl;
	return (*this);
};
Paragraph &Paragraph::operator--() {
	cout << "Entering function Paragraph::operator--(int num)" << endl;
	
	cout << "Leaving function Paragraph::operator--(int num)" << endl;
	return (*this);
};



Sentence Paragraph::first() const {
	cout << "Entering function Paragraph::first()" << endl;
	Sentence s;
	cout << "Leaving function Paragraph::first()" << endl;
	return s;
};
Paragraph Paragraph::rest() const {
	cout << "Entering function Paragraph::rest()" << endl;
	Paragraph p;
	cout << "Leaving function Paragraph::rest()" << endl;
	return p;
};



ostream& operator<<(ostream &out, const Paragraph &p) {
cout << "Entering function operator<<(ostream &out, const Paragraph &p)" << endl;
	p.show();
cout << "Leaving function operator<<(ostream &out, const Paragraph &p)" << endl;
	return out;
};


Paragraph operator+(const Paragraph& leftParagraph, const Sentence& rightSentence) {
cout << "Entering function operator+(const Paragraph& leftParagraph, const Sentence& rightSentence)" << endl;
	Paragraph copy;
	copy = leftParagraph;
	Sentence *lastSentence = new Sentence();
	*lastSentence = rightSentence;
	Sentence *temp = copy.s;
	if(temp != NULL) {
		while(temp->next != NULL) {
			temp = temp->next;
		}
	}
	temp->next = lastSentence;

cout << "Leaving function operator+(const Paragraph& leftParagraph, const Sentence& rightSentence)" << endl;
	return copy;
};
Paragraph operator+(const Sentence& leftSentence, const Paragraph& rightParagraph) {
cout << "Entering function operator+(const Sentence& leftSentence, const Paragraph& rightParagraph)" << endl;
	Paragraph copy;
	copy = rightParagraph;
	Sentence *nS = new Sentence();
	*nS = leftSentence;
	Sentence *temp = copy.s;
	copy.s = nS;
	nS->next = temp;

cout << "Leaving function operator+(const Sentence& leftSentence, const Paragraph& rightParagraph)" << endl;
	return copy;
};

Paragraph operator+(const Sentence& leftSentence, const Sentence& rightSentence) {
cout << "Entering function operator+(const Sentence& leftSentence, const Sentence& rightSentence)" << endl;
	Paragraph p;
	Sentence* leftCopy = new Sentence();
	*leftCopy = leftSentence;
	Sentence* rightCopy = new Sentence();
	*rightCopy = rightSentence;
	leftCopy->next = rightCopy;
	p.s = leftCopy;
cout << "Leaving function operator+(const Sentence& leftSentence, const Sentence& rightSentence)" << endl;
	return p;
};

Paragraph operator+(const Paragraph& leftParagraph, const Paragraph& rightParagraph) {
cout << "Entering function operator+(const Paragraph& leftParagraph, const Paragraph& rightParagraph)" << endl;
	Paragraph leftCopy;		
	Paragraph rightCopy;
	leftCopy = leftParagraph;	//deep copies
	rightCopy = rightParagraph;
	if(leftCopy.s != NULL) {
		Sentence* temp = leftCopy.s;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = rightCopy.s;
	} else {
		leftCopy.s = rightCopy.s;
	}
cout << "Leaving function operator+(const Paragraph& leftParagraph, const Paragraph& rightParagraph)" << endl;
	return leftCopy;
};
