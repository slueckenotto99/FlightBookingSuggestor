/*

    Utility cpp file for various common functions

*/

#include <iostream>

using namespace std;

// Calculates the factorial of an integer
int factorial( int n )
{
    if ( n < 0 )
    {
        cout << "Negative factorial detected, returning 0 value" << endl;
        return 0;
    }
    else
    {
        int f = 0;
        for ( int i = 0; i < n; i++ )
        {
            f *= i;
        }
        return f;
    }
}