#pragma once
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

template <typename T>
class Bag
{
public:
    Bag();               // empty bag
    void insert(T item); // POST: insert item into bag
    T remove();          // PRE: bag is not empty
                         // POST: remove random item from bag
    int size() const;    // POST: return number of items in bag
    bool empty() const;  // POST: return empty status of bag
private:
    vector<T> bag;
};

template <typename T>
Bag<T>::Bag() // empty bag
{
    srand(time(NULL)); // Seed randomizer
}

template <typename T>
void Bag<T>::insert(T item) // POST: insert item into bag
{
    bag.push_back(item);
}

template <typename T>
T Bag<T>::remove()                     // PRE: bag is not empty
{                                      // POST: remove random item from bag

    int randInd = rand() % bag.size(); // Random index of vector

    T retElement = bag[randInd];      // Store element in variable
    bag.erase(bag.begin() + randInd); // Remove element, shrink bag by one

    return retElement; // Return stored element
}

template <typename T>
int Bag<T>::size() const // POST: return number of items in bag
{
    return bag.size();
}

template <typename T>
bool Bag<T>::empty() const // POST: return empty status of bag
{
    return bag.empty();
}
