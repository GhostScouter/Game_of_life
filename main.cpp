#include "static_array_int.h"
#include "class_1.h"



using namespace std;

int main()
{

    zellulaerer_automat test;
    test.feldgroese();
    test.setze_feld();
    test.zeige_feld();
    test.veraendere_feld();
    test.zeige_feld();
    cout << "got here\n";
    test.evolution();
    cout << "got here too\n";
    test.zeige_feld();

    int static_array[HEIGHT][WIDTH];
    int *dynamic_d = new int[900];

    int while_input;
    bool while_tf = true;

    while (while_tf == true)
    {
        cout << "Statischen Array erstellen(1)" << endl;
        cout << "Statischen Array ausgeben(2)" << endl;
        cout << "Statischen in Dynamischen Array übertragen(3)" << endl;
        cout << "Dynamischen Array ausgeben(4)" << endl;
        cout << "Beenden(5)" << endl;
        cin >> while_input;

        system("CLS");

        if (while_input == 1)
        {
            cout << "static_a func" << endl;
            static_array_func(static_array);
        }
        else if (while_input == 2)
        {
            cout << "static_out" << endl;
            static_array_out(static_array);
        }
        else if (while_input == 3)
        {
            cout << "dynamic_d func" << endl;
            dynamic_array_func(static_array, dynamic_d);
        }
        else if (while_input == 4)
        {
            cout << "dynamic_d out" << endl;
            dynamic_array_out(dynamic_d);
        }
        else if (while_input == 5)
        {
            while_tf = false;
        }
        else
        {
            cout << "Ungültige Eingabe" << endl;
        }
    }

    return 0;
}




