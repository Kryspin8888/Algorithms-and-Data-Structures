#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std;

int m=6;
int n=100;

void stworz_tablice(char *a, int *p1)
{
    int j;
    p1[0] = -1;
    for (int i = 1; i < m; i++)
    {
        j = p1[i - 1];
        while (j >= 0)
        {
            if (a[j] ==a[i - 1])
                break;
            else
                j = p1[j];
        }
        p1[i] = j + 1;
    }
}

bool szukaj_wzorca(char *w, char *t, int *x)
{
    int f[m];
    stworz_tablice(w, f);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (j == -1)
        {
            i++;
            j = 0;
        }
        else if (t[i] == w[j])
        {
            i++;
            j++;
            if (j == m)
            {
                *x=i-m;
                return 1;
            }
        }
        else
            j = f[j];
    }
    return 0;
}

int main()
{
    char tekst[n], wzorzec[m];
    int p[m], y=0;
    int *y1=&y;

    srand(time(NULL));

  for(int i = 0; i < n; i++)
  {
      tekst[i] = 65 + rand() % 2;
  }
  for(int i = 0; i < m; i++)
  {
      wzorzec[i] = 65 + rand() % 2;
  }

  szukaj_wzorca(wzorzec,tekst,y1);
      cout<<"Twoj wylosowany tekst to: "<<endl<<endl;
  for(int i = 0; i < n; i++)
  {
      if(i==y-1) {tekst[i]=(char)219; tekst[i+m+1]=(char)219;}
      cout<<tekst[i];
  }
   cout<<endl<<endl<<"Twoj wylosowany wzorzec to: "<<endl<<endl;
  for(int i = 0; i < m; i++)
  {
      cout<<wzorzec[i];
  }
  cout<<endl<<endl;

  cout<<"Wypelniona tablica: "<<endl<<endl;
  stworz_tablice(wzorzec,p);

  for(int i=0; i<m; i++)
    cout<<p[i]<<" ";

  cout<<endl<<endl;

    if (szukaj_wzorca(wzorzec, tekst,y1))
        cout<<"Wzorzec znaleziony - zaczyna sie na pozycji "<<y<<" tesktu"<<endl;
    else
        cout<<"Wzorzec nie znaleziony"<<endl;

     cout<<endl<<endl;
    system("pause");
    return 0;
}
