#include <iostream>
#include <fstream>
#include <ios>
#ifndef CLASS_1_H
#define CLASS_1_H
#define CONVERT_ASCII 48



class zellulaerer_automat // name of the class which will be key for our program and run the automat
{
private:                // defining various variables for class-wide use

    char *koor_feld_alt; // this is the field on which the evolution will be applied to
    char *koor_feld_neu; // this is the output field

    std::string koor_feld_out;

    int groese;         // standard array size for evol.automat, only for dialogue purposes
    int neue_hoehe;     // heigth of our 2-d array
    int neue_breite;    // width of our 2-d array


public:     // public funtions to operate with

    zellulaerer_automat();  //

    int feldgroese();       // custominzing the array size
    int setze_feld();       // manual input of each cell
    int veraendere_feld();  // specific cell value changing
    int evolution();        // the main part =)
    int zeige_feld();       // prints the array
    int export_field();
    int import_field();

    ~zellulaerer_automat(); // deconstructor


};

#endif // CLASS_1_H
