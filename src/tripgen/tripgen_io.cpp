/*

    Trip Generation I/O file. This is where all user input is gathered and transferred to public class members

*/

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
    return;
}