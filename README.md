Lista jednokierunkowa w C++
Opis projektu

Program napisany w języku C++, który obsługuje listę jednokierunkową. Dane są odczytywane z pliku tekstowego, zapisywane w kolejnych elementach listy, a następnie wyświetlane w konsoli i zapisywane do pliku wyjściowego.

Program wykorzystuje funkcje, dynamiczną alokację pamięci oraz obsługę plików.

Funkcjonalności
Odczytywanie danych z pliku wejscie.txt.
Tworzenie listy jednokierunkowej.
Dodawanie elementów na koniec listy.
Wyświetlanie zawartości listy w konsoli.
Zapisywanie danych do pliku wyjscie.txt.
Usuwanie elementów listy i zwalnianie pamięci.
Sprawdzanie poprawności otwarcia plików.
Wykorzystane technologie
C++
Biblioteki standardowe: iostream, fstream, string
Lista jednokierunkowa
Wskaźniki i dynamiczna alokacja pamięci
Funkcje
Struktura programu

Program został podzielony na następujące funkcje:

dodajElement() – dodaje nowy element na koniec listy.
wczytajPlik() – odczytuje dane z pliku i umieszcza je na liście.
wyswietlIZapisz() – wyświetla dane w konsoli i zapisuje je do pliku wyjściowego.
usunListe() – usuwa wszystkie elementy listy i zwalnia zajętą pamięć.
main() – odpowiada za otwarcie plików i wywołanie pozostałych funkcji.
Pliki wejściowe i wyjściowe

Program korzysta z dwóch plików tekstowych:

wejscie.txt – plik zawierający dane do odczytania, po jednej linii na element listy.
wyjscie.txt – plik, do którego zapisywana jest zawartość listy.
Przykład

Zawartość pliku wejscie.txt:

3
7
1
2


Wynik wyświetlony w konsoli i zapisany w pliku wyjscie.txt:

text
Ala ma kota
Programowanie w C++
Lista jednokierunkowa

Uruchomienie programu
Sklonuj repozytorium lub pobierz pliki na komputer.
Utwórz plik wejscie.txt w katalogu, z którego będzie uruchamiany program.
Umieść w nim dane do odczytania.
Skompiluj program za pomocą kompilatora C++, np. g++:
bash
g++ main.cpp -o lista

Uruchom program:

Windows:

bash
lista.exe


Linux:

bash
./lista

Wynik znajdziesz w konsoli oraz w pliku wyjscie.txt.
Obsługa błędów

Jeżeli nie uda się otworzyć pliku wejściowego lub wyjściowego, program wyświetli komunikat:

text
Blad w plikach
