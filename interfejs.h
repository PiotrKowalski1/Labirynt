#ifndef INTERFEJS_H
#define INTERFEJS_H

void start();
void wybor();
void ustawienia_uzytkownika(int );
char** tworz_labirynt(int, int);
void rysuj( char **,int,int,char &,char &);
void wyswietl(char ** , int , int );
void czytajzpl(char &  , char & );
void zapiszdopl(char**, int,int);
void kasuj_labirynt(char**,int );
void zakoncz();


#endif // INTERFEJS_H
