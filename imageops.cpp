/**
*.cpp Imageops File
* Carla Wilby 01/03/2016
*/

#include "imageops.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

namespace WLBCAR002{

	Image::Image(){

	}

	Image::~Image(){

	}

	void Image::add(std::string l1, std::string l2){

	}

	void Image::subtract(std::string l1, std::string l2){

	}

	void Image::invert(std::string l1){

	}

	void Image::mask(std::string l1, std::string l2){

	}

	void Image::threshold(std::string l1, int f){

	}

	void Image::copy(const Image& rhs){

	}

	void Image::readin(string str){
		string filename = str + ".pgm";
		ifstream binfile(filename.c_str(), ios::in|ios::binary|ios::ate);
	    // ios::ate flag - get pointer positioned at end of the file;
			

		if(!binfile){
			cout << "File not found." << endl;
			cout << "Please ensure images are inside this directory" << endl;
		}

		// Stream image header items
		int linecounter = 0;
		string line;
		getline(binfile, line);
		while(line!="255"){
			if(line=="#"){
				linecounter++;
			}else{
				istringstream ss(line);
				ss >> width;
				ss >> height;
				linecounter++;
			}
			getline(binfile, line);
		}

		// Stream binary file contents
		for(int i = 0; i < height*width; i++){
			
			// Stream header file contents
			char * blck;
			streampos size;
			if(binfile.is_open()){
				size = binfile.tellg();
				blck = new char[size];
				binfile.seekg(linecounter, ios::beg); //CHECK
				// Get position at beginning of file
				// Read everything into blck
				binfile.read(blck, size);
				binfile.close();
			}
			data.reset(new unsigned char[height*width]);
		}
	}

	void Image::save(string str){
		string filename = str + ".pgm";
		ofstream outfile(filename.c_str(), ios::in|ios::binary);

		outfile << "P5" << endl;
		outfile << "Output file" << endl;
		outfile << height + " " + width << endl;

		int size = height*width;
		// use iterator here
		//outfile.write(*data, size);
		outfile.close();
	}

	unsigned char *ptr;
	// construct only via Image class (begin/end)

	//Image::iterator(u_char *p) : ptr(p){

	//}

	//copy construct is public
	//Image::iterator( const iterator & rhs) : ptr(rhs.ptr){

	//}

	// define begin()/end() to get iterator to start and
 	// "one-past" end.
 	//Image::iterator begin(void) { return iterator(data.get());} // etc

}