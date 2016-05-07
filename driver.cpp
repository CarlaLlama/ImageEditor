/**
*.cpp Imageops Driver File
* Carla Wilby 05/05/2016
*/
#include "imageops.h"

using namespace std;

using namespace WLBCAR002;

int main(int argc, char* argv[]){

	string outfile;
	string infile;
	string infile1;
	string infile2;

	if(argc < 4){
		cout << "Incorrect program entry." << endl;
		cout << "Correct usage: imageops <option> <outputfilename>" << endl;
		return 0;
	}

	if((argc == 4) && (string(argv[1]) == "-i")){
		infile = string(argv[2]);
		outfile = string(argv[3]);
		Image img = Image(infile);
		Image result = Image(!img);
		result.save(outfile);
	}else if((argc == 5) && (string(argv[1]) == "-a")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		Image img1 = Image(infile1);
		Image img2 = Image(infile2);
		Image result = Image(img1+img2);
		result.save(outfile);
	}else if((argc == 5) && (string(argv[1]) == "-s")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		Image img1 = Image(infile1);
		Image img2 = Image(infile2);
		Image result = Image(img1-img2);
		result.save(outfile);
	}else if((argc == 5) && (string(argv[1]) == "-l")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		Image img1 = Image(infile1);
		Image img2 = Image(infile2);
		Image result = Image(img1/img2);
		result.save(outfile);
	}else if((argc == 5) && (string(argv[1]) == "-f")){
		infile = string(argv[2]);
		int f;
		istringstream is(argv[3]);
		is >> f;
		outfile = string(argv[4]);
		Image img = Image(infile);
		Image result = Image(img*f);
		result.save(outfile);
	}else{
		cout << "Incorrect program entry." << endl;
		cout << "Correct usage: imageops <option> <outputfilename>" << endl;
		return 0;
	}
	return 0;
};