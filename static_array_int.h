#ifndef STATIC_ARRAY_INT_H
#define STATIC_ARRAY_INT_H

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30    // width of the static list (main.cpp, l. 22)
#define HEIGHT 30   // height of the static list (main.cpp, l. 22)



int static_array_func(int static_a[HEIGHT][WIDTH]);
int static_array_out(int static_a[HEIGHT][WIDTH]);
int dynamic_array_func(int static_a[HEIGHT][WIDTH], int dynamic_d[900]);
int dynamic_array_out(int dynamic_d[900]);




#endif // STATIC_ARRAY_INT_H
