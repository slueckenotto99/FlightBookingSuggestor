/*

    Trip Generation I/O file. This is where all user input is gathered and transferred to private class members

*/

// System hookups
#include "tripgen_obj.h"

void    tripgen_obj_t::inputs( tripgen_inputs_t &inp )
{
    // Pass input structure to class members
    this->in = inp;
}

void    tripgen_obj_t::outputs()
{
    
}