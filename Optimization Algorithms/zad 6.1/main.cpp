#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Podaj n: " << endl;
    cin>>n;
    int cenyakcji[n];
    cout<<endl<<"Wprowadz ceny akcji do tablicy: "<<endl;
    for (int i=0; i<n; i++)
    {
     cin>>cenyakcji[i];
    }
    cout<<endl<<"Twoja tablica cen: "<<endl;
     for (int i=0; i<n; i++)
    {
     cout<<cenyakcji[i]<<" ";
    }

    int zysk=0,cena=cenyakcji[0],dzienkupna=1,dziensprzedarzy=1;
    int pomdni=0;

    for (int i=1; i<n; i++)
        {
         if(cenyakcji[i]-cena>zysk) { zysk=cenyakcji[i]-cena; dziensprzedarzy=i+1;if(pomdni<i){dzienkupna=pomdni+1;} }
         if(cenyakcji[i]<cena)      { cena=cenyakcji[i];pomdni=i; }

        }

    cout<<endl<<endl<<"Najwyzszy zysk to : "<<zysk;
    cout<<endl<<endl<<"Najlepiej kupic dnia : "<<dzienkupna<<" sprzedac dnia : "<<dziensprzedarzy;

    cout<<endl<<endl;
    return 0;
}
