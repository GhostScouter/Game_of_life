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
                cout << "neue Hoehe\n";
                cin >> neue_hoehe;          // users new width
                cout << "neue breite\n";
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
            neue_hoehe = 30;                // sets default size values to 30x30
            neue_breite = 30;               //                "
        }
        else                                // if the user entered something else than 1 or 2 (l.24)
        {
            cout << "Ungueltige Eingabe\n"; // tells the user they did something stupid
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
    int feld_aenderung = 1;

    cout << "Welches Feld wollen sie ändern?\n";

    cin >> height_change >> width_change;               // both inputs
    koor_feld_alt[height_change*neue_breite+width_change] = (koor_feld_alt[height_change*neue_breite+width_change] +1) % 2;
    // finds the correct cell and increases the value of it by 1. Then applies % 2 onto it, so its status is either 0 or 1



    while (feld_aenderung == 1)     // asks the user if they like to change another cell until they decide otherwise
    {
        cout << "Wollen sie Felder ändern?(Ja = 1, Nein = 0)\n";
        cin >> feld_aenderung;                                          // awaits the user's input
        if (feld_aenderung == 1)                                        // if they like to
        {
            cout << "Welches Feld wollen sie ändern?\n";
            cin >> height_change >> width_change;                       // awaits the inputs
            koor_feld_alt[height_change*neue_breite+width_change] = (koor_feld_alt[height_change*neue_breite+width_change] +1) % 2;     // <=> l.85
        }
    }
}

int zellulaerer_automat::evolution()            // goes through all cells, checks their neighbours,
{
    int n, j;                                   // initiates 2 variables for loop purposes
    int counter = 0;                            // this variable counts the amount of neighbours, it gets resetted for each cell (i.e. l. 159)

    delete koor_feld_neu;                                   // deletes the new field, only useful after the first evolution, else this is empty
    koor_feld_neu = new int[(neue_hoehe*neue_breite)];      // creates a new field with the size parameters, taken in l. 30 or l.46

    for (n=0; n<(neue_hoehe*neue_breite); n++) // starts the evolution, runs through the entire array, the following if-statements are executed for each cell
    {
        // we are now trying to find out where our cell 2-d location is, there are 9 different positions possible
        if (n == 0) // checks if we are in the top left corner
        {

            if (koor_feld_alt[neue_hoehe*neue_breite-1] == 1) // checks the top left corner of our cell, which is the botton right one
            {
                counter ++;         // if the value of checked cell is 1 the counter increases by one, since we just found one neighbour
            }
            for (j = (neue_hoehe*neue_breite-neue_breite); j < ((neue_hoehe*neue_breite-neue_breite)+2); j++) // checks the top middle and top right of our cell
            {
                // in order to save some code, we decided to use for-loops for every successive cells that are checked
                if (koor_feld_alt[j] == 1)          // for each of the 2 checked cells
                {
                    counter ++; // if the value of either cell is 1 the counter increases by one, since we just found one neighbour
                }
            }
            if (koor_feld_alt[neue_breite-1] == 1)  // now we are just checking all surrounding cells
            {
                counter ++;
            }
            if (koor_feld_alt[1] == 1)
            {
                counter ++;
            }
            if (koor_feld_alt[2*neue_breite-1] == 1)
            {
                counter ++;
            }
            for (j = (neue_breite); j < (neue_breite+2); j++)
            {
                if (koor_feld_alt[j] == 1)
                {
                    counter ++;
                }
            }    

            // we are now deciding how to deal with the given cell depending on its neighbor-counter
            if (counter == 3)       // if they have 3, it will be alive, no matter its old status
            {
                koor_feld_neu[n]=1; // the new field has the letter 1 on the cells position (alive)
            }
            else if (counter == 2)  // if the cell has 2 neighbors its old status will remain (dead ones stays dead, alive ones stay alive)
            {
                koor_feld_neu[n] = koor_feld_alt[n];        // cell in the new position gets the same value
            }
            else
            {
                koor_feld_neu[n] = 0;       // if a cell has neither 2 or 3 neighbors its gonna die or stay dead
            }
            counter = 0;        // resets the neighbor counter for the next cell

        }
        else if (n == (neue_breite - 1)) // top right corner
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

            // new status
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
        else if (n == (neue_hoehe*neue_breite-neue_breite)) // bottom left corner
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

            // new status
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
        else if (n == (neue_breite*neue_hoehe - 1)) // bottom right corner
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

            // new status
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
        else if (n>0 && n<(neue_breite-1)) // top line without the corners
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

            // new status
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
        else if (n % (neue_breite) == 0 && n != 0 && n!= (neue_hoehe*neue_breite-neue_breite)) // left side, without corners
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

            // new status
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
        else if (n % (neue_breite) == (neue_breite-1) && n!=(neue_breite - 1) && n!=(neue_breite*neue_hoehe - 1)) // right side, without corners
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

            // new status
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
        else if (n> neue_breite*neue_hoehe-neue_breite && n<neue_hoehe*neue_breite) // bottom line
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

            // new status
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
        else // every other cell
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
            // new status
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
    delete koor_feld_alt;           // the big for-loop is now finished and the old field can be deleted
    koor_feld_alt = koor_feld_neu;  // the new field becomes the old one, so it can be deleted in the next iteration again (l. 107)
}

int zellulaerer_automat::zeige_feld()   // will print the field as a string
{
    int n,m;    // initialises 2 variables for the loops down below

    for (n=0; n<neue_hoehe; n++)        // iterates over the height
    {
        for (m=0; m<neue_breite; m++)   // iterates over the width
        {
            cout << koor_feld_alt[(n*(neue_breite) +m)]<< " ";  // prints the current cell
        }
    cout << endl;       // ends the line for a "matrix like view"
    }
}

int zellulaerer_automat::export_field()
{
    ofstream myfile;
    myfile.open ("export.txt");

    int i = 0;
    myfile << neue_hoehe << endl;
    myfile << neue_breite << endl;

    while (true)
    {
        myfile << koor_feld_neu[i];
        i ++;
        if ((i%neue_breite) == 0)
        {
            myfile << endl;
        }
        else if (i == (neue_hoehe*neue_breite)-1)
        {
            myfile << koor_feld_neu[(neue_hoehe*neue_breite)-1];
            break;
        }
    }
    myfile.close();

}


zellulaerer_automat::~zellulaerer_automat() // deconstructor
{

}
