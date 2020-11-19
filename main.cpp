/*Algorytmy i Struktury Danych*/
/*Jakub Matuszko Grupa 5*/
/*Uporzadkuj zadane tablice wielu powtarzajacych sie elementow, tak aby zgromadzic te same elementy
zachowujuc kolejnosc ich pierwszego wystapienia.*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector <int> numbers;
void swap(int a,int b)//Funkcja przestawiajaca dwa elementy
{
    int temp;
    temp = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = temp;
}

void sort() //Funkcja sortujaca - wzgledem kolejnosci wystepowania elementow
{
    int znacznik=0;
    for(int i=0; i<numbers.size(); i++)
    {
        for(int j=i; j<numbers.size(); j++)
        {
            if(numbers[i]==numbers[j])
            {
                for(int k=j; k>i+1; k--) //Petla malejaca - przestawiajaca elementy
                {
                    swap(k,k-1);
                }
            }
        }
    }
}

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    int n;

    if(!input.good())
    {
        cerr << "File error";
        return 1;
    }
    else
    {
        while(!input.eof())
        {
            input >> n;
            numbers.push_back(n);
        }
        sort();
        for(int i=0; i<numbers.size();i++)
        {
            output << numbers[i] << "; ";
        }
    }
    return 0;
}

