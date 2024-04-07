#include <conio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "tripgen/tripgen_obj.h"
#include "util/util.h"

using namespace std;

void getch_test( void);
void vector_test( void);

int main()
{

    string test;

    test = "KTPAKICTKSFOKJFK";

    vector<string> icao_combos;
    string icao_str = test;

    
    icao_combos.push_back("KICT");
    icao_combos.push_back("KICT");
    icao_combos.push_back("KICT");
    icao_combos.push_back("KICT");
    //icao_combos.push_back(test);

    //cout << find(icao_combos.begin(), icao_combos.end(), icao_str) << endl;
    cout << (find(icao_combos.begin(), icao_combos.end(), icao_str) != icao_combos.end()) << endl;

    cout << factorial( 6 - 2 ) << endl;
    cout << factorial(4) << endl;

    return 0;
}

void vector_test()
{
    vector<string> test;
    test.push_back("This is line1");
    test.push_back("Now this is line 2");

    cout << test[0][2] << endl;
    
}

void getch_test()
{
    int test = 0;
    int count = 0;


    for ( int i=0; i< 10000; i++)
    {
        if (_kbhit()) test = _getch();

        if (test != 0) 
        {
            cout << "LOOP BROKEN" << endl;
            break;
        }
    }

    cout << "test:  " << test << endl;
}