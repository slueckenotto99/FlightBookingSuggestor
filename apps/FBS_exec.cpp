/*

    Flight Booking Suggestor main executable

*/

#include <conio.h>
#include <iostream>
#include <new>

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

void    init()
{
// Program initialization function

    // Allocate memory for FBS class objects
    tripgen = new tripgen_obj_t;

    // Perform class-specific inits
    tripgen->init();

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
    cout    << "***********************************"
            << "*                                 *"
            << "* PROGRAM EXITED CELANUP FINISHED *"
            << "*                                 *"
            << "***********************************";

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

