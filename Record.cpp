#include "Record.h"

void Record::czekaj() {
    cout<<"\nWcisnij dowolny klawisz by kontynuowac...\n";
    getch();
    system("cls");
}

void Record::wypozyczenie() {
    system("cls");
   	int flag = 0;
    cout<<"Podaj sygnature"<<endl;
    cin>>sygnatura;
    system("cls");
    file.open("spis.txt");
    file1.open("temp.txt");
    while(file>>tytul>>autor>>syg>>status){
        if(syg==sygnatura) {
            if(status=="-----") {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout<<"Kto wypozycza?"<<endl;
                getline(cin, uzytkownik);
                uzytkownik = uzytkownik.substr(0, uzytkownik.find(' '));
                file1<<tytul<<"	"<<autor<<"	"<<syg<<"	"<<uzytkownik<<"	"<<endl;
                system("cls");
                cout<<"Pomyslnie wypozyczono"<<endl;
                flag = 1;
            }
            else {
                flag = 2;
                file1<<tytul<<"	"<<autor<<"	"<<syg<<"	"<<status<<"	"<<endl;
            }
        }
        else {
            file1<<tytul<<"	"<<autor<<"	"<<syg<<"	"<<status<<"	"<<endl;;
        }
    }
    if(flag==0) {
        cout<<"Brak ksiazki o danej sygnaturze."<<endl;
    }
    else if(flag==2) {
        cout<<"Ksiazka zostala jzu wypozyczona przez kogos innego."<<endl;
    }
    file.close();
    file1.close();
    remove("spis.txt");
    rename("temp.txt","spis.txt");
}

void Record::zwrot() {
    system("cls");
    int flag = 0;
    cout<<"Podaj sygnature"<<endl;
    cin>>sygnatura;
    system("cls");
    file.open("spis.txt");
    file1.open("temp.txt");
    while(file>>tytul>>autor>>syg>>status){
        if(syg==sygnatura) {
            file1<<tytul<<"	"<<autor<<"	"<<syg<<"	"<<"-----"<<"	"<<endl;
            cout<<"Pomyslnie zwrocono"<<endl;
            flag = 1;
        }
        else {
            file1<<tytul<<"	"<<autor<<"	"<<syg<<"	"<<status<<"	"<<endl;;
        }
    }
    if(flag==0) {
        cout<< "Brak ksiazki o danej sygnaturze."<<endl;
    }
    file.close();
    file1.close();
    remove("spis.txt");
    rename("temp.txt","spis.txt");
}

void Record::szukajWypozyczen() {
   	int flag=0;
   	system("cls");
    cout<<"Podaj uzytkownika"<<endl;
    getline(cin, uzytkownik);
    system("cls");
    uzytkownik = uzytkownik.substr(0, uzytkownik.find(' '));
    file.open("spis.txt");
    while(file>>tytul>>autor>>syg>>status){
        if(status==uzytkownik) {
            if (flag==0) {
                cout<<"\n"<<left<<setw(50)<<"Tytul"<<" "<<setw(30)<<"Autor"<<" "<<setw(20)<<"Sygnatura"<<" "<<setw(15)<<"Status"<<endl<<endl;
            }
            cout<<left<<setw(50)<<tytul<<" "<<setw(30)<<autor<<" "<<setw(20)<<syg<<" "<<setw(15)<<status<<endl;
            flag = 1;
        }
    }
    if(flag==0) {
        cout<< "Uzytkownik '"<<uzytkownik<<"' nie wypozyczal zadnych ksiazek."<<endl;
    }
    file.close();
}
