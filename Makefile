mytests: HashMapTree mytests.cpp HashMapTree.cpp HashMapTree.hpp RBTree.hpp RBTree.cpp customexceptions.hpp HashFunction.cpp HashFunction.hpp
	g++ -std=c++17 -c mytests.cpp -o mytests.o
	g++ -std=c++17 HashMapTree.o mytests.o RBTree.o RBTreeNode.o HashFunction.o -o mytests
	./myTests

HashMapTree: HashMapTree.cpp HashMapTree.hpp RBTree.hpp RBTree.cpp RBTreeNode.cpp RBTreeNode.hpp
	g++ -std=c++17 -c RBTree.cpp -o RBTree.o
	g++ -std=c++17 -c RBTreeNode.cpp -o RBTreeNode.o
	g++ -std=c++17 -c HashMapTree.cpp -o HashMapTree.o
	g++ -std=c++17 -c HashFunction.cpp -o HashFunction.o
