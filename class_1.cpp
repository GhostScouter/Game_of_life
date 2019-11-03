#include "class_1.h"

using namespace std;

zellulaerer_automat::zellulaerer_automat()
{

}

int zellulaerer_automat::feldgroese(int a)
{
    int height = a;
    int width = 30;

    bool while_groese = false;
    int input_feldaenderung;

    cout << "Wenn sie keine Änderungen an der Feldgröße vernehmen wollen, wird die mit den Standartwerten" << height << "höhe" << width << "breite belegt.\n";
    cout << "Höhe verändern(1).\n";
    cout << "Breite verändern(2)\n";
    cout << "Höhe und Breite verändern(3)\n";
    cout << "nichts verandern(4)\n";
    while (while_groese == false)
    {
        cin >> input_feldaenderung;
        if (input_feldaenderung == 1)
        {
            cout << "neue Höhe\n";
            cin >> height;
            while_groese = true;
        }
        else if (input_feldaenderung == 2)
        {
            while_groese = true;
        }
        else if (input_feldaenderung == 3)
        {
            while_groese = true;
        }
        else if (input_feldaenderung == 4)
        {
            while_groese = true;
        }
        else
        {
            cout << "Ungültige Eingabe\n";
        }
    }
}

int zellulaerer_automat::setze_feld()
{

}

int zellulaerer_automat::veraendere_feld()
{

}

int zellulaerer_automat::evolution()
{

}
