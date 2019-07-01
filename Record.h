#ifndef RECORD_H
#define RECORD_H
#include <fstream>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

class Record {
    public:

    protected:
        void wypozyczenie();
        void zwrot();
        void szukajWypozyczen();
        void czekaj();
        long long int syg;
        ifstream file;
        ofstream file1;
        string autor;
        string tytul;
        string status;

    private:
        string uzytkownik;
        int sygnatura;
};

#endif
