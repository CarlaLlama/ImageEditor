/**
*.h Header file
* Carla Wilby 06/05/2016
*/

#ifndef IMAGEOPS_H
#define IMAGEOPS_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <queue>

namespace WLBCAR002{

	class Image
	{
	private:
		std::string outfile;

	public:

		Image();
		~Image();

		void add(std::string l1, std::string l2, std::string outfile);
		
		void subtract(std::string l1, std::string l2, std::string outfile);

		void invert(std::string l1, std::string outfile);

		void mask(std::string l1, std::string l2, std::string outfile);

		void threshold(std::string l1, int f, std::string outfile);	

		bool operator<(const Image& b) const;

		Image & operator=(const Image & rhs){
			if(this != &rhs){
				inFile = rhs.inFile;
				outFile = rhs.outFile;
				bitBuffer = rhs.bitBuffer;
				root = rhs.root;
			}
			return *this;
		}

		Image & operator=(Image && rhs){
			if(this != &rhs){
				inFile = std::move(rhs.inFile);
				outFile = std::move(rhs.outFile);
				bitBuffer = std::move(rhs.bitBuffer);
				root = rhs.root;
				rhs.root = nullptr;
			}
			return *this;
		}
	};

	struct Compare
	{

	  bool operator()(const std::shared_ptr<HuffmanNode>& lhs, const std::shared_ptr<HuffmanNode>& rhs) const;
	};

}
#endif
