# # Target to build and run the test executable
# mytests: mytests.o HashMap.o HashFunction.o
# 	g++ -o mytests mytests.o HashMap.o HashFunction.o
# 	./mytests

# # Rule for building mytests.o
# mytests.o: mytests.cpp HashMap.hpp HashFunction.hpp
# 	g++ -c mytests.cpp -o mytests.o 

# # Rule for building HashMap.o
# HashMap.o: HashMap.cpp HashMap.hpp HashFunction.hpp
# 	g++ -c HashMap.cpp -o HashMap.o 

# # Rule for building HashFunction.o
# HashFunction.o: HashFunction.hpp HashFunction.cpp
# 	g++ -c HashFunction.cpp -o HashFunction.o 

# # Cleaning all object files and executable
# clean:
# 	rm -f *.o mytests

# Target to build and run the test executable
# mytests: mytests.o HashMapTree.o RBTree.o RBTreeNode.o HashFunction.o
# 	g++ -o mytests mytests.o HashMapTree.o RBTree.o RBTreeNode.o HashFunction.o
# 	./mytests

# # Rule for building mytests.o
# mytests.o: mytests.cpp HashMapTree.hpp RBTree.hpp RBTreeNode.hpp HashFunction.hpp
# 	g++ -c mytests.cpp -o mytests.o

# # Rule for building HashMapTree.o
# HashMapTree.o: HashMapTree.cpp HashMapTree.hpp RBTree.hpp RBTreeNode.hpp HashFunction.hpp
# 	g++ -c HashMapTree.cpp -o HashMapTree.o

# # Rule for building RBTree.o
# RBTree.o: RBTree.cpp RBTree.hpp RBTreeNode.hpp
# 	g++ -c RBTree.cpp -o RBTree.o

# # Rule for building RBTreeNode.o
# RBTreeNode.o: RBTreeNode.cpp RBTreeNode.hpp
# 	g++ -c RBTreeNode.cpp -o RBTreeNode.o

# # Rule for building HashFunction.o
# HashFunction.o: HashFunction.cpp HashFunction.hpp
# 	g++ -c HashFunction.cpp -o HashFunction.o

# # Cleaning all object files and executable
# clean:
# 	rm -f *.o mytests
# Target to build and run the test executable
mytests: mytests.o HashMap.o HashMapTree.o RBTree.o RBTreeNode.o HashFunction.o
	g++ -o mytests mytests.o HashMap.o HashMapTree.o RBTree.o RBTreeNode.o HashFunction.o
	./mytests

# Rule for building mytests.o
mytests.o: mytests.cpp HashMap.hpp HashMapTree.hpp RBTree.hpp RBTreeNode.hpp HashFunction.hpp
	g++ -c mytests.cpp -o mytests.o

# Rule for building HashMap.o
HashMap.o: HashMap.cpp HashMap.hpp HashFunction.hpp
	g++ -c HashMap.cpp -o HashMap.o

# Rule for building HashMapTree.o
HashMapTree.o: HashMapTree.cpp HashMapTree.hpp RBTree.hpp RBTreeNode.hpp HashFunction.hpp
	g++ -c HashMapTree.cpp -o HashMapTree.o

# Rule for building RBTree.o
RBTree.o: RBTree.cpp RBTree.hpp RBTreeNode.hpp
	g++ -c RBTree.cpp -o RBTree.o

# Rule for building RBTreeNode.o
RBTreeNode.o: RBTreeNode.cpp RBTreeNode.hpp
	g++ -c RBTreeNode.cpp -o RBTreeNode.o

# Rule for building HashFunction.o
HashFunction.o: HashFunction.cpp HashFunction.hpp
	g++ -c HashFunction.cpp -o HashFunction.o

# Cleaning all object files and executable
clean:
	rm -f *.o mytests
