#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Here are the unit conversions available, and vice versa
// Feet and Inches to Meters and Centimeters
// Miles to Kilometers
// Pounds to Kilograms
// Celsius to Kelvin to Farenheit
// Square feet to square meters

bool is_valid_option(const int input) {
    // Check if the input string contains a valid integer
    return (input >= 1 && input <= 9);
}

// Function to read a double from the user and validate the input
double readDouble(const char str[]) {
    double result;
    while (1) {
        // Prompt to enter a value here using printf()
        printf("%s", str);

        // Check condition to break out of loop
        if (scanf("%lf", &result) == 1) {
            // Input was successfully read and stored in result, so return the value
            return result;
        } else {
            // Input was not a valid double value
            printf("Invalid input! Please enter a valid double value.\n");

            // Clear the input buffer to avoid an infinite loop in case of invalid input
            while (getchar() != '\n')
                continue;
        }
    }
}

// Function to read an integer from the user and validate the input
int readInt(const char str[]) {
    int result;
    while (1) {
        // Prompt to enter a value here using printf()
        printf("%s", str);

        // Check condition to break out of loop
        if (scanf("%d", &result) == 1) {
            // Input was successfully read and stored in result, so return the value
            return result;
        } else {
            // Input was not a valid double value
            printf("Invalid input! Please enter a valid integer value.\n");

            // Clear the input buffer to avoid an infinite loop in case of invalid input
            while (getchar() != '\n')
                continue;
        }
    }
}

// Specific functions for converting feet and inches to meters and centimeters
void feetInchesToMetersCentimeters(int feet, int inches, double *meters, double *centimeters) {
    double totalInches = (feet * 12) + inches;
    double totalMeters = totalInches * 0.0254;

    *meters = totalMeters; // Get value in meters
    *centimeters = totalMeters * 100; // Get value in centimeters
}

double metersCentimetersToFeetInches(double meters, int *feet, int *inches) {
    double totalInches = (meters * 100) / 2.54;
    *feet = (int)(totalInches / 12); // Extract the integer part of feet
    *inches = (int)(totalInches) % 12; // Extract the remainder as inches
    return totalInches;
}

// Main function begin
int main(void) {

    printf("\n* * * * WELCOME TO UNIT CONVERTER * * * *\n");
    printf("IMPORTANT NOTE: Make sure your units do not exceed 16 significant digits, for maximum precision\n");
    printf("1 - Feet (ft) and inches (in) to Meters (m) and centimeters (cm)\n");
    printf("2 - Meters (m) to Feet (ft) and inches (in)\n");
    printf("3 - Pounds (lb) to Kilograms (kg)\n");
    printf("4 - Kilograms (kg) to Pounds (lb)\n");
    printf("5 - Celsius (°C) to Farenheit (°F) and Kelvin (K)\n");
    printf("6 - Farenheit (°F) to Celsius (°C) and Kelvin (K)\n");
    printf("7 - Kelvin (K) to Celsius (°C) and Farenheit (°F)\n");
    printf("8 - Square feet (sq ft) to Square meters (sq m^2)\n");
    printf("9 - Square meters (sq m^2) to Square feet (sq ft)\n");

    int userInt;

    while (1) {
        printf("Enter an integer corresponding to the conversion option: ");

        if (scanf("%d", &userInt) != 1) {
            // Invalid input (not an integer)
            printf("Invalid input! Please enter a valid integer.\n");

            // Clear the input buffer to avoid an infinite loop
            while (getchar() != '\n')
                continue;

            continue;
        }

        // Check if the input is valid
        if (!is_valid_option(userInt)) {
            printf("Invalid input! Please enter a valid integer with a corresponding conversion option.\n");
            continue;
        } else {
            break;
        }
    }

    // Get user inputs
    double userInput = 0.0;

    double result;
    double result2;

    char buffer[50]; // Allocate a buffer to store the formatted result in string format
    char buffer2[50];

    int feet = 0;
    int inches = 0;
    double meters = 0.0;
    double centimeters = 0.0;

    switch(userInt) {
        case 1:
            printf("\nYou selected 1 - Feet (ft) and inches (in) to Meters (m) and centimeters (cm)\n");
            feet = readInt("Step 1/2: Enter height/length in feet (ft): ");
            inches = readInt("Step 2/2: Enter height/length in inches (in): ");
            printf("You entered: %d feet %d inches.\n", feet, inches);
            feetInchesToMetersCentimeters(feet, inches, &meters, &centimeters);
            printf("%d feet %d inches is equal to %.2lf meter(s) or %.2lf centimeter(s).\n", feet, inches, meters, centimeters);
            break;

        case 2:
            printf("\nYou selected 2 - Meters (m) to Feet (ft) and inches (in)\n");
            meters = readDouble("Enter height/length in meters (m): ");
            double totalInches = metersCentimetersToFeetInches(meters, &feet, &inches);
            printf("You entered: %.2lf meters or %.2lf centimeters\n", meters, meters * 100);
            printf("%.2lf meters is equal to %d feet and %d inches, or %.2lf total inches.\n", meters, feet, inches, totalInches);
            break;

        case 3:
            printf("\nYou selected 3 - Pounds (lb) to Kilograms (kg)\n");
            userInput = readDouble("Enter weight in pounds (lb): ");  // Call the function and check if the input is valid
            printf("You entered: %.2lf lbs.\n", userInput);           // Input was valid, print the input value
            result = userInput / 2.20462;                             // Get the result            
            sprintf(buffer, "%.2f", result);                          // Format the double value into the string buffer
            printf("This is equal to %s kg(s).\n", buffer);           // Print final result
            break;
            
        case 4:
            printf("\nYou selected 4 - Kilograms (kg) to Pounds (lb)\n");
            userInput = readDouble("Enter weight in kilograms (kg): ");  // Call the function and check if the input is valid
            printf("You entered: %.2lf lbs.\n", userInput);              // Input was valid, print the input value
            result = userInput * 2.20462;                                // Get the result            
            sprintf(buffer, "%.2f", result);                             // Format the double value into the string buffer
            printf("This is equal to %s kg(s).\n", buffer);              // Print final result
            break;

        case 5:
            printf("\nYou selected 5 - Celsius (°C) to Farenheit (°F) and Kelvin (K)\n");
            userInput = readDouble("Enter temperature in degrees Celsisus (°C): ");
            printf("You entered: %.2lf degrees Celsius (°C).\n", userInput);              
            result = (userInput * (9.0/5.0)) + 32;
            result2 = userInput + 273.15;                                
            sprintf(buffer, "%.2f", result);
            sprintf(buffer2, "%.2f", result2);                             
            printf("This is equal to %s degrees Farenheit (°F).\n", buffer);       
            printf("This is equal to %s Kelvin (K).\n", buffer2);       
            break;

        case 6:
            printf("\nYou selected 6 - Farenheit (°F) to Celsius (°C) and Kelvin (K)\n");
            userInput = readDouble("Enter temperature in degrees Farenheit (°F): ");
            printf("You entered: %.2lf degrees Farenheit (°F).\n", userInput);              
            result = (userInput - 32) * (5.0/9.0);
            result2 = result + 273.15;                                
            sprintf(buffer, "%.2f", result);
            sprintf(buffer2, "%.2f", result2);                     
            printf("This is equal to %s degrees Celsius (°C).\n", buffer);       
            printf("This is equal to %s Kelvin (K).\n", buffer2);    
            break;

        case 7:
            printf("\nYou selected 7 - Kelvin (K) to Celsius (°C) and Farenheit (°F)\n");
            userInput = readDouble("Enter temperature in Kelvin (K): ");
            printf("You entered: %.2lf Kelvin (K).\n", userInput);              
            result = userInput - 273.15;
            result2 = (result * (9.0/5.0)) + 32;                                
            sprintf(buffer, "%.2f", result);
            sprintf(buffer2, "%.2f", result2);                     
            printf("This is equal to %s degrees Celsius (°C).\n", buffer);       
            printf("This is equal to %s degrees Farenheit (°F).\n", buffer2);    
            break;

        case 8:
            printf("\nYou selected 8 - Square feet (sq ft) to Square meters (sq m^2)\n");
            userInput = readDouble("Enter area in square feet (sq ft): ");  
            printf("You entered: %.2lf sqft.\n", userInput);           
            result = userInput / 10.7639;                                       
            sprintf(buffer, "%.2f", result);                        
            printf("This is equal to %s square meters (sq m^2).\n", buffer);   
            break;

        case 9:
            printf("\nYou selected 9 - Square meters (sq m^2) to Square feet (sq ft)\n");
            userInput = readDouble("Enter area in square meters (sq m^2): ");  
            printf("You entered: %.2lf sqm^2.\n", userInput);           
            result = userInput * 10.7639;                                       
            sprintf(buffer, "%.2f", result);                        
            printf("This is equal to %s square feet (sq ft).\n", buffer);  
            break;

        default:
            printf("Not a valid selection");
    }

    while(1) {
        
        char againResponse;
        printf("\nAnother new conversion? (Y/N): ");
        scanf(" %c", &againResponse);

        // Clear the input buffer (discard any remaining characters, including the newline)
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ; // Empty loop body

        if (againResponse == 'Y' || againResponse == 'y') {
            main();
        } else if (againResponse == 'N' || againResponse == 'n') {
            break;
        } else {
            continue;
        }
    
    }
    
    return 0;
}
