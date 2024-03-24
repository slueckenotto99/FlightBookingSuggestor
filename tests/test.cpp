#include <conio.h>
#include <iostream>

using namespace std;

int main()
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


    return 0;
}