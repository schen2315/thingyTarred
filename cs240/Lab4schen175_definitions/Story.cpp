#include "Story.h"
#include "Paragraph.h"
#include <iostream>
Story::Story() {

}
Story::Story(string file) {

}
void Story::show() {

};
void Story::save(string file) {

};
bool Story::empty() const {
	return true;
};
int Story::sizeOf() const {
	return 0;
};
Story::~Story() {
	
}
Story &Story::operator=(const Story &rightStory) {
	return (*this);
};
Story Story::operator+(const Story &rightStory) const {
	Story s;
	return s;
};
Story Story::operator+(const Paragraph &para) const {
	Story s;
	return s;
};
//postfix
Story &Story::operator++(int num) {
	return (*this);
};
Story &Story::operator--(int num) {
	return (*this);
};
Story &Story::operator+(int num) {
	return (*this);
};
//prefix
Story &Story::operator++() {
	return (*this);
};
Story &Story::operator--() {
	return (*this);
};

Paragraph Story::first() const {
	Paragraph p;
	return p;
};
Story Story::rest() const {
	Story s;
	return s;
};
ostream& operator<<(ostream &out, const Story &s) {
	return out;
};
Story operator+(const Paragraph &leftParagraph, const Story &rightStory) {
	Story s;
	return s;
};
