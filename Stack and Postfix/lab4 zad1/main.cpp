#include<iostream>
#include<cstdlib>

#define ERROR 1000000000
#define MAX 1000

using namespace std;

int tab[MAX],
i = 0;               //zmienna wskazujaca komórke tablicy, w której jest wierzcholek stosu

bool push(int element)
{
  if(i>=MAX) return 0;

  tab[i++] = element;
  return 1;
}

int pop()
{
  if(i==0) return ERROR;

  --i;
  return 1;
}

bool isEmpty()
{
  if(i==0) return 1;

  return 0;
}

long long int size()
{
  return i;
}

int peek()
{
  if(i==0) return ERROR; //gdy stos jest pusty

  return tab[i-1];
}

int main()
{
  if(!push(1)) cout<<"Stos jest przepelniony!\n";
  if(!push(2)) cout<<"Stos jest przepelniony!\n";
  if(!push(3)) cout<<"Stos jest przepelniony!\n";
  if(!push(4)) cout<<"Stos jest przepelniony!\n";

  cout<<"Liczba elementow na stosie: "<<size()<<endl;

  cout<<"Element, ktory mozna usunac: "<<peek()<<endl;
  pop();
  cout<<"Element, ktory mozna usunac: "<<peek()<<endl;
  pop();
  cout<<"Element, ktory mozna usunac: "<<peek()<<endl;
  pop();
  cout<<"Element, ktory mozna usunac: "<<peek()<<endl;
  pop();


  if(isEmpty())
    cout<<"Stos jest pusty\n";
  else
    cout<<"Na stosie znajduja sie elementy, jest ich "<<size()<<endl;

  if(pop()==ERROR)
    cout<<"Nie mozna usunac elementu ze stosu, poniewaz jest on pusty\n";

  system("pause");
  return 0;
}
