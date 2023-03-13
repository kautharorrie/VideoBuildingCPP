#include "FrameSequence.h"

//constructor implementation
ORRKAU001::FrameSequence::FrameSequence(void)
{

} 

//destructor implementation
ORRKAU001::FrameSequence::~FrameSequence()
{
    
    for (int i = 0; i < ORRKAU001::FrameSequence::imageSequence.size() ; i++)
    {
        unsigned char** p = NULL; 
        p = ORRKAU001::FrameSequence::imageSequence[i];
        for (int j = 0; j < sizeof(p); j++)
        {
            //p[j] = NULL;
            delete[] p[j];
        }
        delete[] p;
    }
    //std::cout << "Object destroyed" << std::endl;
  
}


//print the frames out normally
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::none(std::string file, int width, int height, int blocksize)
{
    
    char * mem = NULL;
    mem = new char [width*height];

    std::ostringstream str1;
    str1 << width << " " << height;
    std::string wh = str1.str(); //converting the width + height to a string to pass into the filename 

    for (int v = 0; v < ORRKAU001::FrameSequence::imageSequence.size(); v++)
    {

        int k = 0;
        for (int i = 0; i < height; i++ )
        {
            for (int j = 0; j < width; j++ )
            {
                mem[k] = ORRKAU001::FrameSequence::imageSequence[v][i][j];
                k++;
            }
        }
        
      std::ostringstream str;
      str << file << "-" << std::setw(4) << std::setfill('0') << v << ".pgm";
      std::string filename = str.str();
      
      //std::ofstream wf("data/" + filename, std::ios::out | std::ios::binary);
        std::fstream File(filename, std::ios::out |std::ios::binary);
        if (File.is_open())
        {
            //file.seekg (0, ios::beg); //get the first position
            File << fileType << std::endl;
            File << comments<< std::endl;;
            File << wh << std::endl;;
            File << greyscale << std::endl;;
            File.write(mem, blocksize);
            File.close();

        }
        else 
        {
            std::cout << "Unable to open file" << std::endl;
        }
        
    }
    delete[] mem;
}   

//print the frames out in reverse
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::reverse(std::string file, int width, int height, int blocksize)
{
    char * mem = NULL;
    mem = new char [width*height];

    std::ostringstream str1;
    str1 << width << " " << height;
    std::string wh = str1.str(); //converting the width + height to a string to pass into the filename 

    int count = 0;
    for (int v = ORRKAU001::FrameSequence::imageSequence.size() -1; v >= 0; v--)
    {

        int k = 0;
        for (int i = 0; i < height; i++ )
        {
            for (int j = 0; j < width; j++ )
            {
                mem[k] = ORRKAU001::FrameSequence::imageSequence[v][i][j];
                k++;
            }
        }
        
      std::ostringstream str;
      str << file << "-" << std::setw(4) << std::setfill('0') << count << ".pgm";
      std::string filename = str.str();
      
      //std::ofstream wf("data/" + filename, std::ios::out | std::ios::binary);
        std::fstream File(filename, std::ios::out |std::ios::binary);
        if (File.is_open())
        {
            //file.seekg (0, ios::beg); //get the first position
            File << fileType << std::endl;
            File << comments<< std::endl;;
            File << wh << std::endl;;
            File << greyscale << std::endl;;
            File.write(mem, blocksize);
            File.close();

        }
    else {std::cout << "Unable to open file" << std::endl;}
    count++;
    }
    delete[] mem;

}


//invert the frames 
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::invert(std::string file, int width, int height, int blocksize)
{
    char * mem = NULL;
    mem = new char [width*height];
    
    std::ostringstream str1;
    str1 << width << " " << height;
    std::string wh = str1.str(); //converting the width + height to a string to pass into the filename 
    
    for (int v = 0; v < ORRKAU001::FrameSequence::imageSequence.size(); v++)
    {

        int k = 0;
        for (int i = 0; i < height; i++ )
        {
            for (int j = 0; j < width; j++ )
            {
                unsigned char val = 255-ORRKAU001::FrameSequence::imageSequence[v][i][j];
                
                mem[k] = val;
                k++;
            }
        }
        
      std::ostringstream str;
      str << file << "-" << std::setw(4) << std::setfill('0') << v << ".pgm";
      std::string filename = str.str();
      
      //std::ofstream wf("data/" + filename, std::ios::out | std::ios::binary);
        std::fstream File(filename, std::ios::out |std::ios::binary);
        if (File.is_open())
        {
            //file.seekg (0, ios::beg); //get the first position
            File << fileType << std::endl;
            File << comments<< std::endl;;
            File << wh << std::endl;;
            File << greyscale << std::endl;;
            File.write(mem, blocksize);
            File.close();

        }
        else 
        {
            std::cout << "Unable to open file" << std::endl;
        }
        
    }
    delete[] mem;
}

//reverse and invert the frames
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::revinvert(std::string file, int width, int height, int blocksize)
{
    char * mem = NULL;
    mem = new char [width*height];

    std::ostringstream str1;
    str1 << width << " " << height;
    std::string wh = str1.str(); //converting the width + height to a string to pass into the filename 
    
    int count = 0;
    for (int v = ORRKAU001::FrameSequence::imageSequence.size() -1; v >= 0; v--)
    {

        int k = 0;
        for (int i = 0; i < height; i++ )
        {
            for (int j = 0; j < width; j++ )
            {
                unsigned char val = 255-ORRKAU001::FrameSequence::imageSequence[v][i][j];
                
                mem[k] = val;
                k++;
            }
        }
        
      std::ostringstream str;
      str << file << "-" << std::setw(4) << std::setfill('0') << count << ".pgm";
      std::string filename = str.str();
      
      //std::ofstream wf("data/" + filename, std::ios::out | std::ios::binary);
        std::fstream File(filename, std::ios::out |std::ios::binary);
        if (File.is_open())
        {
            //file.seekg (0, ios::beg); //get the first position
            File << fileType << std::endl;
            File << comments<< std::endl;;
            File << wh << std::endl;;
            File << greyscale << std::endl;;
            File.write(mem, blocksize);
            File.close();

        }
        else 
        {
            std::cout << "Unable to open file" << std::endl;
        }
        count++;
        
    }
    delete[] mem;
}

void ORRKAU001::FrameSequence::extractFrames(unsigned char ** values, int x1, int y1, int x2, int y2, int frameWidth, int frameHeight )
{

    float gradient = (y2-y1)/(x2-x1);
    
    float yy = y1;
    
    int wi = 10000;
    int gi = 400;
    
    for (int xx = x1+1  ; xx < x2 ; ++xx)
    {   
        // x is already defined
        yy += gradient; 
        //frame coordinate = the new (x, yy)
        
        unsigned char** input = NULL;
        input = new unsigned char*[frameHeight];
        for (int f = 0; f < frameWidth; f++)
        {   
            input[f] = NULL;
            input[f] = new unsigned char[frameWidth];
        }
        
        int y = round(yy);
        int x = xx;
    
        for (int g = 0; g < frameHeight ; g++){
            y = round(yy);
            //std::cout << "check x: " << xx << std::endl;
            for (int l = 0; l < frameWidth; l++)
            {
                //std::cout << "( " << x  << " "<< y << " )" << std::endl;
                input[g][l] = values[x][y];
                //std::cout <<  x << " " << y << std::endl;
                y++;

            }
            x++;
        }
        ORRKAU001::FrameSequence::imageSequence.push_back(input);
    }

}