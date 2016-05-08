/**
*.cpp Imageops Driver File
* Carla Wilby 06/05/2016
*/
#include "imageops.h"

using namespace std;

using namespace WLBCAR002;

int main(int argc, char* argv[]){
	
	string infile1;
	string infile2;
	string outfile;

	if(argc < 4){
		cout << "Incorrect program entry." << endl;
		cout << "Correct usage: imageops <option> <outputfilename>" << endl;
		return 0;
	}
	if((argc == 4) && (string(argv[1]) == "-i")){
		infile1 = string(argv[2]);
		outfile = string(argv[3]);
		Image img(infile1);
		cout << "Inverting " + infile1 + ".pgm" << endl;
		Image result = !img;
		cout << "Inversion successful." << endl;
		cout << "Saving to " + outfile + ".pgm" << endl;
		result.save(outfile);
		cout << "Saving successful." << endl;
	}else if((argc == 5) && (string(argv[1]) == "-a")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		cout << "Adding " + infile1 + ".pgm and " + infile1 + ".pgm" << endl;
		Image img1(infile1);
		Image img2(infile2);
		Image result = img1+img2;
		cout << "Addition successful." << endl;
		cout << "Saving to " + outfile + ".pgm" << endl;
		result.save(outfile);
		cout << "Saving successful." << endl;
	}else if((argc == 5) && (string(argv[1]) == "-s")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		cout << "Subtracting " + infile1 + ".pgm and " + infile1 + ".pgm" << endl;
		Image img1(infile1);
		Image img2(infile2);
		Image result = img1-img2;
		cout << "Subtraction successful." << endl;
		cout << "Saving to " + outfile + ".pgm" << endl;
		result.save(outfile);
		cout << "Saving successful." << endl;
	}else if((argc == 5) && (string(argv[1]) == "-l")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		cout << "Masking " + infile1 + ".pgm with " + infile1 + ".pgm" << endl;
		Image img1(infile1);
		Image img2(infile2);
		Image result = img1/img2;
		cout << "Mask successful." << endl;
		cout << "Saving to " + outfile + ".pgm" << endl;
		result.save(outfile);
		cout << "Saving successful." << endl;
	}else if((argc == 5) && (string(argv[1]) == "-t")){
		infile1 = string(argv[2]);
		int f;
		istringstream is(argv[3]);
		is >> f;
		outfile = string(argv[4]);
		cout << "Thresholding " + infile1 + ".pgm with a threshold of " + to_string(f) << endl;
		Image img(infile1);
		Image result = img*f;
		cout << "Threshold successful." << endl;
		cout << "Saving to " + outfile + ".pgm" << endl;
		result.save(outfile);
		cout << "Saving successful." << endl;
	}else{
		cout << "Incorrect program entry." << endl;
		cout << "Correct usage: imageops <option> <outputfilename>" << endl;
		return 0;
	}
	return 0;
};