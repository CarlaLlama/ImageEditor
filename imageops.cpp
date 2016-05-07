/**
*.cpp Imageops File
* Carla Wilby 01/03/2016
*/

#include "imageops.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

using namespace std;

namespace WLBCAR002{

	Image::Image(string str){
		readin(str);
	}

	// copy constructor
	Image::Image(const Image& img): width(img.width), height(img.height){	 
	    unsigned char* chunk = new unsigned char[width*height]; 
	    for(int i=0; i<height*width; i++){
	        chunk[i] =  img.data[i];
	    }
	    data.reset(chunk);
	}

	Image::~Image(){

	}

	void Image::readin(string str){
		string filename = str + ".pgm";
		ifstream binfile(filename.c_str(), ios::in|ios::binary|ios::ate);
	    // ios::ate flag - get pointer positioned at end of the file;
			

		if(!binfile){
			cout << "File not found." << endl;
			cout << "Please ensure images are inside this directory" << endl;
			return;
		}

		// Stream image header items
		int linecounter = 0;
		string line;
		getline(binfile, line);
		while(line!="255"){
			if(string(line.at(0)+"")=="#"){
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

	//ADD OVERLOAD
 	Image Image::operator+(const Image& img){
		Image temp(*this);

		Image::Iterator curr = temp.begin();
		Image::Iterator end = temp.end();
		Image::Iterator other_curr = img.begin();
		Image::Iterator other_end = img.end();

		while(curr != end){
			int sum = *curr + *other_curr;
			if(sum>255){
				sum = 255;
			}
			*curr = sum;
			++curr;
			++other_curr;
		}
		return temp;
 	}

 	//SUBTRACT OVERLOAD
 	Image Image::operator-(const Image& img){
		Image temp(*this);

		Image::Iterator curr = temp.begin();
		Image::Iterator end = temp.end();
		Image::Iterator other_curr = img.begin();
		Image::Iterator other_end = img.end();

		while(curr != end){
			int sum = *curr - *other_curr;
			if(sum<0){
				sum = 0;
			}
			*curr = sum;
			++curr;
			++other_curr;
		}
		return temp;
 	}

 	//INVERT OVERLOAD
 	Image Image::operator!(void){
		Image temp(*this);

		Image::Iterator curr = temp.begin();
		Image::Iterator end = temp.end();

		while(curr != end){
			int inv = 255 - *curr;
			*curr = inv;
			++curr;
		}
		return temp;
 	}

 	//MASK OVERLOAD
 	Image Image::operator/(const Image& img){
		Image temp(*this);

		Image::Iterator curr = temp.begin();
		Image::Iterator end = temp.end();
		Image::Iterator mask_curr = img.begin();
		Image::Iterator mask_end = img.end();

		while(curr != end){		
			if(*mask_curr == 255){
				int val = *curr;
				*curr = val;
			}else{
				int val = 0;
				*curr = val;
			}
			++curr;
			++mask_curr;
		}
		return temp;
 	}


 	//THRESHOLD OVERLOAD
 	Image Image::operator*(int f){
		Image temp(*this);

		Image::Iterator curr = temp.begin();
		Image::Iterator end = temp.end();

		while(curr != end){
			int thr;
			if(*curr>f){
				thr = 255;
			}else{
				thr = 0;
			}
			*curr = thr;
			++curr;
		}
		return temp;
 	}

	
	Image::Iterator::Iterator(const Image::Iterator & rhs) : ptr(rhs.ptr){
		ptr = rhs.ptr;
	}

	Image::Iterator::Iterator(unsigned char *p) : ptr(p) {};

	Image::Iterator::~Iterator(){
            ptr = nullptr;
    }

 	Image::Iterator Image::begin(void) const{
 		return Iterator(&(data.get()[0]));
 	}

    Image::Iterator Image::end(void) const{
		return Iterator(&(data.get()[width*height]));
    }

}