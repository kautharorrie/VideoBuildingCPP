extractor: main.o FrameSequence.o
	g++ main.o FrameSequence.o -o extractor -std=c++20
main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++20
FrameSequence.o: FrameSequence.cpp
	g++ -c FrameSequence.cpp -o FrameSequence.o -std=c++20
clean: 
	rm *.o extractor
