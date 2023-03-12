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
    int ystart = 0;
    int xend = 100;
    int yend = 100;
    
    //variables for the frame width
    int frameWidth = 640;
    int frameHeight = 480; 

    frame.setStartAndEnd(xstart, ystart, xend, yend);
    frame.setWidthHeight(frameWidth, frameHeight);


    //////////////////// file opening and manipulation //////////////
    std::cout << "The file is being read..." << std::endl;
	std::string f;
    std::string filename = "sloan_image.pgm";

    //get file comments
    std::string fileType = "";
    std::string comments = "";
    std::string blank = "";
    std::string widthheight = "";
    int width = 0 ;
    int height = 0; 
    std::string greyscale = "";
    int val = 0;
    int blocksize = 0;

    streampos size;
    char * memblock;

    char * mem;

    //open the image in binary format
    ifstream file("sloan_image.pgm", ios::in|ios::binary);
    if (file.is_open())
    {    
        getline(file >> std::ws, fileType);

        getline(file >> std::ws, comments);
    
        getline(file >> std::ws, widthheight);

        getline(file >> std::ws, greyscale);

        int g = widthheight.find(" ");
        std::string w = widthheight.substr(0, g);
        std::string h = widthheight.substr(g+1, widthheight.length());

        width = atoi(w.c_str());
        height = atoi(h.c_str());
        
        blocksize = width*height;
        
        memblock = new char [blocksize];
        
        file.read (memblock, blocksize);
        file.close();
    }

    else 
    {
        cout << "Unable to open file." << std::endl;
        return 0;
    }

    std::cout << width << std::endl;

    unsigned char** values = new unsigned char*[height];
        for (int f = 0; f < width; f++)
        {
            values[f] = new unsigned char[width];
        }

    //create 2D vector to store values from file in [x][y] format
    //unsigned char values[height][width]; 

    //create a 2D array for the overall image (the whole image)
    int index = 0;
    for (int a = 0; a < height; a++ )
    {
        for (int b = 0; b < width; b++ )
        {
            values[a][b] = memblock[index];
            index++; 
        }
    }


    delete[] memblock; //delete the file contents extracted from reading the file 

    frame.extractFrames(values, xstart, ystart, xend, yend, frameWidth, frameWidth);
    frame.none("none", frameWidth, frameHeight, blocksize);
    //frame.reverse("reverse", frameWidth, frameHeight, blocksize);
    //frame.invert("invert", frameWidth, frameHeight, blocksize);
    //frame.revinvert("revinvert", frameWidth, frameHeight, blocksize);

    for (int j = 0; j < width; j++)
    {
        delete[] values[width];
    }
    delete[] values;

    


    return 0;





}

