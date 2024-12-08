#include <iostream>
#include <string> 
#include <fstream>
#include <map>
#include <list>

using namespace std;

int gen_hash_index(string);

int main() {
    
    // Initialize hash table
    map<int, list<string>> hash_table;

    // open up the txt file with the data strings to be read
    ifstream dataFile("lab-37-data.txt");
    string temp;

    // read in each string in file
    while(getline(dataFile, temp)) {
        // store total integer value using hash function
        int ascii_total = gen_hash_index(temp);
        // add the string into the list at the generated key value
        hash_table[ascii_total].push_back(temp);
    }

    // display the first 100 map entries
    int count = 0;

    // Loop through each map element 
    for (const auto & pair : hash_table) {
        // exit loop at 100 map entries
        if (count >= 100) 
            break;
        
        // display key value
        cout << "Map Entry #" << count + 1 << ":\n    Key: " << pair.first << " Value: ";

        // loop through and output each element in list
        for (const auto i : pair.second) {
            cout << i << ", ";
        }

        cout << endl;
        // increment count variable 
        count++;
    }

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/


int gen_hash_index(string s) {

    // create accumulator variable to store total values
    int ascciSum = 0;

    // loop through the string entered in the function
    for (char c : s) {
        // add each chars integer value into the accumulator 
        ascciSum += (int) c;
    }

    return ascciSum;
}





