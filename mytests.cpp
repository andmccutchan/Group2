#include <iostream>
#include "HashMapTree.hpp"
using namespace std;

int main() {
    HashMapTree<int, int> map;
    map.insert(2, 5);
    map.remove(2);
    return 0;
}