/*Algorytmy i Struktury Danych*/
/*Jakub Matuszko Grupa 5*/
/*Uporzadkuj zadane tablice wielu powtarzajacych sie elementow, tak aby zgromadzic te same elementy
zachowujuc kolejnosc ich pierwszego wystapienia.*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void f_swap(int &a,int &b)  //Funkcja zmieniajaca miejscami dwie liczby (poprzez podanie adresu liczby)
{
    int temp = a;           //Zmienna temp - przechowuje tymczasowa wartosc liczby a;
    a = b;                  //Przypisanie zmiennej a watrosci z liczby b
    b = temp;               //Przypisanie zmiennej b wartosci tymczasowej
}

void sort(vector <int> &numbers)                        //Funkcja sortujaca wzgledem wystapienia liczb
{
    for(int i=0; i<numbers.size(); i++)                 //Petla i, to do wektora z jej indeksem porownywane sa liczby
    {
        for(int j=i+1; j<numbers.size(); j++)           //Petla j, druga liczba z wektora o indeksie j jest porownywana z i
        {
            if(numbers[i]==numbers[j])                  //Porownanie liczby o indeksie i do liczby o indeksie j
            {
                for(int k=j; k>i+1; k--)                //Petla odpowiadajaca za przestawianie liczb, zamienia dwie obok siebie
                {                                       //jej celem jest przesuniecie liczby z pozycji j do pozycji i+1
                    f_swap(numbers[k],numbers[k-1]);    //Funkcja przestawiajaca dwa elementy
                }
                i++;                                    //Po odnalezieniu liczby rownej, zostaje przesuniety dodatkowo o jedno
            }                                           //miejsce indeks i
        }
    }
}

int main()
{
    ifstream input("input.txt");            //Deklaracja pliku wejsciowego
    ofstream output("output.txt");          //Deklaracja pliku wyjsciowego
    int n;
    vector <int> numbers;                   //Deklaracja wektora liczb
    if(!input.good())                       //Sprawdzanie poprawnosci otwarcia pliku
    {
        cerr << "File error";               //Przekazanie do konsoli informacji o bledzie pliku
        return 1;                           //Zwrocenie wartosci 1, konczy program
    }
    else                                    //W przeciwnym wypadku:
    {
        while(!input.eof())                 //Petla wczytujaca liczby do wektora do napotkania
        {                                   //konca pliku
            input >> n;
            if(input.fail())                //Sprawdzenie poprawnosci wczytanej liczby
            {                               //Jezeli wejscie wskaze blad:
                input.clear();              //Zostanie usunieta flaga bledu z wejscia
                input.ignore();             //Zostanie pominiety jeden znak
            }
            else numbers.push_back(n);      //Gdy nie bedzie bledu, program wczyta liczbe na koniec wektora
        }
        sort(numbers);                      //Przejscie do funkcji sortujacej
        for(int i=0; i<numbers.size();i++)  //Wypisanie posortowanych liczb do pliku
        {
            output << numbers[i] << "; ";
        }
    }
    return 0;
}

