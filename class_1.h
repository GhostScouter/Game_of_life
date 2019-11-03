#include <iostream>
#ifndef CLASS_1_H
#define CLASS_1_H



class zellulaerer_automat
{
private:

    int *koor_feld_alt;
    int *koor_feld_neu;

    int groese;
    int neue_hoehe;
    int neue_breite;


public:
    zellulaerer_automat();

    int feldgroese();
    int setze_feld();
    int veraendere_feld();
    int evolution();
    int zeige_feld();

    ~zellulaerer_automat();


};

#endif // CLASS_1_H
