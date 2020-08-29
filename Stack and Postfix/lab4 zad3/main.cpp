#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#define size 20

using namespace std;

int main()
{
  double tab[size];
  int komorka = 0;
  string e;
  double a,b;
  stringstream ss;      // strumieñ ³añcuchowy

cout<<"Podaj wyrazenie w postaci postfix:"<<endl;
cout<<"Znak '=' konczy wprowadzanie:"<<endl<<endl;

  while(true)
  {
    getline(cin,e);

    if(e == "=") break;

    ss.str("");         // usuwamy wszelki tekst ze strumienia
    ss.clear();         // czyœcimy b³êdy konwersji z poprzednich wywo³añ
    ss << e;            // odczytany element umieszczamy w strumieniu

    if(ss >> a)

      tab[komorka++] = a;      // umieszczamy j¹ na stosie

    else
    {
      b = tab[--komorka];
      a = tab[--komorka];
      switch(e[0])
      {
        case '+' : a += b; break;
        case '-' : a -= b; break;
        case '*' : a *= b; break;
        case '/' : a /= b; break;
      }
      tab[komorka++] = a;
    }
  }

  cout <<endl<<"Wynik to:"<<endl<<endl<<tab[--komorka] << endl;

  return 0;
}
