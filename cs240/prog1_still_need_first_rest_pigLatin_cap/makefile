# C++11 support
FLAGS = -g -Wall -std=c++11

all: driver

sampleDriver: Story.o Paragraph.o Sentence.o Word.o sampleDriver.o
	g++ $(FLAGS) Story.o Paragraph.o Sentence.o Word.o sampleDriver.o -o sampleDriver

sampleDriver.o:	sampleDriver.cpp
	g++ $(FLAGS) -c sampleDriver.cpp -o sampleDriver.o

driver:	Story.o Paragraph.o Sentence.o Word.o driver.o
	g++ $(FLAGS) Story.o Paragraph.o Sentence.o Word.o driver.o -o driver

driver.o:	driver.cpp
	g++ $(FLAGS) -c driver.cpp -o driver.o
	
Paragraph.o:	Paragraph.cpp Paragraph.h
	g++ $(FLAGS) -c Paragraph.cpp -o Paragraph.o

Sentence.o:	Sentence.cpp Sentence.h
	g++ $(FLAGS) -c Sentence.cpp -o Sentence.o

Story.o:	Story.cpp Story.h
	g++ $(FLAGS) -c Story.cpp -o Story.o

Word.o:	Word.cpp Word.h
	g++ $(FLAGS) -c Word.cpp -o Word.o


clean:
	rm -f *.o driver sampleDriver