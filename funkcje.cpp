#include "funkcje.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

namespace DomowyMenadzer {

    void menu() {
        cout << "\n== Menadżer Zadań Domowych ==\n";
        cout << "1. Dodaj zadanie\n";
        cout << "2. Wyświetl zadania\n";
        cout << "3. Usuń zadanie\n";
        cout << "4. Sortuj zadania wg priorytetu\n";
        cout << "5. Wyjście\n";
        cout << "Wybierz opcję: ";
    }

    void dodajZadanie(vector<Zadanie>& lista) {
        if (lista.size() >= MAKS_ZADANIA) {
            cout << "Za dużo zadań!\n";
            return;
        }

        Zadanie z;
        cout << "Podaj opis zadania: ";
        getline(cin, z.opis);
        cout << "Podaj priorytet (1-10): ";
        cin >> z.priorytet;
        cin.ignore();

        lista.push_back(z);
        cout << "Dodano zadanie!\n";
    }

    void wypiszZadania(const vector<Zadanie>& lista) {
        if (lista.empty()) {
            cout << "Brak zadań do wyświetlenia.\n";
            return;
        }

        for (Indeks i = 0; i < lista.size(); i++) {
            cout << i + 1 << ". " << lista[i].opis << " (priorytet: " << lista[i].priorytet << ")\n";
        }
    }

    void usunZadanie(vector<Zadanie>& lista) {
        if (lista.empty()) {
            cout << "Brak zadań do usunięcia.\n";
            return;
        }

        wypiszZadania(lista);
        cout << "Podaj numer zadania do usunięcia: ";
        Indeks nr;
        cin >> nr;
        cin.ignore();

        if (nr > 0 && nr <= lista.size()) {
            lista.erase(lista.begin() + nr - 1);
            cout << "Usunięto zadanie.\n";
        } else {
            cout << "Zły numer.\n";
        }
    }

    void sortujZadania(vector<Zadanie>& lista) {
        sort(lista.begin(), lista.end(), [](Zadanie a, Zadanie b) {
            return a.priorytet > b.priorytet;
        });
        cout << "Posortowano zadania.\n";
    }

    void wczytajZPliku(const char* nazwa, vector<Zadanie>& lista) {
        ifstream plik(nazwa);
        if (!plik) {
            cout << "Nie mogę otworzyć pliku: " << nazwa << endl;
            return;
        }

        Zadanie z;
        while (getline(plik, z.opis)) {
            plik >> z.priorytet;
            plik.ignore();
            lista.push_back(z);
        }

        cout << "Wczytano dane z pliku.\n";
    }

    void zapiszDoPliku(const char* nazwa, const vector<Zadanie>& lista) {
        ofstream plik(nazwa);
        if (!plik) {
            cout << "Nie mogę otworzyć pliku do zapisu: " << nazwa << endl;
            return;
        }
        for (const auto& z : lista) {
            plik << z.opis << endl;
            plik << z.priorytet << endl;
        }
        cout << "Zapisano dane do pliku.\n";
    }

    void edytujZadanie(vector<Zadanie>& lista) {
        if (lista.empty()) {
            cout << "Brak zadań do edycji.\n";
            return;
        }
        wypiszZadania(lista);
        cout << "Podaj numer zadania do edycji: ";
        Indeks nr;
        cin >> nr;
        cin.ignore();
        if (nr > 0 && nr <= lista.size()) {
            cout << "Nowy opis zadania: ";
            getline(cin, lista[nr - 1].opis);
            cout << "Nowy priorytet (1-10): ";
            cin >> lista[nr - 1].priorytet;
            cin.ignore();
            cout << "Zadanie zaktualizowane.\n";
        } else {
            cout << "Zły numer.\n";
        }
    }

}
