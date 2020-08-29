#include<iostream>
#include<cstring>
#include<cstdlib>

#define ERROR '!'
#define size 20

using namespace std;

char infix[size], postfix[size], tab[size];

int komorka=0;

int waga(char ch);          // porównuje wagi operatorów
char pop();                 // pobiera element ze stosu
char peek();                // zwraca element ze szczytu stosu
void push(char ch);         // odk³ada element na stos
int b;

int main()
{
char element1, element2;
int pom1,pom2,pom3,j=0;
strcpy(postfix," ");

cout<<"*Podaj wyrazenie w notacji infix: "<<endl<<endl;
cin>>infix;

for(int i=0;infix[i]!=0;i++)
{

    if(infix[i]!='('&&infix[i]!=')'&&
       infix[i]!='^'&&infix[i]!='*'&&
       infix[i]!='/'&&infix[i]!='+'&&
       infix[i]!='-')

    postfix[j++]=infix[i];

    else if(infix[i]=='(')
    {
        element2=infix[i];
        push(element2);
    }

    else if(infix[i]==')')
    {
        while((pom3=pop()) != '(')
        postfix[j++]=pom3;
    }
    else
    {
        element2=infix[i];
        pom2=waga(element2);      //waga operatora z wejscia
        element1=peek();
        pom1=waga(element1);      //waga operatora ze szczytu stosu

        if(pom2 > pom1)
        push(element2);

        else
        {
        while(pom1 >= pom2)
        {
        if(element1==ERROR)
        break;

        pom3=pop();
        element1=peek();
        postfix[j++]=pom3;
        pom1=waga(element1);
        }
        push(element2);
        }
    }
}
while((pom3=pop())!=ERROR)
postfix[j++]=pom3;
postfix[j++]='\0';

cout<<endl<<"*Wyrazenie w notacji postfix to :"<<endl<<endl<<postfix<<endl<<endl;

system("pause");
return 0;
}
int waga(char ch)
{
switch(ch)
{
case '^' : return 5;
case '/' : return 4;
case '*' : return 4;

case '+' : return 3;
case '-' : return 3;
default : return 0;
}
}

char pop()       //funkcja zdejmuje element ze stosu
{
char ret;
if(komorka!=0)
    {
    ret = tab[komorka];
    komorka--;
    return ret;
    }
else

    return ERROR;
}

char peek()    // funkcja zwraca element ze stosu bez jego zdejmowania
{
char ch;
if(komorka!=0)
    ch=tab[komorka];
else
    ch=ERROR;

return ch;
}

void push(char ch) // funkcja umieszcza element na stosie
{
if(komorka!=size-1)
    {
    komorka++;
    tab[komorka]= ch;
    }
}
