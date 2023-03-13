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
    ORRKAU001::FrameSequence frame; //create an instance of the FrameSequence class
    
    //test values from user input, no user input yet
    int xstart = 0; int ystart = 0; int xend = 0; int yend = 0;
    
    //variables for the frame width and frame height
    int frameWidth = 0; int frameHeight = 0; 

    //store the file contents like file type, comments, width and height
    std::string fileType = "";
    std::string comments = "";
    std::string widthheight = ""; 
    int filewidth = 0 ; int fileheight = 0; //width and height extracted from the file 
    std::string greyscale = "";
    int val = 0; int blocksize = 0; //size of the block of the file

    char * memblock = NULL; //char array to store the contents of the file 

    //if the user input is only 1 input tell the user that there was an error 
    if (argc == 1)
    {
        std::cout << "Error reading command line input for extracted frames." << std::endl;
        return 0;
    }

    //get the filename from the user input
    std::string userfilename = argv[1]; 
 
    //////////////////// file opening and manipulation //////////////

    //open the image in binary format and extract the contents
    ifstream file(userfilename, ios::in|ios::binary);
    if (file.is_open())
    {    
        getline(file >> std::ws, fileType);

        getline(file >> std::ws, comments);
    
        getline(file >> std::ws, widthheight);

        getline(file >> std::ws, greyscale);

        int g = widthheight.find(" ");
        std::string w = widthheight.substr(0, g);
        std::string h = widthheight.substr(g+1, widthheight.length());

        filewidth = atoi(w.c_str());
        fileheight = atoi(h.c_str());
        
        blocksize = filewidth*fileheight;
        
        memblock = new char [blocksize];
        
        file.read (memblock, blocksize);
        file.close();
    }

    else 
    {
        cout << "Unable to open file." << std::endl;
        return 0;
    }

    //create 2D vector to store values from file in [x][y] format
    unsigned char** values = NULL;
    values = new unsigned char*[fileheight];
        for (int f = 0; f < filewidth; f++)
        {
            values[f] = NULL;
            values[f] = new unsigned char[filewidth];
        }
    

    //Populate the 2D array with the pixel values to use later to extract the frames
    int index = 0;
    for (int a = 0; a < fileheight; a++ )
    {
        for (int b = 0; b < filewidth; b++ )
        {
            values[a][b] = memblock[index];
            index++; 
        }
    }

    // before extracting the frames delete the file contents from reading the file
    delete[] memblock; 

    //looping through the user input
    for (int i = 2; i < argc; i++ )
    {
        std::string g = argv[i];
        
        if (g == "-t")
        {
            //get the start and end points from user input
            xstart = std::stoi(argv[i+1]);
            ystart = std::stoi(argv[i+2]);
            xend = std::stoi(argv[i+3]);
            yend = std::stoi(argv[i+4]); 

            if (xstart > fileheight || ystart > filewidth || xend > fileheight || yend > filewidth)
            {
                std::cout << "Error. Cannot reach co-ordinates of negative values." << std::endl;
                return 1;
            }
            else if (xstart > 0 || ystart < 0 || xend < 0 || yend < 0)
            {
                std::cout << "Error. Cannot reach co-ordinates of negative values." << std::endl;
                return 1;
            }

            i = i+4; //skip to the next tag
        }
        else if (g == "-s")
        {
            frameWidth = std::stoi(argv[i+1]);
            frameHeight = std::stoi(argv[i+2]);

            //error checking 
            //check if the frame width and height is equal to zero (0)
            if (frameWidth == 0 && frameHeight == 0)
            {
                    std::cout << "Error. Cannot read frames of size zero (0, 0)." << std::endl;
                    return 1;

            }

            ////extract frames here (because after -s tag there is no more input stuff)
            
            frame.extractFrames(values, xstart, ystart, xend, yend, frameWidth, frameHeight);
            
            i = i+2; //skip to the next tag
        }
        else if (g == "-w")
        {
            std::string method = argv[i+1]; //gets the method the frames need to be extracted at
            std::string fileName = argv[i+2];
            
            if (method == "none")
            {
                
                frame.none(fileName, frameWidth, frameHeight, blocksize);
            }
            else if (method == "reverse")
            {
                frame.reverse(fileName, frameWidth, frameHeight, blocksize);
            }
            else if (method == "invert")
            {
                frame.invert(fileName, frameWidth, frameHeight, blocksize);
            }
            else if (method == "revinvert")
            {
                frame.revinvert(fileName, frameWidth, frameHeight, blocksize);
            }
            i = i+2;
        }
        
    }
    
    
    // delete the dynamically stored 2D array from the heap
    // for (int j = 0; j < fileheight; j++)
    // {
    //     delete[] values[j];
    // }
    // delete[] values;

    return 0;





}

