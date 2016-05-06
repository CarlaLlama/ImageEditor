/**
*.cpp Imageops Driver File
* Carla Wilby 05/05/2016
*/
#include "imageops.h"

using namespace std;

namespace WLBCAR002{

int main(int argc, char* argv[])
{
	string outfile;
	string infile;
	string infile1;
	string infile2;

	Image img;

	if(argc < 4){
		cout << "Incorrect program entry." << endl;
		cout << "Correct usage: imageops <option> <outputfilename>" << endl;
		return 0;
	}

	if((argc == 4) && (string(argv[1]) == "-i")){
		infile = string(argv[2]);
		outfile = string(argv[3]);
		img.readin(infile, outfile);
		img.invert(pntr);
		img.save(pntr);
	}else if((argc == 5) && (string(argv[1]) == "-a")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		img.readin(infile1, outfile);
		img.readin(infile2, outfile);
		img.add(pntr1, pntr2);
		img.save(pntr);
	}else if((argc == 5) && (string(argv[1]) == "-s")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		img.readin(infile1, outfile);
		img.readin(infile2, outfile);
		img.subtract(pntr1, pntr2);
		img.save(pntr);
	}else if((argc == 5) && (string(argv[1]) == "-l")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		img.readin(infile1, outfile);
		img.readin(infile2, outfile);
		img.mask(pntr1, pntr2);
		img.save(pntr);
	}else if((argc == 5) && (string(argv[1]) == "-l")){
		infile = string(argv[2]);
		int f;
		istringstream is(argv[3]);
		is >> f;
		outfile = string(argv[4]);
		img.readin(infile, outfile);
		img.threshold(pntr, f);
		img.save(pntr);
	}else{
		cout << "Incorrect program entry." << endl;
		cout << "Correct usage: imageops <option> <outputfilename>" << endl;
		return 0;
	}

};
}