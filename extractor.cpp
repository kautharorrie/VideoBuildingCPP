//includes 

#include "FrameSequence.h"

/*
* Main function for the program
* Extracts pixels from a file of format .pgm   
* Creates an instance of the FrameSequence class, to use the methods to extract frames, write to specific file.
* Frames are extracted from a starting point (x1, y1) and end point (x2, y2)
* Implements and handles the user input and calls appropriate methods according to user input
*/
int main(int argc, char *argv[])
{
    ORRKAU001::FrameSequence frame; //create an instance of the FrameSequence class 
    
    //variables to store the user input values of x1, y1, x2, y2
    int xstart = 0; int ystart = 0; int xend = 0; int yend = 0;
    
    //variables for the frame width and frame height to be extracted
    int frameWidth = 0; int frameHeight = 0; 

    //store the file contents like file type, comments, width and height, greyscale value
    std::string fileType = "";
    std::string comments = "";
    std::string widthheight = ""; 
    int filewidth = 0 ; int fileheight = 0; //width and height extracted from the file 
    std::string greyscale = "";
    int blocksize = 0; //size of the block of the file

    //char array to store the contents of the file, after using the read() method, 
    // the returned array is stored here     
    char * memblock = NULL; //initialise the array to NULL 

    //if the user input is only 1 input tell the user that there was an error because the program needs more input 
    if (argc == 1)
    {
        std::cout << "Error reading command line input for extracted frames." << std::endl;
        return 0; // close the program
    }

    // the second element in the input array is the filename, store the value in this variable
    std::string userfilename = argv[1]; 
 
    //////////////////// file opening and manipulation //////////////
    
    //open the image in binary format and extract the contents
    std::ifstream file(userfilename, std::ios::in|std::ios::binary);
    // if the file successfully opens 
    // get the file type, comments, width and height and greyscale value
    if (file.is_open())
    {    

        // read all the values before the binary block of pixels 
        std::getline(file >> std::ws, fileType); // get the file type e.g "P5"
        std::getline(file >> std::ws, comments); // get the file comments e.g "# comment"
        std::getline(file >> std::ws, widthheight); // get the file width and height e.g "<width> <height>"
        std::getline(file >> std::ws, greyscale); // get the file greyscale value of "255"

        // split the string widthheight by " " to get the values of the file width and height
        int g = widthheight.find(" ");
        std::string w = widthheight.substr(0, g);
        std::string h = widthheight.substr(g+1, widthheight.length());

        // cast the width and height values to an int value to use later
        filewidth = atoi(w.c_str()); fileheight = atoi(h.c_str());
        
        blocksize = filewidth*fileheight; // get the whole binary block size

        // create a dynamically allocated array of pointers to store the values in the binary block of the file
        memblock = new char [blocksize]; 
        
        // read the binary block values and pass it into the array created above
        file.read (memblock, blocksize);
        file.close(); // close the file after reading the file
    }

    // if the file doesn't successfully open, move into this else scope
    // print out an error message and end the program
    else 
    {
        std::cout << "Unable to open file." << std::endl;
        return 0;
    }

    //create 2D array to store values from file in [x][y] format (an array of pointers)
    unsigned char** values = NULL; // initialise 2D array of pointers to NULL
    values = new unsigned char*[fileheight]; // dynamically allocate array of pointers 
    for (int f = 0; f < filewidth; f++)
    {
        values[f] = NULL; //initial array
        values[f] = new unsigned char[filewidth]; //create an array of array pointers 
    }
    

    //Populate the 2D array with the pixel values to use later to extract the frames
    int index = 0; // count value to keep track of where we are inside the memblock array
    for (int a = 0; a < fileheight; a++ )
    {
        for (int b = 0; b < filewidth; b++ )
        {
            values[a][b] = memblock[index]; // assign the appropriate value of the pixel to the right [x][y] position
            index++; 
        }
    }

    // before extracting the frames delete the file contents stored inside the memblock array
    delete[] memblock; 

    ///////////// USER INPUT ////////////////////

    /**
     * loop through the argv[] array to get user input
     * if the user input is -t, save the values for x1, y1, x2, y2: next 4 values of the user input, increment by 4
     * if the user input is -s, save the values of the height and width of the frame: the next 2 values of user input, increment by 2
     * extract the frames once -s tag is read
     * if the user input is -w, save the values of the filename and method of printing out the frames: the next 2 values of user input, increment by 2
     * loop until all the user input is read
     */
    for (int i = 2; i < argc; i++ )
    {
        std::string g = argv[i]; // save the value of the current user input
        
        // if the tag is -t 
        if (g == "-t")
        {
            // get the start and end points from user input by getting the next 4 values of the user input
            // convert the string values to an int value
            xstart = std::stoi(argv[i+1]); // x1
            ystart = std::stoi(argv[i+2]); // y1
            xend = std::stoi(argv[i+3]); // x2
            yend = std::stoi(argv[i+4]); // y2

            // error handling to ensure that the start and end coordinates are not OUT OF BOUNDS
            if (xstart > fileheight || ystart > filewidth || xend > fileheight || yend > filewidth)
            {
                std::cout << "Error. Cannot reach co-ordinates. (OUT OF BOUNDS)" << std::endl;
                return 1;
            }
            // error handling to ensure that the start and end coordinates are not NEGATIVE values
            else if (xstart < 0 || ystart < 0 || xend < 0 || yend < 0)
            {
                std::cout << "Error. Cannot reach co-ordinates of negative values." << std::endl;
                return 1;
            }
            
            i = i+4; //skip to the next tag
        }

        // if the tag is -s
        else if (g == "-s")
        {
            // get the frame width and height from user input by getting the next 2 values of the user input
            // convert the string values to an int value
            frameWidth = std::stoi(argv[i+1]);
            frameHeight = std::stoi(argv[i+2]);

            //error handling
            //check if the frame width and height is equal to zero (0)
            if (frameWidth == 0 && frameHeight == 0)
            {
                    std::cout << "Error. Cannot read frames of size zero (0, 0)." << std::endl;
                    return 1;
            }

            // once the -s tag has been read, call the method within the FrameSequence class to extract frames and add to a vector 
            frame.extractFrames(values, xstart, ystart, xend, yend, frameWidth, frameHeight);
            
            i = i+2; //skip to the next tag
        }

        // if the tag is -w
        else if (g == "-w")
        {
            // store the user method to print out the frames
            // store the user specific file name
            // the next 2 values of the user input array argv
            std::string method = argv[i+1]; //gets the method the frames need to be extracted at
            std::string fileName = argv[i+2];
            
            // if the user choosing to not change the output of the frames
            if (method == "none")
            {
                // call the none() method to output the files normally
                frame.none(fileName, frameWidth, frameHeight, blocksize);
            }
            // if the user is choosing to output the files in reverse
            else if (method == "reverse")
            {
                // call the reverse() method to output frames in reverse
                frame.reverse(fileName, frameWidth, frameHeight, blocksize);
            }
            // if the user is choosing to output the files inversely
            else if (method == "invert")
            {
                // call the invert() method to output frames inversely
                frame.invert(fileName, frameWidth, frameHeight, blocksize);
            }
            // if the user is choosing to output the files 
            else if (method == "revinvert")
            {
                // call the revinvert() method to output frames in reverse and invert the pixels
                frame.revinvert(fileName, frameWidth, frameHeight, blocksize);
            }
            i = i+2; //skip to the next tag
        }
        
    }
    
    return 0;





}

