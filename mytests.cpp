#include <iostream>
#include "HashMap.cpp"
#include "DoublyLinkedList.cpp"
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

int main() {
    hashMap_testDefaultConstructor();
    hashMap_testCopyConstructor();
    hashMap_testAssignmentOperator();
    hashMap_testInsert();
    hashMap_testRemove();
    hashMap_testSearch();
    hashMap_testOperatorAccess();
    printTestSummary();
    return 0;
}
