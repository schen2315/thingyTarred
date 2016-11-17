#ifndef STORY_H
#define STORY_H

#include <iostream>
#include "Paragraph.h"

using namespace std;


//Story is a specific implementation of a linked list
class Story {
public:
	Story();
	Story(const Story &s);
	Story(string file);	
	void show();
	void save(string file);

	bool empty() const;
	int sizeOf() const;
	~Story();
	//the copy constructor will create a shallow copy which is what we want from it
	//the assignment operator will create deep copies 

	Story &operator=(const Story &rightStory);	//creates a deep copy
	Story operator+(const Story &rightStory) const;	//calls the assignment operator
	Story operator+(const Paragraph &rightParagraph) const; 	
	Story &operator++(int num);
	Story &operator--(int num);
	Story &operator+(int num);
	Story &operator++();
	Story &operator--();

	Paragraph first() const;
	Story rest() const;

	friend ostream& operator<<(ostream &out, const Story &s);
	friend Story operator+(const Paragraph &leftParagraph, const Story &rightStory);
	//this friend function does not need to access any private members of Paragraph
private:	
	int size;
	Paragraph* p; 

};

#endif