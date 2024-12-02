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


main(){
    
    Set<int> hset;
    random_device rd;  // Non-deterministic random number generator
    mt19937 gen(rd()); // Mersenne Twister engine
    uniform_int_distribution<int> dist(1, 100); // Distribution for numbers between 1 and 100 (adjust as needed)

    int n = 100;
    //vector<int> randomNumbers(n);
    for (int i = 0; i < n; ++i) {
        //randomNumbers[i] = dist(gen);
        hset.insert(dist(gen));
    }



    hset.print();
}