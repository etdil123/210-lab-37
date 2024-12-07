#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

int sum_ascii(string);

int main() {
    // char a = 'A';
    // cout << a << endl;
    // cout << (int) a << endl;
    // int b = 66;
    // cout << b << endl;
    // cout << (char) b << endl;

    // open up the txt file with the data strings to be read
    ifstream dataFile("lab-37-data.txt");
    string temp;
    int count = 0;

    // read in each string in file
    while(getline(dataFile, temp)) {
        // use sum_ascii function and increment into accumulator variable
        count += sum_ascii(temp);
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


int sum_ascii(string s) {

    // create accumulator variable to store total values
    int ascciSum = 0;

    // loop through the string entered in the function
    for (char c : s) {
        // add each chars integer value into the accumulator 
        ascciSum += (int) c;
    }

    return ascciSum;
}





