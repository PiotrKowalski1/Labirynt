#include <conio.h>
#include <windows.h>
#include <iostream>
#include "interfejs.h"

using namespace std;

// Funkcja umożliwia uzytkownikowi poruszanie się po labiryncie i jednocześnie sprawdza czy nie nastąpiła wygrana
//---------------------------------------------------------------------------------------------------------------

void sterowanie(char** labirynt,int w,int s,char sciana,char korytarz)
{ char kod; char znakS='S',znakK='K';
    int x=1,y=1;
    labirynt[x][y]=znakS;  //ustawiamy punkt starowy na początku labiryntu
    labirynt[w-2][s-2]=znakK;  //ustawiamy punkt końcowy na końcu labiryntu
    system("cls");
    wyswietl(labirynt,w,s);
    while(x!=w-2 || y!=s-2)
{
    kod=getch();
    switch(kod)
    { case 72:  if(x> 1 &&labirynt[x-1][y]!=sciana)              //poruszamy się w górę, pod warunkiem,że nie ma tam śćiany i nie wyjdziemy poza labirynt
        {
            labirynt[x][y]=korytarz;
            x -=1;
            labirynt[x][y]=znakS;
            system("cls");
            wyswietl(labirynt,w,s);}
        break;
    case 77:  if(y< s-2 && labirynt[x][y+1]!=sciana)         //poruszamy się w prawo, pod warunkiem,że nie ma tam śćiany i nie wyjdziemy poza labirynt
        {   labirynt[x][y]=korytarz;
            y += 1;
            labirynt[x][y]=znakS;
            system("cls");
            wyswietl(labirynt,w,s);}
        break;
    case 80:  if(x < w-2 && labirynt[x+1][y]!=sciana) //poruszamy się w dół, pod warunkiem,że nie ma tam śćiany i nie wyjdziemy poza labirynt
        {   labirynt[x][y]=korytarz;
            x += 1;
            labirynt[x][y]=znakS;
            system("cls");
            wyswietl(labirynt,w,s);}
        break;
    case 75:  if(y > 1 && labirynt[x][y-1]!=sciana) //poruszamy się w lewo, pod warunkiem,że nie ma tam śćiany i nie wyjdziemy poza labirynt
        {    labirynt[x][y]=korytarz;
            y -=1 ;
            labirynt[x][y]=znakS;
            system("cls");
            wyswietl(labirynt,w,s);}
        break;
     }
}
    cout<<"Gratulacje wygrana!!!"<<endl;
}
