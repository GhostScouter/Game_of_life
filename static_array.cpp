 #include "static_array_int.h"

using namespace std;

int static_array_func(int static_a[HEIGHT][WIDTH])
{
    int n,m;

    srand (time(NULL));

    for (n=0;n<HEIGHT;n++)
    {
        for (m=0;m<WIDTH;m++)
        {
            static_a[n][m] = rand() % 10;
        }
    }
    return 0;
}



