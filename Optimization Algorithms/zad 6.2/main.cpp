#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
     int n,w;
    cout << "Podaj ilosc plikow" << endl;
    cin>>n;
    int t[n+1][2];
    t[0][0]=0;t[0][1]=0;
    cout<<endl<<"Podaj elementy tablicy t"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<"t["<<i<<"][0] = ";
        cin>>t[i][0];
        cout<<"t["<<i<<"][1] = ";
        cin>>t[i][1];
    }
    cout <<endl<<"Podaj ograniczenie zapisu" << endl;
    cin>>w;

    int v[n+1][w+1];

    for(int i=0; i<=n; i++)
     {
          for(int j=0; j<=w; j++)
            v[i][j]=0;
    }

    int waga, cena,poprzednia,aktualna;

    for (int i=1; i<=n; i++)
    {
        waga = t[i][1];
        cena = t[i][0];

       for (int j=1; j<=w; j++)
       {
           poprzednia = v[i-1][j];

           if (waga>j) v[i][j] = poprzednia;
           else
           {
                 aktualna  = v[i-1][j-waga]+ cena;
                if (aktualna>poprzednia) v[i][j] = aktualna;
                else v[i][j] = poprzednia;
            }
       }
    }

    cout<<endl<<"Tablica"<<endl<<endl;
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=w; j++) cout<<v[i][j]<<"\t";
        cout<<endl;
    }

    waga=0;
    cena=0;

    cout<<endl<<"Maksymalny czas obliczeniowy plikow "<<v[n][w]<<endl;

     cout<<endl;

    int x=n;
    int y = w;
    while (x>0 && y>0)
    {
       while (x>0 && v[x][y]==v[x-1][y])
        { x--; }
       if(x!=0){ cout<<"Nalezy wybrac plik : "<<x<<endl; }
       waga += t[x][1];
       cena += t[x][0];
       y -= t[x][1];
       x--;
    }

    cout<<endl<<endl;
    return 0;
}
