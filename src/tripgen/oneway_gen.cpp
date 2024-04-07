/*

    Trip generation utilizing only one-way flights

*/

#include <string>
#include <iostream>

#include "tripgen_obj.h"
#include "util/util.h"

using namespace std;


/*!
 *  @brief Given a string of ICAO codes, swaps ICAO A with ICAO B
 *
 *  @param A u_int representing which ICAO code to swap (First code is 1)
 *  @param B u_int representing which ICAO code to swap (First code is 1)
 *  @param  work_str Working string to swap ICAO inside
 */
void    swap_icao( unsigned int A, unsigned int B, string &work_str )
{
    char valid = ( A > 0U ) &&
                 ( B > 0U ) &&
                 ( A <= work_str.length() / ICAO_LEN ) &&
                 ( B <= work_str.length() / ICAO_LEN ) &&
                 ( A != B );
    if (!valid) return;         // Check if inputs are valid for given string

    if ( A > B )                // Ensure A is the lower integer
    {
        unsigned int tmp = B;
        B = A;
        A = tmp;
    }
    unsigned int starti[2];
    starti[0] = ICAO_LEN * A - ICAO_LEN;
    starti[1] = ICAO_LEN * B - ICAO_LEN;
    for ( unsigned int i = 0; i < ICAO_LEN; i++ )
    {
        swap_str_char(starti[0] + i, starti[1] + i, work_str);
    }

    return;
}

/*!
 *  @brief Given a string of ICAO codes, shifts each ICAO right or left. ICAO codes at start or end will loop back to opposite side of string
 *
 *  @param direction negative int goes left, positive goes right
 *  @param  work_str Working string to shift ICAO inside
 */
void    shift_icao( int direction, string &work_str )
{
    char valid = ( work_str.length() > ICAO_LEN * 2 -1 ) &&
                 ( direction != 0 );
    if (!valid) return;         // Check if inputs are valid for given string

    const int len = work_str.length();
    const int num_icao = len / ICAO_LEN;
    int x[2], y;
    string tmp_icao = "";
    direction = direction < 0 ? -1 : 1;
    switch ( direction )
    {
        case -1:    // LEFT
            x[0] = ICAO_LEN;
            x[1] = ICAO_LEN * (num_icao - 1);
            y    = ICAO_LEN;
            break;
        default:
        case 1:     // RIGHT
            x[0] = ICAO_LEN * (num_icao - 1);
            x[1] = ICAO_LEN;
            y    = ICAO_LEN * (num_icao - 1);
            break;
    }

    tmp_icao += work_str.substr(x[0], x[1]);
    tmp_icao += work_str.substr(0, y);
    work_str = tmp_icao;

    return;
}
/*!
 *  @brief Given a string of ICAO codes, shifts each ICAO right. ICAO codes at start or end will loop back to opposite side of string
 *
 *  @param  work_str Working string to shift ICAO inside
 */
void    shift_icao( string &work_str )
{
    shift_icao( 1, work_str);
    return;
}

void    tripgen_obj_t::oneway_gen( void )
{
    const string type_id = "OW";                                        ///< One-way specific type identifier
    const unsigned int num_dest = this->locations.size();               ///< Total number of stops, including the start/end locations
    cout << num_dest << " is the total number of destinations" << endl;
    const string start_icao = this->locations[0].airport_icao;          ///< Start location ICAO code
    const string end_icao = this->locations[num_dest-1].airport_icao;     ///< End location ICAO code

    // For one-way generation, there are (n-2)! possible options
    // Ex.  6 stops (including start and end stop) have 4! = 24 possible trip options with one-way flights
    unsigned int trip_count = factorial( num_dest - 2 );      ///< Number of possible trips
    cout << trip_count << " is the number of unique one-way trips" << endl;

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

    vector<string> icao_combos;             ///< Temp vector to store trip combinations
    string icao_str = "";                   ///< Temp string to store icao values
    string icao_mid = "";                   ///< Temp string to store a trip with start/end locations removed
    string packet_str = "";                 ///< Temp string to store single oneway packet
    int oneway_loop = trip_count - 1;       ///< Oneway generator loop logic tracker

    for ( unsigned int i = 0; i < num_dest; i++ )
    {
        icao_str += this->locations[i].airport_icao;        // Create the first string of airport codes
    }

    icao_combos.push_back(icao_str);        // Store first trip string

    while ( oneway_loop > 0 )               // When oneway_loop hits zero, we know that all possible trips have been created
    {
        static int sanity_check = 0;        // Sanity check counter to exit while loop if insane amount of loops take place
        static int swap_check = 3;          // Incrementing ICAO position swap variable

        
        icao_mid = icao_str.substr( ICAO_LEN, ICAO_LEN * num_dest - (2 * ICAO_LEN) );     // Strip start/end loations from trip string
        if (swap_check > num_dest - 1 ) 
        {
            shift_icao(icao_mid);           // Right-shift all ICAO codes by 1 to shuffle positions in string
            swap_check = 3;                 // Reset position swap variable to begin trying all combinations of swaps again
        }
        swap_icao(num_dest - 2, num_dest - swap_check, icao_mid);   // Swap last ICAO with current swap position iteration
        icao_str = start_icao + icao_mid + end_icao;                // Add start/end ICAO to get full trip string
        if ( find(icao_combos.begin(), icao_combos.end(), icao_str) == icao_combos.end() )  // Generated string is not yet saved in ICAO combo vector
        {
            icao_combos.push_back(icao_str);        // Store unique generated trip string
            oneway_loop--;                          // Decrement oneway loop tracker
            swap_check = 3;                         // Reset position swap variable to begin trying all combinations of swaps again
        }
        else                                                                                // Generated string already exists
        {
            swap_icao(num_dest - 2, num_dest - swap_check, icao_mid);   // Undo swap changes 
            icao_str = start_icao + icao_mid + end_icao;                // Add start/end ICAO to get full trip string
            swap_check++;                                               // Increment swap variable to try a new combination next iteration
        }
        if (sanity_check > 100000) // Exit while loop in case code is bad
        {
            oneway_loop = -1;  
            cout << "While Loop code is bad, code is INSANE" << endl;
        }
        sanity_check++;
    }


    for ( auto it : icao_combos )
    {
        for ( int i = 0; i < num_dest - 1; i++ )
        {
            if ( !packet_str.empty() ) packet_str += "-";           // Add hyphen separator
            packet_str += type_id;                                  // Add 'OW' packet identifier
            packet_str += it.substr(i*ICAO_LEN, ICAO_LEN);          // Add departure ICAO
            packet_str += "YDDD";                                   // Add date identifier
            packet_str += it.substr((i+1)*ICAO_LEN, ICAO_LEN);      // Add arrival ICAO
        }
        this->itineraries.push_back(packet_str);                    // Add fully formed trip to list of itineraries
        packet_str = "";                                            // Clear packet string
    }

    return;
}