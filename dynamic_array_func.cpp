#include "static_array_int.h"

using namespace std;

int dynamic_array_func(int static_a[HEIGHT][WIDTH], int dynamic_d[900]) // takes the static and the empty dynamic array as variables
{
   int n,m;                     // initialises 2 variables for the loops down below
   int dynamic_counter;         // initialises a counter to iterate through the elements
   dynamic_counter = 0;         // sets the counter to 0, so we begin with the first element

   for (n=0;n<HEIGHT;n++)       // runs through the static array's height
   {
       for (m=0;m<WIDTH;m++)    // runs through the static array's width
       {
           dynamic_d[dynamic_counter] = static_a[n][m];     // copied the element in the static array into the dynamic array at the position given by the counter
           dynamic_counter += 1;                            // increases the counter to iterate through the dynamic array
       }
   }
   return 0;
}
