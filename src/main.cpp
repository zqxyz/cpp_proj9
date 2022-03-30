#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include "bag.h"

using namespace std;

// POST: Bag is filled with employee names from files
void loadNames(Bag<string> &employeeBag, vector<string> &employees);

// Comparator for sortNames
bool compareAlpha (string a, string b);

// POST: Names are alphabetically sorted
void sortNames(vector<string> &names);

/**
 * @brief Reads files of employee names and builds a randomized
 * secret santa list by pairing names
 */
int main()
{
    vector<string> employees; // Vector of names
    Bag<string> employeeBag;  // Bag of employee names

    loadNames(employeeBag, employees);
    sortNames(employees);

    // while (!employeeBag.empty())
    // {
    //     cout << employeeBag.remove() << endl;
    // }

    for (int i = 0; i < employees.size(); i++)
    {
        cout << employees[i] + '\n';
    }

    return 0;
}

// POST: Bag is filled with employee names from files
void loadNames(Bag<string> &employeeBag, vector<string> &employees)
{
    const int numFiles = {2};
    string files[numFiles] = {"bangor.txt", "brewer.txt"};
    ifstream fileIn;

    // One loop per file
    for (int i = 0; i < numFiles; i++)
    {
        string file = files[i];
        fileIn.open(file);
        if (!fileIn) // Abort on failure
        {
            cerr << "Could not open " << file << endl;
        }

        string str;    // temp string var
        fileIn >> str; // load first name

        while (!fileIn.fail()) // Loop until nothing left to read
        {
            fileIn >> str;
            employeeBag.insert(str);
            employees.push_back(str);
        }

        fileIn.close();
    }
}

// Comparator for sortNames
bool compareAlpha (string a, string b)
{
    return a[0] < b[0];
}

// POST: Names in given vector are alphabetically sorted
void sortNames(vector<string> &names)
{
    sort(names.begin(), names.end(), compareAlpha);
}