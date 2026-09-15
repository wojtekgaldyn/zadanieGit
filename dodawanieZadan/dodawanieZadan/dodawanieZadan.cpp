#include <iostream>
#include <vector>
#include <string>

#include "Task.h"

int main()
{
    std::vector<Task> tasks;

    int nextId = 1;
    int choice;

    while (true)
    {
        std::cout << "\n===== TASK MANAGER =====\n";
        std::cout << "1. Dodaj zadanie\n";
        std::cout << "2. Pokaz zadania\n";
        std::cout << "3. Oznacz jako wykonane\n";
        std::cout << "4. Usun zadanie\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybierz: ";

        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1)
        {
            std::string name;
            int priority;

            std::cout << "Podaj nazwe zadania: ";
            std::getline(std::cin, name);

            std::cout << "Podaj priorytet (1-3): ";
            std::cin >> priority;

            Task newTask(nextId, name, priority);

            tasks.push_back(newTask);

            nextId++;

            std::cout << "Dodano zadanie.\n";
        }
        else if (choice == 2)
        {
            if (tasks.empty())
            {
                std::cout << "Brak zadan.\n";
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

            std::cout << "Podaj ID zadania: ";
            std::cin >> id;

            bool found = false;

            for (Task& task : tasks)
            {
                if (task.getId() == id)
                {
                    task.complete();
                    found = true;
                    std::cout << "Zadanie oznaczone jako wykonane.\n";
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Nie znaleziono zadania.\n";
            }
        }
        else if (choice == 4)
        {
            int id;

            std::cout << "Podaj ID zadania do usuniecia: ";
            std::cin >> id;

            bool found = false;

            for (auto it = tasks.begin(); it != tasks.end(); ++it)
            {
                if (it->getId() == id)
                {
                    tasks.erase(it);
                    found = true;

                    std::cout << "Zadanie usuniete.\n";
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Nie znaleziono zadania.\n";
            }
        }
        else if (choice == 0)
        {
            std::cout << "Koniec programu.\n";
            break;
        }
        else
        {
            std::cout << "Nieprawidlowa opcja.\n";
        }
    }

    return 0;
}