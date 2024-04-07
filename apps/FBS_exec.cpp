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
const char projpath[128] = "C:\\Users\\sluec\\OneDrive\\Documents\\Code\\Projects\\FlightBookingSuggestor_v1";

/*  PROGRAM FUNCTIONS   */

// Will check terminal window for key input. If detected, function will call program exit routine.
// Can forced to call exit routine by passing "1" into the function
void    runtime_check( char override )
{
    if (_kbhit() || override)
    {
        // User input or override specified, exit program nicely
        cout << "User interrupt..." << endl;
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
    char    datapath[140];
    snprintf( datapath, sizeof(datapath), "%s\\data.csv", projpath );
    ifstream file(datapath); // Open the file named "data.csv"
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

    // Test inputs processing
    destination_config_t loc[6];
    loc[0].airport_icao = "KTPA";
    loc[1].airport_icao = "KICT";
    loc[2].airport_icao = "KMCI";
    loc[3].airport_icao = "KORD";
    loc[4].airport_icao = "KMCO";
    loc[5].airport_icao = "KTPA";

    for ( int i = 0; i < 6; i++ )
    {
        inp.locations.push_back(loc[i]);
    }
    return;
}

void    init()
{
// Program initialization function

    // Print confirmation that program is running
    cout    << "************************************" << endl
            << "*                                  *" << endl
            << "*         PROGRAM STARTED          *" << endl
            << "*                                  *" << endl
            << "************************************" << endl;

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
    cout    << "************************************" << endl
            << "*                                  *" << endl
            << "* PROGRAM EXITED, CELANUP FINISHED *" << endl
            << "*                                  *" << endl
            << "************************************" << endl;

    return;
}

int     main()
{
// Program main executable function
    tripgen_inputs_t inp;

    // Call init routine
    init();

    // Begin executing FBS main update code
    // Populate empty tripgen input structure with required data from user
    user_tripgen_inputs(inp);

    // Pass inputs to tripgen class
    tripgen->inputs(inp);
    cout << "Done with tripgen inputs..." << endl;

    // Begin tripgen update calls
    tripgen->oneway_gen();

    // Output the generated itineraries to terminal
    tripgen->outputs();

    // Close program nicely
    close();

    return 0;
}

