#include <iostream>

using namespace std;

int lucas (int n)
{
    if(n==0) return 2;
    else if(n==1) return 1;
    else return lucas(n-2)+lucas(n-1);

}
int main()
{
    int x;
    cout << "Ile liczb Lucasa chcesz wypisac ? " << endl;
    cin>>x;
    cout<<"Oto wynik :"<<endl;
    for(int i=0; i<x; i++)
    cout<<lucas(i)<<" ";
    return 0;
}
