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

struct
{
	string nombre;
	char ficha;
	short cant_fichas = 9;
	short cant_mov = 0;
	short fichas_puestas = 0;
	bool fase3 = false;
} jugador1, jugador2;

typedef struct {
	char* posicion;
	char letra;
	bool molino = false;
} ficha;

char opcion, posicion;
bool empieza_j1;
short x, y;
ficha** fichas = new ficha * [2];
char* espacios_tablero = new char[24];
char** tablero;


//------------------------------------------------------------------------------
void obtener_coordenadas();

bool verificar_espacio_libre();

bool puede_mover(int& i, int& j);

void recibir_jugada_fase2(int& i);

void fase2();

void guardar_datos_fase1(int& i, int& j);

void recibir_jugada_fase1(int& i, int& j);

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
	switch (posicion)
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
	if (tablero[x][y] == jugador1.ficha || tablero[x][y] == jugador2.ficha)
		return false;
	else
		return true;
}

bool puede_mover(int& i, int& j) {
	if (fichas[i][j].letra == 'A') {
		if (B != jugador1.ficha || J != jugador1.ficha)
			return true;
		else
			return false;
	}
	if (fichas[i][j].letra == 'B') {
		if (A != jugador1.ficha || C != jugador1.ficha || E != jugador1.ficha)
			return true;
		else
			return false;
	}
}

void recibir_jugada_fase2(int& i) {
	bool hay_ficha = false;
	int j;

	cout << "TURNO: " << jugador1.nombre << endl;
	do {
		do {
			cout << "FICHA A MOVER: ";
			cin >> posicion;

			posicion = toupper(posicion);
		} while (posicion < 'A' || posicion > 'X');

		for (j = 0; j < 9; j++) {
			if (fichas[i][j].letra == posicion) {
				hay_ficha = true;
				break;
			}
		}
	} while (hay_ficha == false || puede_mover(i, j) == false);

	do {
		do {
			cout << "LUGAR A MOVER: ";
			cin >> posicion;

			posicion = toupper(posicion);
		} while (posicion < 'A' || posicion > 'X');

		obtener_coordenadas();
	} while (verificar_espacio_libre() == false);

	*fichas[i][j].posicion = a0;
	J = jugador1.ficha;

	cout << endl << "MOVIO" << endl;
}

void fase2() {
	int i = 0;

	while (jugador1.cant_fichas > 2 || jugador2.cant_fichas > 2)
	{
		recibir_jugada_fase2(i);

		imprimir_tablero();
	}

}

void guardar_datos_fase1(int& i, int& j) {
	if (posicion == 'A') {
		A = jugador1.ficha;
		fichas[i][j].posicion = &A;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'B') {
		B = jugador1.ficha;
		fichas[i][j].posicion = &B;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'C') {
		C = jugador1.ficha;
		fichas[i][j].posicion = &C;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'D') {
		D = jugador1.ficha;
		fichas[i][j].posicion = &D;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'E') {
		E = jugador1.ficha;
		fichas[i][j].posicion = &E;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'F') {
		F = jugador1.ficha;
		fichas[i][j].posicion = &F;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'G') {
		G = jugador1.ficha;
		fichas[i][j].posicion = &G;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'H') {
		H = jugador1.ficha;
		fichas[i][j].posicion = &H;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'I') {
		I = jugador1.ficha;
		fichas[i][j].posicion = &I;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'J') {
		J = jugador1.ficha;
		fichas[i][j].posicion = &J;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'K') {
		K = jugador1.ficha;
		fichas[i][j].posicion = &K;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'L') {
		L = jugador1.ficha;
		fichas[i][j].posicion = &L;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'M') {
		M = jugador1.ficha;
		fichas[i][j].posicion = &M;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'N') {
		N = jugador1.ficha;
		fichas[i][j].posicion = &N;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'O') {
		O = jugador1.ficha;
		fichas[i][j].posicion = &O;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'P') {
		P = jugador1.ficha;
		fichas[i][j].posicion = &P;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'Q') {
		Q = jugador1.ficha;
		fichas[i][j].posicion = &Q;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'R') {
		R = jugador1.ficha;
		fichas[i][j].posicion = &R;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'S') {
		S = jugador1.ficha;
		fichas[i][j].posicion = &S;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'T') {
		T = jugador1.ficha;
		fichas[i][j].posicion = &T;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'U') {
		U = jugador1.ficha;
		fichas[i][j].posicion = &U;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'V') {
		V = jugador1.ficha;
		fichas[i][j].posicion = &V;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'W') {
		W = jugador1.ficha;
		fichas[i][j].posicion = &W;
		fichas[i][j].letra = posicion;
	}
	else if (posicion == 'X') {
		X = jugador1.ficha;
		fichas[i][j].posicion = &X;
		fichas[i][j].letra = posicion;
	}
}

void recibir_jugada_fase1(int& i, int& j) {
	//if (empieza_j1 == true) falta ordenar turnos, con j ingresar fichas[i][j].letra
	cout << "TURNO: " << jugador1.nombre << endl;

	do {
		do {
			cout << "Posicion: ";
			cin >> posicion;

			posicion = toupper(posicion);
		} while (posicion < 'A' || posicion > 'X');

		obtener_coordenadas();
	} while (verificar_espacio_libre() == false);

	guardar_datos_fase1(i, j);
}

void fase1() {
	//i = 0: jugador1, i = 1: jugador2
	//j = fichas
	//if empieza_j1 == true i = 0 else i = 1
	int i = 0;

	for (int j = 0; jugador1.fichas_puestas < 9; j++) {
		recibir_jugada_fase1(i, j);

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

		jugador1.fichas_puestas++;
		//jugador2.fichas_puestas++;
		//imprimir_tablero() <- agregar para jugador2
	}
}

void asignar_turnos() {
	Random rng;

	if (rng.Next(0, 3) % 2 != 0) {
		empieza_j1 = true;

		cout << "Empieza";

		_sleep(800);
		cout << ".";

		_sleep(800);
		cout << ".";

		_sleep(800);
		cout << ". ";

		_sleep(800);
		cout << jugador1.nombre << endl << endl;
		cout << "PRESIONA UNA TECLA PARA CONTINUAR";
		getch();

		cls;

		do {
			cout << "1)Blanco " << blanco << endl;
			cout << "2)Negro " << negro << endl;
			cout << jugador1.nombre << " elige fichas: ";
			cin >> jugador1.ficha;
		} while (jugador1.ficha != '1' && jugador1.ficha != '2');

		if (jugador1.ficha == '1') {
			jugador1.ficha = blanco;
			jugador2.ficha = negro;
		}
		else {
			jugador1.ficha = negro;
			jugador2.ficha = blanco;
		}
	}
	else {
		empieza_j1 = false;

		cout << "Empieza";

		_sleep(800);
		cout << ".";

		_sleep(800);
		cout << ".";

		_sleep(800);
		cout << ". ";

		_sleep(800);
		cout << jugador2.nombre << endl << endl;
		cout << "PRESIONA UNA TECLA PARA CONTINUAR";
		getch();

		cls;

		do {
			cout << "1)Blanco " << blanco << endl;
			cout << "2)Negro " << negro << endl;
			cout << jugador2.nombre << " elige fichas: ";
			cin >> jugador2.ficha;
		} while (jugador2.ficha != '1' && jugador2.ficha != '2');

		if (jugador2.ficha == '1') {
			jugador2.ficha = blanco;
			jugador1.ficha = negro;
		}
		else {
			jugador2.ficha = negro;
			jugador1.ficha = blanco;
		}
	}
}

void datos_jugadores() {
	cout << "***************************************************************************************************" << endl;
	cout << "********************************************  JUGADOR 1  ******************************************" << endl;
	cout << "***************************************************************************************************" << endl;
	cout << endl;
	cout << "                                        INGRESA TU NOMBRE: ";
	cin >> jugador1.nombre;

	cls;

	cout << "***************************************************************************************************" << endl;
	cout << "********************************************  JUGADOR 2  ******************************************" << endl;
	cout << "***************************************************************************************************" << endl;
	cout << endl;
	cout << "                                        INGRESA TU NOMBRE: ";
	cin >> jugador2.nombre;

	cls;

	asignar_turnos();

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