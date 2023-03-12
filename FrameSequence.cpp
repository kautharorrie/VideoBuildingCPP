#include "FrameSequence.h"

//constructor implementation
ORRKAU001::FrameSequence::FrameSequence(void)
{

} 

//destructor implementation
ORRKAU001::FrameSequence::~FrameSequence()
{
  
}

void ORRKAU001::FrameSequence::helloworld()
{
    std::cout << "Hello World!" << std::endl;
}

//print the frames out normally
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::none(std::string file, int width, int height, int blocksize)
{
    std::cout << "none" << std::endl;
    char * mem;
    mem = new char [width*height];

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
        std::fstream File("none/" + filename, std::ios::out |std::ios::binary);
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
        else 
        {
            std::cout << "Unable to open file" << std::endl;
        }
        
    }

}   

//print the frames out in reverse
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::reverse(std::string file, int width, int height, int blocksize)
{
    std::cout << "reverse" << std::endl;

    std::cout << "none" << std::endl;
    char * mem;
    mem = new char [width*height];

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
        std::fstream File("reverse/" + filename, std::ios::out |std::ios::binary);
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
    else {std::cout << "Unable to open file" << std::endl;}
    count++;
    }

}


//invert the frames 
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::invert(std::string file, int width, int height, int blocksize)
{
    std::cout << "invert" << std::endl;
    std::cout << "none" << std::endl;
    char * mem;
    mem = new char [width*height];
    
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
        std::fstream File("invert/" + filename, std::ios::out |std::ios::binary);
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
        else 
        {
            std::cout << "Unable to open file" << std::endl;
        }
        
    }
}

//reverse and invert the frames
//takes in the filename to where the frames are written to
void ORRKAU001::FrameSequence::revinvert(std::string file, int width, int height, int blocksize)
{
    std::cout << "revinvert" << std::endl;
    std::cout << "none" << std::endl;
    char * mem;
    mem = new char [width*height];
    
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
        std::fstream File("revinvert/" + filename, std::ios::out |std::ios::binary);
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
        else 
        {
            std::cout << "Unable to open file" << std::endl;
        }
        count++;
        
    }
}

//add a frame to the vector
void ORRKAU001::FrameSequence::addToVector(unsigned char** frame)
{
    std::cout << "add to vector" << std::endl;
    ORRKAU001::FrameSequence::imageSequence.push_back(frame);
}

// set the values for x1, x2, y1, y2
void ORRKAU001::FrameSequence::setStartAndEnd(int x1, int y1, int x2, int y2)
{
    ORRKAU001::FrameSequence::x1 = x1;
    ORRKAU001::FrameSequence::y1 = y1;
    ORRKAU001::FrameSequence::x2 = x2;
    ORRKAU001::FrameSequence::y2 = y2;
}

void ORRKAU001::FrameSequence::setWidthHeight(int width, int height)
{
    ORRKAU001::FrameSequence::w = width;
    ORRKAU001::FrameSequence::h = height;
}

void ORRKAU001::FrameSequence::extractFrames(unsigned char ** values)
{
    std::cout << "extract frames." << std::endl;

    int gradient = (ORRKAU001::FrameSequence::y2-ORRKAU001::FrameSequence::y1)/(ORRKAU001::FrameSequence::x2-ORRKAU001::FrameSequence::x1);
    
    float yy = ORRKAU001::FrameSequence::y1;
    
    std::cout << "gradient: " << gradient << std::endl;
    
    int wi = 10000;
    int gi = 400;
    
    for (int xx = ORRKAU001::FrameSequence::x1+1  ; xx < ORRKAU001::FrameSequence::x2 ; ++xx)
    {   
        // x is already defined
        yy += gradient; 
        //std::cout <<  yy << " " << xx << std::endl;
        //frame coordinate = the new (x, yy)
  
        unsigned char** input = new unsigned char*[800];
        for (int f = 0; f < wi; f++)
        {
            input[f] = new unsigned char[800];
        }
        
        int y = round(yy);
        int x = xx;
    
        for (int g = 0; g < ORRKAU001::FrameSequence::h ; g++){
            y = round(yy);
            //std::cout << "check x: " << xx << std::endl;
            for (int l = 0; l < ORRKAU001::FrameSequence::w; l++)
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

    std::cout << "size of vector " << ORRKAU001::FrameSequence::imageSequence.size() << std::endl;
}