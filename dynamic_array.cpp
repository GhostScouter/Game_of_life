#include "static_array_int.h"

using namespace std;

int dynamic_array_out(int dynamic_d[900])   // will print the dynamic array, is given a dynamic array
{
   int n,m;                     // initialises 2 variables for the loops down below
   int dynamic_counter;         // variable that iterates through the array
   dynamic_counter = 0;         // starts at 0 since the first element is 0

   for (n=0;n<HEIGHT;n++)       // goes through the array's height
   {
       for (m=0;m<WIDTH;m++)    // goes through the array's height
       {
           cout << dynamic_d[dynamic_counter] << " ";   // prints the current element
           dynamic_counter += 1;                        // increases the counter to interate to the next element
       }
       cout << endl;                                    // ends the line for a "matrix like view"
   }
   return 0;
}
