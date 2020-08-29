#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

int main()
{
    std::fstream plik;
    std::fstream negacja("i100szarosc.ppm");
    plik.open("i100.ppm");
    if( !plik.good() )
         std::cout<<"Nie mozna otworzyc pliku "<<std::endl;
std::string r1,g1,b1;
int r,g,b;
for(int i=0;i<10000;i++)
{
    plik>>r1>>g1>>b1;
    if(i==0)
    negacja<<r1<<'\n'<<g1<<" "<<b1<<'\n'<<255<<std::endl;
    r=atoi(r1.c_str()); g=atoi(g1.c_str()); b=atoi(b1.c_str());
    r=g=b=(r+g+b)/3;                                   //w moim przypadku r=g g=b b=r
    if(i==1)
    negacja<<g<<" "<<b<<" ";
   if(i>=2)
    negacja <<r<<" "<<g<<" "<<b<<" "; //wyœwietlenie linii
}
std::cout<<"Nowe szare zdjecie zostalo stworzone"<<std::endl;
negacja.close();
plik.close();
return 0;
}
