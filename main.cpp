/*Algorytmy i Struktury Danych*/
/*Jakub Matuszko Grupa 5*/
/*Uporzadkuj zadane tablice wielu powtarzajacych sie elementow, tak aby zgromadzic te same elementy
zachowujuc kolejnosc ich pierwszego wystapienia.*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void f_swap(int &a,int &b)//Funkcja przestawiajaca dwa elementy
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void sort(vector <int> &numbers) //Funkcja sortujaca - wzgledem kolejnosci wystepowania elementow
{
    for(int i=0; i<numbers.size(); i++)
    {
        for(int j=i+1; j<numbers.size(); j++)
        {
            if(numbers[i]==numbers[j])
            {
                for(int k=j; k>i+1; k--)
                {
                    f_swap(numbers[k],numbers[k-1]);
                }
                i++; //Inkrementacja i, przestawia pierwszy wskaznik po znalezieniu liczby rownej numbers[i];
            }
        }
    }
}

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    int n;
    vector <int> numbers;
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
        sort(numbers);
        for(int i=0; i<numbers.size();i++)
        {
            output << numbers[i] << "; ";
        }
    }
    return 0;
}

