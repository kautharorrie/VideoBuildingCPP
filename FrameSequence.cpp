#include "FrameSequence.h"

//constructor implementation
ORRKAU001::FrameSequence::FrameSequence(void)
{
    // initialise public variables
    ORRKAU001::FrameSequence::fileType = "P5";
    ORRKAU001::FrameSequence::comments = "# extracted frame";
    ORRKAU001::FrameSequence::widthheight = "";
    ORRKAU001::FrameSequence::width = 0;
    ORRKAU001::FrameSequence::height = 0; 
    ORRKAU001::FrameSequence::greyscale = "255";
} 

//destructor implementation
ORRKAU001::FrameSequence::~FrameSequence()
{
    /**
     * loop through the image sequence vector to free up all the heap memory
     * delete all the pointers to a pointer array (2D dynamically allocated array)
     */
    for (int i = 0; i < ORRKAU001::FrameSequence::imageSequence.size() ; i++)
    {
        unsigned char** p = NULL; // set the array to NULL
        p = ORRKAU001::FrameSequence::imageSequence[i]; // get each 2D array from the vector
        // loop through the 2D array of pointers to delete the memory from the heap
        for (int j = 0; j < sizeof(p); j++)
        {
            delete[] p[j]; // delete the inner array of pointers ( the y values in [x][y])
        }
        delete[] p; // delete outer array of the matrix
    }
  
}


//output the frames out normally
//takes in the filename to where the frames are written to
//width and height of the frame and the block size of the binary block of memory to later use when writing to a file
void ORRKAU001::FrameSequence::none(std::string file, int width, int height, int blocksize)
{
    // array to pass into the write() method that contains the binary memory block of the extracted frame
    char * mem = NULL; // initialise pointer to zero  
    mem = new char [width*height]; // create an array of dynamically stored pointer array

    //converting the width + height to a string to pass into the filename 
    std::ostringstream str1;
    str1 << width << " " << height; // concatenate
    std::string wh = str1.str(); 

    // loop through vector to access all the 2D pointer arrays to get each and every frame
    for (int v = 0; v < ORRKAU001::FrameSequence::imageSequence.size(); v++)
    {
        
        // write the frame to the "mem" array to later pass into the write method
        int k = 0;
        for (int i = 0; i < height; i++ )
        {
            for (int j = 0; j < width; j++ )
            {
                mem[k] = ORRKAU001::FrameSequence::imageSequence[v][i][j]; // access each and every pixel value and pass to array
                k++;
            }
        }

    // formating the file name where the output frame data will be written to
    // format will be <filename>-<frame no.>.pgm e.g. sequence-00000.pgm
    // "setw()" and "setfill(0)" are the methods used to create the padding
    std::ostringstream str;
    str << file << "-" << std::setw(5) << std::setfill('0') << v << ".pgm";
    std::string filename = str.str();

        std::ofstream File(filename, std::ios::out |std::ios::binary);
        if (File.is_open())
        {
            // write the file messages to the file like file type, comments, width + height and greyscale values
            File << fileType << std::endl;
            File << comments<< std::endl;;
            File << wh << std::endl;;
            File << greyscale << std::endl;;

            // write the binary memory block to the file using the write() method and passing in the populated memory array
            File.write(mem, blocksize);
            File.close(); // close th file

        }
        // if the file cannot be opened, read the error message
        else 
        {
            std::cout << "Unable to open file" << std::endl;
        }
        
    }
    delete[] mem; // delete the dynamically allocated array 
}   

//outputs the frames out in reverse
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::reverse(std::string file, int width, int height, int blocksize)
{
   // array to pass into the write() method that contains the binary memory block of the extracted frame
    char * mem = NULL; // initialise pointer to zero  
    mem = new char [width*height]; // create an array of dynamically stored pointer array

    //converting the width + height to a string to pass into the filename 
    std::ostringstream str1;
    str1 << width << " " << height; // concatenate
    std::string wh = str1.str(); 

    // loop through vector to access all the 2D pointer arrays to get each and every frame
    // start loop at the end of vector array (last value) until the first value 99 -> 0
    int count = 0;
    for (int v = ORRKAU001::FrameSequence::imageSequence.size() -1; v >= 0; v--)
    {
        // write the frame to the "mem" array to later pass into the write method
        int k = 0;
        for (int i = 0; i < height; i++ )
        {
            for (int j = 0; j < width; j++ )
            {
                mem[k] = ORRKAU001::FrameSequence::imageSequence[v][i][j];
                k++;
            }
        }
    
        // formating the file name where the output frame data will be written to
        // format will be <filename>-<frame no.>.pgm e.g. sequence-00000.pgm
        // "setw()" and "setfill(0)" are the methods used to create the padding
        std::ostringstream str;
        str << file << "-" << std::setw(5) << std::setfill('0') << count << ".pgm";
        std::string filename = str.str();
        
        ///// START WRITING THE PIXEL VALUES TO THE OUTPUT FILE
        std::ofstream File(filename, std::ios::out |std::ios::binary);
        if (File.is_open())
        {
            // write the file messages to the file like file type, comments, width + height and greyscale values
            File << fileType << std::endl;
            File << comments<< std::endl;;
            File << wh << std::endl;;
            File << greyscale << std::endl;;

            // write the binary memory block to the file using the write() method and passing in the populated memory array
            File.write(mem, blocksize);
            File.close(); // close th file

        }
        // if the file cannot be opened, read the error message
        else 
        {
            std::cout << "Unable to open file" << std::endl;
        }
        
        count++;
    }
    delete[] mem; // delete the dynamically allocated array 

}


//invert the frames, for every pixel value p, the pixel value is written as "255 - p"
// e.g if the pixel value is 255 then the inverse will be 255-255 = 0 
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::invert(std::string file, int width, int height, int blocksize)
{
    // array to pass into the write() method that contains the binary memory block of the extracted frame
    char * mem = NULL; // initialise pointer to zero  
    mem = new char [width*height]; // create an array of dynamically stored pointer array

    //converting the width + height to a string to pass into the filename 
    std::ostringstream str1;
    str1 << width << " " << height; // concatenate
    std::string wh = str1.str(); 

    // loop through vector to access all the 2D pointer arrays to get each and every frame
    for (int v = 0; v < ORRKAU001::FrameSequence::imageSequence.size(); v++)
    {

        int k = 0;
        for (int i = 0; i < height; i++ )
        {
            for (int j = 0; j < width; j++ )
            {
                // get the opposite value of the pixel 255 - pixel value = inverse pixel value
                // e.g if the pixel value is 55 then the new value will be 255-55 = 200
                unsigned char val = 255-ORRKAU001::FrameSequence::imageSequence[v][i][j];

                //add new pixel value to the memory array to pass to a file later
                mem[k] = val;
                k++;
            }
        }
        
        // formating the file name where the output frame data will be written to
        // format will be <filename>-<frame no.>.pgm e.g. sequence-00000.pgm
        // "setw()" and "setfill(0)" are the methods used to create the padding
        std::ostringstream str;
        str << file << "-" << std::setw(5) << std::setfill('0') << v << ".pgm";
        std::string filename = str.str();

        std::ofstream File(filename, std::ios::out |std::ios::binary);
        if (File.is_open())
        {
            // write the file messages to the file like file type, comments, width + height and greyscale values
            File << fileType << std::endl;
            File << comments<< std::endl;;
            File << wh << std::endl;;
            File << greyscale << std::endl;;

            // write the binary memory block to the file using the write() method and passing in the populated memory array
            File.write(mem, blocksize);
            File.close(); // close th file

        }
        // if the file cannot be opened, read the error message
        else 
        {
            std::cout << "Unable to open file" << std::endl;
        }
        
    }
    delete[] mem; // delete the dynamically allocated array 
}

//reverse and invert the frames 
//combine the methods of reverse() and inverse
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::revinvert(std::string file, int width, int height, int blocksize)
{
    // array to pass into the write() method that contains the binary memory block of the extracted frame
    char * mem = NULL; // initialise pointer to zero  
    mem = new char [width*height]; // create an array of dynamically stored pointer array

    //converting the width + height to a string to pass into the filename 
    std::ostringstream str1;
    str1 << width << " " << height; // concatenate
    std::string wh = str1.str(); 
    
    // start loop at the end of vector array (last value) until the first value 99 -> 0
    int count = 0;
    for (int v = ORRKAU001::FrameSequence::imageSequence.size() -1; v >= 0; v--)
    {

        int k = 0;
        for (int i = 0; i < height; i++ )
        {
            for (int j = 0; j < width; j++ )
            {
                // get the opposite value of the pixel 255 - pixel value = inverse pixel value
                // e.g if the pixel value is 55 then the new value will be 255-55 = 200
                unsigned char val = 255-ORRKAU001::FrameSequence::imageSequence[v][i][j];

                //add new pixel value to the memory array to pass to a file later
                mem[k] = val;
                k++;
            }
        }
        
        // formating the file name where the output frame data will be written to
        // format will be <filename>-<frame no.>.pgm e.g. sequence-00000.pgm
        // "setw()" and "setfill(0)" are the methods used to create the padding
        std::ostringstream str;
        str << file << "-" << std::setw(5) << std::setfill('0') << count << ".pgm";
        std::string filename = str.str();
        
        ///// START WRITING THE PIXEL VALUES TO THE OUTPUT FILE
        std::ofstream File(filename, std::ios::out |std::ios::binary);
        if (File.is_open())
        {
            // write the file messages to the file like file type, comments, width + height and greyscale values
            File << fileType << std::endl;
            File << comments<< std::endl;;
            File << wh << std::endl;;
            File << greyscale << std::endl;;

            // write the binary memory block to the file using the write() method and passing in the populated memory array
            File.write(mem, blocksize);
            File.close(); // close th file

        }
        // if the file cannot be opened, read the error message
        else 
        {
            std::cout << "Unable to open file" << std::endl;
        }
        
        count++;
    }
    delete[] mem; // delete the dynamically allocated array 

}

/**
 * method to extract all the frames and store it in a vector
 * creates a dynamically 2D array to store array frames
 * finds the gradient necessary to follow a path from starting point (x1, y1) to the end point (x2, y2)
 * loops through the path to extract all frames
 */
void ORRKAU001::FrameSequence::extractFrames(unsigned char ** values, int x1, int y1, int x2, int y2, int frameWidth, int frameHeight )
{

    float gradient = (y2-y1)/(x2-x1); // find the gradient of the path to follow when extracting the frames
    
    float yy = y1; // sets the starting point of the path for the y value

    //check if the x start is more than x end 
    //error handling to allow for a backwards extraction of the frames
    if (x1 > x2)
    {
        // start at the x1 and decrease x as you loop through the path 
        for (int xx = x1+1  ; xx > x2 ; --xx)
        {   
            // x is already defined
            yy += gradient; 
            //frame coordinate = the new (x, yy)
            
            //create dynamically 2D array of pointers to store the extracted frames pixel values
            unsigned char** input = NULL; // initialise the array to NULL
            input = new unsigned char*[frameHeight]; // create an array of pointers to an array of points, where this is x in [x][y]
            // loop through 2D array to create new array pointers (pointers to pointers)
            // this array gets deleted inside the destructor method
            for (int f = 0; f < frameWidth; f++)
            {   
                input[f] = NULL;
                input[f] = new unsigned char[frameWidth]; // create inner array of points within 2D array where this is y in [x][y]
            }
            
            //round the value of y
            int y = round(yy);
            int x = xx; // x remains the same

            // extract the frame at the point (x, y) on the path specified of the user input heigth and width
            for (int g = 0; g < frameHeight ; g++){
                y = round(yy);
                //std::cout << "check x: " << xx << std::endl;
                for (int l = 0; l < frameWidth; l++)
                {
                    input[g][l] = values[x][y]; // add pixel to 2D frame array
                     y++;
                }
                x++;
            };
            // add the extracted frame inside the vector of the FrameSequence class
            ORRKAU001::FrameSequence::imageSequence.push_back(input);
    
        }
    }
    // if x1 is less than x2 increment x on the path of frame extraction
    else
    {
        // move 1 pixel at a time on the path specified while increasing x
        for (int xx = x1+1  ; xx < x2 ; ++xx)
        {   
            // x is already defined
            yy += gradient; 
            //frame coordinate = the new (x, yy)
            
            //create dynamically 2D array of pointers to store the extracted frames pixel values
            unsigned char** input = NULL; // initialise the array to NULL
            input = new unsigned char*[frameHeight]; // create an array of pointers to an array of points, where this is x in [x][y]
            // loop through 2D array to create new array pointers (pointers to pointers)
            // this array gets deleted inside the destructor method
            for (int f = 0; f < frameWidth; f++)
            {   
                input[f] = NULL;
                input[f] = new unsigned char[frameWidth]; // create inner array of points within 2D array where this is y in [x][y]
            }
            
            //round the value of y
            int y = round(yy);
            int x = xx; // x remains the same

            // extract the frame at the point (x, y) on the path specified of the user input heigth and width
            for (int g = 0; g < frameHeight ; g++){
                y = round(yy);
                //std::cout << "check x: " << xx << std::endl;
                for (int l = 0; l < frameWidth; l++)
                {
                    input[g][l] = values[x][y]; // add pixel to 2D frame array
                     y++;
                }
                x++;
            };
            // add the extracted frame inside the vector of the FrameSequence class
            ORRKAU001::FrameSequence::imageSequence.push_back(input);
        }
    }
}