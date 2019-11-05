 #include "static_array_int.h"

using namespace std;

int static_array_func(int static_a[HEIGHT][WIDTH])      // fills a static array with random integers, is given a array as a variable
{
    int n,m;        // initialises 2 variables to iterate with down below

    srand (time(NULL));         // part of the random function, which secures that our random number are truly random

    for (n=0;n<HEIGHT;n++)      // iterates through the height
    {
        for (m=0;m<WIDTH;m++)   // iterates through the width
        {
            static_a[n][m] = rand() % 10;       // creates a random number from 0 to 9 and puts it into the static array
        }
    }
    return 0;
}



