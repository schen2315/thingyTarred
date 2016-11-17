#include "Paragraph.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
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
Paragraph::Paragraph(string para) {
cout << "Entering function Paragraph::Paragraph(string input)" << endl;
	//It was a rainy day. Everyone stayed inside.
	s = NULL;
	next = NULL;
	//create several sentences
	//cin the words, check if there is an endMark 
	//pass the substring into a Sentence value constructor
	//do this until a newline is reached
	//set (*this) to the sum of these sentences
	vector<string> sentences;
	string si = "";
	string tmp = "";
	istringstream input(para);
	//only get the first line of input
	getline(input, para);
	input = istringstream(para);
	bool end = false;
	while(!input.fail() && end == false) {
		input >> tmp;
		//loop thru
		//every time we reach a '.', '!', '?', take the substring
		for(int i=0; i < tmp.length(); i++) {
			if(tmp.at(i) == '.' || tmp.at(i) == '!' || tmp.at(i) == '?') {
				//string e(1,tmp.at(i));
				si += " " + tmp.substr(0, i+1);
				sentences.push_back(si);
				si = "";
				tmp = tmp.substr(i+1, tmp.length() - i - 1);
				break;
			} else if(tmp.at(i) == '\n') {
				si += " " + tmp.substr(0, i+1);
				sentences.push_back(si);
				si = "";
				tmp = tmp.substr(i+1, tmp.length() - i - 1);
				break;
				end = true;
			}
		}
		si += " " + tmp;
	}
	Paragraph p1;
	for(int i=0; i < sentences.size(); i++) {
		//cout << sentences[i] << endl;
		Sentence si(sentences[i]);
		p1 = p1 + si;
	}
	(*this) = p1;
cout << "Leaving function Paragraph::Paragraph(string input)" << endl;
}
void Paragraph::show() const {
cout << "Entering function Paragraph::show()" << endl;
	if(s != NULL) {
		cout << "	";
		s->show();
	} else {
		cout << "no words in paragraph" << endl;
	}
	cout << endl;
	if(next != NULL) {
		next->show();
	}
cout << "Leaving function Paragraph::show()" << endl;
};
void Paragraph::save(ofstream& file) {
	if(s != NULL) {
		file << "	";
		s->save(file);
	} 
	file << endl;
	if(next != NULL) {
		next->save(file);
	}
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
	//Sentence *hs = NULL;
	//Paragraph *hnext = NULL;
	// if(s != NULL) {
	// 	hs = s;
	// 	//hnext = next;
	// }
	if(this == &rightParagraph) return (*this);
	if(s != NULL) delete s;
	if(next != NULL) delete next;
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
	//if(hs != NULL) delete hs;
	//if(hnext != NULL) delete hnext;
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
	if(s != NULL) (*s)++;	
	if(next != NULL) (*next)++;
cout << "Leaving function Paragraph::operator++(int num)" << endl;
	return (*this);
};
Paragraph &Paragraph::operator--(int num) {
cout << "Entering function Paragraph::operator--(int num)" << endl;
	if(s != NULL) (*s)--;	
	if(next != NULL) (*next)--;
cout << "Leaving function Paragraph::operator--(int num)" << endl;
	return (*this);
};
Paragraph &Paragraph::operator+(int num) {
cout << "Entering function Paragraph::operator+(int num)" << endl;
	if(s != NULL) (*s) + 1;	
	if(next != NULL) (*next) + 1;
cout << "Leaving function Paragraph::operator+(int num)" << endl;
	return (*this);
};
Paragraph &Paragraph::operator++() {
cout << "Entering function Paragraph::operator++()" << endl;
	if(s != NULL) ++(*s);	
	if(next != NULL) ++(*next);	
cout << "Leaving function Paragraph::operator++()" << endl;
	return (*this);
};
Paragraph &Paragraph::operator--() {
cout << "Entering function Paragraph::operator--(int num)" << endl;
	if(s != NULL) --(*s);	
	if(next != NULL) --(*next);	
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
		temp->next = lastSentence;
	} else {
		copy.s = lastSentence;
	}
	

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
	//Paragraph* rightCopy = new Paragraph();			//if this is an object, the compiler will delete it since it is technically not needed anymore
													//the object won't get deleted unless it is explicitly deleted
													//this way cannot be done b.c. there is a definite memory leak
	leftCopy = leftParagraph;	//deep copies

	//Sentence* head = NULL;
	Sentence* copyIt = NULL;
	//Sentence* rightIt = NULL;
	
	//rightIt = rightParagraph.s;
	if(rightParagraph.s != NULL) {
		Sentence* nS = new Sentence();
		copyIt = nS;
		*copyIt = *(rightParagraph.s);		//deep copies of all sentences
		//head = copyIt;
		//rightIt = rightIt->next;
		/*
		while(rightIt != NULL) {
			Sentence* nS = new Sentence();
			copyIt->next = nS;
			copyIt = nS;
			*copyIt = *rightIt;
			rightIt = rightIt->next;
		}
		*/
	}
	//*rightCopy = rightParagraph;
	if(leftCopy.s != NULL) {
		Sentence* temp = leftCopy.s;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		//temp->next = rightCopy->s;
		temp->next = copyIt;
	} else {
		//leftCopy.s = rightCopy->s;
		leftCopy.s = copyIt;
	}
cout << "Leaving function operator+(const Paragraph& leftParagraph, const Paragraph& rightParagraph)" << endl;
	return leftCopy;
};
