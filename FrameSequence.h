/**
 * .h file 
 * Simple Tag Enumeration Assignment 1 
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
#include <cstdlib>

//declaring my namespace with my student number
namespace ORRKAU001
{

    //create FrameSequence class
    class FrameSequence
    {
        //public functions
        public:
                
            std::string fileType = "P5";
            std::string comments = "# extracted frame";
            std::string widthheight = "";
            int width = 0 ;
            int height = 0; 
            std::string greyscale = "255";

            std::string x1, y1, x2, y2;

            //non parametised constructor
            FrameSequence(void);

            //destructor
            ~FrameSequence();

            std::vector<unsigned char **> imageSequence; //stores all extracted image frames

            /// FUNCTIONS //
            void helloworld(); //tester functions

            void none(void); //print out frames as is

            void reverse(void); //print frames from first to last

            void invert(void); //print all v characters to 255-v
            
            void revinvert(void); //print in reverse and invert

            void addToVector(unsigned char** frame);

            void setStartAndEnd(std::string x1, std::string y1, std::string x2, std::string y2);



    };
    
}
    

#endif