//includes 
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;
int main (int argc, char** argv)
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "The file is being read..." << std::endl;
	std::string f;
    std::string filename = "sloan_image.pgm";

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

     
    std::cout << blocksize << std::endl;

    char values[height][width];
	int index = 0;

    for (int x = 0; x < height; x++ )
    {
        for (int y = 0; y <width; y++ )
        {

            values[x][y] = memblock[index];
            index++; 
        }
    }

    mem = new char [blocksize];
    int in = 0;
    for (int x = 0; x < 1500; x++ )
    {
        for (int y = 1500; y <3000; y++ )
        {
            mem[in] = values[x][y];
            
            in++;
        }
    }

    ofstream File("image.pgm", ios::in|ios::binary);
    if (File.is_open())
    {
        //file.seekg (0, ios::beg); //get the first position
        File << fileType << std::endl;
        File << comments<< std::endl;;
        File << "1500 1500"<< std::endl;;
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
    return 0;
}

