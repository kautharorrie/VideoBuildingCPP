#include "FrameSequence.h"

ORRKAU001::FrameSequence::FrameSequence(void){}    

ORRKAU001::FrameSequence::~FrameSequence(){}

void ORRKAU001::FrameSequence::helloworld()
{
    std::cout << "Hello World!" << std::endl;
}

void ORRKAU001::FrameSequence::none(void)
{
    std::cout << "none" << std::endl;
}   

void ORRKAU001::FrameSequence::reverse(void)
{
    std::cout << "reverse" << std::endl;
}

void ORRKAU001::FrameSequence::invert(void)
{
    std::cout << "invert" << std::endl;
}

void ORRKAU001::FrameSequence::revinvert(void)
{
    std::cout << "revinvert" << std::endl;
}

void ORRKAU001::FrameSequence::addToVector(unsigned char** frame)
{
    std::cout << "revinvert" << std::endl;
}

// set the values for x1, x2, y1, y2
void ORRKAU001::FrameSequence::setStartAndEnd(std::string x1, std::string y1, std::string x2, std::string y2)
{
    ORRKAU001::FrameSequence::x1 = x1;
    ORRKAU001::FrameSequence::y1 = y1;
    ORRKAU001::FrameSequence::x2 = x2;
    ORRKAU001::FrameSequence::y2 = y2;
}