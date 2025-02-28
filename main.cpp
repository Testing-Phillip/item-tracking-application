//Author: Phillip Gooden
//Date: 02/23/25


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;

// case-insensitive comparisons.
string toLowerCase(const string &str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

// Class: ItemTracker
// Description: Manages item frequency data by loading from a file, processing item counts,
//              printing frequencies and histograms, and backing up data.
class ItemTracker {
private:
    map<string, int> frequencyMap;  // Stores item frequencies (keys are in lowercase).

    // Helper: Adds a word to the frequency map.
    void addWord(const string &word) {
        frequencyMap[toLowerCase(word)]++;
    }

public:
    // Loads data from the specified file into the frequency map.
    // Returns true if successful, false otherwise.
    bool loadData(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        string word;
        while (file >> word) {
            addWord(word);
        }
        file.close();
        return true;
    }

    // Returns the frequency of a specific item (case-insensitive).
    int getFrequency(const string &item) const {
        string lowerItem = toLowerCase(item);
        auto it = frequencyMap.find(lowerItem);
        return (it != frequencyMap.end()) ? it->second : 0;
    }

    // Prints the frequency of all items to the console.
    void printFrequencies() const {
        for (const auto &pair : frequencyMap) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Prints a histogram of item frequencies to the console with aligned asterisks.
    void printHistogram() const {
        const int columnWidth = 15;  // Adjust width as needed for alignment.
        for (const auto &pair : frequencyMap) {
            cout << setw(columnWidth) << left << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Backs up the frequency data to the specified file.
    // Returns true if the backup was successful, false otherwise.
    bool backupData(const string &backupFileName) const {
        ofstream backup(backupFileName);
        if (!backup.is_open()) {
            return false;
        }
        for (const auto &pair : frequencyMap) {
            backup << pair.first << " " << pair.second << endl;
            if (backup.fail()) {
                backup.close();
                return false;
            }
        }
        backup.close();
        return true;
    }
};

int main() {
    // Absolute path to the input file.
    const string inputFile = "Project3/CS210_Project_Three_Input_File.txt.txt";

    // Create an ItemTracker instance and load data from the input file.
    ItemTracker tracker;
    if (!tracker.loadData(inputFile)) {
        cerr << "Error: Unable to open file '" << inputFile << "'." << endl;
        return 1;
    }

    // Create a backup file named "frequency.dat" at program startup.
    if (!tracker.backupData("frequency.dat")) {
        cerr << "Error: Unable to create backup file 'frequency.dat'." << endl;
        return 1;
    } else {
        cout << "Backup file 'frequency.dat' created successfully." << endl;
    }

    // Main program loop to handle user menu options.
    int menuOption;
    bool running = true;
    while (running) {
        // Menu
        cout << "\nCorner Grocer Item Tracking Program" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Search for an item frequency" << endl;
        cout << "2. Display frequency of all items" << endl;
        cout << "3. Display histogram of item frequencies" << endl;
        cout << "4. Exit the program" << endl;
        cout << "Enter your menu option (1-4): ";

        // Validation
        if (!(cin >> menuOption)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        // Process the menu selection.
        switch (menuOption) {
            case 1: {
                // Option 1: Search for the frequency of a specific item.
                string searchWord;
                cout << "Enter the item to search for: ";
                cin >> searchWord;
                int frequency = tracker.getFrequency(searchWord);
                cout << "The frequency of '" << toLowerCase(searchWord) << "' is: " << frequency << endl;
                break;
            }
            case 2:
                // Option 2: Display all item frequencies.
                cout << "\nItem Frequencies:" << endl;
                cout << "-----------------" << endl;
                tracker.printFrequencies();
                break;
            case 3:
                // Option 3: Display a histogram of item frequencies.
                cout << "\nHistogram of Item Frequencies:" << endl;
                cout << "------------------------------" << endl;
                tracker.printHistogram();
                break;
            case 4:
                // Option 4: Exit the program.
                cout << "Exiting program." << endl;
                running = false;
                break;
            default:
                cout << "Invalid menu option. Please try again." << endl;
                break;
        }
    }
    return 0;
}
