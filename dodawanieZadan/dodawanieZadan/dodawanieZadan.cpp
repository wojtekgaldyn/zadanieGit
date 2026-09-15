#include <iostream>
#include <vector>
#include <string>

#include "Task.h"
using namespace std;
int main()
{
    vector<Task> tasks;

    int nextId = 1;
    int choice;

    while (true)
    {
        cout << "\n===== TASK MANAGER =====\n";
        cout << "1. Dodaj zadanie\n";
        cout << "2. Pokaz zadania\n";
        cout << "3. Oznacz jako wykonane\n";
        cout << "4. Edytuj zadanie\n";
        cout << "5. Usun zadanie\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz: ";

        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string name;
            int priority;

            cout << "Podaj nazwe zadania: ";
            getline(cin, name);

            cout << "Podaj priorytet (1-3): ";
            cin >> priority;

            if (priority >= 1 && priority <= 3) {
                Task newTask(nextId, name, priority);

                tasks.push_back(newTask);

                nextId++;

                cout << "Dodano zadanie.\n";
            }
            else {
                cout << "Zle podano dane\n";
            }
        }
        else if (choice == 2)
        {
            if (tasks.empty())
            {
                cout << "Brak zadan.\n";
            }
            else
            {
                for (const Task& task : tasks)
                {
                    task.display();
                }
            }
        }
        else if (choice == 3)
        {
            int id;

            cout << "Podaj ID zadania: ";
            cin >> id;

            bool found = false;

            for (Task& task : tasks)
            {
                if (task.getId() == id)
                {
                    task.complete();
                    found = true;
                    cout << "Zadanie oznaczone jako wykonane.\n";
                    break;
                }
            }

            if (!found)
            {
                cout << "Nie znaleziono zadania.\n";
            }
        }
        else if (choice == 4)
        {
            int id;
            string newName;
            int newPriority;

            cout << "Podaj ID zadania do edytowania: ";
            cin >> id;
            cin.ignore();

            bool found = false;
            for (Task& task : tasks) {
                if (task.getId() == id) {
                    found = true;
                    cout << "Podaj nowa nazwe: ";
                    getline(cin, newName);
                    task.setName(newName);
                    cout << "Podaj priorytet zadania\n";
                    cin >> newPriority;
                    task.setPriority(newPriority);
                    cout << "Zadanie zostalo edytowane.\n";
                    break;
                }
            }
            if (!found) {
                cout << "Nie znaleziono tego zadania. \n";
            }
        }
        else if (choice == 5)
        {
            int id;

            cout << "Podaj ID zadania do usuniecia: ";
            cin >> id;

            bool found = false;

            for (auto it = tasks.begin(); it != tasks.end(); ++it)
            {
                if (it->getId() == id)
                {
                    tasks.erase(it);
                    found = true;

                    cout << "Zadanie usuniete.\n";
                    break;
                }
            }

            if (!found)
            {
                cout << "Nie znaleziono zadania.\n";
            }
        }
        else if (choice == 0)
        {
            cout << "Koniec programu.\n";
            break;
        }
        else
        {
            cout << "Nieprawidlowa opcja.\n";
        }
    }

    return 0;
}