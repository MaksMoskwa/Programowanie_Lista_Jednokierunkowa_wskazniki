
#include <iostream> //biblioteki pozwalajace na otwarcie plikow , wyswietlenie w konsoli , uzycie danych tekstowych
#include <fstream>
#include <string>

using namespace std;

//lista 1 kierunkowa
struct lista {
    string dane;//zmienna przechowujaca tekst
    struct lista* /*wskaznik ( * ) na kolejny el listy*/nastepny;
};

//funkcja dodajaca nowy element na koniec listy
void dodajElement(struct lista*& szczyt, struct lista*& koniec, string tekst) {
    struct lista* nowy = new struct lista;/*nowy el w pamieci*/
    nowy->dane = tekst;//wpisanie tekst do dane
    nowy->nastepny = nullptr;//ustawienie wskaznika na nastepny pusty element

    if (szczyt == nullptr)//jesli lista jest pusta
    {
        szczyt = nowy;// to poczatek i koniec sa nowymi elementami
        koniec = nowy;
    }
    else {//a jesli nie to dodajemy element na koncu listy
        koniec->nastepny = nowy; //ostatni element wskazuje na nowy
        koniec = nowy; //przesuniecie wskaznika na nowy ostatni el
    }
}

//funkcja wczytujaca dane z pliku do listy
void wczytajPlik(ifstream& wejscie, struct lista*& szczyt, struct lista*& koniec) {
    string tekst;//przechowywanie linii odczytanej z pliku

    //petla wykonujaca sie do momentu odczytania wszystkich lin
    while (getline(wejscie, tekst)) {
        dodajElement(szczyt, koniec, tekst);
    }
}

//funkcja wyswietlajaca liste i zapisujaca dane do pliku
void wyswietlIZapisz(struct lista* szczyt, ofstream& wyjscie) {
    struct lista* pomoc = szczyt;//wskaznik pomoc odnosi sie do 1szego el

    while (pomoc != nullptr)//petla wykonuje sie tak dlugo jak pomoc wskazuje na istniejacy el
    {
        cout << pomoc->dane << endl; //wypisanie
        wyjscie << pomoc->dane << endl;//zapis do pliku

        pomoc = pomoc->nastepny; //wskaznik pomoc przesuniety na kolejny el listy
    }
}

//funkcja usuwajaca elementy listy
void usunListe(struct lista*& szczyt) {
    struct lista* pomoc = szczyt;//powrot na poczatek listy

    while (pomoc != nullptr) {//petla wykonuje sie tak dlugo jak pomoc wskazuje na istniejacy el
        struct lista* usun = pomoc; //wskaznik usun wskazuje na obecny element do usuniecia
        pomoc = pomoc->nastepny/*sostep do pomoc przez nastepny*/;
        /*zwolnienie pamieci tymczasowej*/
        delete usun;
    }

    szczyt = nullptr;
}

int main() {
    ifstream wejscie("wejscie.txt");//otwarcie plikow
    ofstream wyjscie("wyjscie.txt");

    if (!wejscie.is_open() || !wyjscie.is_open()) {//jesli ktorys z plikow sie nie otworzyl zwroc blad
        cout << "Blad w plikach" << endl;
        return 1;
    }

    //utworzenie wskaznikow ( od 1 elementu listy [szczyt] , ostatniego [koniec] i aktualnego [nowy])
    struct lista* szczyt = /*nie wskazuje zadnego obiektu bo poczatkowo lista jest pusta*/nullptr;
    struct lista* koniec = nullptr;

    //wczytanie danych z pliku do listy
    wczytajPlik(wejscie, szczyt, koniec);

    //wyswietlenie listy i zapisanie jej do pliku
    wyswietlIZapisz(szczyt, wyjscie);

    //usuniecie wszystkich elementow listy
    usunListe(szczyt);

    wejscie.close();//zamkniecie plikow
    wyjscie.close();

    return 0;
}
