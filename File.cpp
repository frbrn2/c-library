#include "File.h"

File::File() {
    cout<<"Witamy w elektronicznym systemie bibliotecznym"<<endl;
    wybor();
}

void File::wybor() {
	czekaj();
	cout<<"\n1. Dodaj Rekord"<<endl;
	cout<<"2. Usun Rekord"<<endl;
	cout<<"3. Odczytaj liste"<<endl;
	cout<<"4. Sortowanie"<<endl;
    cout<<"5. Zmodyfikuj Rekord"<<endl;;
    cout<<"6. Wypozyczenie Rekordu"<<endl;
    cout<<"7. Zwrot Rekordu"<<endl;
    cout<<"8. Znajdz wypozyczenia"<<endl;
	cout<<"9. Wyjdz"<<endl;
	cout<<"Wybierz opcje: ";
	char choice = getch();
	switch(choice)
	{
    case '1':
        dodaj();
        wybor();
        break;
    case '2':
        usun();
        wybor();
        break;
    case '3':
        odczyt();
        wybor();
        break;
    case '4':
        sortowanie();
        wybor();
        break;
    case '5':
        modyfikacja();
        wybor();
        break;
    case '6':
        wypozyczenie();
        wybor();
        break;
    case '7':
        zwrot();
        wybor();
        break;
    case '8':
        szukajWypozyczen();
        wybor();
        break;
    case '9':
        return;
    default:
        cout<<"Wpisz poprawny numer"<<endl;
        wybor();
        break;
	}
}

void File::dodaj() {
    system("cls");
    file1.open("spis.txt",ios::app);
    cout<<"Tytul ksiazki: "<<endl;
    getline(cin, tytul);
    tytul = tytul.substr(0, tytul.find(' '));
    system("cls");
    cout<<"Autor ksiazki: "<<endl;
    getline(cin, autor);
    autor = autor.substr(0, autor.find(' '));
    system("cls");
    cout<<"Wprowadz sygnature: "<<endl;
    cin>>syg;
    while (cin.fail()) {
        system("cls");
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"Mozesz wprowadzic tylko cyfry\n";
        cout<<"Wprowadz liczbe: ";
        cin>>syg;
    }
    system("cls");
    status ="-----";
    if(test()) {
        file1<<tytul<<"	"<<autor<<"	"<<syg<<"     "<<status<<" "<<endl;
        cout<<"\nPomyslnie dodano rekord"<<endl;
    }
    else {
        cout<<"Identyfikator nieunikalny "<<syg;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    file1.close();
}

bool File::test() {
    file.open("spis.txt");
    while(file>>tytul2>>autor2>>syg2>>status2) {
      if(syg==syg2){
        file.close();
        return false;
      }
    }
    file.close();
    return true;
}

void File::usun() {
    bool jest = false;
    string name;
    system("cls");
    cout<<"wpisz nazwe rekordu ktory chcesz usunac"<<endl;
    cin>>name;
    system("cls");
    file.open("spis.txt");
    file1.open("temp.txt");
    while(file>>tytul>>autor>>syg>>status) {
      if(tytul!=name) {
        file1<<tytul<<"	"<<autor<<"	"<<syg<<" "<<status<<"      "<<endl;
        }
        else {
            jest = true;
        }
    }
    if(jest == true) {
        cout<<"rekord o nazwie: "<<name<<" zostal usuniety"<<endl;
    }
    else {
        cout<<"rekord o nazwie: "<<name<<" nie zostal znaleziony"<<endl;
    }
    file.close();
    file1.close();
    remove("spis.txt");
    rename("temp.txt","spis.txt");
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

void File::odczyt() {
    wczytanie();
    for(size_t i = 0;i < vsyg.size();i++) {
		for(size_t j = 1;j < vsyg.size() - i;j++) {
            if(vsyg[j - 1]>vsyg[j]) {
                swap(vsyg[j - 1], vsyg[j]);
            }
		}
    }
    cout<<"\n"<<left<<setw(50)<<"Tytul"<<" "<<setw(30)<<"Autor"<<" "<<setw(20)<<"Sygnatura"<<" "<<setw(15)<<"Status"<<endl<<endl;
    for(size_t i = 0; i < vsyg.size();i++) {
        cout<<left<<setw(50)<<vtytul.at(i)<<" "<<setw(30)<<vautor.at(i)<<" "<<setw(20)<<vsyg.at(i)<<" "<<setw(15)<<vstatus.at(i)<<endl;
    }
}

void File::modyfikacja() {
   	int sygnatura,zmienna;
    string newautor,newtytul;
    bool znalazlo = false;
    system("cls");
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout<<"Podaj sygnature"<<endl;
    cin>>sygnatura;
    system("cls");
    file.open("spis.txt");
    file1.open("temp.txt");
    while(file>>tytul>>autor>>syg>>status){
        if(syg==sygnatura) {
            znalazlo = true;
            cout<<"Co chcesz zmienic?"<<endl;
            cout<<"1. Tytul"<<endl;
            cout<<"2. Autor"<<endl;
            cin>>zmienna;
            system("cls");
            switch(zmienna){
            case 1:
                cout<<"Podaj nowy tytul: "<<endl;
                cin>>newtytul;
                system("cls");
                file1<<newtytul<<"	"<<autor<<"	"<<syg<<"	"<<status<<"	"<<endl;
                cout<<"Pomyslnie zmieniono tytul"<<endl;
                break;
            case 2:
                cout<<"Podaj nowego autora: "<<endl;
                cin>>newautor;
                system("cls");
                file1<<tytul<<"	"<<newautor<<"	"<<syg<<"	"<<status<<"	"<<endl;
                cout<<"Pomyslnie zmieniono autora"<<endl;
                break;
            default:
                file1<<tytul<<"	"<<autor<<"	"<<syg<<"	"<<status<<"	"<<endl;;
                cout<<"Podano zly parametr"<<endl;
                wybor();
                break;
            }
        }
        else {
            file1<<tytul<<"	"<<autor<<"	"<<syg<<"	"<<status<<"	"<<endl;;
        }
    }
    if(znalazlo == false) {
        cout<<"nie odnaleziono rekordu o danej sygnaturze"<<endl;
    }
    file.close();
    file1.close();
    remove("spis.txt");
    rename("temp.txt","spis.txt");
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}
void File::sortowanie() {
    int sort;
    system("cls");
    wczytanie();
    cout<<"Sortowanie"<<endl;
    cout<<"1. Rosnace"<<endl;
    cout<<"2. Malejace"<<endl;
    cin>>sort;
    if(sort == 1) {
        for(size_t i = 0;i < vtytul.size();i++) {
            for(size_t j = 1;j < vtytul.size() - i;j++) {
                if(vtytul[j - 1][0]>vtytul[j][0]) {
                    swap(vtytul[j - 1][0], vtytul[j][0]);
                }
            }
         }
    }
    else if(sort == 2){
        for(size_t i = 0;i < vtytul.size();i++) {
            for(size_t j = 1;j < vtytul.size() - i;j++) {
                if(vtytul[j - 1][0]<vtytul[j][0]) {
                    swap(vtytul[j - 1][0], vtytul[j][0]);
                }
            }
         }
    }
    else {
        system("cls");
        cout<<"Podano bledny parametr"<<endl;
        return;
    }
    system("cls");
    cout<<"\n"<<left<<setw(50)<<"Tytul"<<" "<<setw(30)<<"Autor"<<" "<<setw(20)<<"Sygnatura"<<" "<<setw(15)<<"Status"<<endl<<endl;
    for(size_t i = 0; i < vtytul.size();i++) {
        cout<<left<<setw(50)<<vtytul.at(i)<<" "<<setw(30)<<vautor.at(i)<<" "<<setw(20)<<vsyg.at(i)<<" "<<setw(15)<<vstatus.at(i)<<endl;
    }
}

void File::wczytanie() {
    system("cls");
    file.open("spis.txt");
    vsyg.clear();
    vtytul.clear();
    vautor.clear();
    vstatus.clear();
    while(file>>tytul>>autor>>syg>>status) {
        vsyg.push_back(syg);
        vtytul.push_back(tytul);
        vautor.push_back(autor);
        vstatus.push_back(status);
    }
    file.close();
}
