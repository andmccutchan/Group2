#include <iostream>
#include "HashMap.hpp"
#include "HashMapTree.hpp"
using namespace std;

void testHashMapTreeInsert();
void testHashMapTreeRemove();
void testHashMapTreeSearch();
void testHashMapTreeAccess();

int main() {

    HashMapTree<int, int> map;
    map.insert(2, 5);

    testHashMapTreeInsert();
    // testHashMapTreeRemove();git 
    // testHashMapTreeSearch();
    // testHashMapTreeAccess();
    return 0;
}





void testHashMapTreeInsert() {
    cout << "Testing HashMapTree insertion" << endl;
    cout << "=============================" << endl;
    HashMapTree<int, int> map;
    map.insert(2,6);
    map.insert(6,3);
    map.insert(2,4);
    map.insert(22, 7);
    map.insert(1, 14);
    map.insert(3, 90);
    map.insert(11, 14);
    HashMapTree<int, int> map2(map);
    map.printMap();
    cout << "=============================" << endl;
    cout << endl;
}

void testHashMapTreeRemove() {
    cout << "Testing HashMapTree removal" << endl;
    cout << "=============================" << endl;
    HashMapTree<int, int> map;
    map.insert(5, 18);
    map.insert(9, 10);
    map.insert(7, 2);
    map.insert(18, 6);

    cout << "BEOFRE: " << endl;
    map.printMap();

    map.remove(7);


    cout << "AFTER: " << endl;
    map.printMap();
    cout << "=============================" << endl;
    cout << endl;
}

void testHashMapTreeSearch() {
    cout << "Testing HashMapTree search" << endl;
    cout << "=============================" << endl;
    HashMapTree<int, int> map;
    map.insert(2,6);
    map.insert(6,3);
    map.insert(2,4);
    map.insert(22, 7);
    map.insert(1, 14);
    map.insert(3, 90);
    map.insert(11, 14);
    map.printMap();

    cout << "Searching for key: 2: ";
    if (map.search(2) != nullptr) {
        cout << "Key found!" << endl;
    } 
    else {
        cout << "Key not found :(" << endl;
    }

    cout << "Searching for key: 4: ";
    if (map.search(4) != nullptr) {
        cout << "Key found!" << endl;
    } 
    else {
        cout << "Key not found :(" << endl;
    }
    cout << "=============================" << endl;
    cout << endl;
}

void testHashMapTreeAccess() {
    cout << "Testing HashMapTree search" << endl;
    cout << "=============================" << endl;
    HashMapTree<int, int> map;
    map.insert(2,6);
    map.insert(6,3);
    map.insert(2,4);
    map.insert(22, 7);
    map.insert(1, 14);
    map.insert(3, 90);
    map.insert(11, 14);
    map.printMap();

    cout << "Value with key 2 = " << map[2] << endl;

    cout << "=============================" << endl;
    cout << endl;
}