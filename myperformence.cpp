#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include "Set.cpp"

using namespace std;

// Function to generate random integers
int* generateRandomArray(long size, int min, int max) {
    int* array = new int[size];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);

    for (long i = 0; i < size; ++i) {
        array[i] = dist(gen);
    }

    return array;
}

// Measure HashMap operations
void measure_hashmap_operations(const vector<long>& sizes, int min_val, int max_val, const string& output_file) {
    vector<tuple<long, double, double, double>> results;

    for (long size : sizes) {
        cout << "Processing size: " << size << endl;
        int* data = generateRandomArray(size, min_val, max_val);

        // Calculate capacity as size / 10
        int capacity = size / 10;
        if (capacity == 0) capacity = 1; // Ensure capacity is at least 1

        //Create HashMap;
        Set<int> hset(capacity);

        // Measure insertion time
        cout << "Inserting..." << endl;
        auto start_insert = chrono::high_resolution_clock::now();
        for (long i = 0; i < size; ++i) {
            hset.insert(data[i]);
        }
        auto end_insert = chrono::high_resolution_clock::now();
        chrono::duration<double> insert_duration = end_insert - start_insert;
        cout << "Insertion time: " << insert_duration.count() << " seconds." << endl;

        // Measure deletion time
        cout << "Deleting..." << endl;
        long deletions = size / 10;
        mt19937 gen(random_device{}());
        uniform_real_distribution<> probability(0.0, 1.0);
        uniform_int_distribution<> index_dist(0, size - 1);

        auto start_delete = chrono::high_resolution_clock::now();
        for (long i = 0; i < size && deletions > 0; ++i) {
            if (probability(gen) < 0.5) {
                int key_to_remove = data[index_dist(gen)];
                if (hset.search(key_to_remove)) {
                    hset.remove(key_to_remove);
                    --deletions;
                }
            }
        }
        auto end_delete = chrono::high_resolution_clock::now();
        chrono::duration<double> delete_duration = end_delete - start_delete;
        cout << "Deletion time: " << delete_duration.count() << " seconds." << endl;

        // Measure search time
        cout << "Searching..." << endl;
        auto start_search = chrono::high_resolution_clock::now();
        for (long i = 0; i < size; ++i) {
            hset.search(data[index_dist(gen)]);
        }
        auto end_search = chrono::high_resolution_clock::now();
        chrono::duration<double> search_duration = end_search - start_search;
        cout << "Search time: " << search_duration.count() << " seconds." << endl;

        results.emplace_back(size, insert_duration.count(), delete_duration.count(), search_duration.count());
        delete[] data;
    }

     // Save results to a CSV file
    ofstream file(output_file);
    file << "Size,Insert Time (s),Delete Time (s),Search Time (s)\n";
    for (const auto& [size, insert_time, delete_time, search_time] : results) {
        file << size << "," << insert_time << "," << delete_time << "," << search_time << "\n";
    }
    file.close();
    cout << "Results saved to " << output_file << endl;
}

// Analyze HashMap slot distribution
void analyze_hashmap_distribution(const vector<long>& sizes, int min_val, int max_val, const string& slot_output_file) {
    ofstream file(slot_output_file);
    file << "Size,Slot,Count\n";

    for (long size : sizes) {
        cout << "Analyzing distribution for size: " << size << endl;

        int* data = generateRandomArray(size, min_val, max_val);

        // Calculate capacity dynamically as size / 10
        int capacity = size / 10;
        // Create a HashMap with calculated capacity
        Set<int> hset(capacity);

        // Insert elements into the hash map
        for (long i = 0; i < size; ++i) {
            hset.insert(data[i]);
        }

        // Get slot distribution
        vector<int> slot_counts = hset.count_elements_per_slot();

        // Write slot counts to file
        for (size_t i = 0; i < slot_counts.size(); ++i) {
            file << size << "," << i << "," << slot_counts[i] << "\n";
        }

        delete[] data;
    }
    file.close();
    cout << "Slot distribution results saved to " << slot_output_file << endl;
}



// Main function
int main() {
    vector<long> sizes = {100, 1000, 10000, 100000, 1000000};
    int min_val = 1, max_val = 1000000;

    string output_file = "hashset_performance.csv";
    string slot_output_file = "hashset_slot_distribution.csv";

    measure_hashmap_operations(sizes, min_val, max_val, output_file);
    analyze_hashmap_distribution(sizes, min_val, max_val, slot_output_file);

    return 0;
}
