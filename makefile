driver.exe: main.o
	g++ main.o -o driver.exe -std=c++20
main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++20
clean: 
	rm *.o driver.exe
