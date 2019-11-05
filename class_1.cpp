#include "class_1.h"

using namespace std;

zellulaerer_automat::zellulaerer_automat()
{
    int *koor_feld_neu = new int[900];
    int *koor_feld_alt = new int[900];
}

int zellulaerer_automat::feldgroese()
{
    int groese = 900;               // standard field size, for dialogue purposes (line.18)

    bool while_groese = false;      // while-loop break variable
    int input_feldaenderung;        // user input variable defninition (l.24)

    cout << "Wenn sie keine Aenderungen an der Feldgroese vernehmen wollen, wird ein Standartfeld der groese"<< groese<<"verwendet.\n";
    cout << "Hoehe und Breite veraendern(1)\n";
    cout << "nichts verandern(2)\n";

    while (while_groese == false)       // initiates while-loop, to secure the user input
    {
        cin >> input_feldaenderung;     // user input on whether they like to change the array size or not
        if (input_feldaenderung == 1)   // they do
        {
            while (true)
            {
                cout << "neue Hoehe\n";     // dialogue about new width
                cin >> neue_hoehe;          // users new width
                cout << "neue breite\n";    // dialogue about new height
                cin >> neue_breite;         // users new height
                if (neue_hoehe > 0 && neue_breite > 0) // quick check on input
                {
                    break;                  // exits while-loop (l.27)
                }
            }
            delete koor_feld_alt;           // deletes the old field with old size
            koor_feld_alt = new int[(neue_hoehe*neue_breite)];  // initiates new one with new size

            while_groese = true;            // exits while-loop (l.22)
        }
        else if (input_feldaenderung == 2)  // if the user does not want to change the field size
        {
            while_groese = true;            // exits the while-loop (l.22)
            neue_hoehe = 30;                // sets default size values of 30x30
            neue_breite = 30;               //                "
        }
        else                                // if the user entered something else than 1 or 2 (l.24)
        {
            cout << "Ungueltige Eingabe\n"; // tells the user he did something stupid
        }
    }
}

int zellulaerer_automat::setze_feld()        // allow the user to enter each cell's status
{
    int n,m;                                 // initiates 2 varibles for the loops in l.61 and l. 63
    int zustand;                             // this variable will save the cell status (alive or dead)

    for (n=0; n<neue_hoehe; n++)             // for-loop through the height of the array - runs from 0 to 29 (on default)
    {
        for (m=0; m<neue_breite; m++)        // for-loop through the width of the array - runs from 0 to 29 (on default)
        {
            cout << "soll Zelle " << n << " " << m << " Leben(1) oder Tod(0) sein\n";       // asks the user about the cell status for each cell
            cin >> zustand;                                                                 // lets them enter the status
            koor_feld_alt[(n*neue_breite +m)] = zustand;                                    // decides where the new input will be saved
                                                                         // since the array is just one long line of numbers and not "really" 2-d
        }

    }

}

int zellulaerer_automat::veraendere_feld()      // allows the user to change a specific field's status
{
    int height_change;                          // both inputs regarding the cell's position
    int width_change;                           //                    "

    cout << "Welches Feld wollen sie ändern?\n";        // dialogue about which cell to change

    cin >> height_change >> width_change;               // both inputs
    koor_feld_alt[height_change*neue_breite+width_change] = (koor_feld_alt[height_change*neue_breite+width_change] +1) % 2;
    // finds the correct cell and increases the value of it by 1. Then applies % 2 onto it, so its status is either 0 or 1
}

int zellulaerer_automat::evolution()            // goes through all cells, checks their neighbours,
{
    int n, j;
    int zellen_status;
    int counter = 0;

    delete koor_feld_neu;
    koor_feld_neu = new int[(neue_hoehe*neue_breite)];

    for (n=0; n<(neue_hoehe*neue_breite); n++) // start der kontrolle, wie Zellen auf Evolution reagieren
    {
        cout << "jeder evolution\n";
        if (n == 0) // ecke links oben
        {
            zellen_status = koor_feld_alt[n];

            if (koor_feld_alt[neue_hoehe*neue_breite-1] == 1) // links oben von "ecke links oben" -> ecke rechts unten
            {
                counter += 1;
            }
            cout<< "1";
            for (j = (neue_hoehe*neue_breite-neue_breite); j < ((neue_hoehe*neue_breite-neue_breite)+2); j++) // oben und rechts oben von "ecke links oben" -> ecke links unten und rechts von ecke links unten
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
                cout << "endless!\n";
            j = 0;
            }
            cout<<"2";
            if (koor_feld_alt[neue_breite-1] == 1)  // links von "Ecke links oben" -> Ecke rechts oben
            {
                counter += 1;
            }
            cout<<"3";
            if (koor_feld_alt[1] == 1) // rechts von "Ecke links oben"
            {
                counter += 1;
            }
            cout<<"4";
            if (koor_feld_alt[2*neue_breite-1] == 1) // links unten von "Ecke links oben" -> unter Ecke rechts oben
            {
                counter += 1;
            }
            cout<<"5";
            for (j = (neue_breite); j < (neue_breite+2); j++) // unter rechts unter "Ecke links oben"
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            j = 0;
            }    
            cout<< "6";

            if (counter == 3)
            {
                koor_feld_neu[n]=1;
            }
            else if (counter == 2)
            {
                koor_feld_neu[n] = koor_feld_alt[n];
            }
            else
            {
                koor_feld_neu[n] = 0;
            }
            counter = 0;

        }
        else if (n == (neue_breite - 1)) // ecke rechts oben
        {
            zellen_status = koor_feld_alt[n];

            for (j = (neue_breite*neue_hoehe-2); j < (neue_breite*neue_hoehe); j++)  //
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            j = 0;
            }
            if (koor_feld_alt[neue_hoehe*neue_breite-neue_breite] == 1)
            {
                counter += 1;
            }
            if (koor_feld_alt[neue_breite-2] == 1)
            {
                counter +=1;
            }
            if (koor_feld_alt[0] == 1)
            {
                counter +=1;
            }
            for (j = (neue_breite*2-2); j < (neue_breite*2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            j = 0;
            }
            if (koor_feld_alt[neue_breite] == 1)
            {
                counter +=1;
            }


            if (counter == 3)
            {
                koor_feld_neu[n]=1;
            }
            else if (counter == 2)
            {
                koor_feld_neu[n] = koor_feld_alt[n];
            }
            else
            {
                koor_feld_neu[n] = 0;
            }
            counter = 0;
        }
        else if (n == (neue_hoehe*neue_breite-neue_breite)) // ecke links unten
        {
            zellen_status = koor_feld_alt[n];

            if (counter == 3)
            {
                koor_feld_neu[n]=1;
            }
            else if (counter == 2)
            {
                koor_feld_neu[n] = koor_feld_alt[n];
            }
            else
            {
                koor_feld_neu[n] = 0;
            }
            counter = 0;
        }
        else if (n == (neue_breite*neue_hoehe - 1)) // ecke rechts unten
        {
            zellen_status = koor_feld_alt[n];

            if (counter == 3)
            {
                koor_feld_neu[n]=1;
            }
            else if (counter == 2)
            {
                koor_feld_neu[n] = koor_feld_alt[n];
            }
            else
            {
                koor_feld_neu[n] = 0;
            }
            counter = 0;
        }
        else if (n>0 && n<(neue_breite-1)) // obere Zeile (ohne Ecken)
        {
            zellen_status = koor_feld_alt[n];

            if (counter == 3)
            {
                koor_feld_neu[n]=1;
            }
            else if (counter == 2)
            {
                koor_feld_neu[n] = koor_feld_alt[n];
            }
            else
            {
                koor_feld_neu[n] = 0;
            }
            counter = 0;
        }
        else if (n % (neue_breite) == 0 && n != 0 && n!= (neue_hoehe*neue_breite-neue_breite)) // linke Seite (ohne Ecken)
        {
            zellen_status = koor_feld_alt[n];

            if (counter == 3)
            {
                koor_feld_neu[n]=1;
            }
            else if (counter == 2)
            {
                koor_feld_neu[n] = koor_feld_alt[n];
            }
            else
            {
                koor_feld_neu[n] = 0;
            }
            counter = 0;
        }
        else if (n % (neue_breite) == (neue_breite-1) && n!=(neue_breite - 1) && n!=(neue_breite*neue_hoehe - 1)) // rechte Seite (ohne Ecken)
        {
            zellen_status = koor_feld_alt[n];

            if (counter == 3)
            {
                koor_feld_neu[n]=1;
            }
            else if (counter == 2)
            {
                koor_feld_neu[n] = koor_feld_alt[n];
            }
            else
            {
                koor_feld_neu[n] = 0;
            }
            counter = 0;
        }
        else if (n> neue_breite*neue_hoehe-neue_breite && n<neue_hoehe*neue_breite) // untere Zeile (ohne Ecken)
        {
            zellen_status = koor_feld_alt[n];

            if (counter == 3)
            {
                koor_feld_neu[n]=1;
            }
            else if (counter == 2)
            {
                koor_feld_neu[n] = koor_feld_alt[n];
            }
            else
            {
                koor_feld_neu[n] = 0;
            }
            counter = 0;
        }
        else // Alle Felder außer Randfelder
        {
            zellen_status = koor_feld_alt[n];

            if (counter == 3)
            {
                koor_feld_neu[n]=1;
            }
            else if (counter == 2)
            {
                koor_feld_neu[n] = koor_feld_alt[n];
            }
            else
            {
                koor_feld_neu[n] = 0;
            }
            counter = 0;
        }
    }
    cout << "hello?\n";
    delete koor_feld_alt;
    koor_feld_alt = koor_feld_neu;
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
