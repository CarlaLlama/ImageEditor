CXX=g++
CPPFLAGS=-std=c++11

test: imageops.o unittest.o
	$(CXX) imageops.o unittest.o -o test $(CPPFLAGS)

imageops.o: ../imageops.cpp ../imageops.h
	$(CXX) -c ../imageops.cpp $(CPPFLAGS)

unittest.o: unittest.cpp unittest.h
	$(CXX) -c unittest.cpp $(CPPFLAGS)	

clean:
	@rm -f *.o test
