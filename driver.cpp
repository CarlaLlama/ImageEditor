/**
*.cpp Imageops Driver File
* Carla Wilby 05/05/2016
*/
#include "imageops.h"

using namespace std;

int main(int argc, char* argv[])
{
	string outfile;
	string infile;

	Image::Image img;

	if(argc < 4){
		cout << "Incorrect program entry." << endl;
		cout << "Correct usage: imageops <option> <outputfilename>" << endl;
		return 0;
	}

	if((argc == 4) && (string(argv[1]) == "-i")){
		infile = string(argv[2]);
		outfile = string(argv[3]);
		std::unique_ptr pntr = img.readin(infile, outfile);
		img.invert(pntr, outfile);
	}else if((argc == 5) && (string(argv[1]) == "-a")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		std::unique_ptr pntr1 = img.readin(infile1, outfile);
		std::unique_ptr pntr2 = img.readin(infile2, outfile);
		img.add(pntr1, pntr2, outfile);
	}else if((argc == 5) && (string(argv[1]) == "-s")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		std::unique_ptr pntr1 = img.readin(infile1, outfile);
		std::unique_ptr pntr2 = img.readin(infile2, outfile);
		img.subtract(pntr1, pntr2, outfile);
	}else if((argc == 5) && (string(argv[1]) == "-l")){
		infile1 = string(argv[2]);
		infile2 = string(argv[3]);
		outfile = string(argv[4]);
		std::unique_ptr pntr1 = img.readin(infile1, outfile);
		std::unique_ptr pntr2 = img.readin(infile2, outfile);
		img.mask(pntr1, pntr2, outfile);
	}else if((argc == 5) && (string(argv[1]) == "-l")){
		infile = string(argv[2]);
		int f;
		istringstream is(argv[3]);
		is >> f;
		outfile = string(argv[4]);
		std::unique_ptr pntr = img.readin(infile, outfile);
		img.threshold(pntr, f, outfile);
	}else{
		cout << "Incorrect program entry." << endl;
		cout << "Correct usage: volimage <imageBase> [-d i j output_file_name] [-x i output_file_name] [-g i output_file_name]" << endl;
		return 0;
	}

	// Print number of images and bytes required
	img_no = volimg.volNumberImages();
	bytes_no = volimg.volImageSize();

	ostringstream oss;
	oss << img_no;
	cout << "Number of images: " + oss.str() << endl;

	ostringstream ss;
	ss << bytes_no;
	cout << "Number of bytes required: " + ss.str() << endl;

	cout << "Operation achieved: " << operation_message << endl;

	return 0;

};