Assignment 2 
Name: Kauthar Orrie 
Student No.: ORRKAU001
Date: 13/03/2023

Notes for the tutor marking:
    - when I run the frametester_updated.sh, all my tests are successful, the filenames are written out correctly 
    and as specified by the assignment brief, but when the program is moved to the new directory as stated by the line
    in frametester_updated.sh -> "mv $file "$2/$(printf %05d $count).pgm"" (line 88) the filenames change to just a number.
    - I've tried debugging, but I couldn't find a solution. 
    - My frames output correctly, to the write filenames too and create videos, but when the videos are created, the videos from the previously 
    tested sequence is added together to make one big video of all the tested functions. So all the output videos are concatenated together.
    - I am uncertain if this is the desired outcome, but wanted to let you know of this.
    - I did not complete the Mastery Section.

How to run the program: 
- type 'make' in the terminal to compile the files and create binary files
- run program with using " ./extractor " to run the program
    NOTE:
        - to successfully run the program make sure you add the "-t", "-s" and "-w" flag, if the flags aren't specified the program will run into errors
        - format of input: 
                -> "./extractor <filename> -t <x1> <y1> <x2> <y2> -s <width> <height> -w <output> <filename>"

Files included in submission:
- FrameSequence.cpp (source file)
	- includes the methods needed for the program
	- implements the methods used in the extractor.cpp file like extracting the necessary frames, outputing the files 
      in the specified method declared by the user

- FrameSequence.h (header file)
	- declares my namespace with my student number ORRKAU001
	- declares all the required methods which is defined within FrameSequence.cpp (source file)
	- declares all the '#include' files
    - declares the FrameSequence class which includes the constructor, destructor, public methods and variables

- extractor.cpp (driver file)
	- the main includes the command loop to handle the user input and output
	- includes and implements methods from the source file FrameSequence.cpp

- makefile 
	- compiles the program

	