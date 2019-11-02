#include "static_array_int.h"

using namespace std;

int dynamic_array_out(int dynamic_d[900])
{
   int n,m;
   int dynamic_counter;
   dynamic_counter = 0;

   for (n=0;n<HEIGHT;n++)
   {
       for (m=0;m<WIDTH;m++)
       {
           cout << dynamic_d[dynamic_counter] << " ";
           dynamic_counter += 1;
       }
       cout << endl;
   }
   return 0;
}



