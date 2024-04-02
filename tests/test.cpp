#include <conio.h>
#include <iostream>
#include <string>
#include <vector>

#include "util/util.h"

using namespace std;

void getch_test( void);
void vector_test( void);

int main()
{

    string test;

    test = "123456789";

    swap_str_char(0,3, test);

    cout << test << endl;

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