#include <iostream>
#include <conio.h>
#include <Windows.h>

#define cls system("cls") //borra consola
#define blanco char(2) //Ø
#define negro char(1) //@

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
	char letra; //donde esta ubicado
	bool vivo = true; //despues de comer, bloquea el uso
	bool molino = false; //si pertenece a un molino, bloquea de ser comida
} ficha;

char opcion, posicion_elegida, posicion_previa;
bool hay_ficha, horizontal, vertical, diagonal;
short x, y, i, j;
ficha** fichas;
char** tablero;

//------------------------------------------------------------------------------

void cambiar_turno();

void obtener_coordenadas();

bool verificar_espacio_libre();

bool verificar_molino();

bool puede_recibir();

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

void cambiar_turno() {
	i++;

	if (i >= 2)
		i = 0;
}

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
		y = 32;
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
	if (tablero[x][y] != jugador[0].ficha && tablero[x][y] != jugador[1].ficha)
		return true;
	else
		return false;
}

bool verificar_molino() {
	horizontal = false, vertical = false, diagonal = false;

	switch (posicion_elegida)
	{
	case 'A':
		//horizontal
		if (B == jugador[i].ficha && C == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'B') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'C') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (J == jugador[i].ficha && V == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'J') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'V') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (D == jugador[i].ficha && G == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'D') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'G') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;

	case'B':
		//horizontal
		if (A == jugador[i].ficha && C == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'A') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'C') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (E == jugador[i].ficha && H == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'E') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'H') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'C':
		//horizontal
		if (A == jugador[i].ficha && B == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'A') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'B') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (O == jugador[i].ficha && X == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'O') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'X') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (F == jugador[i].ficha && I == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'F') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'I') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;

	case 'D':
		//horizontal
		if (E == jugador[i].ficha && F == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'E') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'F') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (K == jugador[i].ficha && S == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'K') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'S') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (A == jugador[i].ficha && G == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'A') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'G') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;

	case 'E':
		//horizontal
		if (D == jugador[i].ficha && F == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'D') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'F') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (B == jugador[i].ficha && H == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'B') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'H') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'F':
		//horizontal
		if (D == jugador[i].ficha && E == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'D') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'E') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (N == jugador[i].ficha && U == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'N') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'U') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (C == jugador[i].ficha && I == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'C') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'I') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;

	case'G':
		//horizontal
		if (H == jugador[i].ficha && I == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'H') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'I') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (L == jugador[i].ficha && P == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'L') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'P') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (A == jugador[i].ficha && D == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'A') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'D') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;

	case'H':
		//horizontal
		if (G == jugador[i].ficha && I == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'G') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'I') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (B == jugador[i].ficha && E == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'B') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'E') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'I':
		//horizontal
		if (G == jugador[i].ficha && H == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'G') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'H') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (M == jugador[i].ficha && R == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'M') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'R') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (C == jugador[i].ficha && F == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'C') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'F') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;

	case'J':
		//horizontal
		if (K == jugador[i].ficha && L == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'K') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'L') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (A == jugador[i].ficha && V == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'A') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'V') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'K':
		//horizontal
		if (J == jugador[i].ficha && L == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'J') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'L') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (D == jugador[i].ficha && S == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'D') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'S') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'L':
		//horizontal
		if (J == jugador[i].ficha && K == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'J') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'K') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (G == jugador[i].ficha && P == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'G') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'P') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'M':
		//horizontal
		if (N == jugador[i].ficha && O == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'N') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'O') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (I == jugador[i].ficha && R == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'I') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'R') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'N':
		//horizontal
		if (M == jugador[i].ficha && O == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'M') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'O') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (F == jugador[i].ficha && U == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'F') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'U') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'O':
		//horizontal
		if (M == jugador[i].ficha && N == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'M') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'N') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (C == jugador[i].ficha && X == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'C') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'X') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'P':
		//horizontal
		if (Q == jugador[i].ficha && R == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'Q') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'R') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (G == jugador[i].ficha && L == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'G') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'L') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (S == jugador[i].ficha && V == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'S') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'V') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;

	case 'Q':
		//horizontal
		if (P == jugador[i].ficha && R == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'P') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'R') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (T == jugador[i].ficha && W == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'T') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'W') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'R':
		//horizontal
		if (P == jugador[i].ficha && Q == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'R') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'Q') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (I == jugador[i].ficha && M == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'I') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'M') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (U == jugador[i].ficha && X == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'U') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'X') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;

	case'S':
		//horizontal
		if (T == jugador[i].ficha && U == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'T') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'U') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (D == jugador[i].ficha && K == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'D') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'K') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (P == jugador[i].ficha && V == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'P') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'V') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;

	case 'T':
		//horizontal
		if (S == jugador[i].ficha && U == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'S') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'U') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (Q == jugador[i].ficha && W == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'Q') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'W') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'U':
		//horizontal
		if (S == jugador[i].ficha && T == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'S') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'T') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (F == jugador[i].ficha && N == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'F') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'N') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (R == jugador[i].ficha && X == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'R') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'X') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;

	case'V':
		//horizontal
		if (W == jugador[i].ficha && X == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'W') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'X') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (A == jugador[i].ficha && J == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'A') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'J') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (P == jugador[i].ficha && S == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'P') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'S') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;

	case 'W':
		//horizontal
		if (V == jugador[i].ficha && X == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'V') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'X') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (Q == jugador[i].ficha && T == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'Q') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'T') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true)
			return true;
		else
			return false;
		break;

	case 'X':
		//horizontal
		if (V == jugador[i].ficha && W == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'V') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'W') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//vertical
		if (C == jugador[i].ficha && O == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'C') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'O') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (R == jugador[i].ficha && U == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'R') {
					fichas[i][j].molino = true;
					break;
				}
			}

			for (j = 0; j < 9; j++) {
				if (fichas[i][j].letra == 'U') {
					fichas[i][j].molino = true;
					break;
				}
			}
		}

		if (horizontal == true || vertical == true || diagonal == true)
			return true;
		else
			return false;
		break;
	}
}

bool puede_recibir() {
	switch (posicion_previa)
	{
	case 'A':
		if (posicion_elegida == 'B' || posicion_elegida == 'J')
			return true;
		else
			return false;
		break;

	case 'B':
		if (posicion_elegida == 'A' || posicion_elegida == 'C' || posicion_elegida == 'E')
			return true;
		else
			return false;
		break;

	case 'C':
		if (posicion_elegida == 'B' || posicion_elegida == 'O')
			return true;
		else
			return false;
		break;

	case 'D':
		if (posicion_elegida == 'E' || posicion_elegida == 'K')
			return true;
		else
			return false;
		break;

	case 'E':
		if (posicion_elegida == 'B' || posicion_elegida == 'D' || posicion_elegida == 'F' || posicion_elegida == 'H')
			return true;
		else
			return false;
		break;

	case 'F':
		if (posicion_elegida == 'E' || posicion_elegida == 'N')
			return true;
		else
			return false;
		break;

	case 'G':
		if (posicion_elegida == 'H' || posicion_elegida == 'L')
			return true;
		else
			return false;
		break;

	case 'H':
		if (posicion_elegida == 'E' || posicion_elegida == 'G' || posicion_elegida == 'I')
			return true;
		else
			return false;
		break;

	case 'I':
		if (posicion_elegida == 'H' || posicion_elegida == 'M')
			return true;
		else
			return false;
		break;

	case 'J':
		if (posicion_elegida == 'A' || posicion_elegida == 'K' || posicion_elegida == 'V')
			return true;
		else
			return false;
		break;

	case 'K':
		if (posicion_elegida == 'D' || posicion_elegida == 'J' || posicion_elegida == 'L' || posicion_elegida == 'S')
			return true;
		else
			return false;
		break;

	case 'L':
		if (posicion_elegida == 'G' || posicion_elegida == 'K' || posicion_elegida == 'P')
			return true;
		else
			return false;
		break;

	case 'M':
		if (posicion_elegida == 'I' || posicion_elegida == 'N' || posicion_elegida == 'R')
			return true;
		else
			return false;
		break;

	case 'N':
		if (posicion_elegida == 'F' || posicion_elegida == 'M' || posicion_elegida == 'O' || posicion_elegida == 'U')
			return true;
		else
			return false;
		break;

	case 'O':
		if (posicion_elegida == 'C' || posicion_elegida == 'N' || posicion_elegida == 'X')
			return true;
		else
			return false;
		break;

	case 'P':
		if (posicion_elegida == 'L' || posicion_elegida == 'Q')
			return true;
		else
			return false;
		break;

	case 'Q':
		if (posicion_elegida == 'P' || posicion_elegida == 'R' || posicion_elegida == 'T')
			return true;
		else
			return false;
		break;

	case 'R':
		if (posicion_elegida == 'M' || posicion_elegida == 'Q')
			return true;
		else
			return false;
		break;

	case 'S':
		if (posicion_elegida == 'K' || posicion_elegida == 'T')
			return true;
		else
			return false;
		break;

	case 'T':
		if (posicion_elegida == 'Q' || posicion_elegida == 'S' || posicion_elegida == 'U' || posicion_elegida == 'W')
			return true;
		else
			return false;
		break;

	case 'U':
		if (posicion_elegida == 'N' || posicion_elegida == 'T')
			return true;
		else
			return false;
		break;

	case 'V':
		if (posicion_elegida == 'J' || posicion_elegida == 'W')
			return true;
		else
			return false;
		break;

	case 'W':
		if (posicion_elegida == 'T' || posicion_elegida == 'V' || posicion_elegida == 'X')
			return true;
		else
			return false;
		break;

	case 'X':
		if (posicion_elegida == 'O' || posicion_elegida == 'W')
			return true;
		else
			return false;
		break;
	}
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
	} while ((hay_ficha == false || fichas[i][j].vivo == false) || (puede_mover() == false && jugador[i].fase3 == false));

	do {
		do {
			cout << "LUGAR A MOVER: ";
			cin >> posicion_elegida;

			posicion_elegida = toupper(posicion_elegida);
		} while (posicion_elegida < 'A' || posicion_elegida > 'X');

		obtener_coordenadas();
	} while (verificar_espacio_libre() == false || (puede_recibir() == false && jugador[i].fase3 == false));

	mover();
	actualizar_datos_fase2();
}

void fase2() {
	while (jugador[0].cant_fichas > 2 && jugador[1].cant_fichas > 2)
	{
		recibir_jugada_fase2();

		imprimir_tablero();

		cambiar_turno();

		/*if (verificar_molino() == true) {
			comer();
		}*/

		recibir_jugada_fase2();

		imprimir_tablero();

		cambiar_turno();
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

	for (j = 0; jugador[0].fichas_puestas < 9 || jugador[1].fichas_puestas < 9; j++) {
		recibir_jugada_fase1();

		imprimir_tablero();

		jugador[i].fichas_puestas++;

		cambiar_turno();

		recibir_jugada_fase1();

		imprimir_tablero();

		jugador[i].fichas_puestas++;

		cambiar_turno();
	}
}

void asignar_turnos() {
	Random rng;

	if (rng.Next(0, 2) % 2 != 0) {
		//empieza_j1 = true;
		i = 0;

		cout << "Empieza";

		Sleep(700);
		cout << ".";

		Sleep(700);
		cout << ".";

		Sleep(700);
		cout << ". ";

		Sleep(700);
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
		i = 1;

		cout << "Empieza";

		Sleep(700);
		cout << ".";

		Sleep(700);
		cout << ".";

		Sleep(700);
		cout << ". ";

		Sleep(700);
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
	A = a0; //tablero[0][2] = char(65)
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

	//poner guias
	tablero[1][3] = a0;
	tablero[1][26] = b0;
	tablero[1][48] = c0;
	tablero[5][11] = d0;
	tablero[5][26] = e0;
	tablero[5][39] = f0;
	tablero[9][19] = g0;
	tablero[9][25] = h0;
	tablero[9][31] = i0;
	tablero[12][3] = j0;
	tablero[12][11] = k0;
	tablero[11][19] = l0;
	tablero[11][31] = m0;
	tablero[12][39] = n0;
	tablero[12][48] = o0;
	tablero[13][19] = p0;
	tablero[13][25] = q0;
	tablero[13][31] = r0;
	tablero[17][11] = s0;
	tablero[17][26] = t0;
	tablero[17][39] = u0;
	tablero[21][3] = v0;
	tablero[21][26] = w0;
	tablero[21][48] = x0;
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
