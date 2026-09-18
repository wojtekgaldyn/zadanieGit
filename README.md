# Projekt zarzadzajacy dodawaniem zadan

Konsolowy menedzer zadan w C++. Klasa `Task` trzyma pojedyncze zadanie
(id, nazwa, priorytet, status), a `main()` obsluguje menu.

## Struktura

```
dodawanieZadan/
  dodawanieZadan.slnx              rozwiazanie Visual Studio
  dodawanieZadan/                  aplikacja (Task.h, Task.cpp, dodawanieZadan.cpp)
  dodawanieZadanTests/             testy jednostkowe klasy Task
```

## Uruchomienie testow

**W Visual Studio:** menu `Test` -> `Test Explorer` -> `Run All Tests`
(skrot: `Ctrl+R, A`). Testy widac po zbudowaniu rozwiazania.

**Z linii polecen:**

```
msbuild dodawanieZadan\dodawanieZadan.slnx /p:Configuration=Debug /p:Platform=x64
vstest.console.exe dodawanieZadan\x64\Debug\dodawanieZadanTests.dll
```

Te same dwa kroki wykonuje GitHub Actions przy kazdym pushu i pull requescie -
konfiguracja siedzi w `.github/workflows/ci.yml`.
