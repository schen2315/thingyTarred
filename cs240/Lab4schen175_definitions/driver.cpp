#include <iostream>
#include "Paragraph.h"
#include "Sentence.h"
#include "Story.h"
#include "Word.h"

using namespace std;
int main() {
	Paragraph p;
	Sentence s;
	Story st;
	Word w;
	return 0;
}


//combine 2 stories -> new Story 					+ operators   const
	//create copies of the Story objects
		
		//delete the 2nd Story object

//copy a story -> new story  						copy constructor, assignment operator   const
//convert stories :					
	//all caps										a++ operator
	//all lowercase									a-- operator
	//appropriate capitalization					Story + 1 
	//Pig Latin										++a operator and --a operator
	//print 										<< extraction operator --> implement as a friend function const
	
		//	**the above can all be implemented the same way**
		//	**by having a story object call the same function/operator
		//	**on each of its paragraph objects who then call the same
		//	**function on each of its sentence objects and etc

	//get a copy of the first Paragraph 			first() const
		//basically only call the assignment on the first paragraph
			//call the assignment on each sentence when assigning Paragraphs
			//remember to EXPLICITLY allocate memory for the private node data member
			
		

	//get a copy of all but the first Paragraph 	rest()  const
		
		//implement this in the copy constructor?
		//or the assignment operator?
			
			//the copy constructor for Story will call the copy for each of its 
			//paragraph objects
		
			//copy constructor:
			//Story s;
			//Story newS = s;
			//OR Story news(s);

			//assignment
			//newS = s;

// implement a save() function in Story class
// for Story constructor: take a parameter "story.txt" to construct a new instance of Story

// for the destructor:
// in Story:
//		explicitly delete each Paragraph node
// in Paragraph:
//		explicitly delete each Sentence node
// in Sentence:
//		explicitly delete each Word node
// in Word:
//		use default constructor since Word will not have any pointer data members

// private data member node that points to Paragraph object
// private data member getSize
// a function that creates a DEEP copy to only the private node data member

// public getter for size

// the operators have access to private members
// implement a private setter for the ith node which gets called in the operator+ function
	//can this be done?

// in each word class implement a pigLatin data member


// should i implement a get pointer to "last" function?
		//NOOOO!
		//the pointer can be dereferenced and changed

//how a destructor works:
	//it can be called in one of 3 cases:
		//when a local variable goes out of scope
		//when you explicitly call delete on a pointer
		//for global objects when the program terminates
	//when a destructor is called on an object, the destructor for 
	//each of the object's NON-pointer data members gets called to delete those objects
	//for pointer types, you must explicitly delete them with the delete operator
	//inside the destructor
	//the destructor will delete the pointer but not what the pointer points to
