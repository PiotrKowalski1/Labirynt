#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include "interfejs.h"
#include "algorytm.h"
#include <fstream>
#include "player.h"

using namespace std;

// Funkcja wyświetla menu z opcjami programu
//-------------------------------------------------------------------
void start()
{
cout<<"-------------------------------"<<endl;
cout<<"-------------------------------"<<endl;
cout<<"Witaj w programie labirynt"<<endl;
cout<<"-------------------------------"<<endl;
cout<<"-------------------------------"<<endl;
cout<<"           MENU           "<<endl;
cout<<"-------------------------------"<<endl;
cout<<"-------------------------------"<<endl;
cout<<"1.Znajdowanie najkrotszej drogi-ALGORYTM"<<endl;
cout<<endl;
cout<<"2.Gra w labirynt"<<endl;
cout<<endl;
cout<<"3.Wyjscie"<<endl;
cout<<"-------------------------------"<<endl;
cout<<"-------------------------------"<<endl;
cout<<"Wybierz..."<<endl;


}
// Funkcja umożliwia uzytkownikowi wybór jednej z trzech opcji programu (pokazanie algorytmu BFS, gra w przechodzenie labiryntu lub wyjśćie)
//-------------------------------------------------------------------
void wybor()
{  char znak;
do
 {   znak= getch();
   if(znak=='1')
      ustawienia_uzytkownika(1);
   else if(znak=='2')
      ustawienia_uzytkownika(2);
   else if(znak=='3')
       exit(0);
   else
   {
       cout<<"wybierz jescze raz!!!";
     cout<<"\r\a";} }
    while(znak!='1'&&znak!='2'&&znak!='3');

}
// Funkcja umożliwia uzytkownikowi ustawienie rozmiarow labiryntu
//-------------------------------------------------------------------
void ustawienia_uzytkownika(int pom)
{ system("cls");
int wysokosc=13, szerokosc=13;
    cout<<"Podaj rozmiary labiryntu"<<endl;
    cout<<endl<<endl;
    cout<<"Podaj szerokosc labiryntu"<<endl;
    cin>>szerokosc;
    if(szerokosc<1)
        szerokosc=3;
    if(szerokosc%2==0)
        szerokosc=szerokosc+1;

    cout<<"Podaj wysokosc labiryntu"<<endl;
    cin>>wysokosc;
    if(wysokosc<1)
        wysokosc=3;
    if(wysokosc%2==0)
        wysokosc=wysokosc+1;

    Sleep(500); system("cls");
    char **labirynt;
    labirynt=tworz_labirynt(wysokosc, szerokosc);



     char sciana='x';  char korytarz=' ';
     rysuj(labirynt,wysokosc,szerokosc,sciana,korytarz);

    if(pom==1) {ustawS_K(labirynt,korytarz,wysokosc,szerokosc); }
    if(pom==2) sterowanie(labirynt,wysokosc,szerokosc,sciana,korytarz);
    kasuj_labirynt(labirynt,wysokosc);
}
// Funkcja tworzy labirynt
//-------------------------------------------------------------------
void rysuj(char **labirynt, int w, int s ,char &sciana, char &korytarz)
{

      czytajzpl(sciana,korytarz);





       for(int x=0; x<w; x++)
           for(int y=0; y<s; y++)
               labirynt[x][y]=sciana;

        for(int x=1; x<w; x+=2)
            for(int y=1;y<s; y+=2)
            {labirynt[x][y]=korytarz;

                if(rand() % 3 == 0)
                {
                    if(x > 1)
                        labirynt[x-1][y] = korytarz;
                }
                else    if(rand() % 3 == 0)
                {
                    if(y > 1)
                        labirynt[x][y-1] = korytarz;

                }
                else
                {
                    if(rand() % 2)
                    {
                        if(x > 1) labirynt[x-1][y] =korytarz ;
                    }
                    else
                    {
                        if(y > 1) labirynt[x][y-1] = korytarz;
                    } } }

         zapiszdopl(labirynt,w,s);

        }
// Funkcja wyświetla labirynt
//-------------------------------------------------------------------
        void wyswietl(char**labirynt,int w, int s)
          {
              for(int x=0; x<w; x++)
              {for(int y=0; y<s; y++)
                      cout<<labirynt[x][y];
                  cout<<endl;} }
        // Funkcja czyta z pliku wzory scian i korytarzy labiryntu
        //-------------------------------------------------------------------

        void czytajzpl(char &sci  , char &kor )
          {
              ifstream plik("wzor.txt");
              if(!plik.good())
                  return;
              plik>>sci;
              plik>>kor;
              plik.close();

          }

 // Funkcja zapisuje utworzony labirynt do pliku
 //-------------------------------------------------------------------
        void zapiszdopl(char** labirynt,int w,int s)
        {
            ofstream plik1("labirynt.txt");
            for(int x=0;x<w;x++)
               { for(int y=0;y<s;y++)
                    plik1<<labirynt[x][y];
                plik1<<endl;
                }
            plik1.close();

        }
 // Funkcja tworzy labirynt jako liste dynamiczą
 //-------------------------------------------------------------------
char** tworz_labirynt(int w,int s)
{
char **labirynt=new char*[w];
for(int x=0; x<w; x++)
    labirynt[x]=new char [s];
return labirynt;
}
// Funkcja usuwa labirynt
//-------------------------------------------------------------------
void kasuj_labirynt(char**labirynt,int w)
{
    for(int x=0; x<w; x++)
        delete []labirynt[x];
    delete []  labirynt;

}


