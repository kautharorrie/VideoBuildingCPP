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


    streampos size;
    char * memblock;

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
            //size = file.tellg();
        memblock = new char [4130*1968];
        //file.seekg (0, ios::beg); //get the first position
        file.read (memblock, 4130*1938);
        file.close();

        cout << "the entire file content is in memory";


    }
    else {cout << "Unable to open file";}

    int g = widthheight.find(" ");
    std::string w = widthheight.substr(0, g);
    std::string h = widthheight.substr(g+1, widthheight.length());

    width = atoi(w.c_str());
    height = atoi(h.c_str());
     
    


	
    // for (int x =0; x < height; x++ )
    // {
    //     for (int y = 0; y <width; y++ )
    //     {
    //         in >> val;
    //         values[x][y] = val; 
    //     }
    // }

    // // for (int x =0; x <2; x++ )
    // // {
    // //     for (int y = 0; y <6; y++ )
    // //     {
    // //         std::cout << values[x][y] << std::endl;
    // //     }
    // // }


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

    return 0;
}

