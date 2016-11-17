#

all: link

#
#
link:	compile
	g++ Voter.o VoterDatabase.o main.o -o Voter
#
#
compile:	
	g++ -c Voter.cpp VoterDatabase.cpp main.cpp -std=c++11

#
#
clean:
	rm -f *.o *~ Voter output.txt
