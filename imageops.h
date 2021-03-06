/**
*.h Header file
* Carla Wilby 06/05/2016
*/

#ifndef IMAGEOPS_H
#define IMAGEOPS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

namespace WLBCAR002{

	class Image{

	private:

		int width, height;
		std::unique_ptr<unsigned char[]> data;


	public:

		// Constructors
		Image(std::string str);
		Image(const Image& img);
		Image(Image && img);
		Image(int w, int h, unsigned char* buffer);
		~Image();

		// Getters, used for testing
		int getHeight(void);
		int getWidth(void);
		std::unique_ptr<unsigned char []>* getDataPntr(void);

		// File handlers
		void load(std::string str);
		void save(std::string str);

	 	struct Filter
		{
			int n;
			float filter [];
		  
		};
		Filter loadFilter(std::string str);

		void copy(const Image& rhs);

		// Operator overloads for image manipulation functions
		Image operator!(void);
		Image operator+(const Image& img);
		Image operator-(const Image& img);
		Image operator/(const Image& img);
		Image operator*(int f);
		Image operator%(std::string g);

		// Operator overload for reading from file
		friend std::istream& operator>>(std::istream& binfile, Image& img);
		// Operator overload for writing to file
		friend std::ostream& operator<<(std::ostream& binfile, const Image& img);

		// Nested iterator class
		class iterator
		{
			private:
				unsigned char *ptr;
				friend class Image;
				// Private constructor
				iterator(unsigned char *p);

			public:
				// Copy constructor
				iterator(const iterator & rhs);
				~iterator();

				// Operator overloads for iterator specific operations
				unsigned char & operator*(){
	 				return *ptr;
	 			}

	 			const iterator & operator++(){
	 				++ptr;
					return *this;
	 			}

	 			const iterator & operator--(){
	 				ptr-1;
					return *this;
	 			}

	 			bool operator!=(const iterator& other){
	 				if(ptr != other.ptr){
	 					return true;
	 				}else{
	 					return false;
	 				}
	 			}
		};

		// Iterator pointer functions
 		iterator begin(void) const;
      	iterator end(void) const;
 	
	};



}
#endif
