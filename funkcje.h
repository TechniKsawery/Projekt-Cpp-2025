#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <vector>
#include <string>

#define MAKS_ZADANIA 100

typedef std::string Tekst;
typedef int Indeks;

namespace DomowyMenadzer {

    struct Zadanie {
        Tekst opis;
        int priorytet;
    };

    void menu();
    void dodajZadanie(std::vector<Zadanie>& lista);
    void wypiszZadania(const std::vector<Zadanie>& lista);
    void usunZadanie(std::vector<Zadanie>& lista);
    void sortujZadania(std::vector<Zadanie>& lista);
    void wczytajZPliku(const char* nazwa, std::vector<Zadanie>& lista);

}

#endif
