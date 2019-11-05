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
    int feld_aenderung = 1;


    while (feld_aenderung == 1)
    {
        cout << "Wollen sie Felder ändern?(Ja = 1, Nein = 0)\n";
        cin >> feld_aenderung;
        if (feld_aenderung == 1)
        {
            cout << "Welches Feld wollen sie ändern?\n";
            cin >> height_change >> width_change;
            koor_feld_alt[height_change*neue_breite+width_change] = (koor_feld_alt[height_change*neue_breite+width_change] +1) % 2;
        }
    }
}

int zellulaerer_automat::evolution()
{
    int n, j;
    int counter = 0;

    delete koor_feld_neu;
    koor_feld_neu = new int[(neue_hoehe*neue_breite)];

    for (n=0; n<(neue_hoehe*neue_breite); n++) // start der kontrolle, wie Zellen auf Evolution reagieren
    {
        if (n == 0) // ecke links oben
        {

            if (koor_feld_alt[neue_hoehe*neue_breite-1] == 1) // links oben von "ecke links oben" -> ecke rechts unten
            {
                counter ++;
            }
            for (j = (neue_hoehe*neue_breite-neue_breite); j < ((neue_hoehe*neue_breite-neue_breite)+2); j++) // oben und rechts oben von "ecke links oben" -> ecke links unten und rechts von ecke links unten
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter ++;
                }
            }
            if (koor_feld_alt[neue_breite-1] == 1)  // links von "Ecke links oben" -> Ecke rechts oben
            {
                counter ++;
            }
            if (koor_feld_alt[1] == 1) // rechts von "Ecke links oben"
            {
                counter ++;
            }
            if (koor_feld_alt[2*neue_breite-1] == 1) // links unten von "Ecke links oben" -> unter Ecke rechts oben
            {
                counter ++;
            }
            for (j = (neue_breite); j < (neue_breite+2); j++) // unter rechts unter "Ecke links oben"
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter ++;
                }
            }    

            // alive or dead
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

            for (j = (neue_breite*neue_hoehe-2); j < (neue_breite*neue_hoehe); j++)  //
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
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
            }
            if (koor_feld_alt[neue_breite] == 1)
            {
                counter +=1;
            }

            // alive or dead
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

            if (koor_feld_alt[neue_hoehe*neue_breite-neue_breite-1] == 1)
            {
                counter +=1;
            }
            for (j = (n-neue_breite); j < (n-neue_breite+2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }
            if (koor_feld_alt[neue_hoehe*neue_breite-1] == 1)
            {
                counter +=1;
            }
            if (koor_feld_alt[n+1] == 1)
            {
                counter +=1;
            }
            if (koor_feld_alt[neue_breite-1] == 1)
            {
                counter +=1;
            }
            for (j = (0); j < (2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }

            // alive or dead
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

            for (j = (n-neue_breite-1); j < (n-neue_breite+1); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }
            if (koor_feld_alt[n-2*neue_breite+1] == 1)
            {
                counter +=1;
            }
            if (koor_feld_alt[n-1] == 1)
            {
                counter +=1;
            }
            if (koor_feld_alt[n-(neue_breite+1)] == 1)
            {
                counter +=1;
            }
            for (j = (neue_breite-2); j < (neue_breite); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }
            if (koor_feld_alt[0] == 1)
            {
                counter +=1;
            }

            // dead or alive
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

            for (j = (neue_breite*neue_hoehe-neue_breite+n-1); j < (neue_breite*neue_hoehe-neue_breite+n+2); j++) // für samuel: war beim ersten n-2 bis n+1 habs auf n-1 bis n+2 geändert
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }
            if (koor_feld_alt[n-1] == 1)
            {
                counter +=1;
            }
            if (koor_feld_alt[n+1] == 1)
            {
                counter +=1;
            }
            for (j = (n+neue_breite-1); j < (n+neue_breite+2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }

            // dead or alive
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

            if (koor_feld_alt[n-1] == 1)
            {
                counter +=1;
            }
            for (j = (n-neue_breite); j < (n-neue_breite+2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }
            for (j = (n+neue_breite-1); j < (n+neue_breite+2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }
            if (koor_feld_alt[n+1] == 1)
            {
                counter +=1;
            }
            if (koor_feld_alt[n+2*neue_breite-1] == 1)
            {
                counter +=1;
            }

            // dead or alive
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

            for (j = (n-neue_breite-1); j < (n-neue_breite+2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }
            if (koor_feld_alt[n-2*neue_breite+1] == 1)
            {
                counter +=1;
            }
            if (koor_feld_alt[n-1] == 1)
            {
                counter +=1;
            }
            for (j = (n+neue_breite-1); j < (n+neue_breite+1); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }
            if (koor_feld_alt[n+1] == 1)
            {
                counter +=1;
            }

            // dead or alive
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

            for (j = (n-neue_breite-1); j < (n-neue_breite+2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }
            if (koor_feld_alt[n-1] == 1)
            {
                counter +=1;
            }
            if (koor_feld_alt[n+1] == 1)
            {
                counter +=1;
            }
            for (j = (n-((neue_hoehe-1)*neue_breite)-1); j < (n-((neue_hoehe-1)*neue_breite)+2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }

            // dead or alive
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

            for (j = (n-neue_breite-1); j < (n-neue_breite+2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
            }
            if (koor_feld_alt[n-1] == 1)
            {
                counter +=1;
            }
            if (koor_feld_alt[n+1] == 1)
            {
                counter +=1;
            }
            for (j = (n+neue_breite-1); j < (n+neue_breite+2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter += 1;
                }
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
    }
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
