/*

    Utility cpp file for various common functions

*/
#include "util.h"

#include <iostream>

using namespace std;

// Calculates the factorial of an integer
unsigned int factorial( int n )
{
    if ( n < 0 )
    {
        cout << "Negative factorial detected, returning 0 value" << endl;
        return 0;
    }
    else
    {
        int f = n;
        for ( int i = 1; i < n; i++ )
        {
            f *= i;
        }
        return f;
    }
}

/*!
 * @brief Swaps one character in a string for another in the same string
 *
 * @param to    Index in string to swap TO
 * @param from  Index in string to swap FROM
 * @param op_string Address of string to be modified
 * 
 * @return Returns void. op_string is modified at return of this function
 *
 */
void swap_str_char( unsigned int to, unsigned int from, string &op_string )
{

    char xfr[2];
    xfr[0] = op_string.at(to);
    xfr[1] = op_string.at(from);
    op_string[to] = xfr[1];
    op_string[from] = xfr[0];

    return;
}