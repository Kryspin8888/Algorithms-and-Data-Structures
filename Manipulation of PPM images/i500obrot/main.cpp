#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

int main()
{
    std::fstream plik;
    std::fstream obrot("i500obrot.ppm");
    plik.open("i500.ppm");
    if( !plik.good() )
         std::cout<<"Nie mozna otworzyc pliku "<<std::endl;

std::string r,g,b,h;
int x,y,z;
int ***tablica;
tablica = (int***)malloc(500 * sizeof(int**));
for( x = 0; x < 500; ++x)
{
    tablica[x] = (int**)malloc(500 * sizeof(int*));
    for( y = 0; y < 500; ++y)
       tablica[x][y] = (int*)malloc(3 * sizeof(int));
}

    plik>>r>>g>>b>>h;
    obrot<<r<<"\n"<<g<<" "<<b<<"\n"<<h<<std::endl;


for(x=0;x<500;x++)
for(y=0;y<500;y++)
for(z=0;z<3;z++)
{
    plik>>r;
    tablica[x][y][z]=atoi(r.c_str());

}
for(x=0;x<500;x++)
for(y=0;y<500;y++)
for(z=0;z<3;z++)
{

    obrot<<tablica[y][499-x][z]<<" ";
}

for( x = 0; x < 3; ++x)
{
    for( y = 0; y < 500; ++y)
        free(tablica[x][y]);
    free(tablica[x]);
}
free(tablica);
std::cout<<"Nowe zdjecie zostalo stworzone"<<std::endl;
obrot.close();
plik.close();
return 0;
}
