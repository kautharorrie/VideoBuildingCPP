#include "FrameSequence.h"

ORRKAU001::FrameSequence::FrameSequence(void){}    

ORRKAU001::FrameSequence::~FrameSequence(){}

void ORRKAU001::FrameSequence::helloworld()
{
    std::cout << "Hello World!" << std::endl;
}

//print the frames out normally
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::none(std::string filename)
{
    std::cout << "none" << std::endl;
}   

//print the frames out in reverse
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::reverse(std::string filename)
{
    std::cout << "reverse" << std::endl;
}

//invert the frames 
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::invert(std::string filename)
{
    std::cout << "invert" << std::endl;
}

//reverse and invert the frames
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::revinvert(std::string filename)
{
    std::cout << "revinvert" << std::endl;
}

//add a frame to the vector
void ORRKAU001::FrameSequence::addToVector(unsigned char** frame)
{
    std::cout << "add to vector" << std::endl;
    ORRKAU001::FrameSequence::imageSequence.push_back(frame);
}

// set the values for x1, x2, y1, y2
void ORRKAU001::FrameSequence::setStartAndEnd(int x1, int y1, int x2, int y2)
{
    ORRKAU001::FrameSequence::x1 = x1;
    ORRKAU001::FrameSequence::y1 = y1;
    ORRKAU001::FrameSequence::x2 = x2;
    ORRKAU001::FrameSequence::y2 = y2;
}

void ORRKAU001::FrameSequence::setWidthHeight(int width, int height)
{
    ORRKAU001::FrameSequence::w = width;
    ORRKAU001::FrameSequence::h = height;
}