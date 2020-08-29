#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

int main()
{
    std::fstream plik;
    std::fstream negacja("i100negacja.ppm");
    plik.open("i100.ppm");
    if( !plik.good() )
         std::cout<<"Nie mozna otworzyc pliku "<<std::endl;
std::string r1,g1,b1;
int r,g,b,x;
std::cout<<"Jaki kolor chcesz zanegowac wpisz jesli czerwony: 1, zielony: 2, niebieski: 3 ?"<<std::endl;
std::cin>>x;
for(int i=0;i<10000;i++)
{
    plik>>r1>>g1>>b1;
    if(i==0)
    negacja<<r1<<'\n'<<g1<<" "<<b1<<'\n'<<255<<std::endl;
    r=atoi(r1.c_str()); g=atoi(g1.c_str()); b=atoi(b1.c_str());
    if(x==1)
    g=255-g;
    if(x==2)
    b=255-b;
    if(x==3)
    r=255-r;                                      //w moim przypadku r=g g=b b=r
    if(i==1)
    negacja<<g<<" "<<b<<" ";
   if(i>=2)
    negacja <<r<<" "<<g<<" "<<b<<" "; //wyœwietlenie linii
}
std::cout<<"Nowe zdjecie zostalo stworzone"<<std::endl;
negacja.close();
plik.close();
return 0;
}
