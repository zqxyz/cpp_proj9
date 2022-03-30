#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bag.h"

using namespace std;

// POST: Bag is filled with employee names from files
void loadNames(Bag<string> employees);

int main()
{
    // vector<string> employees;

    Bag<string> employees;
    employees.insert("fart");
    employees.insert("mart");
    employees.insert("shart");
    employees.insert("shopping cart");

    while (!employees.empty())
    {
        cout << employees.remove() << endl;
    }

    return 0;
}