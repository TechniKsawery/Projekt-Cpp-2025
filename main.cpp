#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "funkcje.h"
#include <locale.h>

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Polish");

    using namespace std;
    using namespace DomowyMenadzer;

    vector<Zadanie> lista;

    if (argc > 1) {
        wczytajZPliku(argv[1], lista);
    }

    int wybor;
    do {
        cout << "\n== Menadżer Zadań Domowych ==\n";
        cout << "1. Dodaj zadanie\n";
        cout << "2. Wyświetl zadania\n";
        cout << "3. Usuń zadanie\n";
        cout << "4. Sortuj zadania wg priorytetu\n";
        cout << "5. Edytuj zadanie\n";
        cout << "6. Zapisz zadania do pliku\n";
        cout << "7. Wyjście\n";
        cout << "Wybierz opcję: ";
        cin >> wybor;
        cin.ignore();

        switch (wybor) {
            case 1:
                dodajZadanie(lista);
                break;
            case 2:
                wypiszZadania(lista);
                break;
            case 3:
                usunZadanie(lista);
                break;
            case 4:
                sortujZadania(lista);
                break;
            case 5:
                edytujZadanie(lista);
                break;
            case 6: {
                string nazwa;
                cout << "Podaj nazwę pliku do zapisu: ";
                getline(cin, nazwa);
                zapiszDoPliku(nazwa.c_str(), lista);
                break;
            }
            case 7:
                cout << "Koniec programu.\n";
                break;
            default:
                cout << "Zły wybór, spróbuj jeszcze raz.\n";
                break;
        }
    } while (wybor != 7);

    return 0;
}