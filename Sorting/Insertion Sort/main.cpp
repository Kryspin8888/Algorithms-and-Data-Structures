#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    unsigned long long n, operacje=0, pom, j;
    clock_t start, koniec;
    fstream plik;
    fstream plik1;
    plik.open("Wylosowane.txt");
    plik1.open("Posortowane.txt");
    if( !plik.good() && !plik1.good() )
         cout<<"Nie mozna otworzyc ktoregos pliku "<<std::endl;
    srand(time(NULL));
    cout << "SORTOWANIE PRZEZ WSTAWIANIE - INSERTION SORT: " << endl<<endl;
    cout << "Podaj liczbe elementow tablicy" << endl<<endl;
    cin>>n;
    cout<<endl;
    unsigned long long* tab = (unsigned long long*)malloc(n * sizeof(unsigned long long));
    for(unsigned long long i=0; i<n; i++)
    {
        tab[i] = rand() % (32000+1);
        plik<<tab[i]<<" ";
        if(i%19==0 && i!=0)
        plik<<'\n';
    }
    cout << "Wylosowanie liczby zostaly zapisane do pliku" << endl<<endl;
    start=clock();
    for(unsigned long long i=1; i<n; i++)
     {
                            //wstawienie elementu w odpowiednie miejsce
             pom = tab[i]; //ten element bêdzie wstawiony w odpowiednie miejsce
             j = i-1;

                                      //przesuwanie elementów wiêkszych od pom
             while(j>=0 && tab[j]>pom)
             {
                        tab[j+1] = tab[j];      //przesuwanie elementów
                        --j;
                        operacje++;
             }
             tab[j+1] = pom;
             operacje++;              //wstawienie pom w odpowiednie miejsce
     }
    koniec=clock();
    for(unsigned long long i=0; i<n; i++)
    {
        plik1<<tab[i]<<" ";
        if(i%19==0 && i!=0)
        plik<<'\n';
    }

    cout << "Posortowane liczby zostaly zapisane do pliku" << endl<<endl;
    cout << "Liczba operacji: " << operacje <<endl<<endl;
    cout <<"Czas sortowania: ";
    printf("%.3f",(double)(koniec - start) / (double)(CLOCKS_PER_SEC));
    cout <<endl<<endl;
    return 0;
}
