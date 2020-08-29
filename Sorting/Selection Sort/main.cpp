#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    unsigned long long n, operacje=-1, k;
    clock_t start, koniec;
    fstream plik;
    fstream plik1;
    plik.open("Wylosowane.txt");
    plik1.open("Posortowane.txt");
    if( !plik.good() && !plik1.good() )
         cout<<"Nie mozna otworzyc ktoregos pliku "<<std::endl;
    srand(time(NULL));
    cout << "SORTOWANIE PRZEZ WYBOR - SELECTION SORT: " << endl<<endl;
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
    for(unsigned long long i = 0; i <n; i++ )
    {
        k = i;
        for(unsigned long long j = i + 1; j <n; j++ )
        if( tab[ j ] < tab[ k ] )
             k = j;

        swap( tab[ k ], tab[ i ] );
        operacje++;
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
