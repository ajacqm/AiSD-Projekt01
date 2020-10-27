/*Algorytmy i Struktury Danych*/
/*Jakub Matuszko Grupa 5*/
/*Uporzadkuj zadane tablice wielu powtarzajacych sie elementow, tak aby zgromadzic te same elementy
zachowujuc kolejnosc ich pierwszego wystapienia.*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;

void sort(int tab[])
{
    /*Ogolnie cel jest taki zeby przesuwac tablice w prawo*/
    int znacznik, temp;
    for(int i=0; i<n; i++)
    {
        znacznik = tab[i];
        for(int j=i+1; j<n; j++) //1+1 ? - sprawdzic pozniej czy jest okej
        {
            if(tab[i]!=tab[j])
            {
                for(int k=j+1; k<n; k++)
                {
                    if(tab[k]==znacznik)
                    {
                        for(int p=k; p>j; p--)
                        {
                            swap(tab[p],tab[p-1]); //przesuwanie elementow tablicy
                        }
                    }
                }
            }
        }
    }
}

void sort2(char tab[]) //drugi sposob obliczania
{
    char znacznik;
    char tab2[n];
    int z=0;
    for(int i=0; i<n; i++)
    {
        if(tab[i] != '\0')
        {
            znacznik = tab[i];
            for(int j=i; j<n; j++)
            {
                if(tab[j]==znacznik)
                {
                    cout << "BUG: I: " << tab[j] << " - " << znacznik << endl;
                    tab2[z] = znacznik;
                    tab[j] = '\0';
                    z++;
                    cout << "BUG: Z" << z <<endl;
                }
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout << "Element: " << i+1 << " jest rowny: " << tab2[i] << endl;
    }

}

int main()
{
    cout << "Wprowadz ilosc elementow: ";
    cin >> n;
    char tab[n];
    for(int i=0; i<n; i++)
    {
        cout << "Wprowadz " << i+1 << " element tablicy: ";
        cin >> tab[i];
    }
    sort2(tab); //Przekazanie tablicy do funkcji

    return 0;
}
