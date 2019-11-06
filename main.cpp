#include "static_array_int.h"
#include "class_1.h"



using namespace std;

int main()
{

    zellulaerer_automat test;       // creates one instance of the class "zellulärer_automat"
    cout << "Would you like to import an automaton? Yes (1) or No (0)";
    int import_decision;
    cin >> import_decision;

    if (import_decision == 1)
    {
        test.import_field();
    }
    test.feldgroese();              // calls the function, that asks the user for the automaton size
    test.setze_feld();              // calls the function, that allows the user to set each cells value
    test.zeige_feld();              // calls the function, that shows the field
    test.veraendere_feld();         // calls the function, allows the user to change specific cells
    cout << "Ergebnis veraendertes Feld\n";
    test.zeige_feld();              // shows the field again
    test.evolution();               // starts the evolution process
    cout << "Ergebnis Evolution\n";
    test.zeige_feld();              // shows the field again

    int static_array[HEIGHT][WIDTH];// creates a static array with given parameters
    int *dynamic_d = new int[900];  // creates a dynamic array with given parameters

    int while_input;                // menu input by the user
    bool while_tf = true;           // while-loop variable initialise

    while (while_tf == true)        // while-loop, contains the menu and secures valid inputs
    {
        cout << "Statischen Array erstellen(1)" << endl;
        cout << "Statischen Array ausgeben(2)" << endl;
        cout << "Statischen in Dynamischen Array übertragen(3)" << endl;
        cout << "Dynamischen Array ausgeben(4)" << endl;
        cout << "Beenden(5)" << endl;
        cout << "Exportieren (6)" << endl;
        cin >> while_input;                 // user input for the menu

        system("CLS");                      // clears the console so it doesnt get filled up

        if (while_input == 1)               // static array creation
        {
            cout << "static_a func" << endl;
            static_array_func(static_array);    // calls the function that creates the array, located in static_array.cpp
        }
        else if (while_input == 2)              // static array output
        {
            cout << "static_out" << endl;
            static_array_out(static_array);     // calls the print funtion for the static arry, located in static_array_out.cpp
        }
        else if (while_input == 3)              // copying stat. array => dyn. array
        {
            cout << "dynamic_d func" << endl;
            dynamic_array_func(static_array, dynamic_d);    // calls the function, that copies the stat. array into the dyn. array, located in dynamic_array.cpp
        }
        else if (while_input == 4)              // dyn. array print
        {
            cout << "dynamic_d out" << endl;
            dynamic_array_out(dynamic_d);       // calls the funtion that print the dyn. array, located in dynamic_array_out.cpp
        }
        else if (while_input == 5)              // the menu ending choice
        {
            while_tf = false;                   // sets the while-loop variable to false, so it ends
        }
        else if (while_input == 6)
        {
            test.export_field();
        }
        else
        {
            cout << "Ungültige Eingabe" << endl;// catches other inputs
        }
    }

    return 0;
}




