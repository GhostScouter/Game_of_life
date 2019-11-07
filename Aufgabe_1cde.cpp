#include "class_1.h"

using namespace std;

int aufgabe_1cde()
{
    zellulaerer_automat test;       // creates one instance of the class "zellulärer_automat"
    cout << "Would you like to import an automaton? Yes (1) or No (0)";
    int import_decision;
    cin >> import_decision;

    if (import_decision == 1)
    {
        test.import_field();
    }
    else
    {
        test.feldgroese();              // calls the function, that asks the user for the automaton size
        test.setze_feld();              // calls the function, that allows the user to set each cells value
    }
    test.zeige_feld();              // calls the function, that shows the field
    test.veraendere_feld();         // calls the function, allows the user to change specific cells
    cout << "Ergebnis veraendertes Feld\n";
    test.zeige_feld();              // shows the field again


    bool evolution_while_var = true;
    int user_while_input;
    while (evolution_while_var)
    {
        test.evolution();               // starts the evolution process
        cout << "Ergebnis Evolution\n";
        test.zeige_feld();              // shows the field again

        cout <<" Noch einmal? ja(1) / nein(0) / exportieren(2)";
        cin >> user_while_input;
        if (user_while_input == 0)
        {
            evolution_while_var = false;
        }
        else if (user_while_input == 2)
        {
            test.export_field();
        }
    }
    return 0;
}
