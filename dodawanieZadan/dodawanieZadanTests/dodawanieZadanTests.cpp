#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Task.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace dodawanieZadanTests
{
    // display() nie zwraca tekstu, tylko pisze na std::cout. Zeby dalo sie go sprawdzic,
    // podmieniamy bufor cout na wlasny, wolamy display() i oddajemy bufor na miejsce.
    static std::string przechwycWyjscie(const Task& task)
    {
        std::ostringstream bufor;
        std::streambuf* stary = std::cout.rdbuf(bufor.rdbuf());
        task.display();
        std::cout.rdbuf(stary);
        return bufor.str();
    }

    TEST_CLASS(TaskKonstruktor)
    {
    public:

        TEST_METHOD(zapisujeDanePodaneWKonstruktorze)
        {
            Task task(7, "napisac testy", 2);

            Assert::AreEqual(7, task.getId());
            Assert::AreEqual(std::string("napisac testy"), task.getName());
            Assert::AreEqual(2, task.getPriority());
        }

        TEST_METHOD(noweZadanieNieJestWykonane)
        {
            Task task(1, "cokolwiek", 1);

            Assert::IsFalse(task.isCompleted());
        }

        TEST_METHOD(pustaNazwaJestPrzyjmowana)
        {
            Task task(1, "", 1);

            Assert::AreEqual(std::string(""), task.getName());
        }
    };

    TEST_CLASS(TaskOznaczanieJakoWykonane)
    {
    public:

        TEST_METHOD(completeUstawiaStatusNaWykonane)
        {
            Task task(1, "zakupy", 1);
            Assert::IsFalse(task.isCompleted(), L"zadanie powinno startowac jako niewykonane");

            task.complete();

            Assert::IsTrue(task.isCompleted());
        }

        TEST_METHOD(completeWywolaneDwaRazyNieZmieniaStanu)
        {
            Task task(1, "zakupy", 1);

            task.complete();
            task.complete();

            Assert::IsTrue(task.isCompleted());
        }

        TEST_METHOD(completeNieDotykaPozostalychPol)
        {
            Task task(3, "zakupy", 2);

            task.complete();

            Assert::AreEqual(3, task.getId());
            Assert::AreEqual(std::string("zakupy"), task.getName());
            Assert::AreEqual(2, task.getPriority());
        }
    };

    TEST_CLASS(TaskEdycja)
    {
    public:

        TEST_METHOD(setNameZmieniaNazwe)
        {
            Task task(1, "stara nazwa", 1);

            task.setName("nowa nazwa");

            Assert::AreEqual(std::string("nowa nazwa"), task.getName());
        }

        TEST_METHOD(setPriorityZmieniaPriorytet)
        {
            Task task(1, "nauka", 1);

            task.setPriority(3);

            Assert::AreEqual(3, task.getPriority());
        }

        TEST_METHOD(edycjaNieZmieniaIdAniStatusu)
        {
            Task task(42, "stara", 1);
            task.complete();

            task.setName("nowa");
            task.setPriority(3);

            Assert::AreEqual(42, task.getId());
            Assert::IsTrue(task.isCompleted());
        }

        // Test dokumentujacy stan na dzisiaj: Task NIE sprawdza zakresu priorytetu.
        // Warunek 1-3 siedzi tylko w main(), i tylko przy dodawaniu zadania.
        // Jesli dolozysz walidacje do Task, ten test zacznie swiecic na czerwono -
        // to jest sygnal, zeby go poprawic, a nie usunac.
        TEST_METHOD(setPriorityNieWalidujeZakresu)
        {
            Task task(1, "nauka", 2);

            task.setPriority(99);

            Assert::AreEqual(99, task.getPriority());
        }
    };

    TEST_CLASS(TaskKopiowanie)
    {
    public:

        TEST_METHOD(zadanieWlozoneDoVectoraZachowujeDane)
        {
            std::vector<Task> zadania;

            zadania.push_back(Task(1, "pierwsze", 3));

            Assert::AreEqual(1, static_cast<int>(zadania.size()));
            Assert::AreEqual(std::string("pierwsze"), zadania[0].getName());
            Assert::AreEqual(3, zadania[0].getPriority());
        }

        TEST_METHOD(kopiaZadaniaJestNiezalezna)
        {
            Task oryginal(1, "oryginal", 1);

            Task kopia = oryginal;
            kopia.setName("kopia");
            kopia.complete();

            Assert::AreEqual(std::string("oryginal"), oryginal.getName());
            Assert::IsFalse(oryginal.isCompleted());
        }
    };

    TEST_CLASS(TaskWypisywanie)
    {
    public:

        TEST_METHOD(displayPokazujeStatusDoWykonania)
        {
            Task task(1, "zakupy", 2);

            const std::string wyjscie = przechwycWyjscie(task);

            Assert::IsTrue(wyjscie.find("Status: Do wykonania") != std::string::npos,
                L"display() powinno wypisac status niewykonanego zadania");
        }

        TEST_METHOD(displayPokazujeStatusWykonane)
        {
            Task task(1, "zakupy", 2);
            task.complete();

            const std::string wyjscie = przechwycWyjscie(task);

            Assert::IsTrue(wyjscie.find("Status: Wykonane") != std::string::npos,
                L"display() powinno wypisac status wykonanego zadania");
        }

        TEST_METHOD(displayZawieraIdNazweIPriorytet)
        {
            Task task(5, "nauka C++", 3);

            const std::string wyjscie = przechwycWyjscie(task);

            Assert::IsTrue(wyjscie.find("ID: 5") != std::string::npos, L"brak ID");
            Assert::IsTrue(wyjscie.find("Nazwa: nauka C++") != std::string::npos, L"brak nazwy");
            Assert::IsTrue(wyjscie.find("Priorytet: 3") != std::string::npos, L"brak priorytetu");
        }
    };
}
