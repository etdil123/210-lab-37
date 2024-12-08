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
void addHash(map<int, list<string>> &, string);
void removeHash(map<int, list<string>> &, string);
void modifyHash(map<int, list<string>> &, string, string);

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
                // use addHash to enter user inputted string into hash table
                addHash(hash_table, addKey);
                break;
            }
            // Remove a key
            case 4: {
                string removeKey;
                cout << "Please enter key you would like to be removed: " << endl;
                cin >> removeKey;
                // use removeHash to remove user inputted value from hash table if it is in the hash table
                removeHash(hash_table, removeKey);
                break;
            }
            // Modify a key
            case 5: {
                string modifyKey;
                string newKey;
                cout << "Please enter key you would like to be modified: " << endl;
                cin >> modifyKey;

                cout << "Please enter value you would like to replace: " << endl;
                cin >> newKey;
                // use modifyHash to adjust value of modifyKey to the value of newKey
                modifyHash(hash_table, modifyKey, newKey);
                break;
            }
            
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

// gen_hash_index takes in a string, calculates the sum of ASCII value and returns total integer value
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
// mainMenu displays menu option to user and returns back which number the user selected
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
// display_entries returns no value - takes in a hash_table and iterates through to print out first 100 entries
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
// searchHash returns no value - searches through hash_table and looks for a user inputted string
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

void addHash(map<int, list<string>> &hash_table, string addString) {

    // Use hash function to calculate hash index
    int hashIndex = gen_hash_index(addString);

     // add the string into the list at the generated key value
    hash_table[hashIndex].push_back(addString);

    // display to user that value has been added
    cout << addString << " has been added in hash table with hash index " << hashIndex << endl;
}

void removeHash(map<int, list<string>> &hash_table, string removeString) {

    // use hash function to calculate hash index 
    int hashIndex = gen_hash_index(removeString);

    // search hash table to see if hashIndex exists
    auto searchMap = hash_table.find(hashIndex);

    // search through hash_table looking for hashIndex - if found loop through list
    if (searchMap != hash_table.end()) {
        // Create iterator to move through the list from beginning 
        for (auto it = hash_table[hashIndex].begin() ; it != hash_table[hashIndex].end(); ) {
            if (*it == removeString) {
                // erase value if removeString is found
                it = hash_table[hashIndex].erase(it);
                cout << removeString << " has been removed from hash table!" << endl;
                return;
            }
            // increment pointer if item was not found
            else 
                ++it;
        }

        // If string has not been found print to user that it cannot be removed
        cout << removeString << " cannot be removed - value was not found in hash table!" << endl;

    }
    // if it doesn't exist - value isn't in hash table and cannot be removed
    else
        cout << removeString << " cannot be removed - value was not found in hash table!" << endl;
}

void modifyHash(map<int, list<string>> & hash_table, string oldString, string modifyString) {

    // use hash function to calculate hash index 
    int hashIndex = gen_hash_index(oldString);

    // search hash table to see if hashIndex exists
    auto searchMap = hash_table.find(hashIndex);

    // search through hash_table looking for hashIndex - if found loop through list
    if (searchMap != hash_table.end()) {
        // Create iterator to move through the list from beginning 
        for (auto it = hash_table[hashIndex].begin() ; it != hash_table[hashIndex].end(); ) {
            if (*it == oldString) {
                // erase value if removeString is found
                it = hash_table[hashIndex].erase(it);

                // get new calculated hash index for the modified string
                int newHashIndex = gen_hash_index(modifyString);

                // Insert the new string into hash table
                hash_table[newHashIndex].push_back(modifyString);
                
                cout << modifyString << " has modified the value of " << oldString << "!" << endl;
                return;
            }
            // increment pointer if item was not found
            else 
                ++it;
        }
        
        // If old string cannot be found, display to user it cannot be modified
        cout << oldString << " cannot be modified - value was not found in hash table!" << endl;

    }
    // if it doesn't exist - value isn't in hash table and cannot be modified
    else
        cout << oldString << " cannot be modified - value was not found in hash table!" << endl;
}