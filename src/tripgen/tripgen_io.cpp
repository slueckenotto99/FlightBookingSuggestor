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

    for ( int i = 0; i < this->locations.size(); i++ )        // Filter through locations and find start/end location
    {
        if ( this->locations[i].is_starting_point )     start_loc   = this->locations[i];
        else if ( this->locations[i].is_initial_cond )  end_loc     = this->locations[i];
    }
    return;
}

void    tripgen_obj_t::outputs()
{
    return;
}