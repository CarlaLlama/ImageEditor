CXX=g++
CPPFLAGS=-std=c++11

imageops: imageops.o driver.o
	$(CXX) -o imageops driver.o imageops.o $(CPPFLAGS)

imageops.o:	imageops.cpp imageops.h
	$(CXX) -c -o imageops.o imageops.cpp $(CPPFLAGS)

driver.o: driver.cpp imageops.h
	$(CXX) -c -o driver.o driver.cpp $(CPPFLAGS)

clean:
	@rm -f *.o imageops

run:
	./imageops