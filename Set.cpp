#include<iostream>
#include "Set.hpp"
#include <random> // for testing

template <typename T>
Set<T>::Set(){
    HSetSize = hash.getCapacity();
    HSet.resize(HSetSize);
}

template <typename T>
Set<T>::Set(const Set<T>& other){
    HSetSize = other.HSetSize;
    HSet = other.HSet;
    hash = other.hash;
}

template <typename T>
Set<T>::~Set(){
    HSet.clear();
    HSet.shrink_to_fit();
}

template <typename T>
void Set<T>::print() const{
    cout << "\n***Hash Set***" << endl;
    for (int i = 0; i < HSet.size(); i++){
        cout << "Index " << i << ": { ";
        for (int j = 0; j < HSet[i].size(); j++){
            cout << HSet[i][j] << " ";
        }
        cout << "}" << endl;
    }
}

template <typename T>
void Set<T>::insert(const T& value){
    int index = hash.getHash(value);
    auto& chain = HSet[index];
    if(chain.empty()){
        chain.push_back(value);
    }
    else{
        for (auto i = chain.begin(); i != chain.end(); i++){
            if(*i == value){
                cout << value << " is already in hash set" << endl;
                break;
            }
            else{
                i++;
                if(*i == value){
                    cout << value << " is already in hash set" << endl;;
                    break;
                }
                else{
                    chain.push_back(value);
                    break;
                }
            }
        }
    }
}

template <typename T>
void Set<T>::remove(const T& value){
    int index = hash.getHash(value);
    auto& chain = HSet[index];
}

template <typename T>
bool Set<T>::search(const T& value){
    int index = hash.getHash(value);
    auto& chain = HSet[index];
    if (chain.empty()){
        return false;
    }
    else{
        for (auto i = chain.begin(); i != chain.end(); i++){
            if (*i == value){
                return true;
            }
        }
    }
    return false;
}


main(){

    Set<int> hset;
    random_device rd;  // Non-deterministic random number generator
    mt19937 gen(rd()); // Mersenne Twister engine
    uniform_int_distribution<int> dist(1, 100); // Distribution for numbers between 1 and 100 (adjust as needed)

    int n = 60;
    vector<int> randomNumbers(n);
    vector<int> wrongNumbers(n);
    for (int i = 0; i < n; ++i) {
        randomNumbers[i] = dist(gen);
        hset.insert(randomNumbers[i]);
    }

    hset.print();

    for (int i = 0; i < n; i++){
        //n = dist(gen);
        wrongNumbers[i] = randomNumbers[i]*-1;
        n = randomNumbers[i];
        cout << "Searching for " << n << "... ";
        if(hset.search(n)){
            cout << "FOUND" << endl;
        }
        else{
            cout << "NOT_FOUND" << endl;
        }
    }

        for (int i = 0; i < n; i++){
        //n = dist(gen);
        int m = wrongNumbers[i];
        cout << "Searching for " << m << "... ";
        if(hset.search(m)){
            cout << "FOUND" << endl;
        }
        else{
            cout << "NOT_FOUND" << endl;
        }
    }


}