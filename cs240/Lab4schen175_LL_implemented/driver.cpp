#include <iostream>
//#include "Paragraph.h"
//#include "Sentence.h"
#include "Story.h"
//#include "Word.h"
Word testCopyConstructor() {
	Word s("string");
	return s;
}
// Word testCopyConstructor2() {
// 	Word* s = new Word("string2");	//YOU NEED TO EXPLICITLY DELETE THIS
// 	return *s;		//copy constructor should get called
// }
void testDeepCopy(Sentence &s) {
std::cout << "Entering testDeepCopy(Sentence &s)" << std::endl;
	Word w0("Watch");
	Word w1("Ko");
	Word w2("No");
	Word w3("Suba");
	Word w4("Ru");
	Sentence k = w1 + w2;
	s = k + w3;
	s = s + w4;
	s = w0 + s;
	s.show();
	//Sentence s2(w1 + w2);	
	//Sentence s3(s + w3);
	//s = s + w3;		//error -> seg fault
	//Sentence w;
	//w = s;
std::cout << "Leaving testDeepCopy(Sentence &s)" << std::endl;
}

//dummy test functions
void dummyTest() {
	//test constructor
	Word* w1 = new Word("Hi");
	w1->show();
	cout << endl;
	//test assignment operator
	//why do the output statements in the assignment operator not print?
	Word* w2 = new Word("this");
	//*w2 = *w1;
	w2->show();
	cout << endl;

	Word* w3 = new Word("is");
	//*w3 = *w1;
	w3->show();
	cout << endl;

	Word* w4 = new Word("a");
	//*w4 = *w1;
	w4->show();
	cout << endl;

	Word* w5 = new Word("coherrent");
	//*w5 = *w1;
	w5->show();
	cout << endl;

	Word* w6 = new Word("sentence");
	//*w6 = *w1;
	w6->show();
	cout << endl;


	// Word* w7 = new Word("dummy");
	// *w7 = *w6;
	// w7->show();

	//*w6 = *w1;
	Sentence s = *w1 + *w2+ *w3 + *w4 + *w5 + *w6;
	cout << endl;
	delete w1;
	delete w2;
	delete w3;
	delete w4;
	delete w5;
	delete w6;
	// s.show();
	// cout << endl;
	// Sentence w;
	// //w = s;
	// testDeepCopy(w);
	// cout << endl;
	// w.show();
	// cout << endl;
	// Paragraph p = s + w;
	// p.show();
	// cout << endl;
	// Paragraph g;
	// g = p;
	// g.show();
	// cout << endl;
	// Sentence s3 = *(new Word("Hello")) + *(new Word("World"));
	// Paragraph l = g + s3;
	// l.show();
	// cout << endl;
	// g.show();
	// cout << endl;
	// Paragraph m = s3 + l;
	// m.show();
	// cout << endl;
	//w.show();
	//delete s;	//can't delete s because s resides on the stack
	//w.show();
	//s.show(); 
	
	//change the words of s
	//check that the original words have not been changed
}

using namespace std;
int main() {
	dummyTest();
	//Word g("string");
	//Word w(g);	 
	//w.show();
	//Word s("");
	//s = testCopyConstructor2();
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
