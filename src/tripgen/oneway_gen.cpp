/*

    Trip generation utilizing only one-way flights

*/

#include <string>

#include "tripgen_obj.h"
#include "util/util.h"

using namespace std;

void    tripgen_obj_t::oneway_gen( void )
{
    const string type_id = "OW";                               ///< One-way specific type identifier
    
    const unsigned int num_dest = this->locations.size();            ///< Total number of stops, including the starting location 

    // For one-way generation, there are (n-2)! possible options
    // Ex.  6 stops (including start and end stop) have 4! = 24 possible trip options with one-way flights
    const unsigned int trip_count = factorial( num_dest - 2 );      ///< Number of possible trips

    /* ONE-WAY ITINERARY STRING FORMAT
     *
     *    2-letter type ID
     *    |  4-letter ICAO code, Depart
     *    |  |  Year offset from current year 
     *    |  |  | Day offset from current day (0-366)
     *    |  |  | |  4-letter ICAO code, Arrive
     *    |  |  | |  |
     *    /\/--\|/-\/--\
     *   "OWKTPAYDDDKICT-OWKICTYDDDKTPA-..."
     */

    vector<string> icao_combos;
    string icao_str = "";
    for ( unsigned int i = 0; i < num_dest; i++ )
    {
        icao_str += this->locations[i].airport_icao;        // Create the first string of airport codes
    }
    

    for ( unsigned int i = 0; i < 2; i++ )
    {
        
        icao_str += this->start_loc.airport_icao;
        icao_str += this->locations[i+1].airport_icao;
        icao_combos.push_back(icao_str);
    }

    for ( unsigned int i = 0; i < trip_count; i++ )      // Find all possible permutations of routes
    {


        string itin = "";                           ///< Current itinerary string
        itin += type_id;                            // Start with type ID
        itin += this->start_loc.airport_icao;       // Add depart location ICAO
        itin += this->start_loc.year_offset[DEP];   // Add depart year offset
        itin += this->start_loc.day_offset[DEP];    // Add depart day offset
        


        
    }
    return;
}