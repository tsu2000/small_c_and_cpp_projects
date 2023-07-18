#include <iostream>
#include <algorithm> 
#include <string>
#include <cctype>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

void quit() {
    cout << "Goodbye!" << endl;
    exit(0);
}

int main() {   
    // Initialise necessary variables and their types
    int numLower, numUpper, numDigits, numSymbols;

    cout << "Welcome to the Random Password Generator!\n";

    cout << "Input number of lowercase letters you want in your password: ";
    cin >> numLower;

    cout << "Input number of uppercase letters you want in your password: ";
    cin >> numUpper;

    cout << "Input number of digits you want in your password: ";
    cin >> numDigits;

    cout << "Input number of symbols/punctuation marks you want in your password: ";
    cin >> numSymbols;

    // Declare constants for types of characters
    const string ASCII_LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
    const string ASCII_UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string ASCII_DIGITS = "0123456789";
    const string ASCII_SYMBOLS = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    // Seed the random number generator with the current time
    srand(time(NULL));

    vector<char> lowercase;
    vector<char> uppercase;
    vector<char> digits;
    vector<char> symbols;

    for (int i = 0; i < numLower; i++) {
        int num = rand() % ASCII_LOWERCASE.size();
        char c = ASCII_LOWERCASE[num];
        lowercase.push_back(c);
    }
    for (int i = 0; i < numUpper; i++) {
        int num = rand() % ASCII_UPPERCASE.size();
        char c = ASCII_UPPERCASE[num];
        uppercase.push_back(c);
    }
    for (int i = 0; i < numDigits; i++) {
        int num = rand() % ASCII_DIGITS.size();
        char c = ASCII_DIGITS[num];
        digits.push_back(c);
    }
    for (int i = 0; i < numSymbols; i++) {
        int num = rand() % ASCII_SYMBOLS.size();
        char c = ASCII_SYMBOLS[num];
        symbols.push_back(c);
    }

    vector<char> concatenatedList;
    concatenatedList.insert(concatenatedList.end(), lowercase.begin(), lowercase.end());
    concatenatedList.insert(concatenatedList.end(), uppercase.begin(), uppercase.end());
    concatenatedList.insert(concatenatedList.end(), digits.begin(), digits.end());
    concatenatedList.insert(concatenatedList.end(), symbols.begin(), symbols.end());

    // Shuffle the concatenated list using a random device
    random_device rd;
    mt19937 g(rd());
    shuffle(concatenatedList.begin(), concatenatedList.end(), g);

    // Print the shuffled list
    cout << "Here is your password:\n";
    for (int i = 0; i < concatenatedList.size(); i++) {
        cout << concatenatedList[i];
    }
    cout << endl;

    string response;
    do {
        cout << "Another password? (Y/N): ";
        cin >> response;
        if (toupper(response[0]) == 'Y') {
            break;
        } else if (toupper(response[0]) == 'N') {
            quit();
        } else {
            cout << "Invalid response. Please enter Y or N." << endl;
        }
    } while (true);

    main();
    return 0;
}