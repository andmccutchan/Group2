#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <map>
#include "HashMap.cpp"
#include "DoublyLinkedList.cpp"

using namespace std;

//=========================================================
// Function to generate a random data set of key-value pairs
//=========================================================
vector<pair<int, string>> generateDataSet(size_t n) {
    vector<pair<int, string>> dataSet;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> keyDist(1, n * 10);
    uniform_int_distribution<int> charDist(0, 25);

    for (size_t i = 0; i < n; ++i) {
        string value(5, 'a');
        for (auto& c : value) {
            c = 'a' + charDist(gen);
        }
        dataSet.emplace_back(keyDist(gen), value);
    }
    return dataSet;
}

//=========================================================
// Analyzes hash function by plotting bucket distribution
//=========================================================
template <typename HashMap>
void measureHashFunction(size_t n) {
    auto dataSet = generateDataSet(n);
    HashMap map;

    // Insert all elements into the hash map
    for (const auto& pair : dataSet) {
        map.insert(pair.first, pair.second);
    }

    // Create a map to count elements in each bucket
    std::map<size_t, size_t> bucketCounts;

    for (const auto& pair : dataSet) {
        size_t bucketIndex = map.hashFunction.getHash(pair.first) % 10; // Assuming 10 buckets
        bucketCounts[bucketIndex]++;
    }

    // Print bucket distribution
    cout << "Bucket Distribution for n=" << n << ":\n";
    for (size_t i = 0; i < 10; ++i) {
        cout << "Bucket " << i << ": " << bucketCounts[i] << " elements\n";
    }
    cout << "--------------------------------\n";
}

//=========================================================
// Main function to run bucket distribution tests for all n
//=========================================================
int main() {
    vector<size_t> dataSizes = {100, 1000, 10000, 100000};

    for (size_t n : dataSizes) {
        measureHashFunction<HashMap<int, string>>(n);
    }

    return 0;
}
//g++ -std=c++20 -o graph graph.cpp HashMap.cpp