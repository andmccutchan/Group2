mytests: HashMapTree DoublyLinkedList.cpp DoublyLinkedList.hpp HashMap.cpp HashMap.hpp mytests.cpp HashMapTree.cpp HashMapTree.hpp RBTree.hpp RBTree.cpp customexceptions.hpp HashFunction.cpp HashFunction.hpp
	g++ -std=c++17 -c mytests.cpp -o mytests.o
	time g++ -std=c++17  HashMapTree.o mytests.o RBTree.o RBTreeNode.o HashFunction.o -o mytests
	./myTests

HashMapTree: HashMapTree.cpp HashMapTree.hpp RBTree.hpp RBTree.cpp RBTreeNode.cpp RBTreeNode.hpp
	g++ -std=c++17 -c RBTree.cpp -o RBTree.o
	g++ -std=c++17 -c RBTreeNode.cpp -o RBTreeNode.o
	g++ -std=c++17 -c HashMapTree.cpp -o HashMapTree.o
	g++ -std=c++17 -c HashFunction.cpp -o HashFunction.o
	


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