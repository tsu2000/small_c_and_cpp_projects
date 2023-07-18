#include <iostream>
#include <algorithm> 
#include <string>
#include <vector>
#include <random>

using namespace std;

void quit() {
    cout << "Goodbye!" << endl;
    exit(0);
};

// Function to simulate a coin flip
void coinFlip(int numIterations) {
    // Set up random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 1);

    int headsCount = 0;
    int tailsCount = 0;

    // Flip the coin the specified number of times
    for (int i = 1; i <= numIterations; i++) {
        int result = dist(gen);
        if (result == 0) {
            cout << "Roll " << i << ": " << "Heads" << endl;
            headsCount++;
        } else {
            cout << "Roll " << i << ": " << "Tails" << endl;
            tailsCount++;
        }
    }

    // Calculate output percentages
    double headsPercent = (double)headsCount / numIterations * 100;
    double tailsPercent = (double)tailsCount / numIterations * 100;
    cout << "Heads count: " << headsCount << ", Percentage: " << headsPercent << " %" << endl;
    cout << "Tails count: " << tailsCount << ", Percentage: " << tailsPercent << " %" << endl;
}

// Function to simulate dice rolls
void diceRoll(int numIterations) {
    // Initialise weights and outcomes
    const vector<string> choices = {"1⚀", "2⚁", "3⚂", "4⚃", "5⚄", "6⚅"};
    const vector<double> weights = {1, 1, 1, 1, 1, 1};
 
    // Set up random number generator
    random_device rd;
    mt19937 gen(rd());
    discrete_distribution<> dist(weights.begin(), weights.end());

    int count_1 = 0, count_2 = 0, count_3 = 0;
    int count_4 = 0, count_5 = 0, count_6 = 0;

    // Roll the dice the specified number of times
    for (int i = 1; i <= numIterations; i++) {
        string result = choices[dist(gen)];
        cout << "Roll " << i << ": " << result << endl;

        // Add to counts
        if (result == "1⚀") {
            count_1++;
        } else if (result == "2⚁") {
            count_2++;
        } else if (result == "3⚂") {
            count_3++;
        } else if (result == "4⚃") {
            count_4++;
        } else if (result == "5⚄") {
            count_5++;
        } else if (result == "6⚅") {
            count_6++;
        }
    }

    // Calculate output percentages
    double count1percent = (double)count_1 / numIterations * 100;
    double count2percent = (double)count_2 / numIterations * 100;
    double count3percent = (double)count_3 / numIterations * 100;
    double count4percent = (double)count_4 / numIterations * 100;
    double count5percent = (double)count_5 / numIterations * 100;
    double count6percent = (double)count_6 / numIterations * 100;
    cout << "* * * RESULTS * * *" << endl;
    cout << "1⚀ count: " << count_1 << ", Percentage: " << count1percent << " %" << endl;
    cout << "2⚁ count: " << count_2 << ", Percentage: " << count2percent << " %" << endl;
    cout << "3⚂ count: " << count_3 << ", Percentage: " << count3percent << " %" << endl;
    cout << "4⚃ count: " << count_4 << ", Percentage: " << count4percent << " %" << endl;
    cout << "5⚄ count: " << count_5 << ", Percentage: " << count5percent << " %" << endl;
    cout << "6⚅ count: " << count_6 << ", Percentage: " << count6percent << " %" << endl;

}

// Function to generate a random event based on weights
int main() {
    int choice;

    cout << "~ ~ ~ Welcome to C++ Simulations! Choose a simulation: ~ ~ ~" << endl
         << "1. Coin Flip" << endl
         << "2. Dice Rolling" << endl
         << "Enter a number: ";
    cin >> choice;

    int numIter;
    cout << "How many iterations would you like? ";
    cin >> numIter;

    if (choice == 1) {
        coinFlip(numIter);
    } else if (choice == 2) {
        diceRoll(numIter);
    }

    string response;
    do {
        cout << "Another simulation? (Y/N): ";
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
};
