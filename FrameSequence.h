/**
 * .h file 
 * Assignment 2
 * CSC3022F 
 * Author: Kauthar Orrie
 *
 */
 
#ifndef FRAMESEQUENCE_H
#define FRAMESEQUENCE_H

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

//declaring my namespace with my student number
namespace ORRKAU001
{
    //create FrameSequence class
    class FrameSequence
    {
        //public functions
        public:
            // public variables to store the filename, comments and greyscale of the file details
            std::string fileType;
            std::string comments;
            std::string widthheight;
            int width; int height;
            std::string greyscale;

            //variables to store the start and end coordinates and the width and height of the extracted frame
            int x1, y1, x2, y2, w, h;

            std::vector<unsigned char **> imageSequence; //stores all extracted image frames

            //non parametised constructor declaration
            FrameSequence(void);

            //destructor declaration
            ~FrameSequence();

            /// PUBLIC FUNCTIONS //
            // NOTE:: all method implementation and their explanations are found inside the .cpp file (FrameSequence.cpp) //
        
            void none(std::string filename, int width, int height, int blocksize); //print out frames as is

            void reverse(std::string filename, int width, int height, int blocksize); //print frames from first to last

            void invert(std::string file, int width, int height, int blocksize);  //print all v characters to 255-v
            
            void revinvert(std::string file, int width, int height, int blocksize);  //print in reverse and invert

            void addToVector(unsigned char** frame);

            void setStartAndEnd(int x1, int y1, int x2, int y2);
            
            void setWidthHeight(int w, int h);

            void extractFrames(unsigned char ** values, int x1, int y1, int x2, int y2, int frameWidth, int frameHeight);

    };
    
}
    

#endif