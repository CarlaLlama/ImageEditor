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
#include <string>
#include <queue>

namespace WLBCAR002{

	class Image
	{
	private:
		int width, height;
		std::unique_ptr<unsigned char[]> data;

	public:

		Image(std::string str);
		Image(const Image& img);
		~Image();

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

		Image operator!(void);

		Image operator+(const Image& img);

		Image operator-(const Image& img);

		Image operator/(const Image& img);

		Image operator*(int f);

		class Iterator
		{
			private:
				unsigned char *ptr;
				friend class Image;
				// construct only via Image class (begin/end)
				Iterator(unsigned char *p);
				

			public:
				Iterator(const Iterator & rhs);
				~Iterator();

				// define overloaded ops: *, ++, --, =
				
				// other methods for iterator

				// Iterator & operator=(const iterator & rhs){
				// 	*this = *other;
				// 	return this;
				// }

				unsigned char & operator*(){
	 				return *ptr;
	 			}

	 			const Iterator & operator++(){
	 				ptr+1;
					return *this;
	 			}

	 			const Iterator & operator--(){
	 				ptr-1;
					return *this;
	 			}

	 			bool operator!=(const Iterator& other){
	 				if(ptr != other.ptr){
	 					return true;
	 				}else{
	 					return false;
	 				}
	 			}
			
		};

		// define begin()/end() to get iterator to start and
 		// "one-past" end.
 		//iterator begin(void); // etc

 		Iterator begin(void) const;
      	Iterator end(void) const;
	};

}
#endif
