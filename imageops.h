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
		int width, height;
		std::unique_ptr<unsigned char[]> data;

	public:

		Image();
		~Image();

		void add(std::string l1, std::string l2);

		void subtract(std::string l1, std::string l2);

		void invert(std::string l1);

		void mask(std::string l1, std::string l2);

		void threshold(std::string l1, int f);

		void copy(const Image& rhs);

		void readin(std::string str);

		void save(std::string str);

		bool operator<(const Image& b) const;

		//Image & operator=(const Image & rhs){
			//if(this != &rhs){
				//inFile = rhs.inFile;
				//outFile = rhs.outFile;
				//bitBuffer = rhs.bitBuffer;
				//root = rhs.root;
			//}
			//return *this;
		//}

		//Image & operator=(Image && rhs){
		//	if(this != &rhs){
		//		inFile = std::move(rhs.inFile);
		//		outFile = std::move(rhs.outFile);
		//		bitBuffer = std::move(rhs.bitBuffer);
		//		root = rhs.root;
		//		rhs.root = nullptr;
		//	}
		//	return *this;
		//}
		 class iterator
		 {
			private:
			unsigned char *ptr;
			// construct only via Image class (begin/end)

			//iterator(u_char *p) : ptr(p) {};

			public:
			//copy construct is public
			//iterator( const iterator & rhs) : ptr(rhs.ptr) {};
			// define overloaded ops: *, ++, --, =
			//iterator & operator=(const iterator & rhs);
			// other methods for iterator
		};

		// define begin()/end() to get iterator to start and
 		// "one-past" end.
 		//iterator begin(void); // etc
	};

}
#endif
