/**
*.cpp Imageops File
* Carla Wilby 06/05/2016
*/

#include "imageops.h"

using namespace std;

namespace WLBCAR002{

	// Constructor for creating image from file
	Image::Image(std::string str){
		load(str);
	}

	// Copy constructor
	Image::Image(const Image& img): width(img.width), height(img.height){	 
	    unsigned char* chunk = new unsigned char[width*height]; 
	    for(int i=0; i<height*width; i++){
	        chunk[i] =  img.data[i];
	    }
	    data.reset(chunk);
	}

	// Move constructor
	Image::Image(Image && img): width(img.width), height(img.height){	 
	    unsigned char* chunk = new unsigned char[width*height]; 
	    for(int i=0; i<height*width; i++){
	        chunk[i] =  img.data[i];
	    }
	    data.reset(chunk);
	    img.width = 0;
	    img.height = 0;
	}

	// Destructor
	Image::~Image(){
		data = nullptr;
		width = 0;
		height = 0;
	}

	// Constructor for testing
	Image::Image(int w, int h, unsigned char* buffer):width(w), height(h){
   		data.reset(buffer); 
	}

	// Get width, used for testing
	int Image::getWidth(void){
		return width;
	}

	// Get height, used for testing
	int Image::getHeight(void){
		return height;
	}

	// Get data pointer, used for testing
	std::unique_ptr<unsigned char []>* Image::getDataPntr(void){
		return &data;
	}	

	// Image file reader
	void Image::load(string str){
		string filename = str + ".pgm";
		ifstream binfile(filename.c_str(), ios::in|ios::binary);

		if(!binfile){
			cout << "File " + filename + "not found." << endl;
			cout << "Please ensure images are inside this directory" << endl;
			return;
		}

		// Stream image header items
		if(binfile.is_open()){
			string line;
			getline(binfile, line);
			while(line!="255"){
				if(!(line.at(0)=='#' || line=="P5")){
					istringstream ss(line);
					ss >> width;
					ss >> height;
				}
				getline(binfile, line);
			}
		// Stream char contents of image
		data.reset(new unsigned char[height*width]);
		skipws(binfile);

		// Read entire chunk into array pointed to by data pntr
		binfile.read((char*)&data[0], width*height);
		binfile.close();
		}
	}

	// Image file writer
	void Image::save(string str){
		string filename = str + ".pgm";
		ofstream outfile(filename.c_str(), ios::out|ios::binary);

		// Write image file header
		outfile << "P5" << endl;
		outfile << "# Output file" << endl;
		outfile << to_string(height) + " " + to_string(width) << endl;
		outfile << "255" << endl;

		// Write image char chunk to memory
		outfile.write((char*)&data[0], height*width);
		outfile.close();
	}

	void Image::copy(const Image& rhs){
		Image::iterator beg = this->begin(), end = this->end();
		Image::iterator inStart = rhs.begin(), inEnd = rhs.end();
		while (beg != end) { 
			*beg = *inStart; ++beg; ++inStart;
		}
	}

	// Filter file reader
	Image::Filter Image::loadFilter(string str){
		ifstream infile(str.c_str());
		Image::Filter f;

		if(!infile){
			cout << "File " + str + "not found." << endl;
			cout << "Please ensure images are inside this directory" << endl;
			exit(1);
		}

		if(infile.is_open()){
			string line;
			getline(infile, line);
			istringstream ss(line);
			
			ss >> f.n;
			int cnt = 0;
			while(ss){
				ss >> *(f.filter + cnt); 
			}
			infile.close();
		}
		return f;
	}

	// Addition operator overload
 	Image Image::operator+(const Image& img){
 		if((img.width == this->width) && (img.height == this->height)){
			// Resultant image copied from current image
			Image temp(*this);
			Image::iterator curr = temp.begin();
			Image::iterator end = temp.end();
			Image::iterator other_curr = img.begin();
			Image::iterator other_end = img.end();
			// Iterate through image numbers
			while(curr != end){
				// Add current values
				int sum = *curr + *other_curr;
				// Cap at 255 if necessary
				if(sum>255){
					sum = 255;
				}
				// Set sum
				*curr = sum;
				// Increment iterators
				++curr;
				++other_curr;
			}
			return temp;
 		}else{
 			cout << "Files are not the same size, cannot perform this operation." << endl;
 			exit(1);
 		}
 	}

 	// Subtraction operator overload
 	Image Image::operator-(const Image& img){
 		if((img.width == this->width) && (img.height == this->height)){
	 		// Resultant image copied from current image
			Image temp(*this);
			Image::iterator curr = temp.begin();
			Image::iterator end = temp.end();
			Image::iterator other_curr = img.begin();
			Image::iterator other_end = img.end();
			// Iterate through image numbers
			while(curr != end){
				// Subtract current values
				int sum = *curr - *other_curr;
				// Cap at 0 if necessary
				if(sum<0){
					sum = 0;
				}
				// Set result
				*curr = sum;
				// Increment iterators
				++curr;
				++other_curr;
			}
			return temp;
	 	}else{
			cout << "Files are not the same size, cannot perform this operation." << endl;
			exit(1);
 		}
 	}

 	// Inversion operator overload
 	Image Image::operator!(void){
 		// Resultant image copied from current image
		Image temp(*this);
		Image::iterator curr = temp.begin();
		Image::iterator end = temp.end();
		// Iterate through image numbers
		while(curr != end){
			// Invert current value
			int inv = 255 - *curr;
			*curr = inv;
			// Increment iterator
			++curr;
		}
		return temp;
 	}

 	// Mask operator overload
 	Image Image::operator/(const Image& img){
 		if((img.width == this->width) && (img.height == this->height)){
	 		// Resultant image copied from current image
			Image temp(*this);
			Image::iterator curr = temp.begin();
			Image::iterator end = temp.end();
			Image::iterator mask_curr = img.begin();
			Image::iterator mask_end = img.end();
			// Iterate through image numbers
			while(curr != end){
				// For mask values of 255 keep value, otherwise set to 0
				if(!(*mask_curr == 255)){
					int val = 0;
					*curr = val;
				}
				// Increment iterators
				++curr;
				++mask_curr;
			}
			return temp;
		}else{
 			cout << "Files are not the same size, cannot perform this operation." << endl;
 			exit(1);
 		}
 	}


 	// Threshold operator overload
 	Image Image::operator*(int f){
 		// Resultant image copied from current image
		Image temp(*this);
		Image::iterator curr = temp.begin();
		Image::iterator end = temp.end();
		// Iterate through image numbers
		while(curr != end){
			// For image values below threshold f set to 0
			// For greater than threshold, set to 255 
			int thr;
			if(*curr>f){
				thr = 255;
			}else{
				thr = 0;
			}
			*curr = thr;
			// Increment iterators
			++curr;
		}
		return temp;
 	}

 	// Operator overload for filtering
 	Image Image::operator%(string g){
 		// Create filter
 		Filter f = loadFilter(g);

 		// Resultant image copied from current image
		Image temp(*this);
		Image::iterator curr = temp.begin();
		Image::iterator end = temp.end();
		// Iterate through image numbers
		while(curr != end){
			++curr;
		}
		cout << "Please purchase full version to activate filtering." << endl;
		exit(1);
 	}

 	// Operator overload for reading from file
	istream& operator>>(istream& binfile, Image& img){
		// Stream image header items
			string line;
			getline(binfile, line);
			while(line!="255"){
				if(!(line.at(0)=='#' || line=="P5")){
					istringstream ss(line);
					ss >> img.width;
					ss >> img.height;
				}
				getline(binfile, line);
			}

		// Stream char contents of image
		img.data.reset(new unsigned char[img.height*img.width]);
		skipws(binfile);

		// Read entire chunk into array pointed to by data pntr
		binfile.read((char*)(&(img.data[0])), img.width*img.height);
	}

	// Operator overload for writing to file
	ostream& operator<<(ostream& binfile, const Image& img){
		// Write image file header
		binfile << "P5" << endl;
		binfile << "# Output file" << endl;
		binfile << to_string(img.height) + " " + to_string(img.width) << endl;
		binfile << "255" << endl;

		// Write image char chunk to memory
		binfile.write((char*)&(img.data[0]), img.height*img.width);
		return binfile;
	}

	// Iterator copy constructor
	Image::iterator::iterator(const Image::iterator & rhs) : ptr(rhs.ptr){
		ptr = rhs.ptr;
	}

	// Iterator constructor
	Image::iterator::iterator(unsigned char *p) : ptr(p) {};

	// Iterator destructor
	Image::iterator::~iterator(){
            ptr = nullptr;
    }

    // Pointer to beginning of data chunk
 	Image::iterator Image::begin(void) const{
 		return iterator(&(data.get()[0]));
 	}

 	// Pointer to end of data chunk
    Image::iterator Image::end(void) const{
		return iterator(&(data.get()[width*height]));
    }

}