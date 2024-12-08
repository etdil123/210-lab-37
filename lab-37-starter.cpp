// Ethan Dilk | Lab 38 | COMSC 210
#include <iostream>
#include <string> 
#include <fstream>
#include <map>
#include <list>

using namespace std;

int gen_hash_index(string);
void display_entries(const map<int, list<string>>);
int mainMenu();
void searchHash(map<int, list<string>>, string);
void addHash(map<int, list<string>>, string);

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

    bool programRun = true;
    int userPick;
    // while loop to implemenet menu functionality
    while (programRun != false) {

        userPick = mainMenu();

        // switch case on user selected option
        switch (userPick)
        {
            // display first 100 entries
            case 1:
                cout << "Displaying first 100 entries: " << endl;
                display_entries(hash_table);
                break;
            // search for a key
            case 2: {
                string searchKey;
                cout << "Please enter key you would like to search for: " << endl;
                cin >> searchKey;
                // use searchHash to display if user inputted value is in hash table
                searchHash(hash_table, searchKey);
                break;
            }
            // add a key into hash table
            case 3: {
                string addKey;
                cout << "Please enter key you would like to be added: " << endl;
                cin >> addKey;


                break;
            }
            case 4:
                break;
            case 5:
                break;
            
            // end program
            case 6:
                programRun = false;
                cout << "Thank you for using hash table program!" << endl;
                break;

        };

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

int mainMenu() {

    int userOption;
    // string menu to display to user
    string menuDisplay = "\n** Hash Table Menu ** - Select an option below:\n[1] Print first 100 entries\n[2] Search for key\n[3] Add key\n[4] Remove key\n[5] Modify key\n[6] Exit program\n";

    cout << menuDisplay;
    cin >> userOption;

    // input validation - ensure user selects option between 1 and 6
    while (userOption < 1 || userOption > 6 ) {
        cout << "Please select valid menu option between 1 and 6" << endl;
        cout << menuDisplay;
        cin >> userOption;
    }

    return userOption;
}

void display_entries(const map<int, list<string>> hash_table) {
    // constant 
    int ENTRIES = 100;

    // display the first 100 map entries
    int count = 0;

    // Loop through each map element 
    for (const auto & pair : hash_table) {
        // exit loop at 100 map entries
        if (count >= ENTRIES) 
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

}

void searchHash(map<int, list<string>> hash_table, string searchString) {

    // use hash function to calculate hash index 
    int hashIndex = gen_hash_index(searchString);

    // search hash table to see if hashIndex exists
    auto searchMap = hash_table.find(hashIndex);

    // search through hash_table looking for hashIndex - if found loop through list
    if (searchMap != hash_table.end()) {
        // iterate through list
        for (string & s : searchMap->second) {
            // If string is found print to user
            if (searchString == s) {
                cout << searchString << " was found in hash table with hash index " << hashIndex << endl;
                return;  
            }
        }
        
        // If string has not been found print to user it is not in hash table
        cout << searchString << " was not found in hash table!" << endl;

    }
    // if it doesn't exist - value isn't in hash table and return false
    else
        cout << searchString << " was not found in hash table!" << endl;
        
}

void addHash(map<int, list<string>> hash_table, string addString) {


    
}
