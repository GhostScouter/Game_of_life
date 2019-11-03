#include "static_array_int.h"
#include "class_1.h"



using namespace std;

int main()
{
    int a = 5;

    zellulaerer_automat::feldgroese(a);

    int static_array[HEIGHT][WIDTH];
    int dynamic_d[900];

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




