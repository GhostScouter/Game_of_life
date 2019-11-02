#include "static_array_int.h"

using namespace std;

int dynamic_array_func(int static_a[HEIGHT][WIDTH], int dynamic_d[900])
{
   int n,m;
   int dynamic_counter;
   dynamic_counter = 0;

   for (n=0;n<HEIGHT;n++)
   {
       for (m=0;m<WIDTH;m++)
       {
           dynamic_d[dynamic_counter] = static_a[n][m];
           dynamic_counter += 1;
       }
   }
   return 0;
}



