#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

int main()
{
    std::fstream plik;
    std::fstream obrot("i100obrot.ppm");
    plik.open("i100.ppm");
    if( !plik.good() )
         std::cout<<"Nie mozna otworzyc pliku "<<std::endl;

std::string r,g,b,h;
int x,y,z;
int ***tablica;
tablica = (int***)malloc(100 * sizeof(int**));
for( x = 0; x < 100; ++x)
{
    tablica[x] = (int**)malloc(100 * sizeof(int*));
    for( y = 0; y < 100; ++y)
       tablica[x][y] = (int*)malloc(3 * sizeof(int));
}

    plik>>r>>g>>b>>h;
    obrot<<r<<"\n"<<g<<" "<<b<<"\n"<<h<<std::endl;


for(x=0;x<100;x++)
for(y=0;y<100;y++)
for(z=0;z<3;z++)
{
    plik>>r;
    tablica[x][y][z]=atoi(r.c_str());

}
for(x=0;x<100;x++)
for(y=0;y<100;y++)
for(z=0;z<3;z++)
{

    obrot<<tablica[y][99-x][z]<<" ";
}

for( x = 0; x < 3; ++x)
{
    for( y = 0; y < 100; ++y)
        free(tablica[x][y]);
    free(tablica[x]);
}
free(tablica);
std::cout<<"Nowe zdjecie zostalo stworzone"<<std::endl;
obrot.close();
plik.close();
return 0;
}
