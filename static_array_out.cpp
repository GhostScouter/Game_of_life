#include "static_array_int.h"

using namespace std;

int static_array_out(int static_a[HEIGHT][WIDTH])
{
   int n,m;

   for (n=0;n<HEIGHT;n++)
   {
       for (m=0;m<WIDTH;m++)
       {
           cout << static_a[n][m] << " ";
       }
   cout << endl;
   }
   return 0;
}
