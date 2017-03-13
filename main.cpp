#include <QCoreApplication>
#include <iostream>
#include "interfejs.h"
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    start(); //funkcja wywoluje menu
    wybor(); //funkcja umożliwia wybór opcji użytkownikowi
    
    return a.exec();
}
