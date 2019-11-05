#include "static_array_int.h"

using namespace std;

int static_array_out(int static_a[HEIGHT][WIDTH])   // will print the static array, is given a static array
{
   int n,m;                                         // 2 running variables

   for (n=0;n<HEIGHT;n++)                           // iterates through the array's height
   {
       for (m=0;m<WIDTH;m++)                        // iterates through the array's width
       {
           cout << static_a[n][m] << " ";           // prints the current element
       }
   cout << endl;                                    // ends the line for a "matrix like view"
   }
   return 0;
}
