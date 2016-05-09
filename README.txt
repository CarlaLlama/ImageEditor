IMAGE MANIPULATION OPERATOR
---------------

To compile this project:
	Extract project to desired directory
	cd into project directory
	run:
		$ make

To run this project:
	Ensure it has been compiled correctly
	cd into project directory
	run:
		$ ./imageops <option> <output filename prefix>

To clean project:
	run:
		$ make clean

COMMAND LINE ARGUMENTS
----------------------

imageops : name of executable
<option> : manipulation to be executed, see below
<output file prefix> : prefix of output files

Options:

[-a l1 l2 output_file_name] :
	-a: addition of two images
	l1 : first image filename prefix
	l2 : second image filename prefix
	output_file_name : name of file to print result to

[-s l1 l2 output_file_name] :
	-s: subtraction of two images
	l1 : first image filename prefix
	l2 : second image filename prefix
	output_file_name : name of file to print result to

[-i l1 output_file_name] :
	-i : invert image
	l1 : image filename prefix
	output_file_name : name of file to print result to

[-l l1 l2 output_file_name] :
	-l: mask image one with image two
	l1 : first image filename prefix
	l2 : second image filename prefix
	output_file_name : name of file to print result to

[-t l1 f output_file_name] :
	-t: adjust image on threshold f
	l1 : image filename prefix
	f : threshold
	output_file_name : name of file to print result to

[-g l1 g output_file_name] :
	-g: filter image
	l1 : image filename prefix
	g : file containing filter
	output_file_name : name of file to print result to

HELP
----

1. If this directory is not included in the project path, ./ will have to be used before the executable name (ie ./imageops)
2. Both input and output files are NOT expected to have an extension (ie. .pgm). Please enter only the prefix.
3. The output will be sent the the output file. The first lines of the header file contain the width and height and additional information about the resultant image.
4. Testing files are contained in the testing subdirectory (./test). Running make in this directory will generate them.
5. Run ./test/test to run the tests

DIRECTORY STRUCTURE
-------------------

Here is an example of the working directory structure:

/imageops
	/driver.cpp
	/imageops.cpp
	/imageops.h
	/Makefile
	/README.txt
	/.gitignore
	/test
		/unittest.cpp
		/unittest.h
		/catch.hpp
		/Makefile

FILE STRUCTURE
--------------

Makefile:
	Used to correctly compile source files.
driver.cpp:
	Source file containing main() method, called at start of project.
	Reads in arguments from user.
imageops.h:
	Header file containing Image and iterator class declaration.
imageops.cpp:
	Source file containing overloading and manipulation functions

MAINTAINERS
-----------

Current Maintainers:
* Carla Wilby (carlallama) - https://github.com/CarlaLlama