#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <array>
#include <string>
#include "bag.h"

using namespace std;

// POST: Bag is filled with employee names from files
void loadNames(Bag<string> &employeeBag, vector<string> &employees,
               string file1, string file2);

// Comparator for sortNames
bool compareAlpha(string a, string b);

// POST: Names are alphabetically sorted
void sortNames(vector<string> &names);

// Checks if vector contains a string
bool vectorHas(vector<string> &employees, string query);

/**
 * @brief Reads files of employee names and builds a randomized
 * secret santa list by pairing names
 */
int main()
{
    vector<string> employees; // Vector of names
    Bag<string> employeeBag;  // Bag of employee names
    string file1, file2;

    // Get filenames
    // cout << "Enter first store filename: ";
    // cin >> file1;
    // cout << "Enter second store filename: ";
    // cin >> file2;
    // cout << endl;

    file2 = "bangor.txt";
    file1 = "brewer.txt";

    // Load and sort names from user specified files
    loadNames(employeeBag, employees, file1, file2);
    sortNames(employees);

    // Output name pairs
    string gifter, giftee, rejectedName;

    gifter = employees[0];
    giftee = employeeBag.remove();
    for (int i = 1; i < (int)employees.size()-1; i++)
    {
        if (gifter == giftee) // if person is paired with themself
        {
            rejectedName = giftee;            // Store employee name
            giftee = employeeBag.remove();    // Grab new name
            employeeBag.insert(rejectedName); // Put stored name back
        }

        // Output valid pair
        cout << setw(13) << left
             << gifter << " "
             << giftee << '\n';

        // Set next names
        gifter = employees[i];
        giftee = employeeBag.remove();
    }

    return 0;
}

// POST: Bag is filled with employee names from files
void loadNames(Bag<string> &employeeBag, vector<string> &employees,
               string file1, string file2)
{
    const int numFiles = {2};
    string files[numFiles] = {file1, file2};
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

            if (!vectorHas(employees, str))
            {
                employeeBag.insert(str);
                employees.push_back(str);
            }
            fileIn >> str;
        }

        fileIn.close();
    }
}

// Comparator for sortNames
bool compareAlpha(string a, string b)
{
    return a[0] < b[0];
}

// POST: Names in given vector are alphabetically sorted
void sortNames(vector<string> &names)
{
    sort(names.begin(), names.end(), compareAlpha);
}

// Checks if vector contains a string
bool vectorHas(vector<string> &employees, string query)
{
    if (find(employees.begin(), employees.end(), query) == employees.end() ||
        employees.back() == query)
        return false;
    else
        return true;
}