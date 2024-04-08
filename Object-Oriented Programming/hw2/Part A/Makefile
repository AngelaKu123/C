main.out: Line.o Line2.o Circle.o Circle2.o main.o
	g++ Line.o Line2.o Circle.o Circle2.o main.o -o main.out -Wall

Line.o: Line.cpp Line.h
	g++ -c Line.cpp -o Line.o -Wall

Line2.o: Line2.cpp Line2.h
	g++ -std=c++17 -c Line2.cpp -o Line2.o -Wall
	
Circle.o: Circle.cpp Circle.h
	g++ -c Circle.cpp -o Circle.o -Wall
	
Circle2.o: Circle2.cpp Circle2.h
	g++ -std=c++11 -c Circle2.cpp -o Circle2.o -Wall

main.o: main.cpp Line.h Line2.h Circle.h Circle2.h
	g++ -c main.cpp -o main.o -Wall

clean:
	rm -f *.o main.out
