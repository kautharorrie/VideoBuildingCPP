//includes 
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>


#include "FrameSequence.h"

using namespace std;
int main(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;
    ORRKAU001::FrameSequence frame; //create an instance of the FrameSequence class
    
    //test values from user input, no user input yet
    int xstart = 0;
    int xend = 100;
    int ystart = 0; 
    int yend = 500;
    
    //variables for the frame width
    int frameWidth = 640;
    int frameHeight = 480; 

    frame.setStartAndEnd(0, 0, 100, 500);

}

