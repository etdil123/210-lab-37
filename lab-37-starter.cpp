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
    int count = 0;

    // read in each string in file
    while(getline(dataFile, temp)) {
        // use sum_ascii function and increment into accumulator variable
        count += gen_hash_index(temp);
    }

    cout << "Grand Total: " << count << endl;

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





