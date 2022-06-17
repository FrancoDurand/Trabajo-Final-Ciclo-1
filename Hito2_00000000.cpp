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


	//bordes cuadrado grande
		//fila arriba
		for (int j = 2; j <= 49; j++)
			tablero[0][j] = char(220);

		//fila abajo        
		for (int j = 2; j <= 49; j++)
			tablero[22][j] = char(223);
		
		//columna izquierda
		for (int i = 1; i <= 21; i++)
			tablero[i][2] = char(219);

		//columna derecha
		for (int i = 1; i <= 21; i++)
			tablero[i][49] = char(219);

	//bordes cuadrado mediano
		//fila arriba
		for (int j = 10; j <= 40; j++)
			tablero[4][j] = char(220);

		//fila abajo        
		for (int j = 10; j <= 40; j++)
			tablero[18][j] = char(223);
		
		//columna izquierda
		for (int i = 5; i <= 17; i++)
			tablero[i][10] = char(219);

		//columna derecha
		for (int i = 5; i <= 17; i++)
			tablero[i][40] = char(219);

	//bordes cuadrado pequeño
		//fila arriba
		for (int j = 19; j <= 31; j++)
			tablero[8][j] = char(223);

		//fila abajo        
		for (int j = 19; j <= 31; j++)
			tablero[14][j] = char(220);
		
		//columna izquierda
		for (int i = 8; i <= 14; i++)
			tablero[i][18] = char(219);

		//columna derecha
		for (int i = 8; i <= 14; i++)
			tablero[i][32] = char(219);

	//uniones
		//linea arriba
		for (int i = 1; i <= 7; i++)
			tablero[i][25] = char(219);
		
		//linea arriba
		for (int i = 15; i <= 21; i++)
			tablero[i][25] = char(219);
		
		//linea izquierda
		for (int j = 3; j <= 17; j++) {
			if (j != 10)
				tablero[11][j] = char(254);
			else
				continue;
		}
		
		//linea derecha
		for (int j = 33; j <= 48; j++) {
			if (j != 40)
				tablero[11][j] = char(254);
			else
				continue;
		}

	return tablero;
}

string* registrar_nombres()
{
	string* nombres = new string [2];

	cls;

	cout << "Nombre jugador 1:";
	cin >> nombres[0];
	cout << "Nombre jugador 2:";
	cin >> nombres[1];

	return nombres;
}

void jugar()
{
	cls;

	char** tablero = setear_tablero();

	for (int i = 1; i <= 3; i++)
		cout << endl;

	for (int i = 0; i < 25; i++){
		cout << "\t\t\t";
		
		for (int j = 0; j < 50; j++){
			cout << tablero[i][j];
		}
		
		cout << endl;
	}

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
			jugar();
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
 
1 ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
  █                      █                       █   
  █                      █                       █                                                                                    
  █                      █                       █                                                                                
2 █       ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄        █
  █       █              █              █        █
  █       █              █              █        █
  █       █              █              █        █
3 █       █       █▀▀▀▀▀▀▀▀▀▀▀▀▀█       █        █
  █       █       █             █       █        █
  █       █       █             █       █        █ 
4 █■■■■■■■█■■■■■■■█             █■■■■■■■█■■■■■■■■█
  █       █       █             █       █        █
  █       █       █             █       █        █
5 █       █       █▄▄▄▄▄▄▄▄▄▄▄▄▄█       █        █
  █       █              █              █        █
  █       █              █              █        █
  █       █              █              █        █
6 █       ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀        █
  █                      █                       █                            
  █                      █                       █
  █                      █                       █
7 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀                                                  
  
  A       B       C      D      E       F        G                                                                       
																				 
																				   
																					   
																					
																																				
																																			
                  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄       █        █
  █       █       █             █       █        █
  █       █       █             █       █        █ 
4 █■■■■■■■█■■■■■■■█             █■■■■■■■█■■■■■■■■█
  █       █       █             █       █        █
  █       █       █             █       █        █
5 █       █       ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀																									
																					   
																					   
																	 
																	   
*/                                                  