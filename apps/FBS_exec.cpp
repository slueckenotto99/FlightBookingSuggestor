/*

    Flight Booking Suggestor main executable

*/

// Library hookups
#include <conio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <new>

// System hookups
#include "FBS_obj.h"

/*  GLOBAL DECLARATIONS */
using namespace std;

/*  PROGRAM FUNCTIONS   */

// Will check terminal window for key input. If detected, function will call program exit routine.
// Can forced to call exit routine by passing "1" into the function
void    runtime_check( char override )
{
    if (_kbhit() || override)
    {
        // User input or override specified, exit program nicely
        close();
    }
    return;
}
void    runtime_check()
{
    runtime_check(0);
    return;
}
void    user_tripgen_inputs( tripgen_inputs_t &inp)
{
    ifstream file("data.csv"); // Open the file named "data.csv"
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    while (getline(file, line)) { // Read lines from the file
        istringstream iss(line);
        string token;

        while (getline(iss, token, ',')) { // Parse line into tokens separated by commas
            cout << token << endl; // Print each token
        }
    }

    file.close(); // Close the file
    return;
}

void    init()
{
// Program initialization function

    // Allocate memory for FBS class objects
    tripgen = new tripgen_obj_t;

    // Perform class-specific inits
    tripgen->init();

    runtime_check();
    return;
}

void    close()
{
// Program closing function

    // Perform class-specific close functions
    tripgen->close();

    // Deallocate memory for FBS class objects
    delete tripgen;

    // Print confirmation that program exited nicely
    cout    << "************************************"
            << "*                                  *"
            << "* PROGRAM EXITED, CELANUP FINISHED *"
            << "*                                  *"
            << "************************************";

    return;
}

int     main()
{
// Program main executable function
    tripgen_inputs_t inp;

    // Call init routine
    init();

    // Begin executing FBS main update code
    // Populate empty input structure with required data from user
    



    return 0;
}

