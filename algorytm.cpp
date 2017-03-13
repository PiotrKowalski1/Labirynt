#include <iostream>
#include "algorytm.h"
#include "interfejs.h"
#include <windows.h>
#include <conio.h>


using namespace std;

int MAXINT=-2147483647;

// Konstruktor, którzy tworzy liste
//---------------------------------

kolejka::kolejka(slistEl *h, slistEl *t)
{
    glowa =h;
    ogon =t;
}


// Destruktor, który usuwa liste
//---------------------------------

kolejka::~kolejka()
{
    while(glowa) usun();
}



// Sprawdza, czy kolejka jest pusta
//---------------------------------

bool kolejka::pusty(void)
{
    return !glowa;
}



// Zwraca początek kolejki.
// Wartość specjalna to -MAXINT
//-----------------------------

int kolejka::pobierz(void)
{
    if(glowa) return glowa->v;
    else     return -MAXINT;
}



// Zapisuje do kolejki
//--------------------

void kolejka::dodaj(int v)
{
    slistEl * p = new slistEl;
    p->next = NULL;
    p->v = v;
    if(ogon) ogon->next = p;
    else     glowa = p;
    ogon = p;
}



// Usuwa z kolejki
//----------------

void kolejka::usun(void)
{
    if(glowa)
    {
        slistEl * p = glowa;
        glowa = glowa->next;
        if(!glowa) ogon = NULL;
        delete p;
    }
}



// funkcja ustawia oznaczenia punktów startowych i współrzędne domyślne
//---------------------------------

void ustawS_K(char **labirynt, char korytarz,int w,int s)
{  system("cls");
    cout<<"Ustaw S/K"<<endl;
    char znakS='S';
    char znakK='K';
    int  xpocz=1, ypocz=1;
    int  xkon=w-2, ykon=s-2;

    labirynt[xpocz][ypocz]=znakS;
    labirynt[xkon][ykon]=znakK;

    wyswietl(labirynt,w,s);
    cout<<endl<<endl;
    ustaw(labirynt, korytarz,znakS,xpocz,ypocz,w,s);
    ustaw(labirynt, korytarz,znakK,xkon,ykon,w,s);

    labirynt[xpocz][ypocz]=korytarz;
    labirynt[xkon][ykon]=korytarz;

    szukajdrogi(labirynt,xpocz,ypocz,xkon,ykon,korytarz);
    wyswietl(labirynt,w,s);
    if(labirynt[xkon][ykon]!='O')
        cout<<"Nie znaleziono drogi"<<endl;

}



// Funkcja umożliwia uzytkownikowi wybór pozycji starowej i końcowej
//-------------------------------------------------------------------

void ustaw(char **labirynt, char korytarz, char znak,int &x,int &y,int w,int s )
{  char kod;

    cout<<"Ustaw "<<znak<<endl<<endl;
    while(true)
    {
        kod=getch();                          // pobiera klawisz,który wybrał użytkownik
        switch(kod)
        { case 72:  if(x> 1 )                  // strzałka w górę
            {
                labirynt[x][y]=korytarz;
                x -=2;
                labirynt[x][y]=znak;
                system("cls");
                wyswietl(labirynt,w,s);}
            break;
        case 77:  if(y< s-2)                   // strzałka w prawo
            {   labirynt[x][y]=korytarz;
                y += 2;
                labirynt[x][y]=znak;
                system("cls");
                wyswietl(labirynt,w,s);}
            break;
        case 80:  if(x < w-2 )              // strzałka w dół
            {   labirynt[x][y]=korytarz;
                x += 2;
                labirynt[x][y]=znak;
                system("cls");
                wyswietl(labirynt,w,s);}
            break;
        case 75:  if(y > 1 )               // strzałka w lewo
            {    labirynt[x][y]=korytarz;
                y -= 2;
                labirynt[x][y]=znak;
                system("cls");
                wyswietl(labirynt,w,s);}
            break;
        case 13:  return;}                 //enter kończy pętle
    }




}



// Funkcja szuka najkrótszej drogi z punktu starowego do końcowego za pomocą algorytmu BFS
//----------------------------------------------------------------------------------------

void szukajdrogi(char ** labirynt,int xpocz, int ypocz, int xkon, int ykon, char korytarz)
{ int xp,yp;

    kolejka G(NULL,NULL);                //obiekt klasy Kolejka

    labirynt[xpocz][ypocz] = 'O';       // oznaczamy współrzędne startowe jako odwiedzone

    G.dodaj(xpocz); G.dodaj(ypocz);        // dodajemy współrzędne startowe do kolejki



    while(!G.pusty())                  // Teraz w pętli wykonujemy przejście BFS
    {


        xp = G.pobierz(); G.usun();    // odczytujemy z kolejki współrzędne i je usuwamy
        yp = G.pobierz(); G.usun();



        if(xp == xkon && yp == ykon)      // sprawdzamy, czy doszliśmy do punktu K
        {
            cout<<"Znaleziono droge"<<endl<<endl;  //wyswietlamy komunikat,że znaleziono droge

            while(labirynt[xp][yp] !='O') // cofamy się do punktu starowego, wymazując kroki

            {
                switch(labirynt[xp][yp])
                {
                case 'l'  : labirynt[xp][yp++] = 'O'; break;
                case 'g'  : labirynt[xp++][yp] = 'O'; break;
                case 'p' : labirynt[xp][yp--] = 'O'; break;
                case  'd'   : labirynt[xp--][yp] = 'O'; break;
                }


            }

            break;                // wychodzimy z pętli
        }

        // szukamy wszystkich dróg wyjścia z bieżącej pozycji. Współrzędne
        // komórek umieszczamy w kolejce, w komórkach umieszczamy kierunek przejścia

        if(labirynt[xp-1][yp] == korytarz)
        {
            labirynt[xp-1][yp] = 'g';          // ślad przejścia
            G.dodaj(xp-1); G.dodaj(yp);        // współrzędne do kolejki
        }

        if(labirynt[xp][yp-1] == korytarz)
        {
            labirynt[xp][yp-1] = 'l';        // ślad przejścia
            G.dodaj(xp); G.dodaj(yp-1);     // współrzędne do kolejki
        }

        if(labirynt[xp+1][yp] == korytarz)
        {
            labirynt[xp+1][yp] = 'd'; // ślad przejścia
            G.dodaj(xp+1); G.dodaj(yp);     // współrzędne do kolejki
        }

        if(labirynt[xp][yp+1] == korytarz)
        {
            labirynt[xp][yp+1] = 'p';   // ślad przejścia
            G.dodaj(xp); G.dodaj(yp+1);     // współrzędne do kolejki
        }
    }

}


