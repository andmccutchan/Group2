#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <map>
#include <chrono>
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
// Measures insertion performance
//=========================================================
template <typename HashMap>
double measureInsertion(HashMap& map, const vector<pair<int, string>>& dataSet) {
    auto start = chrono::high_resolution_clock::now();
    for (const auto& pair : dataSet) {
        map.insert(pair.first, pair.second);
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}

//=========================================================
// Measures deletion performance
//=========================================================
template <typename HashMap>
double measureDeletion(HashMap& map, const vector<pair<int, string>>& dataSet, size_t n) {
    size_t numDeletions = n / 10;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> probDist(0.0, 1.0);

    auto start = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < numDeletions; ++i) {
        if (probDist(gen) < 0.5) { // Delete with 50% probability
            int keyToDelete = dataSet[i % n].first;
            pair<int, string> toDelete(keyToDelete, "");
            try {
                map.remove(&toDelete);
            } catch (const exception& e) {
                // Handle errors silently for non-existent keys
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}

//=========================================================
// Measures search performance
//=========================================================
template <typename HashMap>
double measureSearch(HashMap& map, const vector<pair<int, string>>& dataSet, size_t n) {
    size_t numSearches = n / 10;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> keyDist(1, n * 10);

    auto start = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < numSearches; ++i) {
        int keyToSearch = keyDist(gen);
        map.search(keyToSearch);
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}

//=========================================================
// Main function to measure insertion, deletion, and search
//=========================================================
int main() {
    vector<size_t> dataSizes = {100, 1000, 10000, 100000};
    cout << "Performance of HashMap Operations:\n";
    cout << "-----------------------------------\n";
    cout << "Size\tInsertion(ms)\tDeletion(ms)\tSearch(ms)\n";

    for (size_t n : dataSizes) {
        auto dataSet = generateDataSet(n);

        HashMap<int, string> map;
        double insertionTime = measureInsertion(map, dataSet);
        double deletionTime = measureDeletion(map, dataSet, n);
        double searchTime = measureSearch(map, dataSet, n);

        cout << n << "\t" << insertionTime << "\t\t" << deletionTime << "\t\t" << searchTime << "\n";
    }

    return 0;
}
//g++ -std=c++20 -o performance performance.cpp HashMap.cpp
