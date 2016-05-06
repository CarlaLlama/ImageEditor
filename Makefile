CXX=g++
CPPFLAGS=-std=c++11

imageops:	imageops.o driver.o
	$(CXX) -o imageops.o driver.o imageops $(CPPFLAGS)

imageops.o:	imageops.cpp imageops.h
	$(CXX) -c -o imageops.cpp $(CPPFLAGS)

driver.o: driver.cpp imageops.h
	$(CXX) -c -o driver.cpp $(CPPFLAGS)

clean:
	@rm -f *.o imageops

run:
	./db