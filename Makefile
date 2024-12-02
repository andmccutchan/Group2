mytests: mytests.o HashMap.o HashMapTree.o RBTree.o RBTreeNode.o HashFunction.o
	g++ -std=c++17 -o mytests mytests.o HashMap.o HashMapTree.o RBTree.o RBTreeNode.o HashFunction.o
	./mytests

# Rule for building mytests.o
mytests.o: mytests.cpp HashMap.hpp HashMapTree.hpp RBTree.hpp RBTreeNode.hpp HashFunction.hpp
	g++ -std=c++17 -c mytests.cpp -o mytests.o

# Rule for building HashMap.o
HashMap.o: HashMap.cpp HashMap.hpp HashFunction.hpp
	g++ -std=c++17 -c HashMap.cpp -o HashMap.o

# Rule for building HashMapTree.o
HashMapTree.o: HashMapTree.cpp HashMapTree.hpp RBTree.hpp RBTreeNode.hpp HashFunction.hpp
	g++ -std=c++17 -c HashMapTree.cpp -o HashMapTree.o

# Rule for building RBTree.o
RBTree.o: RBTree.cpp RBTree.hpp RBTreeNode.hpp
	g++ -std=c++17 -c RBTree.cpp -o RBTree.o

# Rule for building RBTreeNode.o
RBTreeNode.o: RBTreeNode.cpp RBTreeNode.hpp
	g++ -std=c++17 -c RBTreeNode.cpp -o RBTreeNode.o

# Rule for building HashFunction.o
HashFunction.o: HashFunction.cpp HashFunction.hpp
	g++ -std=c++17 -c HashFunction.cpp -o HashFunction.o

# Cleaning all object files and executable
clean:
	rm -f *.o mytests