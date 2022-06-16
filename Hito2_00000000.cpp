#include <iostream>
#include <conio.h>
#define cls system("cls") //borra consola

using namespace std;
using namespace System;

char** setear_tablero()
{
	char** tablero = new char*[25];

	for (int i = 0; i < 25; i++)
		tablero[i] = new char[50]; //creacion de matriz

    for (int i = 0; i < 25; i++){
        for (int j = 0; j < 50; j++)
            tablero[i][j] = char(32); //lienzo en blanco
    } 

    //poner numeros
    tablero[0][0] = char(49);
    tablero[4][0] = char(50);
    tablero[8][0] = char(51);
    tablero[11][0] = char(52);
    tablero[14][0] = char(53);
    tablero[18][0] = char(54);
    tablero[22][0] = char(55);

    //poner letras
    tablero[24][3] = char(65);
    tablero[24][10] = char(66);
    tablero[24][18] = char(67);
    tablero[24][25] = char(68);
    tablero[24][33] = char(69);
    tablero[24][42] = char(70);
    tablero[24][49] = char(71);

    //imprimir tablero
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 50; j++){
            cout << tablero[i][j];
        }

        cout << endl;
    }

    return tablero;
}

int main()
{
    char opcion;

    do{
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

/*

//fila 0
tablero[0][0] = char(201)

for(int j = 1; j <= 9; j++){
	tablero[0][j] = char(205)
}

tablero[0][10] = char(203)

for(int j = 11; j <= 19; j++){
	tablero[0][j] = char(205)
}

tablero[0][20] = char(187)

219 █ //largote
220 ▄ //apunta abajo
223 ▀ //apunta arriba
254 ■ //centrado

//fila 0
tablero[0][0] = char(201)

for(int j = 1; j <= 9; j++){
	tablero[0][j] = char(205)
}

tablero[0][10] = char(203)

for(int j = 11; j <= 19; j++){
	tablero[0][j] = char(205)
}

tablero[0][20] = char(187)

219 █ //largote
220 ▄ //apunta abajo
223 ▀ //apunta arriba
254 ■ //centrado
  




▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ 1
█                      █                       █   
█                      █                       █                                                                                    
█                      █                       █                                                                                
█       ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄        █ 2
█       █              █              █        █
█       █              █              █        █
█       █              █              █        █
█       █       █▀▀▀▀▀▀▀▀▀▀▀▀▀█       █        █ 3
█       █       █             █       █        █
█       █       █             █       █        █ 
█■■■■■■■█■■■■■■■█             █■■■■■■■█■■■■■■■■█ 4
█       █       █             █       █        █
█       █       █             █       █        █
█       █       █▄▄▄▄▄▄▄▄▄▄▄▄▄█       █        █ 5
█       █              █              █        █
█       █              █              █        █
█       █              █              █        █
█       ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀        █ 6
█                      █                       █                            
█                      █                       █
█                      █                       █
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀ 7                                                  
A       B       C      D      E       F        G                                                                       
                                                                                 
                                                                                   
                                                                                       
                                                                                    
                                                                                                                                                
                                                                                                                                            
                                                                                                                                        
                                                                                       
                                                                                       
                                                                     
                                                                       
*/                                                  