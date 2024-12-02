#include <iostream>
#include <cassert>
#include "HashMapTree.hpp"
#include "HashMap.cpp"
#include "DoublyLinkedList.cpp"
#include <chrono>
#include <vector>
#include <random>
#include <map>
#include "customexceptions.hpp"
#include <fstream>
#include "Set.hpp"
using namespace std;

int testsPassed = 0;
int testsFailed = 0;

// Function to handle assertions
void assertTest(bool condition, const string& testName) {
    if (condition) {
        testsPassed++;
        cout << "[PASS] " << testName << endl;
    } else {
        testsFailed++;
        cout << "[FAIL] " << testName << endl;
    }
}

// Function to print summary of test results
void printTestSummary() {
    cout << "\n--- Test Summary ---" << endl;
    cout << "Tests Passed: " << testsPassed << endl;
    cout << "Tests Failed: " << testsFailed << endl;
    if (testsFailed == 0) {
        cout << "All tests passed!" << endl;
    } else {
        cout << "Some tests failed. Please review the failed cases." << endl;
    }
}

void hashMap_testDefaultConstructor() {
    cout << "\nRunning testDefaultConstructor:" << endl;
    HashMap<int, int> hashMap;

    assertTest(hashMap.getSize() == 0, "Default Constructor: Size is 0");
    assertTest(hashMap.getCapacity() == 10, "Default Constructor: Capacity is 10");

    hashMap.print();
}

void hashMap_testCopyConstructor() {
    cout << "\nRunning testCopyConstructor:" << endl;

    HashMap<int, int> hashMap;
    hashMap.insert(1, 10);
    hashMap.insert(2, 20);

    HashMap<int, int> copy(hashMap);

    assertTest(copy.getSize() == 2, "Copy Constructor: Size matches");
    assertTest(copy[1] == 10, "Copy Constructor: Key 1 value matches");
    assertTest(copy[2] == 20, "Copy Constructor: Key 2 value matches");

    copy.print();
}

void hashMap_testAssignmentOperator() {
    cout << "\nRunning testAssignmentOperator:" << endl;

    HashMap<int, int> hashMap;
    hashMap.insert(1, 10);
    hashMap.insert(2, 20);

    HashMap<int, int> assigned;
    assigned = hashMap;

    assertTest(assigned.getSize() == 2, "Assignment Operator: Size matches");
    assertTest(assigned[1] == 10, "Assignment Operator: Key 1 value matches");
    assertTest(assigned[2] == 20, "Assignment Operator: Key 2 value matches");

    assigned.print();
}

void hashMap_testInsert() {
    cout << "\nRunning testInsert:" << endl;

    HashMap<int, int> hashMap;
    hashMap.insert(1, 10);
    hashMap.insert(2, 20);
    hashMap.insert(11, 30); // Collision with 1 if capacity = 10

    assertTest(hashMap.getSize() == 3, "Insert: Size matches");
    assertTest(hashMap[1] == 10, "Insert: Key 1 value matches");
    assertTest(hashMap[2] == 20, "Insert: Key 2 value matches");
    assertTest(hashMap[11] == 30, "Insert: Key 11 value matches");

    hashMap.print();
}

void hashMap_testRemove() {
    cout << "\nRunning testRemove:" << endl;

    HashMap<int, int> hashMap;
    hashMap.insert(1, 10);
    hashMap.insert(2, 20);

    pair<int, int>* element = hashMap.search(1);
    hashMap.remove(element);

    assertTest(hashMap.getSize() == 1, "Remove: Size decreases");
    assertTest(hashMap.search(1) == nullptr, "Remove: Key 1 is removed");

    hashMap.print();
}

void hashMap_testSearch() {
    cout << "\nRunning testSearch:" << endl;

    HashMap<int, int> hashMap;
    hashMap.insert(1, 10);
    hashMap.insert(2, 20);

    pair<int, int>* result = hashMap.search(1);
    assertTest(result != nullptr, "Search: Key 1 found");
    assertTest(result->second == 10, "Search: Key 1 value matches");

    result = hashMap.search(3);
    assertTest(result == nullptr, "Search: Key 3 not found");

    hashMap.print();
}

void hashMap_testOperatorAccess() {
    cout << "\nRunning testOperatorAccess:" << endl;

    HashMap<int, int> hashMap;
    hashMap[1] = 10;
    hashMap[2] = 20;

    assertTest(hashMap[1] == 10, "Operator[]: Key 1 value matches");
    assertTest(hashMap[2] == 20, "Operator[]: Key 2 value matches");

    hashMap.print();
}

void testHashMapTreeInsert() {
    cout << "Testing HashMapTree insertion" << endl;
    cout << "=============================" << endl;
    HashMapTree<int, int> map;
    map.insert(2,6);
    map.insert(6,3);
    
    HashMapTree<int, int> map2(map);
    
    assertTest(map.getSize() == 2, "Copy Constructor: Size matches");
    assertTest(map[2] == 6, "Copy Constructor: Key 1 value matches");
    assertTest(map[6] == 3, "Copy Constructor: Key 2 value matches");

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

    assertTest(map.getSize() == 3, "Copy Constructor: Size matches");
    assertTest(map[5] == 18, "Copy Constructor: Key 1 value matches");
    assertTest(map[9] == 10, "Copy Constructor: Key 2 value matches");


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

    pair<int, int>* result = map.search(2);
    assertTest(result != nullptr, "Search: Key 2 found");
    assertTest(result->second == 4, "Search: Key 2 value matches");

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

    assertTest(map[22] == 7, "Key Matches");

    cout << "Value with key 2 = " << map[2] << endl;

    cout << "=============================" << endl;
    cout << endl;
}




template <typename K, typename V>
vector<pair<K, V>> generateRandomData(size_t n, K keyRange, V valueRange) {
    vector<pair<K, V>> data;
    mt19937 gen(random_device{}());
    uniform_int_distribution<K> keyDist(1, keyRange);
    uniform_int_distribution<V> valueDist(1, valueRange);

    for (size_t i = 0; i < n; ++i) {
        data.emplace_back(keyDist(gen), valueDist(gen));
    }
    return data;
}

template <typename K, typename V>
double benchmarkInsertion(HashMapTree<K, V>& hashMap, const vector<pair<K, V>>& data) {
    auto start = chrono::high_resolution_clock::now();
    for (const auto& kv : data) {
        hashMap.insert(kv.first, kv.second);
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double>(end - start).count();
}

template <typename K, typename V>
double benchmarkDeletion(HashMapTree<K, V>& hashMap, size_t numDeletions) {
    auto start = chrono::high_resolution_clock::now();
    mt19937 gen(random_device{}());
    uniform_real_distribution<> probDist(0.0, 1.0);
    uniform_int_distribution<K> keyDist(1, 1000000);

    while (numDeletions > 0) {
        double prob = probDist(gen);
        if (prob < 0.5) {  // 50% probability to delete
            K randomKey = keyDist(gen);
            try {
                // Attempt to remove a random key
                hashMap.remove(randomKey);
                --numDeletions;  // Decrease deletion counter if successful
            } catch (const value_not_in_hashmap& e) {
                // Handle cases where key doesn't exist
                // No need to do anything, just skip deletion attempt
            } catch (const empty_tree_exception& e) {
                // Handle cases where the table is empty
                break;
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double>(end - start).count();
}

template <typename K, typename V>
double benchmarkSearch(HashMapTree<K, V>& hashMap, size_t numSearches, const vector<pair<K, V>>& data) {
    auto start = chrono::high_resolution_clock::now();
    mt19937 gen(random_device{}());
    uniform_int_distribution<size_t> indexDist(0, data.size() - 1);

    for (size_t i = 0; i < numSearches; ++i) {
        auto kv = data[indexDist(gen)];
        try {
            // Attempt to search for the random key
            hashMap.search(kv.first);
        } catch (const value_not_in_hashmap& e) {
            // Handle cases where the key doesn't exist
        }
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double>(end - start).count();
}



void hashset_testInsert() {
    cout << "\nTesting Hash Set insert" << endl;
    Set<int> hset;
    hset.insert(3);
    hset.insert(10);
    hset.insert(3);
    hset.insert(13);
    hset.insert(25);
    hset.print();

    assertTest(hset.HSet[3][0] == 3, "insert value 3");
    assertTest(hset.HSet[3][1] == 13, "insert resulting in set with chaining");
    assertTest(hset.HSet[1].empty(), "empty set for non inserted value");
    assertTest(hset.HSet[5][0] == 25, "insert value 25");
}

void hashset_testRemove() {
    cout << "\nTesting Hash Set remove" << endl;
    Set<int> hset;
    hset.insert(4);
    hset.insert(14);
    hset.insert(34);
    hset.insert(56);
    hset.insert(25);

    hset.remove(14);
    hset.remove(56);
    hset.remove(4);
    hset.print();
    assertTest(hset.HSet[4][1] == 34, "Remove 14 test");
    assertTest(hset.HSet[6].empty(), "Remove 56 test");
    assertTest(hset.HSet[4][0] == 34, "Remove 4 test");
}

void hashset_testSearch() {
    cout << "\nTesting Hash Set search" << endl;
    Set<int> hset;
    hset.insert(3);
    hset.insert(10);
    hset.insert(3);
    hset.insert(13);
    hset.insert(25);
    hset.print();

    assertTest(hset.search(13), "search for 13");
    assertTest(hset.search(3), "search for 3");
    assertTest(!hset.search(4), "search for 4");
}






int main() {
    hashMap_testDefaultConstructor();
    hashMap_testCopyConstructor();
    hashMap_testAssignmentOperator();
    hashMap_testInsert();
    hashMap_testRemove();
    hashMap_testSearch();
    hashMap_testOperatorAccess();
    printTestSummary();

    testHashMapTreeInsert();
    testHashMapTreeRemove();
    testHashMapTreeSearch();
    testHashMapTreeAccess();
    printTestSummary();

    hashset_testInsert();
    hashset_testRemove();
    hashset_testSearch();
    printTestSummary();



    // vector<size_t> dataSizes = {100, 1000, 10000, 100000};
    // size_t keyRange = 1000000;  // Range for key values
    // size_t valueRange = 1000;   // Range for value values

    // ofstream outputFile("benchmark_results.csv");
    
    // // Write the CSV header
    // outputFile << "Size,Insert Time (s),Delete Time (s),Search Time (s)" << endl;

    // for (size_t size : dataSizes) {
    //     // Generate random data for each test
    //     auto data = generateRandomData<int, int>(size, keyRange, valueRange);

    //     // Create the hash map for testing
    //     HashMapTree<int, int> hashMap;

    //     // Benchmark insertion
    //     double insertTime = benchmarkInsertion(hashMap, data);

    //     // Benchmark deletion (remove n/10 elements)
    //     double deleteTime = benchmarkDeletion(hashMap, size / 10);

    //     // Benchmark search (search for n/10 elements)
    //     double searchTime = benchmarkSearch(hashMap, size / 10, data);

    //     // Output the benchmark results to the CSV file
    //     outputFile << size << "," 
    //                << insertTime << "," 
    //                << deleteTime << "," 
    //                << searchTime << endl;

    //     // Optionally, print results to the console
    //     cout << "Size: " << size
    //          << ", Insert: " << insertTime
    //          << "s, Delete: " << deleteTime
    //          << "s, Search: " << searchTime << "s\n";
    // }

    // // Close the CSV file
    // outputFile.close();



    return 0;
}