#include "Sentence.h"
#include <fstream>
#include <sstream>
#include <vector>
Sentence::Sentence() {
cout << "Entering function Sentence::Sentence()" << endl;
	next = NULL;
	w = NULL;
	endMark = ". ";
cout << "Leaving function Sentence::Sentence()" << endl;
};
Sentence::Sentence(string s) {
	cout << "Entering function Sentence::Sentence(string s)" << endl;
	next = NULL;
	w = NULL;
	endMark = ". ";
	//we will read in only until the first punctuation mark or until the end of the string
	vector<string> words;
	string tmp = "";
	istringstream input(s);
	bool end = false;
	while(!input.fail() && end == false) {
		//cout << tmp << " ";
		input >> tmp;
		for(int i=0; i < tmp.length(); i++) {
			if(tmp.at(i) == '.' || tmp.at(i) == '!' || tmp.at(i) == '?') {
				string e(1,tmp.at(i));
				endMark = e + " ";
				end = true;
				tmp = tmp.substr(0, i);
				break;
			}
		}
		words.push_back(tmp);
	}
	Sentence s1;
	s1.endMark = endMark;
	//s1 = s1 + Word(words[0]);
	//Word wi(words[0]);
	for(int i=0; i < words.size(); i++) {
		Word wi(words[i]);
		s1 = s1 + wi;
	}
	(*this) = s1;
	cout << "Leaving function Sentence::Sentence(string s)" << endl;
}
Word* Sentence::stringParser(string s) {
	Word *word = NULL;
	return word;
};
/*
Sentence::Sentence(const Sentence &s) {
	cout << "Entering function Sentence::Sentence(const Sentence &s)" << endl;
	//cout << "Parameters: dajksd" << s << endl;

	cout << "Leaving function Sentence::Sentence(const Sentence &s)" << endl;
};
*/	
void Sentence::show() const{
//cout << "Entering function Sentence::show()" << endl;
	
	if(w != NULL) {
		w->show();
	} else {
		cout << "no words in sentence" << endl;
	}
	cout << endMark;
	if(next != NULL) {
		next->show();
	}
//cout << "Leaving function Sentence::show()" << endl;
};
void Sentence::save(ofstream& file) {
	if(w != NULL) {
		w->save(file);
	} 
	file << endMark;
	if(next != NULL) {
		next->save(file);
	}
};
bool Sentence::empty() const {
	cout << "Entering function Sentence::empty()" << endl;
	if(w == NULL) 
		return true;
	cout << "Leaving function Sentence::empty()" << endl;
	return false;
};
Sentence::~Sentence(){
cout << "Entering function Sentence::~Sentence()" << endl;
	if(w != NULL) delete w;
	if(next != NULL) {
		delete next;
	}
cout << "Leaving function Sentence::~Sentence()" << endl;
};
Sentence& Sentence::operator=(const Sentence &rightSentence) {
cout << "Entering function Sentence::operator=(const Sentence &rightSentence)" << endl;
//cout << "Parameters: " << rightSentence << endl;
	//rely on the assignment operator of Word to create the deep copy of Word
	if(this == &rightSentence) return (*this);
	endMark = rightSentence.endMark;
	//you need to delete what is originally inside this object first
	// Word *hw = NULL;
	// if(w != NULL) {
	// 	//hw = w;
	// 	hw = w;
	// }

	if(w != NULL) delete w;
	if(next != NULL) delete next;
	if(rightSentence.w != NULL) {
		//cout << "hey hey" << endl;
		Word *nW = new Word("dummy");
		w = nW;
		cout << *(rightSentence.w) << endl;
		*nW = *(rightSentence.w);
	}
	//eventually add this functionality when writing Paragraph
	
	if(rightSentence.next != NULL) {
		Sentence* nS = new Sentence();
		next = nS;
		*nS = *(rightSentence.next);		//again dynamic/recursive
	}	
	//if(hw != NULL) delete hw;
cout << "Leaving function Sentence::operator=(const Sentence &rightSentence)" << endl;
	return (*this);
};	//creates a deep copy
/*
Sentence Sentence::operator+(const Sentence &rightSentence) const {
	cout << "Entering function Sentence::operator+(const Sentence &rightSentence)" << endl;
	cout << "Parameters: " << rightSentence << endl;
	//
	Sentence s;
	cout << "Leaving function Sentence::operator+(const Sentence &rightSentence)" << endl;
	return s;
};	//calls the assignment operator
*/
	
Sentence& Sentence::operator++(int num) {
cout << "Entering function Sentence::operator++(int num)" << endl;
	//postfix
	if(w != NULL) (*w)++;
	if(next != NULL) (*next)++;
cout << "Leaving function Sentence::operator++(int num)" << endl;
	return (*this);
};
Sentence& Sentence::operator--(int num) {
cout << "Entering function Sentence::operator--(int num)" << endl;
	if(w != NULL) (*w)--;
	if(next != NULL) (*next)--;
cout << "Leaving function Sentence::operator--(int num)" << endl;
	return (*this);
};
Sentence& Sentence::operator+(int num) {
cout << "Entering function Sentence::operator+(int num)" << endl;
	if(w != NULL) (*w) + 1;
	if(next != NULL) (*next) + 1;
cout << "Leaving function Sentence::operator+(int num)" << endl;
	return (*this);
};	
Sentence& Sentence::operator++() {
cout << "Entering function Sentence::operator++" << endl;
	if(w != NULL) ++(*w);
	if(next != NULL) ++(*next);
cout << "Leaving function Sentence::operator++" << endl;
	return (*this);
};
Sentence& Sentence::operator--() {
cout << "Entering function Sentence::operator--" << endl;
	if(w != NULL) --(*w);
	if(next != NULL) --(*next);
cout << "Leaving function Sentence::operator--" << endl;	
	return (*this);
};

Word Sentence::first() const {
	cout << "Entering function Sentence::first()" << endl;
	Word w("dummy");

	cout << "Leaving function Sentence::first()" << endl;	
	return w;
};
Sentence Sentence::rest() const {
	cout << "Entering function Sentence::rest()" << endl;
	Sentence s;
	cout << "Leaving function Sentence::rest()" << endl;
	return s;
};

ostream& operator<<(ostream &out, const Sentence &s) {
	cout << "Entering function operator<<(ostream &out, const Sentence &s))" << endl;
	//cout << "Parameters: " << s << endl;
	s.show();
	cout << "Leaving function operator<<(ostream &out, const Sentence &s))" << endl;
	return out;
};
Sentence operator+(const Sentence &leftSentence, const Word &rightWord) {
cout << "Entering function operator+(const Sentence &leftSentence, const Word &rightWord)" << endl;
	//CREATE a deep copy of Sentence FIRST
	Sentence copy;
	//if((*copy).w == NULL) cout << "(*copy).w == NULL";
	copy = leftSentence;
	//CREATE a deep copy of Word
	Word *lastWord = new Word("dummy");
	*lastWord = rightWord;
	Word *temp = copy.w;
	if(temp != NULL) {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = lastWord;
	} else {
		copy.w = lastWord;
	}
	//copy.show();
cout << "Leaving function Sentence::operator+(const Word &rightWord)" << endl;
	return copy;
	//Sentence s;
	//return s;
}; 
Sentence operator+(const Word& leftWord, const Sentence& rightSentence) {
	cout << "Entering function operator+(const Word& leftWord, const Sentence& rightSentence)" << endl;
	Sentence copy;
	copy = rightSentence;
	Word *newWord = new Word("dummy");
	*newWord = leftWord;
	Word *temp = copy.w;
	copy.w = newWord;
	newWord->next = temp;
	//cout << "Leaving function operator+(const Word& leftWord, const Sentence& rightSentence)" << endl;
	return copy;
};
Sentence operator+(const Word& leftWord, const Word& rightWord) {
cout << "Entering function operator+(const Word& leftWord, const Word& rightWord)" << endl;
cout << "Parameters: " << rightWord << endl;
	Sentence s;
	//allocate space on the heap for leftWord and rightWord copies
	Word* leftCopy = new Word("dummy1");
	*leftCopy = leftWord;
	Word* rightCopy = new Word("dummy2");
	*rightCopy = rightWord;
	leftCopy->next = rightCopy;
	s.w = leftCopy;
cout << "Leaving function operator+(const Word& leftWord, const Word& rightWord)" << endl;
	return s;
};