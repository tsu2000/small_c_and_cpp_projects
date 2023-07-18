#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <limits>
#include <iomanip>

using namespace std;

void quit() {
    cout << "Goodbye!" << endl;
    exit(0);
}

// Future & Present Value
float presentValue(float fv, float i, float n) {
    return fv / pow(1 + i/100, n);
}

float futureValue(float pv, float i, float n) {
    return pv * pow(1 + i/100, n);
}

// Ordinary Annuity - Future & Present Value
float presentValueOrdinaryAnnuity(float pmt, float i, float n) {
    return pmt * 1/(i/100) * (1 - (1 / pow((1 + (i/100)), n)));
}

float futureValueOrdinaryAnnuity(float pmt, float i, float n) {
    return pmt * 1/(i/100) * (pow(1 + i/100, n) - 1);
}
    
// Annuity Due - Future & Present Value
float presentValueAnnuityDue(float pmt, float i, float n) {
    return presentValueOrdinaryAnnuity(pmt, i, n - 1) + pmt;
}

float futureValueAnnuityDue(float pmt, float i, float n) {
    return presentValueOrdinaryAnnuity(futureValue(pmt, i, n), i, n) * (1 + i/100);
}

// Get prompts from function
tuple<float, float, float> userPrompts(string calcType, string valType) {
    float baseAmt;
    float interest;
    float numPeriods;

    cout << "You have chosen: " << calcType << "\n";

    // Get base amount from user
    do {
        cout << "Enter the " << valType << ": ";
        if (cin >> baseAmt) {
            break;
        } else {
            cout << "Invalid input. Please choose an appropriate value for the " << valType << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);

    // Get interest rate from user
    do {
        cout << "Enter the interest rate (in %): ";
        if (cin >> interest) {
            break;
        } else {
            cout << "Invalid input. Please choose an apprioriate value.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);

    // Get number of periods from user
    do {
        cout << "Enter the number of periods: ";
        if (cin >> numPeriods && numPeriods >= 1) {
            break;
        } else {
            cout << "Invalid input. Please choose a number greater than 0.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);

    return make_tuple(baseAmt, interest, numPeriods);
}

int main() {
    cout << "\n* * * WELCOME TO C++ FINANCE CALCULATOR * * *\n";

    cout << "Select a value to compute by typing the corresponding number:\n";
    cout << "1 - Present Value\n";
    cout << "2 - Future Value\n";
    cout << "3 - Present Value of an Ordinary Annuity\n";
    cout << "4 - Future Value of an Ordinary Annuity\n";
    cout << "5 - Present Value of an Annuity Due\n";
    cout << "6 - Future Value of an Annuity Due\n"; 
    cout << "\n";

    int option;
    do {
        cout << "Select the calculation you wish to compute (1 - 6): ";
        if (cin >> option && option >= 1 && option <= 6) {
            break;
        } else {
            cout << "Invalid input. Please select a calculation using the assigned integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);

    float result;

    if (option == 1) {
        tuple<float, float, float> inputs = userPrompts("Present Value", "future value");
        result = presentValue(get<0>(inputs), get<1>(inputs), get<2>(inputs));
    } else if (option == 2) {
        tuple<float, float, float> inputs = userPrompts("Future Value", "present value");
        result = futureValue(get<0>(inputs), get<1>(inputs), get<2>(inputs));
    } else if (option == 3) {
        tuple<float, float, float> inputs = userPrompts("Present Value of an Ordinary Annuity", "periodic payment");
        result = presentValueOrdinaryAnnuity(get<0>(inputs), get<1>(inputs), get<2>(inputs));
    } else if (option == 4) {
        tuple<float, float, float> inputs = userPrompts("Future Value of an Ordinary Annuity", "periodic payment");
        result = futureValueOrdinaryAnnuity(get<0>(inputs), get<1>(inputs), get<2>(inputs));
    } else if (option == 5) {
        tuple<float, float, float> inputs = userPrompts("Present Value of an Annuity Due", "periodic payment");
        result = presentValueAnnuityDue(get<0>(inputs), get<1>(inputs), get<2>(inputs));
    } else {
        tuple<float, float, float> inputs = userPrompts("Future Value of an Annuity Due", "periodic payment");
        result = futureValueAnnuityDue(get<0>(inputs), get<1>(inputs), get<2>(inputs));
    };

    cout << "Result: " << fixed << setprecision(2) << result << endl;

    // Prompt user for another simulation
    string response;
    do {
        cout << "\nAnother result? (Y/N): ";
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