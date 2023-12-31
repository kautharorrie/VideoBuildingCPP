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
//     ORRKAU001::FrameSequence frame; //create an instance of the FrameSequence class

//     if (argc == 1)
//     {
//         std::cout << "Error reading command line input for extracted frames." << std::endl;
//         return 0;
//     }

//     std::string filename = argv[1]; //get filename from the user
    
//     //// extract the file contents here using the filename


//     //looping through the user input
//     for (int i = 2; i < argc; i++ )
//     {
//         std::string g = argv[i];
//         std::cout << "Value for i: " <<  g << std::endl;
        
//         if (g == "-t")
//         {
//             //get the start and end points from user input
//             int xstart = std::stoi(argv[i+1]);
//             int ystart = std::stoi(argv[i+2]);
//             int xend = std::stoi(argv[i+3]);
//             int yend = std::stoi(argv[i+4]); 

//             frame.setStartAndEnd(xstart, ystart, xend, yend);
//             ////
//             //set the start and end points

//             std::cout << "start: " << xstart << "x end: " << xend << " y start: " <<  ystart << " y end: " <<  yend <<std::endl;
//             i = i+4;
//         }
//         else if (g == "-s")
//         {
//             int frameWidth = std::stoi(argv[i+1]);
//             int frameHeight = std::stoi(argv[i+2]);

//             frame.setWidthHeight(frameWidth, frameHeight);

//             ////extract frames here (because after -s tag there is no more input stuff)

//             std::cout << "Value for w: " << frameWidth << " value for h: " <<  frameHeight <<std::endl;
//             i = i+2;
//         }
//         else if (g == "-w")
//         {
//             std::string method = argv[i+1]; //gets the method the frames need to be extracted at
//             std::string fileName = argv[i+2];
//             std::cout << "Value for w: " << method << " value for h: " <<  fileName <<std::endl;
//             i = i+2;
//         }
        
//     }

//     for ( int i = 1; i <= 5; ++i )
//    {
//       std::ostringstream str;
//       str << "invert" << "-" << std::setw(4) << std::setfill('0') << i << ".pgm";
//       std::cout << str.str() << std::endl;
//       std::ofstream wf(str.str(), ios::out | ios::binary);
//         if(!wf) {
//             cout << "Cannot open file!" << endl;
//             return 1;
//         }
//         else{std::cout << "File opened." << std::endl;}
//    }

   



    ////////////// vector initialisation //////////////////

    // std::vector<unsigned char **> imageSequence; //stores all extracted image frames

    // std::cout << "vector size: " << imageSequence.size() << std::endl;

    // unsigned char** input = new unsigned char*[50];
    // for (int i = 0; i < 50; i++)
    // {
    //     input[i] = new unsigned char[50];
    // }

    // input[0][0] = 255;
    // std::cout << "input value: " << input[0] << std::endl;
    // imageSequence.push_back(input);
    // std::cout << "vector size: " << imageSequence.size() << std::endl;
    // std::cout << "vector input: " << imageSequence[0][0][0] << std::endl;
    

    // for (int j = 0; j < 50; j++)
    // {
    //     delete[] input[j];
    // }
    // delete[] input;

    ///////////////////////////testing 
    ///////////// testing 2D array
    // int wi = 1000;
    // int gi = 400;
    // unsigned char** input = new unsigned char*[wi];
    // for (int f = 0; f < wi; f++)
    // {
    //     input[f] = new unsigned char[wi];
    // }
    // int in = 0;
    // int out = 0;
    //     for (int g = 0; g < wi; g++){
    //         out = 0;
    //         for (int l = 0; l < wi; l++ )
    //         {

    //             input[in][out] = in+out;
                
    //             std::cout << "[" << in << "]" << "[" << out << "]" << " [" << g << "]" << "[" << l << "]"  << std::endl;
    //             out++;
    //         }
    //         in++;
    //     }

    // printing out the array
    //     for (int g = 5; g <gi; g++ )
    //     {
    //         for (int l = 5; l <gi; l++ )
    //         {
    //             std::cout << input[g][l] ;
                
    //         }
            
    //     }
    //     std::cout << "End.. " << std::endl;


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
    
    //stores all extracted image frames
    std::vector<unsigned char **> imageSequence; //stores all extracted image frames


    //open the image in binary format
    ifstream file("sloan_image.pgm", ios::in|ios::binary);
    if (file.is_open())
    {

        getline(file >> std::ws, fileType);
        std::cout << "---------------- type: " << fileType << std::endl;

        getline(file >> std::ws, comments);
        std::cout << "---------------- type: " << comments << std::endl;

        getline(file >> std::ws, widthheight);
        std::cout << "---------------- type: " << widthheight << std::endl;

        getline(file >> std::ws, greyscale);
        std::cout << "---------------- type: " << greyscale << std::endl;
        
        
        
        int g = widthheight.find(" ");
        std::string w = widthheight.substr(0, g);
        std::string h = widthheight.substr(g+1, widthheight.length());

        width = atoi(w.c_str());
        height = atoi(h.c_str());
        
        blocksize = width*height;
        //size = file.tellg();
        memblock = new char [blocksize];
        //file.seekg (0, ios::beg); //get the first position
        file.read (memblock, blocksize);
        file.close();

        cout << "the entire file content is in memory" << std::endl;


    }
    else {cout << "Unable to open file" << std::endl;}

    //create 2D vector to store values from file in [x][y] format
    unsigned char values[height][width]; 

    //create a 2D array for the overall image (the whole image)
    int index = 0;
    for (int a = 0; a < height; a++ )
    {
        for (int b = 0; b <width; b++ )
        {

            values[a][b] = memblock[index];
    
            index++; 
        }
    }

    //test values from user input, no user input yet
    int xstart = 0;
    int xend = 100;
    int ystart = 0; 
    int yend = 500;
    
    //variables for the frame width
    int frameWidth = 640;
    int frameHeight = 480; 
    
    //gradient used for file path
    int gradient = (yend-ystart)/(xend-xstart);

    float yy = ystart;
    
    mem = new char [frameWidth*frameHeight];
    std::cout << "gradient: " << gradient << std::endl;

    int wi = 1000;
    int gi = 400;
    
    for (int x = xstart+1  ; x < xend ; ++x)
    {   
        // x is already defined
        yy += gradient;
        //frame coordinate = the new (x, y)
        //std::cout << "check 1 " << std::endl;
        unsigned char** input = new unsigned char*[800];
        for (int f = 0; f < wi; f++)
        {
            input[f] = new unsigned char[800];
        }
        //std::cout << "check 2 " << std::endl;
        int y = round(yy);
        int xx = x;
        int in = 0;
        int out = 0;
        for (int g = 0; g < frameHeight; g++){
            out = 0;
            y = round(yy);
            for (int l = 0; l < frameWidth; l++)
            {
               
                //std::cout << "check 3" << " "<<x << " "<<y<< std::endl;
                input[g][l] = values[xx][y];
                
                out++;
                y++;
            }
            in++;
            xx++;
            //std::cout << "check 4 " << g << std::endl;
        }
        imageSequence.push_back(input);
        //std::cout << "Done vector populating " << std::endl;
    
    }
    std::cout << "check 5 " << std::endl;
    std::cout << "The vector size is: " << imageSequence.size() << std::endl;
    int k = 0;
    for (int i = 0; i < frameHeight; i++ )
        {
            for (int j = 0; j < frameWidth; j++ )
            {
                mem[k] = imageSequence[1][i][j];
                k++;
            }
    }
    



    std::cout << "The vector size is: " << imageSequence.size() << std::endl;
    ofstream File("image.pgm", ios::in|ios::binary);
    if (File.is_open())
    {
        //file.seekg (0, ios::beg); //get the first position
        File << fileType << std::endl;
        File << comments<< std::endl;;
        File << "640 480"<< std::endl;;
        File << greyscale << std::endl;;
        File.write(mem, blocksize);
        File.close();

    }
    else {cout << "Unable to open file" << std::endl;}

    




	std::cout << "Done." << std::endl;
    std::cout << fileType << std::endl;
    std::cout << comments << std::endl;
    std::cout << width << std::endl;
    std::cout << height << std::endl;
    std::cout << greyscale << std::endl;


    for(int i = 0; i < 50; i++)
    {
        std::cout << memblock[i] << " ";
    }
    delete[] memblock;
    delete[] mem;


    // // for (int j = 0; j < wi; j++)
    // // {
    // //     delete[] input[wi];
    // // }
    // // delete[] input;
    return 0;
}

