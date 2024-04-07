/*

    Trip Generation I/O file. This is where all user input is gathered and transferred to public class members

*/

#include <iostream>

// System hookups
#include "tripgen_obj.h"

void    tripgen_obj_t::inputs( tripgen_inputs_t &inp )
{
    // Pass input structure to class members
    this->in = inp;
    this->locations = this->in.locations;

    return;
}

void    tripgen_obj_t::outputs()
{
    // Print itineraries to terminal
    for ( auto it : this->itineraries )
    {
        static int count = 1;
        cout << count << ":\t" << it << endl;
        count++;
    }
    return;
}