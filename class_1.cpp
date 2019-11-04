#include "class_1.h"

using namespace std;

zellulaerer_automat::zellulaerer_automat()
{
    int *koor_feld_neu = new int[900];
    int *koor_feld_alt = new int[900];
}

int zellulaerer_automat::feldgroese()
{
    int groese = 900;

    bool while_groese = false;
    int input_feldaenderung;

    cout << "Wenn sie keine Aenderungen an der Feldgroese vernehmen wollen, wird ein Standartfeld der groese"<< groese<<"verwendet.\n";
    cout << "Hoehe und Breite veraendern(1)\n";
    cout << "nichts verandern(2)\n";

    while (while_groese == false)
    {
        cin >> input_feldaenderung;
        if (input_feldaenderung == 1)
        {
            while (true)
            {
                cout << "neue Hoehe\n";
                cin >> neue_hoehe;
                cout << "neue breite\n";
                cin >> neue_breite;
                if (neue_hoehe > 0 && neue_breite > 0)
                {
                    break;
                }
            }
            delete koor_feld_alt;
            koor_feld_alt = new int[(neue_hoehe*neue_breite)];

            while_groese = true;
        }
        else if (input_feldaenderung == 2)
        {
            while_groese = true;
            neue_hoehe = 30;
            neue_breite = 30;
        }
        else
        {
            cout << "Ungueltige Eingabe\n";
        }
    }
}

int zellulaerer_automat::setze_feld()
{
    int n,m;
    int zustand;

    for (n=0; n<neue_hoehe; n++)
    {
        for (m=0; m<neue_breite; m++)
        {
            cout << "soll Zelle " << n << " " << m << " Leben(1) oder Tod(0) sein\n";
            cin >> zustand;
            koor_feld_alt[(n*neue_breite +m)] = zustand;
        }

    }

}

int zellulaerer_automat::veraendere_feld()
{
    int height_change;
    int width_change;

    cout << "Welches Feld wollen sie ändern?\n";

    cin >> height_change >> width_change;

    koor_feld_alt[height_change*neue_breite+width_change] = (koor_feld_alt[height_change*neue_breite+width_change] +1) % 2;
}

int zellulaerer_automat::evolution()
{
    int n;

    for (n=0; n<(neue_hoehe*neue_breite); n++)
    {

    }
}

int zellulaerer_automat::zeige_feld()
{
    int n,m;

    for (n=0; n<neue_hoehe; n++)
    {
        for (m=0; m<neue_breite; m++)
        {
            cout << koor_feld_alt[(n*(neue_breite) +m)]<< " ";
        }
    cout << endl;
    }
}
zellulaerer_automat::~zellulaerer_automat()
{

}
