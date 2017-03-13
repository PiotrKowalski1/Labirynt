#ifndef ALGORYTM_H
#define ALGORYTM_H


void ustawS_K(char** , char, int , int );           //funkcja umożliwia ustawienie punktów startowych
void ustaw(char** , char , char,  int& , int& , int w, int ); //funkcja umożliwa ustawienie konkretnego punktu
void szukajdrogi(char**,int xpocz, int ypocz, int xkon, int ykon, char korytarz); //funkcja szukjąca najkrótszej drogi w labiryncie
struct slistEl   //struktura , umożliwiająca tworzenie kolejki, do przechowywanie współrzędnych punktów
{
  slistEl * next;
  int v;
};

// Definicja typu obiektowego queue
//---------------------------------
class kolejka
{
  private:
    slistEl * glowa;
    slistEl * ogon;

  public:
    kolejka(slistEl *, slistEl *);      // konstruktor
    ~kolejka();                         // destruktor
    bool pusty(void);
    int  pobierz(void);
    void dodaj(int v);
    void usun(void);
};



#endif // ALGORYTM_H
