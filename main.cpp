#include "static_array_int.h"
#include "class_1.h"



using namespace std;

int main()
{
    bool input_task = true;
    int task_choice;

    while (input_task == true)
    {
        cout << "welche Aufgabe wollen sie sehen?\n";
        cout << "Aufgabe 1ab(1) oder Aufgabe 1cde(2) wenn sie nichts mehr sehen wollen -> (0)\n";
        cin >> task_choice;
        if (task_choice == 1)
        {
            aufgabe_1ab();
        }
        else if (task_choice == 2)
        {
            aufgabe_1cde();
        }
        else if (task_choice == 0)
        {
            input_task = false;
        }
        else
        {
            cout << "Ungueltige Eingabe\n";
        }
    }
    return 0;
}




