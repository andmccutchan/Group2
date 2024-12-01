# Target to build and run the test executable
mytests: mytests.o HashMap.o HashFunction.o
	g++ -o mytests mytests.o HashMap.o HashFunction.o
	./mytests

# Rule for building mytests.o
mytests.o: mytests.cpp HashMap.hpp HashFunction.hpp
	g++ -c mytests.cpp -o mytests.o 

# Rule for building HashMap.o
HashMap.o: HashMap.cpp HashMap.hpp HashFunction.hpp
	g++ -c HashMap.cpp -o HashMap.o 

# Rule for building HashFunction.o
HashFunction.o: HashFunction.hpp HashFunction.cpp
	g++ -c HashFunction.cpp -o HashFunction.o 

# Cleaning all object files and executable
clean:
	rm -f *.o mytests
