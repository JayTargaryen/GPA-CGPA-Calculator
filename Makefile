#CFALGS = -g -O0 -std=c++11

gpa: Users.o Account.o Career.o Semester.o Driver.o
	g++ -o gpa Users.o Account.o Career.o Semester.o Driver.o

Users.o: Users.cpp Users.hpp Account.hpp
	g++ -c Users.cpp

Account.o: Account.cpp Account.hpp Career.hpp
	g++ -c Account.cpp

Career.o: Career.cpp Career.hpp Semester.hpp
	g++ -std=c++11 -c Career.cpp

Semester.o: Semester.cpp Semester.hpp Course.hpp
	g++ -c Semester.cpp

Driver.o: Driver.cpp Users.hpp
	g++ -c Driver.cpp



clean:
	-rm gpa
	-rm Users.o Account.o Career.o Semester.o Driver.o
