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
        menu();
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
                cout << "Koniec programu.\n";
                break;
            default:
                cout << "Zły wybór, spróbuj jeszcze raz.\n";
                break;
        }
    } while (wybor != 5);

    return 0;
}