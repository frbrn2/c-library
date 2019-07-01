#ifndef FILE_H
#define FILE_H
#include "Record.h"

class File : Record {
    public:
        File();

    protected:

    private:
        void wybor();
        void usun();
        void dodaj();
        void odczyt();
        void modyfikacja();
        void sortowanie();
        void wczytanie();
        bool test();
        long long int syg2;
        string tytul2;
        string autor2;
        string status2;
        vector < int > vsyg;
        vector < string > vtytul;
        vector < string > vautor;
        vector < string > vstatus;
};

#endif
