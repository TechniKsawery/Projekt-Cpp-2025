# Projekt-Cpp-2025 — Aplikacja konsolowa w C/C++

Projekt w **C/C++** z organizacją kodu na moduły i konfiguracją budowania przez **CMake** / **Makefile**.

## Funkcje projektu
- Aplikacja konsolowa z logiką wydzieloną do plików `funkcje.*`
- Punkt wejścia w `main.cpp`
- Konfiguracja kompilacji przez `CMakeLists.txt`
- Możliwość budowania w środowiskach opartych o CMake/Make

## Stack
- C++
- C
- CMake
- Makefile

## Struktura
```text
Projekt-Cpp-2025/
├── main.cpp
├── funkcje.cpp
├── funkcje.h
├── CMakeLists.txt
└── (opcjonalnie) Makefile
```

## Wymagania
- Kompilator C/C++ (np. `g++`)
- CMake 3.10+
- (opcjonalnie) Make

## Build i uruchomienie (CMake)
```bash
mkdir build
cd build
cmake ..
cmake --build .
./ProjektCpp2025
```

## Build i uruchomienie (g++)
```bash
g++ -std=c++17 -O2 ../main.cpp ../funkcje.cpp -o app
./app
```

## Co można rozwinąć (roadmap)
- [ ] testy jednostkowe (np. GoogleTest)
- [ ] walidacja danych wejściowych
- [ ] CI (GitHub Actions)
- [ ] rozszerzona dokumentacja funkcji i przykładów użycia

## Autor
Ksawery Bloch
