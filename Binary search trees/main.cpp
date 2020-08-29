#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>

using namespace std;

typedef struct element
{
          int liczba;
          struct element *rodzic;
          struct element *l_syn;
          struct element *p_syn;
} element;

struct element *root = NULL;

int operacje_dodawania=0;
int operacje_szukania=0;
int operacje_usuwania=0;
int wypisz_niektore=0;

void Dodaj(struct element *wchodzacy,int wstawiana)
{
    operacje_dodawania++;
          if (root == NULL)       //jesli nie ma korzenia to go robie
          {
            root = (element*)malloc(sizeof *root);
            root->liczba = wstawiana;
            root->l_syn = NULL;
            root->p_syn = NULL;
            root->rodzic = NULL;
          }
          else if (wstawiana<wchodzacy->liczba)    //jesli wprowadzany jest mniejszy niz ojcec -> idz na lewo
            {
            if(wchodzacy->l_syn != NULL)    //jesli poddrzewo istnieje to jeszcze raz wywoluje
            {
              Dodaj(wchodzacy->l_syn,wstawiana);
            }
            else  //jesli nie istnieje to dodaje element
            {
              element *nowy = (element*)malloc(sizeof *root);
              nowy->liczba = wstawiana;
              nowy->l_syn = NULL;
              nowy->p_syn = NULL;
              nowy->rodzic = wchodzacy;
              wchodzacy->l_syn = nowy;
            }
          }
            else if (wstawiana>wchodzacy->liczba)    //wiekszy niz ojciec -> idz w prawo
            {
            if (wchodzacy->p_syn != NULL)   //jesli prawe poddrzewo istniej to wywoluje funkcje ponownie
            {
              Dodaj(wchodzacy->p_syn,wstawiana);
            }
            else  //jesli nie istnieje to dodaje nowy element
            {
              element *nowy = (element*)malloc(sizeof *root);
              nowy->liczba = wstawiana;
              nowy->l_syn = NULL;
              nowy->p_syn = NULL;
              nowy->rodzic = wchodzacy;
              wchodzacy->p_syn = nowy;
            }
          }

}

void Tworz_drzewo()
{
     srand(time(NULL));
    int a,n;
    cout<<"Podaj N - liczbe elementow: "<<endl;
    cin>>n;
      for(int i=0;i<n;i++)
        {
        a = 1 + (int)(rand() / (RAND_MAX + 1.0) * 99999999);
        Dodaj(root,a);
        }
}

void Wypisz_drzewo(struct element *wchodzacy)
{
          if (wchodzacy->l_syn != NULL)
          {
            Wypisz_drzewo(wchodzacy->l_syn);   //jezeli ma dzieci po lewej stronie wywolaj funkcje ponownie
          }
               wypisz_niektore++;
        if(wypisz_niektore%100==0)
          cout<<wchodzacy->liczba<<setw(15);

          if (wchodzacy->p_syn != NULL)
          {
            Wypisz_drzewo(wchodzacy->p_syn);   //jezeli ma dzieci po prawej stronie wywolaj funkcje ponownie
          }

}

struct element *Szukaj(struct element *wchodzacy,int litera)
{
                operacje_szukania++;
          if (litera==wchodzacy->liczba)    //jezeli wezel ma szukana wartosc to znaleziony
          {
            cout<<endl<<"Znalazlem element: "<< wchodzacy->liczba<<endl;
            return wchodzacy;
          }
          else if (litera<wchodzacy->liczba && wchodzacy->l_syn != NULL)  //jezeli szukana wartosc jest mniejsza to szukamy w lewym poddrzewie
          {
            return Szukaj(wchodzacy->l_syn,litera);
          }
          else if (litera>wchodzacy->liczba && wchodzacy->p_syn != NULL)  //jezeli szukana wartosc jest wieksza to szukamy w prawym poddrzewie
          {
            return Szukaj(wchodzacy->p_syn,litera);
          }
          cout<<endl<<"Nie znalazlem elementu: "<< litera<<endl;
          return NULL;
}

struct element* Skrajnie_lewy(struct element *wchodzacy)   //szuka skrajnie lewego czyli najmniejszego elementu
{
        if(wchodzacy->l_syn != NULL)
        return Skrajnie_lewy(wchodzacy->l_syn);
        else
        return wchodzacy;
}

void Usun(struct element *wchodzacy)
{
    operacje_usuwania++;
          if(wchodzacy->l_syn==NULL && wchodzacy->p_syn==NULL)     //jezeli wezel nie ma dzieci
            {
            if(wchodzacy->rodzic==NULL)      //jezeli wezel jest korzeniem
            {
              root=NULL;
            }
            else if(wchodzacy->rodzic->l_syn==wchodzacy)    //jezeli wezel jest po lewej stronie rodzica
            {
              wchodzacy->rodzic->l_syn=NULL;    //usun wezel z lewej strony wezla rodzica
            }
            else   //usun wezel z prawej strony wezla rodzica
            {
              wchodzacy->rodzic->p_syn=NULL;
            }
          }
          else if(wchodzacy->l_syn==NULL || wchodzacy->p_syn==NULL)   //jezeli wezel ma tylko jedno dziecko
          {
            if(wchodzacy->l_syn==NULL)  //jezeli po lewej stronie nie ma dziecka
            {
              if(wchodzacy->rodzic==NULL)  //jezeli wezel jest korzeniem
              {
                root=wchodzacy->p_syn;
              }
              else if(wchodzacy->rodzic->l_syn==wchodzacy)  //jezeli wezel jest po lewej stronie rodzica
              {
                wchodzacy->rodzic->l_syn=wchodzacy->p_syn;  //dodaj z lewej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
              }
              else
              {
                wchodzacy->rodzic->p_syn=wchodzacy->p_syn;  //dodaj z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
              }
            }
            else
            {
              if(wchodzacy->rodzic==NULL)  //jezeli wezel jest korzeniem
              {
                root=wchodzacy->l_syn;
              }
              else if(wchodzacy->rodzic->l_syn==wchodzacy)  //jezeli wezel jest po lewej stronie rodzica
              {
                wchodzacy->rodzic->l_syn=wchodzacy->l_syn;  //dodaj z lewej strony rodzica wezel bedacy po lewej stronie usuwanego wezla
              }
              else
              {
                wchodzacy->rodzic->p_syn=wchodzacy->l_syn;  //dodaj z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
              }
            }
          }
          else  //wstaw w miejsce usuwanego elementu - najmniejsza wartosc z prawego poddrzewa
          {
            struct element *temp;
            temp=Skrajnie_lewy(wchodzacy->p_syn);
            wchodzacy->liczba = temp->liczba;
            Usun(temp);
          }
}



int main()
{
   Tworz_drzewo();

   cout<<endl<<"Niektore elementy drzewa posortowane: "<<endl<<endl;
      Wypisz_drzewo(root);
      cout<<endl;

    wypisz_niektore=0;
    operacje_dodawania=0;

      Dodaj(root,1234567899);

cout<<endl<<"Operacje dodawania : "<<operacje_dodawania<<endl;
operacje_dodawania=0;

int a;
cout<<endl<<"Jaki element wyszukac ? :"<<endl;
cin>>a;
Szukaj(root,a);

cout<<endl<<"Operacje szukania : "<<operacje_szukania<<endl;
operacje_szukania=0;

cout<<endl<<"Jaki element usunac ? :"<<endl;
cin>>a;

if(Szukaj(root,a)==0) {cout<<endl<<"Nie ma takiego elementu do usuniecia - ZAMYKAM PROGRAM"<<endl;return 1;}
else
Usun(Szukaj(root,a));

cout<<endl<<"Operacje usuwania : "<<operacje_usuwania<<endl;
operacje_usuwania=0;
operacje_szukania=0;

return 0;
}
