ProcessSimulator: main.o  Executive.o Process.o Method.o
	g++ -g -std=c++11 -Wall main.o Executive.o Process.o Method.o -o ProcessSimulator

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -Wall -c main.cpp

Process.o: Process.cpp Stack.h Stack.cpp StackInterface.h LinkedList.cpp LinkedList.h ListInterface.h Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Process.cpp

Executive.o: Executive.cpp Executive.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

Method.o: Method.cpp Method.h
		g++ -g -std=c++11 -Wall -c Method.cpp

clean:
	rm *.o ProcessSimulator
