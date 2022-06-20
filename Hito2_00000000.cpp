#include <iostream>
#include <conio.h>

#define cls system("cls") //borra consola
#define blanco char(157) //Ø
#define negro char(64) //@

#define A tablero[0][2]
#define B tablero[0][25]
#define C tablero[0][49]
#define D tablero[4][10]
#define E tablero[4][25]
#define F tablero[4][40]
#define G tablero[8][18]
#define H tablero[8][25]
#define I tablero[8][32]
#define J tablero[11][2]
#define K tablero[11][10]
#define L tablero[11][18]
#define M tablero[11][32]
#define N tablero[11][40]
#define O tablero[11][49]
#define P tablero[14][18]
#define Q tablero[14][25]
#define R tablero[14][32]
#define S tablero[18][10]
#define T tablero[18][25]
#define U tablero[18][40]
#define V tablero[22][2]
#define W tablero[22][25]
#define X tablero[22][49]

#define a0 char(65)
#define b0 char(66)
#define c0 char(67)
#define d0 char(68)
#define e0 char(69)
#define f0 char(70)
#define g0 char(71)
#define h0 char(72)
#define i0 char(73)
#define j0 char(74)
#define k0 char(75)
#define l0 char(76)
#define m0 char(77)
#define n0 char(78)
#define o0 char(79)
#define p0 char(80)
#define q0 char(81)
#define r0 char(82)
#define s0 char(83)
#define t0 char(84)
#define u0 char(85)
#define v0 char(86)
#define w0 char(87)
#define x0 char(88)

using namespace std;
using namespace System;

struct {
	string nombre;
	char ficha;
	short cant_fichas = 9;
	short cant_mov = 0;
	short fichas_puestas = 0;
	bool fase3 = false;
} jugador[2];

typedef struct {
	char letra;
	bool molino = false;
} ficha;

char opcion, posicion_elegida, posicion_previa;
bool empieza_j1, hay_ficha;
short x, y, i, j;
ficha** fichas;
char** tablero;

//------------------------------------------------------------------------------

void obtener_coordenadas();

bool verificar_espacio_libre();

bool puede_mover();

void mover();

void actualizar_datos_fase2();

void recibir_jugada_fase2();

void fase2();

void guardar_datos_fase1();

void recibir_jugada_fase1();

void fase1();

void asignar_turnos();

void datos_jugadores();

void setear_tablero();

void imprimir_tablero();

void jugar();
//------------------------------------------------------------------------------

int main() {
	jugar();


	delete[] tablero;
	cls;
	cout << "SE ACABO";
	getch();
}

//------------------------------------------------------------------------------
void obtener_coordenadas() {
	switch (posicion_elegida)
	{
	case 'A':
		x = 0;
		y = 2;
		break;

	case 'B':
		x = 0;
		y = 25;
		break;

	case 'C':
		x = 0;
		y = 49;
		break;

	case 'D':
		x = 4;
		y = 10;
		break;

	case 'E':
		x = 4;
		y = 25;
		break;

	case 'F':
		x = 4;
		y = 40;
		break;

	case 'G':
		x = 8;
		y = 10;
		break;

	case 'H':
		x = 8;
		y = 25;
		break;

	case 'I':
		x = 8;
		y = 32;
		break;

	case 'J':
		x = 11;
		y = 2;
		break;

	case 'K':
		x = 11;
		y = 10;
		break;

	case 'L':
		x = 11;
		y = 18;
		break;

	case 'M':
		x = 11;
		y = 32;
		break;

	case 'N':
		x = 11;
		y = 40;
		break;

	case 'O':
		x = 11;
		y = 49;
		break;

	case 'P':
		x = 14;
		y = 18;
		break;

	case 'Q':
		x = 14;
		y = 25;
		break;

	case 'R':
		x = 14;
		y = 25;
		break;

	case 'S':
		x = 18;
		y = 10;
		break;

	case 'T':
		x = 18;
		y = 25;
		break;

	case 'U':
		x = 18;
		y = 40;
		break;

	case 'V':
		x = 22;
		y = 2;
		break;

	case 'W':
		x = 22;
		y = 25;
		break;

	case 'X':
		x = 22;
		y = 49;
		break;
	}
}

bool verificar_espacio_libre() {
	if (tablero[x][y] == jugador[0].ficha || tablero[x][y] == jugador[1].ficha)
		return false;
	else
		return true;
}

bool puede_mover() {
	switch (posicion_elegida)
	{
	case 'A':
		if (B == b0 || J == j0)
			return true;
		else
			return false;
		break;

	case 'B':
		if (A == a0 || C == c0 || E == e0)
			return true;
		else
			return false;
		break;


	case 'C':
		if (B == b0 || O == o0)
			return true;
		else
			return false;
		break;


	case 'D':
		if (E == e0 || K == k0)
			return true;
		else
			return false;
		break;

	case 'E':
		if (B == b0 || D == d0 || F == f0 || H == h0)
			return true;
		else
			return false;
		break;

	case 'F':
		if (E == e0 || N == n0)
			return true;
		else
			return false;
		break;

	case 'G':
		if (H == h0 || L == l0)
			return true;
		else
			return false;
		break;

	case 'H':
		if (E == e0 || G == g0 || I == i0)
			return true;
		else
			return false;
		break;

	case 'I':
		if (H == h0 || M == m0)
			return true;
		else
			return false;
		break;

	case 'J':
		if (A == a0 || K == k0 || V == v0)
			return true;
		else
			return false;
		break;

	case 'K':
		if (D == d0 || J == j0 || L == l0 || S == s0)
			return true;
		else
			return false;
		break;

	case 'L':
		if (G == g0 || K == k0 || P == p0)
			return true;
		else
			return false;
		break;

	case 'M':
		if (I == i0 || N == n0 || R == r0)
			return true;
		else
			return false;
		break;

	case 'N':
		if (F == f0 || M == m0 || O == o0 || U == u0)
			return true;
		else
			return false;
		break;

	case 'O':
		if (C == c0 || N == n0 || X == x0)
			return true;
		else
			return false;
		break;

	case 'P':
		if (L == l0 || Q == q0)
			return true;
		else
			return false;
		break;

	case 'Q':
		if (P == p0 || R == r0 || T == t0)
			return true;
		else
			return false;
		break;

	case 'R':
		if (M == m0 || Q == q0)
			return true;
		else
			return false;
		break;

	case 'S':
		if (K == k0 || T == t0)
			return true;
		else
			return false;
		break;

	case 'T':
		if (Q == q0 || S == s0 || U == u0 || W == w0)
			return true;
		else
			return false;
		break;

	case 'U':
		if (N == n0 || T == t0)
			return true;
		else
			return false;
		break;

	case 'V':
		if (J == j0 || W == w0)
			return true;
		else
			return false;
		break;

	case 'W':
		if (T == t0 || V == v0 || X == x0)
			return true;
		else
			return false;
		break;

	case 'X':
		if (O == o0 || W == w0)
			return true;
		else
			return false;
		break;
	}
}

void mover() {
	switch (posicion_previa)
	{
	case 'A':
		A = a0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'B':
		B = b0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'C':
		C = c0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'D':
		D = d0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'E':
		E = e0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'F':
		F = f0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'G':
		G = g0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'H':
		H = h0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'I':
		I = i0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'J':
		J = j0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'K':
		K = k0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'L':
		L = l0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'M':
		M = m0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'N':
		N = n0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'O':
		O = o0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'P':
		P = p0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'Q':
		Q = q0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'R':
		R = r0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'S':
		S = s0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'T':
		T = t0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'U':
		U = u0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'V':
		V = v0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'W':
		W = w0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;

	case 'X':
		X = x0;

		obtener_coordenadas();

		tablero[x][y] = jugador[i].ficha;
		break;
	}
}

void actualizar_datos_fase2() {
	switch (posicion_elegida)
	{
	case 'A':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'B':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'C':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'D':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'E':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'F':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'G':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'H':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'I':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'J':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'K':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'L':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'M':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'N':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'O':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'P':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'Q':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'R':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'S':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'T':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'U':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'V':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'W':
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'X':
		fichas[i][j].letra = posicion_elegida;
		break;
	}
}

void recibir_jugada_fase2() {
	hay_ficha = false;

	cout << "TURNO: " << jugador[i].nombre << endl;
	do {
		do {
			cout << "FICHA A MOVER: ";
			cin >> posicion_elegida;

			posicion_elegida = toupper(posicion_elegida);
			posicion_previa = posicion_elegida;
		} while (posicion_elegida < 'A' || posicion_elegida > 'X');

		for (j = 0; j < 9; j++) {
			if (fichas[i][j].letra == posicion_elegida) {
				hay_ficha = true;
				break;
			}
		}
	} while (hay_ficha == false || puede_mover() == false);

	do {
		do {
			cout << "LUGAR A MOVER: ";
			cin >> posicion_elegida;

			posicion_elegida = toupper(posicion_elegida);
		} while (posicion_elegida < 'A' || posicion_elegida > 'X');

		obtener_coordenadas();
	} while (verificar_espacio_libre() == false);

	mover();
	actualizar_datos_fase2();
}

void fase2() {
	while (jugador[0].cant_fichas > 2 || jugador[1].cant_fichas > 2)
	{
		recibir_jugada_fase2();

		imprimir_tablero();
	}

}

void guardar_datos_fase1() {
	switch (posicion_elegida)
	{
	case 'A':
		A = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'B':
		B = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'C':
		C = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'D':
		D = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'E':
		E = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'F':
		F = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'G':
		G = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'H':
		H = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'I':
		I = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'J':
		J = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'K':
		K = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'L':
		L = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'M':
		M = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'N':
		N = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'O':
		O = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'P':
		P = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'Q':
		Q = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'R':
		R = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'S':
		S = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'T':
		T = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'U':
		U = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'V':
		V = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'W':
		W = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;

	case 'X':
		X = jugador[i].ficha;
		fichas[i][j].letra = posicion_elegida;
		break;
	}
}

void recibir_jugada_fase1() {
	//if (empieza_j1 == true) falta ordenar turnos, con j ingresar fichas[i][j].letra
	cout << "TURNO: " << jugador[i].nombre << endl;

	do {
		do {
			cout << "Posicion: ";
			cin >> posicion_elegida;

			posicion_elegida = toupper(posicion_elegida);
		} while (posicion_elegida < 'A' || posicion_elegida > 'X');

		obtener_coordenadas();
	} while (verificar_espacio_libre() == false);

	guardar_datos_fase1();
}

void fase1() {
	//i = 0: jugador1, i = 1: jugador2
	//j = fichas
	//if empieza_j1 == true i = 0 else i = 1
	for (j = 0; jugador[0].fichas_puestas < 9; j++) {
		recibir_jugada_fase1();

		imprimir_tablero();

		/*
		//cambio de fila en matriz fichas
		i++;
		if (i > 1)
			i = 0;

		recibir_jugada_fase1(i, j);

		//cambio de fila en matriz fichas
		i++;
		if (i > 1)
			i = 0;
		*/

		jugador[i].fichas_puestas++;
		//jugador2.fichas_puestas++;
		//imprimir_tablero() <- agregar para jugador2
	}
}

void asignar_turnos() {
	Random rng;

	if (rng.Next(0, 3) % 2 != 0) {
		empieza_j1 = true;
		i = 0;

		cout << "Empieza";

		_sleep(800);
		cout << ".";

		_sleep(800);
		cout << ".";

		_sleep(800);
		cout << ". ";

		_sleep(800);
		cout << jugador[0].nombre << endl << endl;
		cout << "PRESIONA UNA TECLA PARA CONTINUAR";
		getch();

		cls;

		do {
			cout << "1)Blanco " << blanco << endl;
			cout << "2)Negro " << negro << endl;
			cout << jugador[0].nombre << " elige fichas: ";
			cin >> jugador[0].ficha;
		} while (jugador[0].ficha != '1' && jugador[0].ficha != '2');

		if (jugador[0].ficha == '1') {
			jugador[0].ficha = blanco;
			jugador[1].ficha = negro;
		}
		else {
			jugador[0].ficha = negro;
			jugador[1].ficha = blanco;
		}
	}
	else {
		empieza_j1 = false;
		i = 0;//modificar i = 1 para 2 jugadores

		cout << "Empieza";

		_sleep(800);
		cout << ".";

		_sleep(800);
		cout << ".";

		_sleep(800);
		cout << ". ";

		_sleep(800);
		cout << jugador[1].nombre << endl << endl;
		cout << "PRESIONA UNA TECLA PARA CONTINUAR";
		getch();

		cls;

		do {
			cout << "1)Blanco " << blanco << endl;
			cout << "2)Negro " << negro << endl;
			cout << jugador[1].nombre << " elige fichas: ";
			cin >> jugador[1].ficha;
		} while (jugador[1].ficha != '1' && jugador[1].ficha != '2');

		if (jugador[1].ficha == '1') {
			jugador[1].ficha = blanco;
			jugador[0].ficha = negro;
		}
		else {
			jugador[1].ficha = negro;
			jugador[0].ficha = blanco;
		}
	}
}

void datos_jugadores() {
	cout << "***************************************************************************************************" << endl;
	cout << "********************************************  JUGADOR 1  ******************************************" << endl;
	cout << "***************************************************************************************************" << endl;
	cout << endl;
	cout << "                                        INGRESA TU NOMBRE: ";
	cin >> jugador[0].nombre;

	cls;

	cout << "***************************************************************************************************" << endl;
	cout << "********************************************  JUGADOR 2  ******************************************" << endl;
	cout << "***************************************************************************************************" << endl;
	cout << endl;
	cout << "                                        INGRESA TU NOMBRE: ";
	cin >> jugador[1].nombre;

	cls;

	asignar_turnos();

	fichas = new ficha * [2];

	for (int i = 0; i < 2; i++)
		fichas[i] = new ficha[9];
}

void setear_tablero() {
	tablero = new char* [25];

	for (int i = 0; i < 25; i++)
		tablero[i] = new char[50]; //creacion de matriz


	//lienzo en blanco
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 50; j++)
			tablero[i][j] = char(32);
	}

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

	//poner letras
	A = a0;
	B = b0;
	C = c0;
	D = d0;
	E = e0;
	F = f0;
	G = g0;
	H = h0;
	I = i0;
	J = j0;
	K = k0;
	L = l0;
	M = m0;
	N = n0;
	O = o0;
	P = p0;
	Q = q0;
	R = r0;
	S = s0;
	T = t0;
	U = u0;
	V = v0;
	W = w0;
	X = x0;
}

void imprimir_tablero() {
	cls;

	for (int i = 1; i <= 2; i++)
		cout << endl;

	for (int i = 0; i < 25; i++) {
		cout << "\t\t\t\t";

		for (int j = 0; j < 50; j++) {
			cout << tablero[i][j];
		}

		cout << endl;
	}
}

void jugar() {
	datos_jugadores();

	setear_tablero();

	imprimir_tablero();

	fase1();

	fase2();
}

