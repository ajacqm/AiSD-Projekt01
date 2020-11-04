/*Algorytmy i Struktury Danych*/
/*Jakub Matuszko Grupa 5*/
/*Uporzadkuj zadane tablice wielu powtarzajacych sie elementow, tak aby zgromadzic te same elementy
zachowujuc kolejnosc ich pierwszego wystapienia.*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;

void sort(int tab[]) //Funkcja sortujaca elementy wzgledem ich wystapienia
{
    int znacznik=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(tab[i]==tab[j])
            {
                for(int k=j; k>i+1; k--) //Petla malejaca - przestawiajaca elementy
                {
                    swap(tab[k],tab[k-1]);// Funkcja przestawiajaca dwa elementy
                }
            }
        }
    }
}

int main()
{
    cout << "Wprowadz ilosc elementow: ";
    cin >> n;//Deklaracja ilosci elementow tablicy
    int tab[n];

    for(int i=0; i<n; i++)//Wczytywanie elementow do tablicy
    {
        cout << "Wprowadz " << i+1 << " element tablicy: ";
        cin >> tab[i];
    }

    sort(tab); //Wywolanie funkcji sort z przekazaniem tablicy tab

    for(int i=0; i<n; i++)//Wypisywanie elementow z tablicy
    {
        cout << "Element: " << i+1 << " jest rowny: " << tab[i] << endl;
    }
    return 0;
}
