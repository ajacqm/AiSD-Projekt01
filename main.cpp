/*Algorytmy i Struktury Danych*/
/*Jakub Matuszko Grupa 5*/
/*Uporzadkuj zadane tablice wielu powtarzajacych sie elementow, tak aby zgromadzic te same elementy
zachowujuc kolejnosc ich pierwszego wystapienia.*/
#include <iostream>

using namespace std;

int n;

void sort(int tab[])
{
}

int main()
{
    cout << "Wprowadz ilosc elementow: ";
    cin >> n;
    int tab[n];
    for(int i=0; i<n; i++)
    {
        cout << "Wprowadz " << i+1 << " element tablicy: ";
        cin >> tab[i];
    }
    sort(tab); //Przekazanie tablicy do funkcji
    for(int i=0; i<n; i++)
    {
        cout << "Element: " << i+1 << " jest rowny: " << tab[i] << endl;
    }

    return 0;
}
