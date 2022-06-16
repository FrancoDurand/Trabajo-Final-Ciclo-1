#include <iostream>
#include <conio.h>
#define cls system("cls") //borra consola

using namespace std;
using namespace System;

int main()
{
    char opcion;

    do {
        cls;

        cout << "1)Jugar";
        cin >> opcion;

        switch (opcion)
        {
        case'1':
            setear_tablero();
            getch();
            break;
        }

    } while (true);

    getch();
}