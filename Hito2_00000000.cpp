#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>

#define cls system("cls") //borra consola
#define blanco char(30) //▲
#define negro char(127) //⌂

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

#define premio1 system("start https://www.baidu.com/")
#define premio2 system("start https://www.baidu.com/")
#define premio3 system("start https://www.baidu.com/")

using namespace std;
using namespace System;

struct {
	string nombre;
	char ficha;
	short cant_fichas = 9;
	short cant_mov = 0;
	short fichas_puestas = 0;
	bool fase3 = false;
	short fichas_comidas = 0;
} jugador[2];

typedef struct {
	char letra; //donde esta ubicado
	bool vivo = false; //despues de comer, bloquea el uso
	bool molino = false; //si pertenece a un molino, bloquea de ser comida
} ficha;

char opcion, posicion_elegida, posicion_previa, posicion_comida;
bool hay_ficha, horizontal, vertical, diagonal, es_molino, comio_molino;
short x, y, i, j, k;
ficha** fichas;
char** tablero, ** molino, ** reglas, ** upc, ** opciones_1, ** opciones_2, ** opciones_3;

//------------------------------------------------------------------------------
void premios();

void cambiar_turno();

void revancha();

void mostrar_ganador();

void mostrar_dinero();

void mostrar_vidas();

void obtener_coordenadas();

bool verificar_espacio_libre();

bool verificar_ganador();

bool verificar_imposibilidad_movimiento();

void verificar_fase3();

bool todas_molino();

bool puede_comer();

void comer();

void recibir_comer();

void actualizar_molinos();

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

void molino_banner();

void reglas_banner();

void upc_banner();

void opciones_banner();

void menu();

void limpiar_memoria();

//------------------------------------------------------------------------------

int main() {
	menu();

	limpiar_memoria();
}

//------------------------------------------------------------------------------
void premios() {
	do {
		cls;
		cout << endl << endl;

		cout << "\t\t\t\tDINERO DE " << jugador[i].nombre << ": ";
		Console::ForegroundColor = ConsoleColor::Green;
		cout << jugador[i].fichas_comidas * 5 << endl;
		Console::ForegroundColor = ConsoleColor::Gray;
		cout << "\t\t\t\tPREMIOS: " << endl;
		cout << "\t\t\t\tA)";
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "$15" << endl;
		Console::ForegroundColor = ConsoleColor::Gray;
		cout << "\t\t\t\tB)";
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "$50" << endl;
		Console::ForegroundColor = ConsoleColor::Gray;
		cout << "\t\t\t\tC)";
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "$100" << endl;
		Console::ForegroundColor = ConsoleColor::Gray;
		cout << "\t\t\t\tOPCION:";
		cin >> opcion;
		opcion = toupper(opcion);
	} while (opcion < 'A' || opcion > 'C');

	switch (opcion) {
	case 'A':
		if (jugador[i].fichas_comidas * 5 >= 15)
			premio1;
		else
			premios();
		break;

	case 'B':
		if (jugador[i].fichas_comidas * 5 >= 50)
			premio2;
		else
			premios();
		break;

	case 'C':
		if (jugador[i].fichas_comidas * 5 >= 100)
			premio3;
		else
			premios();
		break;
	}

	opcion = '1';
}

void cambiar_turno() {
	i++;

	if (i >= 2)
		i = 0;
}

void revancha() {
	do {
		do {
			cls;
			mostrar_ganador();

			cout << endl << "\t\t\t\t" << char(168) << "REVANCHA? (S/N): ";
			cin >> opcion;
			opcion = toupper(opcion);

		} while (opcion != 'S' && opcion != 'N');

		if (opcion == 'S') {
			for (int i = 0; i < 2; i++) {
				jugador[i].cant_fichas = 9;
				jugador[i].cant_mov = 0;
				jugador[i].fichas_puestas = 0;
				jugador[i].fase3 = false;
			}

			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 9; j++) {
					fichas[i][j].vivo = false;
					fichas[i][j].molino = false;
				}
			}

			asignar_turnos();

			setear_tablero();

			imprimir_tablero();

			fase1();

			fase2();

			cambiar_turno();
		}


	} while (opcion != 'N');

	premios();
}

void mostrar_ganador() {
	cout << endl << endl;
	cout << "\t\t\t\t" << jugador[i].nombre << " GANO" << endl;
}

void mostrar_dinero() {
	cout << "\t\t\tDINERO: ";

	Console::ForegroundColor = ConsoleColor::Green;

	cout << "$" << jugador[i].fichas_comidas * 5 << " ";

	cout << endl;

	Console::ForegroundColor = ConsoleColor::Gray;
}

void mostrar_vidas() {
	cout << "\t\t\tVIDAS: " << jugador[i].cant_fichas << " ";

	Console::ForegroundColor = ConsoleColor::Red;

	short vidas = jugador[i].cant_fichas;

	for (short i = 1; i <= vidas; i++)
		cout << char(3) << " ";

	cout << endl;

	Console::ForegroundColor = ConsoleColor::Gray;
}

void obtener_coordenadas() {
	switch (posicion_elegida) {
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
		y = 18;
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

bool verificar_ganador() {
	if (jugador[i].cant_fichas <= 2)
		return true;
	else if (jugador[i].fase3 == false)
		if (verificar_imposibilidad_movimiento() == true)
			return true;

	return false;
}

bool verificar_imposibilidad_movimiento() {
	for (j = 0; j < 9; j++) {
		if (fichas[i][j].vivo == true) {
			posicion_elegida = fichas[i][j].letra;

			if (puede_mover() == true)
				return false;
		}
	}

	return true;
}

void verificar_fase3() {
	if (jugador[i].fase3 == false)
		if (jugador[i].cant_fichas <= 3)
			jugador[i].fase3 = true;
}

bool puede_comer() {
	switch (posicion_elegida) {
	case 'A':
		if (A != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'B':
		if (B != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'C':
		if (C != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'D':
		if (D != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'E':
		if (E != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'F':
		if (F != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'G':
		if (G != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'H':
		if (H != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'I':
		if (I != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'J':
		if (J != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'K':
		if (K != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'L':
		if (L != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'M':
		if (M != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'N':
		if (N != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'O':
		if (O != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'P':
		if (P != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'Q':
		if (Q != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'R':
		if (R != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'S':
		if (S != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'T':
		if (T != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'U':
		if (U != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'V':
		if (V != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'W':
		if (W != jugador[i].ficha)
			return true;
		else
			return false;
		break;

	case 'X':
		if (X != jugador[i].ficha)
			return true;
		else
			return false;
		break;
	}
}

void comer() {
	cambiar_turno();

	for (k = 0; k < 9; k++) {
		if (fichas[i][k].letra == posicion_elegida && fichas[i][k].vivo == true) {
			fichas[i][k].vivo = false;
			break;
		}
	}

	jugador[i].cant_fichas--;

	cambiar_turno();

	switch (posicion_elegida) {
	case 'A':
		A = a0;
		break;

	case 'B':
		B = b0;
		break;

	case 'C':
		C = c0;
		break;

	case 'D':
		D = d0;
		break;

	case 'E':
		E = e0;
		break;

	case 'F':
		F = f0;
		break;

	case 'G':
		G = g0;
		break;

	case 'H':
		H = h0;
		break;

	case 'I':
		I = i0;
		break;

	case 'J':
		J = j0;
		break;

	case 'K':
		K = k0;
		break;

	case 'L':
		L = l0;
		break;

	case 'M':
		M = m0;
		break;

	case 'N':
		N = n0;
		break;

	case 'O':
		O = o0;
		break;

	case 'P':
		P = p0;
		break;

	case 'Q':
		Q = q0;
		break;

	case 'R':
		R = r0;
		break;

	case 'S':
		S = s0;
		break;

	case 'T':
		T = t0;
		break;

	case 'U':
		U = u0;
		break;

	case 'V':
		V = v0;
		break;

	case 'W':
		W = w0;
		break;

	case 'X':
		X = x0;
		break;
	}
}

bool todas_molino() {
	for (k = 0; k < 9; k++) {
		if (fichas[i][k].vivo == true && fichas[i][k].molino == false)
			return false;
	}

	return true;
}

void recibir_comer() {
	es_molino = true;
	comio_molino = false;

	cout << "\t\t\t" << jugador[i].nombre << " HIZO MOLINO" << endl;

	do {
		cout << "\t\t\tFICHA A COMER:";
		cin >> posicion_elegida;

		posicion_elegida = toupper(posicion_elegida);

		obtener_coordenadas();


		cambiar_turno();

		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == posicion_elegida && fichas[i][k].molino == false && fichas[i][k].vivo == true) {
				es_molino = false;
				break;
			}
		}

		if (es_molino == true)
			if (todas_molino() == true) {
				es_molino = false;
				comio_molino = true;
			}

		cambiar_turno();


	} while (verificar_espacio_libre() == true || puede_comer() == false || es_molino == true);

	posicion_comida = posicion_elegida;

	if (comio_molino == true) {
		posicion_previa = posicion_elegida;
		cambiar_turno();
		actualizar_molinos();
		cambiar_turno();
	}

	posicion_elegida = posicion_comida;
	comer();
	jugador[i].fichas_comidas++;
}

void actualizar_molinos() {
	for (k = 0; k < 9; k++) {
		if (fichas[i][k].letra == posicion_previa && fichas[i][k].vivo == true) {
			fichas[i][k].molino = false;
			break;
		}
	}

	switch (posicion_previa) {
	case 'A':
		posicion_elegida = 'B';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'B' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'C';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'D';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'G';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'J';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'J' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'V';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'B':
		posicion_elegida = 'A';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'C';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'E';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'E' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'H';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'H' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'C':
		posicion_elegida = 'A';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'B';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'B' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'F';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'I';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'O';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'O' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'X';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'D':
		posicion_elegida = 'A';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'G';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'E';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'E' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'F';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'K';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'K' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'S';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'E':
		posicion_elegida = 'B';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'B' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'H';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'H' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'D';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'F';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'F':
		posicion_elegida = 'C';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'I';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'E';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'E' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		posicion_elegida = 'D';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'N';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'N' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'U';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'G':
		posicion_elegida = 'A';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'D';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'H';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'H' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'I';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'L';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'L' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'P';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'P' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'H':
		posicion_elegida = 'B';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'B' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'E';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'E' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'G';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'I';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'I':
		posicion_elegida = 'C';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'F';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'H';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'H' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'G';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'M';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'M' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'R';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'J':
		posicion_elegida = 'K';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'K' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'L';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'L' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'A';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'V';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'K':
		posicion_elegida = 'J';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'J' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'L';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'L' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'S';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'D';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'L':
		posicion_elegida = 'J';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'J' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'K';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'K' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'G';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'P';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'P' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'M':
		posicion_elegida = 'O';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'O' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'N';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'N' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'I';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'R';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'N':
		posicion_elegida = 'M';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'M' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'O';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'O' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'F';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'U';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'O':
		posicion_elegida = 'M';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'M' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'N';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'N' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'C';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'X';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'P':
		posicion_elegida = 'S';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'V';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'L';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'L' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'G';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'Q';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'Q' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'R';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'Q':
		posicion_elegida = 'T';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'T' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'W';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'W' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'P';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'P' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'R';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'R':
		posicion_elegida = 'U';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'X';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'Q';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'Q' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'P';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'P' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'M';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'M' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'I';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'S':
		posicion_elegida = 'V';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'P';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'P' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'T';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'T' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'U';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'K';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'K' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'D';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'T':
		posicion_elegida = 'Q';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'Q' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'W';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'W' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'S';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'U';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'U':
		posicion_elegida = 'R';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'X';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'T';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'T' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'S';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'N';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'N' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'F';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'V':
		posicion_elegida = 'S';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'P';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'P' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'W';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'W' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'X';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'J';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'J' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'A';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'W':
		posicion_elegida = 'T';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'T' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'Q';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'Q' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'V';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'X';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;

	case 'X':
		posicion_elegida = 'W';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'W' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'V';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'U';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'R';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'O';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'O' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}

		posicion_elegida = 'C';
		for (k = 0; k < 9; k++) {
			if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
				fichas[i][k].molino = verificar_molino();
				break;
			}
		}
		break;
	}
}

bool verificar_molino() {
	horizontal = false, vertical = false, diagonal = false;

	switch (posicion_elegida) {
	case 'A':
		//horizontal
		if (B == jugador[i].ficha && C == jugador[i].ficha) {
			horizontal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'B' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (J == jugador[i].ficha && V == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'J' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (D == jugador[i].ficha && G == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (E == jugador[i].ficha && H == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'E' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'H' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'B' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (O == jugador[i].ficha && X == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'O' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (F == jugador[i].ficha && I == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'E' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (K == jugador[i].ficha && S == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'K' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (A == jugador[i].ficha && G == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (B == jugador[i].ficha && H == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'B' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'H' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'E' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (N == jugador[i].ficha && U == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'N' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (C == jugador[i].ficha && I == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'H' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (L == jugador[i].ficha && P == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'L' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'P' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (A == jugador[i].ficha && D == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (B == jugador[i].ficha && E == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'B' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'E' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'H' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (M == jugador[i].ficha && R == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'M' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (C == jugador[i].ficha && F == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'K' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'L' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (A == jugador[i].ficha && V == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'J' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'L' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (D == jugador[i].ficha && S == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'J' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'K' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (G == jugador[i].ficha && P == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'P' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'N' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'O' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (I == jugador[i].ficha && R == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'M' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'O' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (F == jugador[i].ficha && U == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'M' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'N' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (C == jugador[i].ficha && X == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'Q' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (G == jugador[i].ficha && L == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'G' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'L' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (S == jugador[i].ficha && V == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'P' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (T == jugador[i].ficha && W == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'T' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'W' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'Q' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (I == jugador[i].ficha && M == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'I' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'M' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (U == jugador[i].ficha && X == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'T' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (D == jugador[i].ficha && K == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'D' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'K' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (P == jugador[i].ficha && V == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'P' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (Q == jugador[i].ficha && W == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'Q' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'W' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'T' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (F == jugador[i].ficha && N == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'F' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'N' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (R == jugador[i].ficha && X == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'W' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (A == jugador[i].ficha && J == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'A' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'J' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (P == jugador[i].ficha && S == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'P' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'S' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'X' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (Q == jugador[i].ficha && T == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'Q' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'T' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'V' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'W' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//vertical
		if (C == jugador[i].ficha && O == jugador[i].ficha) {
			vertical = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'C' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'O' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}
		}

		//diagonal
		if (R == jugador[i].ficha && U == jugador[i].ficha) {
			diagonal = true;

			fichas[i][j].molino = true;

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'R' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
					break;
				}
			}

			for (k = 0; k < 9; k++) {
				if (fichas[i][k].letra == 'U' && fichas[i][k].vivo == true) {
					fichas[i][k].molino = true;
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
	switch (posicion_previa) {
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
	switch (posicion_elegida) {
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
	obtener_coordenadas();

	tablero[x][y] = jugador[i].ficha;

	switch (posicion_previa) {
	case 'A':
		A = a0;
		break;

	case 'B':
		B = b0;
		break;

	case 'C':
		C = c0;
		break;

	case 'D':
		D = d0;
		break;

	case 'E':
		E = e0;
		break;

	case 'F':
		F = f0;
		break;

	case 'G':
		G = g0;
		break;

	case 'H':
		H = h0;
		break;

	case 'I':
		I = i0;
		break;

	case 'J':
		J = j0;
		break;

	case 'K':
		K = k0;
		break;

	case 'L':
		L = l0;
		break;

	case 'M':
		M = m0;
		break;

	case 'N':
		N = n0;
		break;

	case 'O':
		O = o0;
		break;

	case 'P':
		P = p0;
		break;

	case 'Q':
		Q = q0;
		break;

	case 'R':
		R = r0;
		break;

	case 'S':
		S = s0;
		break;

	case 'T':
		T = t0;
		break;

	case 'U':
		U = u0;
		break;

	case 'V':
		V = v0;
		break;

	case 'W':
		W = w0;
		break;

	case 'X':
		X = x0;
		break;
	}
}

void actualizar_datos_fase2() {
	switch (posicion_elegida) {
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

	cout << "\t\t\tTURNO: " << jugador[i].nombre << " " << jugador[i].ficha << "\t\t\tMOVIMIENTOS HECHOS: " << jugador[i].cant_mov << endl;

	mostrar_vidas();
	mostrar_dinero();

	do {
		do {
			cout << "\t\t\tFICHA A MOVER: ";
			cin >> posicion_elegida;

			posicion_elegida = toupper(posicion_elegida);
			posicion_previa = posicion_elegida;
		} while (posicion_elegida < 'A' || posicion_elegida > 'X');

		for (j = 0; j < 9; j++) {
			if (fichas[i][j].letra == posicion_elegida && fichas[i][j].vivo == true) {
				hay_ficha = true;
				break;
			}
		}
	} while (hay_ficha == false || (puede_mover() == false && jugador[i].fase3 == false));

	do {
		do {
			cout << "\t\t\tLUGAR A MOVER: ";
			cin >> posicion_elegida;

			posicion_elegida = toupper(posicion_elegida);
		} while (posicion_elegida < 'A' || posicion_elegida > 'X');

		obtener_coordenadas();
	} while (verificar_espacio_libre() == false || (puede_recibir() == false && jugador[i].fase3 == false));

	jugador[i].cant_mov++;

	mover();
	actualizar_molinos();
	actualizar_datos_fase2();
}

void fase2() {
	while (verificar_ganador() == false) {
		recibir_jugada_fase2();

		imprimir_tablero();

		if (verificar_molino() == true) {
			recibir_comer();
			imprimir_tablero();
		}

		cambiar_turno();
		verificar_fase3();
	}

}

void guardar_datos_fase1() {
	fichas[i][j].letra = posicion_elegida;
	fichas[i][j].vivo = true;

	switch (posicion_elegida) {
	case 'A':
		A = jugador[i].ficha;
		break;

	case 'B':
		B = jugador[i].ficha;
		break;

	case 'C':
		C = jugador[i].ficha;
		break;

	case 'D':
		D = jugador[i].ficha;
		break;

	case 'E':
		E = jugador[i].ficha;
		break;

	case 'F':
		F = jugador[i].ficha;
		break;

	case 'G':
		G = jugador[i].ficha;
		break;

	case 'H':
		H = jugador[i].ficha;
		break;

	case 'I':
		I = jugador[i].ficha;
		break;

	case 'J':
		J = jugador[i].ficha;
		break;

	case 'K':
		K = jugador[i].ficha;
		break;

	case 'L':
		L = jugador[i].ficha;
		break;

	case 'M':
		M = jugador[i].ficha;
		break;

	case 'N':
		N = jugador[i].ficha;
		break;

	case 'O':
		O = jugador[i].ficha;
		break;

	case 'P':
		P = jugador[i].ficha;
		break;

	case 'Q':
		Q = jugador[i].ficha;
		break;

	case 'R':
		R = jugador[i].ficha;
		break;

	case 'S':
		S = jugador[i].ficha;
		break;

	case 'T':
		T = jugador[i].ficha;
		break;

	case 'U':
		U = jugador[i].ficha;
		break;

	case 'V':
		V = jugador[i].ficha;
		break;

	case 'W':
		W = jugador[i].ficha;
		break;

	case 'X':
		X = jugador[i].ficha;
		break;
	}
}

void recibir_jugada_fase1() {
	cout << "\t\t\tTURNO: " << jugador[i].nombre << " " << jugador[i].ficha << endl;
	cout << "\t\t\tFICHAS POR PONER: " << 9 - jugador[i].fichas_puestas << endl;

	mostrar_vidas();
	mostrar_dinero();

	do {
		do {
			cout << "\t\t\tPosicion: ";
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

		if (verificar_molino() == true) {
			recibir_comer();
			imprimir_tablero();
		}

		cambiar_turno();

		recibir_jugada_fase1();

		imprimir_tablero();

		jugador[i].fichas_puestas++;

		if (verificar_molino() == true) {
			recibir_comer();
			imprimir_tablero();
		}

		cambiar_turno();
	}
}

void asignar_turnos() {
	Random rng;

	if (rng.Next(0, 2) % 2 != 0) {
		i = 0;

		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t\tEmpieza";

		Sleep(700);
		cout << ".";

		Sleep(700);
		cout << ".";

		Sleep(700);
		cout << ". ";

		Sleep(700);
		cout << jugador[0].nombre << endl << endl;
		cout << "\t\t\t\t\t\tPRESIONA UNA TECLA PARA CONTINUAR";
		_getch();


		do {
			cls;
			cout << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t1)Blanco " << blanco << endl;
			cout << "\t\t\t\t\t\t\t2)Negro " << negro << endl;
			cout << "\t\t\t\t\t\t\t" << jugador[0].nombre << " elige fichas: ";
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

		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t\tEmpieza";

		Sleep(700);
		cout << ".";

		Sleep(700);
		cout << ".";

		Sleep(700);
		cout << ". ";

		Sleep(700);
		cout << jugador[1].nombre << endl << endl;
		cout << "\t\t\t\t\t\tPRESIONA UNA TECLA PARA CONTINUAR";
		_getch();


		do {
			cls;
			cout << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t1)Blanco " << blanco << endl;
			cout << "\t\t\t\t\t\t\t2)Negro " << negro << endl;
			cout << "\t\t\t\t\t\t\t" << jugador[1].nombre << " elige fichas: ";
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
	cout << endl << endl;
	cout << "\t\t***************************************************************************************************" << endl;
	cout << "\t\t********************************************  JUGADOR 1  ******************************************" << endl;
	cout << "\t\t***************************************************************************************************" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\tINGRESA TU NOMBRE: ";
	cin >> jugador[0].nombre;

	cls;

	cout << endl << endl;
	cout << "\t\t***************************************************************************************************" << endl;
	cout << "\t\t********************************************  JUGADOR 2  ******************************************" << endl;
	cout << "\t\t***************************************************************************************************" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\tINGRESA TU NOMBRE: ";
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

	cambiar_turno();

	revancha();
}

void molino_banner() {
	molino = new char* [20];//crea filas

	for (int i = 0; i < 20; i++) {
		molino[i] = new char[60];//crea columnas
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 60; j++) {
			molino[i][j] = char(32);//todo en blanco
		}
	}

	for (int i = 0; i <= 4; i++) {
		molino[i][15] = char(56);
		molino[i][16] = char(56);
		molino[i][17] = char(56);
	}
	for (int j = 13; j <= 16; j++) {
		molino[5][j] = char(56);
	}

	molino[5][17] = char(39);
	molino[3][12] = char(46);
	molino[4][13] = char(46);
	molino[3][10] = char(56);
	molino[3][11] = char(56);
	molino[4][11] = char(56);
	molino[5][12] = char(89);
	molino[4][10] = char(96);
	molino[5][11] = char(96);
	molino[4][12] = char(111);

	for (int i = 0; i <= 3; i++) {
		molino[i][19] = char(56);
		molino[i][20] = char(56);
		molino[i][21] = char(56);
		molino[i][25] = char(56);
		molino[i][26] = char(56);

	}
	for (int j = 22; j <= 24; j++) {
		molino[5][j] = char(56);
	}

	molino[5][26] = char(39);
	molino[4][24] = char(44);
	molino[4][26] = char(80);
	molino[5][25] = char(80);
	molino[5][21] = char(89);
	molino[4][19] = char(96);
	molino[5][20] = char(96);
	molino[4][25] = char(100);
	molino[4][20] = char(56);
	molino[4][21] = char(56);

	for (int i = 0; i <= 5; i++) {
		molino[i][28] = char(56);
		molino[i][29] = char(56);
	}

	for (int j = 30; j <= 33; j++) {
		molino[0][j] = char(56);
		molino[2][j] = char(56);
		molino[5][j] = char(56);
	}

	for (int i = 1; i <= 4; i++) {
		molino[i][36] = char(56);
		molino[i][37] = char(56);
	}

	for (int j = 38; j <= 40; j++) {
		molino[0][j] = char(56);
		molino[5][j] = char(56);
	}

	for (int j = 40; j <= 43; j++) {
		molino[3][j] = char(56);
	}

	molino[4][43] = char(39);
	molino[5][42] = char(39);
	molino[1][35] = char(44);
	molino[0][36] = char(44);
	molino[0][42] = char(46);
	molino[1][43] = char(46);
	molino[4][41] = char(46);
	molino[2][35] = char(56);
	molino[3][35] = char(56);
	molino[5][37] = char(56);
	molino[1][42] = char(56);
	molino[4][42] = char(56);
	molino[5][41] = char(80);
	molino[4][35] = char(96);
	molino[5][37] = char(96);
	molino[1][41] = char(96);
	molino[0][37] = char(111);
	molino[0][41] = char(111);

	for (int i = 1; i <= 4; i++) {
		molino[i][46] = char(56);
		molino[i][47] = char(56);
		molino[i][51] = char(56);
		molino[i][52] = char(56);
	}

	for (int j = 48; j <= 50; j++) {
		molino[0][j] = char(56);
		molino[5][j] = char(56);
	}

	molino[5][52] = char(39);
	molino[4][53] = char(39);
	molino[1][45] = char(44);
	molino[0][46] = char(44);
	molino[4][50] = char(44);
	molino[2][45] = char(56);
	molino[3][45] = char(56);
	molino[3][53] = char(56);
	molino[2][53] = char(56);
	molino[5][47] = char(56);
	molino[0][52] = char(46);
	molino[1][53] = char(46);
	molino[5][51] = char(80);
	molino[1][50] = char(96);
	molino[4][45] = char(96);
	molino[5][46] = char(96);
	molino[0][47] = char(111);
	molino[0][51] = char(111);

	for (int i = 9; i <= 11; i++) {
		molino[i][21] = char(56);
		molino[i][22] = char(56);
		molino[i][26] = char(56);
		molino[i][27] = char(56);
	}

	for (int j = 21; j <= 25; j++) {
		molino[7][j] = char(56);
		molino[12][j] = char(56);
	}

	molino[11][25] = char(44);
	molino[7][27] = char(46);
	molino[8][21] = char(56);
	molino[8][22] = char(56);
	molino[8][26] = char(56);
	molino[12][26] = char(80);
	molino[8][25] = char(96);
	molino[8][27] = char(98);
	molino[7][26] = char(111);

	for (int i = 7; i <= 12; i++) {
		molino[i][29] = char(56);
		molino[i][30] = char(56);
	}

	for (int j = 31; j <= 34; j++) {
		molino[7][j] = char(56);
		molino[9][j] = char(56);
		molino[12][j] = char(56);
	}

	for (int i = 7; i <= 12; i++) {
		molino[i][36] = char(56);
		molino[i][37] = char(56);
	}

	for (int j = 38; j <= 42; j++) {
		molino[12][j] = char(56);
	}

	for (int i = 15; i <= 17; i++) {
		molino[i][8] = char(56);
		molino[i][9] = char(56);
		molino[i][10] = char(56);
	}

	for (int j = 13; j <= 15; j++) {
		molino[16][j] = char(56);
		molino[17][j] = char(56);
	}

	for (int j = 15; j <= 17; j++) {
		molino[18][j] = char(56);
		molino[19][j] = char(56);
	}

	molino[19][5] = char(39);
	molino[18][6] = char(39);
	molino[17][7] = char(39);
	molino[18][11] = char(39);
	molino[17][12] = char(39);
	molino[19][3] = char(44);
	molino[18][4] = char(44);
	molino[17][5] = char(44);
	molino[16][6] = char(44);
	molino[15][7] = char(44);
	molino[14][8] = char(44);
	molino[13][9] = char(46);
	molino[14][10] = char(46);
	molino[13][13] = char(46);
	molino[14][14] = char(46);
	molino[15][15] = char(46);
	molino[16][16] = char(46);
	molino[17][17] = char(46);
	molino[18][18] = char(46);
	molino[19][19] = char(46);
	molino[19][4] = char(56);
	molino[18][5] = char(56);
	molino[17][6] = char(56);
	molino[16][7] = char(56);
	molino[14][9] = char(56);
	molino[18][9] = char(56);
	molino[18][10] = char(56);
	molino[16][11] = char(56);
	molino[17][11] = char(56);
	molino[16][12] = char(56);
	molino[15][12] = char(56);
	molino[15][13] = char(56);
	molino[15][14] = char(56);
	molino[14][13] = char(56);
	molino[18][14] = char(56);
	molino[17][16] = char(56);
	molino[19][18] = char(56);
	molino[18][8] = char(96);
	molino[18][13] = char(96);
	molino[19][9] = char(96);
	molino[19][14] = char(96);

	for (int i = 15; i <= 18; i++) {
		molino[i][20] = char(56);
		molino[i][21] = char(56);
		molino[i][25] = char(56);
		molino[i][26] = char(56);
	}

	for (int j = 22; j <= 24; j++) {
		molino[15][j] = char(56);
		molino[19][j] = char(56);
	}

	molino[19][26] = char(39);
	molino[18][27] = char(39);
	molino[15][19] = char(44);
	molino[14][20] = char(44);
	molino[18][24] = char(44);
	molino[16][19] = char(56);
	molino[17][19] = char(56);
	molino[17][27] = char(56);
	molino[16][27] = char(56);
	molino[19][21] = char(56);
	molino[14][26] = char(46);
	molino[15][27] = char(46);
	molino[19][25] = char(80);
	molino[15][24] = char(96);
	molino[18][19] = char(96);
	molino[19][20] = char(96);
	molino[14][21] = char(111);
	molino[14][25] = char(111);

	for (int i = 14; i <= 19; i++) {
		molino[i][29] = char(56);
		molino[i][30] = char(56);
	}

	for (int j = 31; j <= 35; j++) {
		molino[19][j] = char(56);
	}

	for (int i = 14; i <= 19; i++) {
		molino[i][37] = char(56);
		molino[i][38] = char(56);
	}

	for (int i = 14; i <= 18; i++) {
		molino[i][40] = char(56);
		molino[i][41] = char(56);
		molino[i][49] = char(56);
	}

	for (int i = 17; i <= 18; i++) {
		molino[i][42] = char(56);
		molino[i][47] = char(56);
	}

	for (int j = 43; j <= 45; j++) {
		molino[16][j] = char(56);
	}

	for (int j = 40; j <= 42; j++) {
		molino[19][j] = char(56);
	}

	molino[14][43] = char(46);
	molino[15][45] = char(46);
	molino[16][47] = char(46);
	molino[15][43] = char(56);
	molino[15][42] = char(56);
	molino[17][45] = char(56);
	molino[17][46] = char(56);
	molino[18][48] = char(56);
	molino[16][42] = char(111);
	molino[17][44] = char(111);
	molino[18][46] = char(111);
	molino[19][48] = char(111);
	molino[17][43] = char(96);
	molino[18][45] = char(96);
	molino[19][47] = char(96);
	molino[14][42] = char(98);
	molino[15][44] = char(111);
	molino[16][46] = char(111);
	molino[17][48] = char(111);
	molino[19][49] = char(56);

	for (int i = 15; i <= 18; i++) {
		molino[i][52] = char(56);
		molino[i][53] = char(56);
		molino[i][57] = char(56);
		molino[i][58] = char(56);
	}

	for (int j = 54; j <= 56; j++) {
		molino[14][j] = char(56);
		molino[19][j] = char(56);
	}

	molino[19][58] = char(39);
	molino[18][59] = char(39);
	molino[15][51] = char(44);
	molino[14][52] = char(44);
	molino[18][51] = char(44);
	molino[16][51] = char(56);
	molino[17][51] = char(56);
	molino[17][59] = char(56);
	molino[16][59] = char(56);
	molino[19][53] = char(56);
	molino[14][58] = char(46);
	molino[15][59] = char(46);
	molino[19][57] = char(80);
	molino[15][56] = char(96);
	molino[18][51] = char(96);
	molino[19][52] = char(96);
	molino[14][53] = char(111);
	molino[14][57] = char(111);

	//imprimir
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 60; j++) {
			cout << molino[i][j];
		}
		cout << endl;
	}
}

void reglas_banner() {
	reglas = new char* [6];//crea filas

	for (int i = 0; i < 6; i++) {
		reglas[i] = new char[50];//crea columnas
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 50; j++) {
			reglas[i][j] = char(32);//todo en blanco
		}
	}

	for (int i = 0; i <= 4; i++) {
		reglas[i][0] = char(219);
		reglas[i][1] = char(219);
		reglas[i][5] = char(219);
	}

	for (int j = 2; j <= 4; j++) {
		reglas[0][j] = char(219);
		reglas[2][j] = char(219);
	}

	for (int j = 3; j <= 4; j++) {
		reglas[1][j] = char(205);
		reglas[3][j] = char(205);
	}

	reglas[5][1] = char(205);
	reglas[5][6] = char(205);
	reglas[5][0] = char(200);
	reglas[5][5] = char(200);
	reglas[5][2] = char(188);
	reglas[5][7] = char(188);
	reglas[2][7] = char(188);
	reglas[0][6] = char(187);
	reglas[1][7] = char(187);
	reglas[3][7] = char(187);
	reglas[4][2] = char(186);
	reglas[4][7] = char(186);
	reglas[1][2] = char(201);
	reglas[3][2] = char(201);
	reglas[2][6] = char(201);
	reglas[1][6] = char(219);
	reglas[3][6] = char(219);
	reglas[4][6] = char(219);

	for (int i = 0; i <= 4; i++) {
		reglas[i][8] = char(219);
		reglas[i][9] = char(219);
	}

	for (int j = 10; j <= 14; j++) {
		reglas[0][j] = char(219);
		reglas[4][j] = char(219);
	}

	for (int j = 10; j <= 12; j++) {
		reglas[2][j] = char(219);
	}

	for (int j = 9; j <= 14; j++) {
		reglas[5][j] = char(205);
	}

	for (int j = 11; j <= 14; j++) {
		reglas[1][j] = char(205);
	}

	reglas[5][8] = char(200);
	reglas[3][11] = char(205);
	reglas[3][12] = char(205);
	reglas[1][10] = char(201);
	reglas[3][10] = char(201);
	reglas[1][15] = char(188);
	reglas[3][13] = char(188);
	reglas[5][15] = char(188);
	reglas[0][15] = char(187);
	reglas[2][13] = char(187);
	reglas[4][15] = char(187);

	for (int i = 1; i <= 3; i++) {
		reglas[i][16] = char(219);
	}

	for (int i = 0; i <= 4; i++) {
		reglas[i][17] = char(219);
	}

	for (int j = 18; j <= 22; j++) {
		reglas[0][j] = char(219);
		reglas[4][j] = char(219);
		reglas[5][j] = char(205);
	}

	for (int j = 21; j <= 23; j++) {
		reglas[2][j] = char(219);
	}

	for (int j = 22; j <= 23; j++) {
		reglas[3][j] = char(219);
	}

	for (int j = 19; j <= 22; j++) {
		reglas[1][j] = char(205);
	}

	reglas[4][16] = char(200);
	reglas[5][17] = char(200);
	reglas[2][18] = char(186);
	reglas[3][18] = char(186);
	reglas[3][24] = char(186);
	reglas[1][18] = char(201);
	reglas[4][23] = char(201);
	reglas[0][23] = char(187);
	reglas[2][24] = char(187);
	reglas[1][23] = char(188);
	reglas[5][23] = char(188);
	reglas[4][24] = char(188);
	reglas[0][25] = char(219);
	reglas[0][26] = char(219);
	reglas[0][27] = char(187);
	reglas[1][25] = char(219);
	reglas[1][26] = char(219);
	reglas[1][27] = char(186);
	reglas[2][25] = char(219);
	reglas[2][26] = char(219);
	reglas[2][27] = char(186);
	reglas[3][25] = char(219);
	reglas[3][26] = char(219);
	reglas[3][27] = char(186);
	reglas[4][25] = char(219);
	reglas[4][26] = char(219);
	reglas[4][27] = char(219);
	reglas[4][28] = char(219);
	reglas[4][29] = char(219);
	reglas[4][30] = char(219);
	reglas[4][31] = char(219);
	reglas[4][32] = char(219);
	reglas[4][33] = char(187);
	reglas[5][25] = char(200);
	reglas[5][26] = char(205);
	reglas[5][27] = char(205);
	reglas[5][28] = char(205);
	reglas[5][29] = char(205);
	reglas[5][30] = char(205);
	reglas[5][31] = char(205);
	reglas[5][32] = char(205);
	reglas[5][33] = char(188);
	reglas[0][35] = char(219);
	reglas[0][36] = char(219);
	reglas[0][37] = char(219);
	reglas[0][38] = char(219);
	reglas[0][39] = char(219);
	reglas[0][40] = char(187);
	reglas[1][34] = char(219);
	reglas[1][35] = char(219);
	reglas[1][36] = char(201);
	reglas[1][37] = char(205);
	reglas[1][38] = char(205);
	reglas[1][39] = char(219);
	reglas[1][40] = char(219);
	reglas[1][41] = char(187);
	reglas[2][34] = char(219);
	reglas[2][35] = char(219);
	reglas[2][36] = char(219);
	reglas[2][37] = char(219);
	reglas[2][38] = char(219);
	reglas[2][39] = char(219);
	reglas[2][40] = char(219);
	reglas[2][41] = char(186);
	reglas[3][34] = char(219);
	reglas[3][35] = char(219);
	reglas[3][36] = char(201);
	reglas[3][37] = char(205);
	reglas[3][38] = char(205);
	reglas[3][39] = char(219);
	reglas[3][40] = char(219);
	reglas[3][41] = char(186);
	reglas[4][34] = char(219);
	reglas[4][35] = char(219);
	reglas[4][36] = char(186);
	reglas[4][39] = char(219);
	reglas[4][40] = char(219);
	reglas[4][41] = char(186);
	reglas[5][34] = char(200);
	reglas[5][35] = char(205);
	reglas[5][36] = char(188);
	reglas[5][39] = char(200);
	reglas[5][40] = char(205);
	reglas[5][41] = char(188);
	reglas[0][42] = char(219);
	reglas[0][43] = char(219);
	reglas[0][44] = char(219);
	reglas[0][45] = char(219);
	reglas[0][46] = char(219);
	reglas[0][47] = char(219);
	reglas[0][48] = char(219);
	reglas[0][49] = char(187);
	reglas[1][42] = char(219);
	reglas[1][43] = char(219);
	reglas[1][44] = char(201);
	reglas[1][45] = char(205);
	reglas[1][46] = char(205);
	reglas[1][47] = char(205);
	reglas[1][48] = char(205);
	reglas[1][49] = char(188);
	reglas[2][42] = char(219);
	reglas[2][43] = char(219);
	reglas[2][44] = char(219);
	reglas[2][45] = char(219);
	reglas[2][46] = char(219);
	reglas[2][47] = char(219);
	reglas[2][48] = char(219);
	reglas[2][49] = char(187);
	reglas[3][42] = char(200);
	reglas[3][43] = char(205);
	reglas[3][44] = char(205);
	reglas[3][45] = char(205);
	reglas[3][46] = char(205);
	reglas[3][47] = char(219);
	reglas[3][48] = char(219);
	reglas[3][49] = char(186);
	reglas[4][42] = char(219);
	reglas[4][43] = char(219);
	reglas[4][44] = char(219);
	reglas[4][45] = char(219);
	reglas[4][46] = char(219);
	reglas[4][47] = char(219);
	reglas[4][48] = char(219);
	reglas[4][49] = char(186);
	reglas[5][42] = char(200);
	reglas[5][43] = char(205);
	reglas[5][44] = char(205);
	reglas[5][45] = char(205);
	reglas[5][46] = char(205);
	reglas[5][47] = char(205);
	reglas[5][48] = char(205);
	reglas[5][49] = char(188);

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 50; j++) {
			cout << reglas[i][j];
		}
		cout << endl;
	}
}

void upc_banner() {
	upc = new char* [6];//crea filas

	for (int i = 0; i < 6; i++) {
		upc[i] = new char[72];//crea columnas
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 72; j++) {
			upc[i][j] = char(32);//todo en blanco
		}
	}

	for (int i = 0; i <= 3; i++) {
		upc[i][0] = char(219);
		upc[i][1] = char(219);
		upc[i][6] = char(219);
		upc[i][7] = char(219);
	}

	for (int j = 1; j <= 6; j++) {
		upc[4][j] = char(219);
	}

	for (int j = 2; j <= 6; j++) {
		upc[5][j] = char(205);
	}

	for (int i = 1; i <= 3; i++) {
		upc[i][2] = char(186);
		upc[i][8] = char(186);
	}

	upc[4][0] = char(200);
	upc[5][1] = char(200);
	upc[4][7] = char(201);
	upc[4][8] = char(188);
	upc[5][7] = char(188);
	upc[0][2] = char(187);
	upc[0][8] = char(187);

	for (int i = 0; i <= 4; i++) {
		upc[i][9] = char(219);
		upc[i][10] = char(219);
	}

	for (int j = 11; j <= 14; j++) {
		upc[0][j] = char(219);
		upc[2][j] = char(219);
	}

	upc[1][14] = char(219);
	upc[1][15] = char(219);
	upc[1][12] = char(205);
	upc[1][13] = char(205);
	upc[3][12] = char(205);
	upc[3][13] = char(205);
	upc[3][14] = char(205);
	upc[5][10] = char(205);
	upc[3][11] = char(201);
	upc[4][11] = char(186);
	upc[5][11] = char(188);
	upc[1][11] = char(201);
	upc[2][15] = char(201);
	upc[0][15] = char(187);
	upc[3][15] = char(188);
	upc[5][9] = char(200);
	upc[1][16] = char(187);
	upc[2][16] = char(188);

	for (int i = 1; i <= 3; i++) {
		upc[i][17] = char(219);
		upc[i][18] = char(219);
	}

	for (int j = 18; j <= 23; j++) {
		upc[0][j] = char(219);
		upc[4][j] = char(219);
	}

	for (int j = 20; j <= 23; j++) {
		upc[1][j] = char(205);
		upc[5][j] = char(205);
	}

	upc[4][17] = char(200);
	upc[5][18] = char(200);
	upc[5][19] = char(205);
	upc[5][24] = char(188);
	upc[4][24] = char(187);
	upc[1][19] = char(201);
	upc[2][19] = char(186);
	upc[3][19] = char(186);
	upc[0][24] = char(187);
	upc[1][24] = char(188);

	for (int j = 29; j <= 33; j++) {
		upc[2][j] = char(219);

	}

	for (int j = 30; j <= 33; j++) {
		upc[3][j] = char(205);
	}
	upc[3][29] = char(200);
	upc[2][34] = char(187);
	upc[3][34] = char(188);

	for (int j = 39; j <= 44; j++) {
		upc[0][j] = char(219);
	}

	for (int j = 40; j <= 44; j++) {
		upc[2][j] = char(219);
	}

	for (int j = 39; j <= 45; j++) {
		upc[4][j] = char(219);
	}

	for (int j = 40; j <= 43; j++) {
		upc[1][j] = char(205);
	}

	for (int j = 42; j <= 44; j++) {
		upc[3][j] = char(205);
	}

	for (int j = 40; j <= 45; j++) {
		upc[5][j] = char(205);
	}

	upc[0][45] = char(187);
	upc[1][46] = char(187);
	upc[4][46] = char(187);
	upc[2][46] = char(188);
	upc[3][45] = char(188);
	upc[5][46] = char(188);
	upc[1][39] = char(200);
	upc[5][39] = char(200);
	upc[2][45] = char(201);
	upc[3][41] = char(201);
	upc[3][39] = char(219);
	upc[3][40] = char(219);
	upc[1][44] = char(219);
	upc[1][45] = char(219);

	for (int i = 0; i <= 4; i++) {
		upc[i][48] = char(219);
		upc[i][53] = char(219);
	}
	for (int i = 1; i <= 3; i++) {
		upc[i][47] = char(219);
		upc[i][54] = char(219);
	}
	for (int j = 49; j <= 52; j++) {
		upc[0][j] = char(219);
		upc[4][j] = char(219);
	}

	for (int j = 49; j <= 53; j++) {
		upc[5][j] = char(205);
	}

	upc[2][49] = char(186);
	upc[2][55] = char(186);
	upc[3][55] = char(186);
	upc[0][54] = char(187);
	upc[1][55] = char(187);
	upc[3][52] = char(188);
	upc[4][55] = char(188);
	upc[5][54] = char(188);
	upc[4][47] = char(200);
	upc[5][48] = char(200);
	upc[1][49] = char(201);
	upc[2][52] = char(201);
	upc[3][51] = char(201);
	upc[4][54] = char(201);
	upc[1][50] = char(205);
	upc[1][51] = char(219);
	upc[1][52] = char(219);
	upc[2][50] = char(219);
	upc[2][51] = char(219);
	upc[3][49] = char(219);
	upc[3][50] = char(219);

	for (int j = 56; j <= 61; j++) {
		upc[0][j] = char(219);
	}

	for (int j = 57; j <= 61; j++) {
		upc[2][j] = char(219);
	}

	for (int j = 56; j <= 62; j++) {
		upc[4][j] = char(219);
	}

	for (int j = 56; j <= 60; j++) {
		upc[1][j] = char(205);
	}

	for (int j = 59; j <= 61; j++) {
		upc[3][j] = char(205);
	}

	for (int j = 57; j <= 62; j++) {
		upc[5][j] = char(205);
	}

	upc[0][62] = char(187);
	upc[1][63] = char(187);
	upc[4][63] = char(187);
	upc[2][63] = char(188);
	upc[3][62] = char(188);
	upc[5][63] = char(188);
	upc[1][56] = char(200);
	upc[5][56] = char(200);
	upc[2][62] = char(201);
	upc[3][58] = char(201);
	upc[3][56] = char(219);
	upc[3][57] = char(219);
	upc[1][61] = char(219);
	upc[1][62] = char(219);

	for (int j = 64; j <= 69; j++) {
		upc[0][j] = char(219);
	}

	for (int j = 65; j <= 69; j++) {
		upc[2][j] = char(219);
	}

	for (int j = 64; j <= 70; j++) {
		upc[4][j] = char(219);
	}

	for (int j = 65; j <= 68; j++) {
		upc[1][j] = char(205);
	}

	for (int j = 67; j <= 69; j++) {
		upc[3][j] = char(205);
	}

	for (int j = 65; j <= 70; j++) {
		upc[5][j] = char(205);
	}

	upc[0][70] = char(187);
	upc[1][71] = char(187);
	upc[4][71] = char(187);
	upc[2][71] = char(188);
	upc[3][70] = char(188);
	upc[5][71] = char(188);
	upc[1][64] = char(200);
	upc[5][64] = char(200);
	upc[2][70] = char(201);
	upc[3][66] = char(201);
	upc[3][64] = char(219);
	upc[3][65] = char(219);
	upc[1][69] = char(219);
	upc[1][70] = char(219);

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 72; j++) {
			cout << upc[i][j];
		}
		cout << endl;
	}
}

void opciones_banner() {
	opciones_1 = new char* [11];

	for (int i = 0; i < 11; i++)
		opciones_1[i] = new char[54];

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 54; j++) {
			opciones_1[i][j] = char(32);
		}
	}

	opciones_2 = new char* [11];

	for (int i = 0; i < 11; i++)
		opciones_2[i] = new char[67];

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 67; j++) {
			opciones_2[i][j] = char(32);
		}
	}

	opciones_3 = new char* [8];

	for (int i = 0; i < 8; i++)
		opciones_3[i] = new char[81];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 81; j++) {
			opciones_3[i][j] = char(32);
		}
	}

	//1)Jugar
	for (int i = 0; i <= 7; i++) {
		opciones_1[i][2] = char(56);
		opciones_1[i][3] = char(56);
		opciones_1[i][4] = char(56);
	}

	for (int j = 0; j <= 6; j++) {
		opciones_1[7][j] = char(56);
	}

	opciones_1[1][1] = char(56);
	opciones_1[0][1] = char(100);
	opciones_1[1][0] = char(100);

	for (int i = 3; i <= 5; i++) {
		opciones_1[i][11] = char(56);
		opciones_1[i][12] = char(56);
		opciones_1[i][13] = char(56);
	}

	opciones_1[0][8] = char(56);
	opciones_1[0][9] = char(56);
	opciones_1[7][8] = char(56);
	opciones_1[7][9] = char(56);
	opciones_1[1][10] = char(56);
	opciones_1[1][11] = char(56);
	opciones_1[6][10] = char(56);
	opciones_1[6][11] = char(56);
	opciones_1[2][11] = char(56);
	opciones_1[2][12] = char(56);
	opciones_1[6][12] = char(80);
	opciones_1[6][13] = char(80);
	opciones_1[7][10] = char(80);
	opciones_1[0][10] = char(98);
	opciones_1[1][12] = char(98);
	opciones_1[2][13] = char(98);
	opciones_1[1][9] = char(89);
	opciones_1[2][10] = char(89);
	opciones_1[5][10] = char(100);
	opciones_1[6][9] = char(100);
	opciones_1[1][8] = char(34);
	opciones_1[7][11] = char(34);
	opciones_1[0][11] = char(46);
	opciones_1[6][8] = char(46);

	for (int i = 1; i <= 8; i++) {
		opciones_1[i][16] = char(56);
		opciones_1[i][17] = char(56);
		opciones_1[i][18] = char(56);
	}

	for (int j = 13; j <= 17; j++) {
		opciones_1[0][j] = char(56);
	}

	opciones_1[9][14] = char(56);
	opciones_1[9][15] = char(56);
	opciones_1[10][11] = char(56);
	opciones_1[10][12] = char(56);
	opciones_1[10][13] = char(56);
	opciones_1[6][18] = char(80);
	opciones_1[8][18] = char(80);
	opciones_1[9][16] = char(80);
	opciones_1[10][14] = char(80);
	opciones_1[1][15] = char(34);
	opciones_1[9][17] = char(34);
	opciones_1[10][15] = char(34);
	opciones_1[8][15] = char(100);
	opciones_1[9][13] = char(100);
	opciones_1[1][18] = char(98);
	opciones_1[8][14] = char(46);
	opciones_1[9][12] = char(46);

	//u
	for (int i = 3; i <= 6; i++) {
		opciones_1[i][20] = char(56);
		opciones_1[i][21] = char(56);
		opciones_1[i][22] = char(56);
	}

	for (int i = 3; i <= 7; i++) {
		opciones_1[i][25] = char(56);
		opciones_1[i][26] = char(56);
		opciones_1[i][27] = char(56);
	}

	opciones_1[7][23] = char(56);
	opciones_1[7][24] = char(56);
	opciones_1[7][21] = char(34);
	opciones_1[7][22] = char(89);
	opciones_1[6][20] = char(89);
	opciones_1[6][23] = char(48);

	//g
	for (int i = 4; i <= 9; i++) {
		opciones_1[i][34] = char(56);
		opciones_1[i][35] = char(56);
		opciones_1[i][36] = char(56);
	}

	for (int i = 4; i <= 6; i++) {
		opciones_1[i][29] = char(56);
		opciones_1[i][30] = char(56);
		opciones_1[i][31] = char(56);
	}

	opciones_1[3][32] = char(56);
	opciones_1[3][33] = char(56);
	opciones_1[7][32] = char(56);
	opciones_1[7][33] = char(56);
	opciones_1[10][32] = char(56);
	opciones_1[10][33] = char(56);
	opciones_1[9][30] = char(56);
	opciones_1[6][29] = char(89);
	opciones_1[9][29] = char(89);
	opciones_1[7][31] = char(89);
	opciones_1[10][31] = char(89);
	opciones_1[7][30] = char(34);
	opciones_1[10][30] = char(34);
	opciones_1[4][33] = char(34);
	opciones_1[10][35] = char(34);
	opciones_1[6][32] = char(98);
	opciones_1[9][31] = char(98);
	opciones_1[3][34] = char(98);
	opciones_1[4][36] = char(98);
	opciones_1[4][32] = char(80);
	opciones_1[10][34] = char(80);
	opciones_1[9][36] = char(80);
	opciones_1[4][29] = char(100);
	opciones_1[9][33] = char(100);
	opciones_1[3][31] = char(100);
	opciones_1[3][30] = char(46);
	opciones_1[3][35] = char(46);

	//a
	for (int i = 4; i <= 7; i++) {
		opciones_1[i][43] = char(56);
		opciones_1[i][44] = char(56);
		opciones_1[i][45] = char(56);
	}

	for (int j = 40; j <= 42; j++) {
		opciones_1[3][j] = char(56);
		opciones_1[5][j] = char(56);
		opciones_1[7][j] = char(56);
	}

	opciones_1[3][39] = char(56);
	opciones_1[6][38] = char(56);
	opciones_1[6][39] = char(56);
	opciones_1[6][40] = char(56);
	opciones_1[3][43] = char(98);
	opciones_1[4][45] = char(98);
	opciones_1[4][42] = char(34);
	opciones_1[7][38] = char(34);
	opciones_1[3][44] = char(46);
	opciones_1[5][38] = char(46);
	opciones_1[5][39] = char(100);
	opciones_1[7][39] = char(89);

	//r
	for (int i = 3; i <= 7; i++) {
		opciones_1[i][47] = char(56);
		opciones_1[i][48] = char(56);
		opciones_1[i][49] = char(56);
	}

	opciones_1[3][51] = char(56);
	opciones_1[3][52] = char(56);
	opciones_1[3][53] = char(56);
	opciones_1[3][50] = char(100);
	opciones_1[4][50] = char(80);
	opciones_1[4][51] = char(34);


	//-------------------------------------
	//2

	for (int j = 0; j <= 3; j++) {
		opciones_2[5][j] = char(56);
		opciones_2[6][j] = char(56);
		opciones_2[7][j] = char(56);
	}

	for (int j = 4; j <= 6; j++) {
		opciones_2[0][j] = char(56);
		opciones_2[4][j] = char(56);
		opciones_2[7][j] = char(56);
	}

	for (int j = 7; j <= 8; j++) {
		opciones_2[1][j] = char(56);
		opciones_2[2][j] = char(56);
		opciones_2[3][j] = char(56);
		opciones_2[7][j] = char(56);
	}

	opciones_2[0][3] = char(56);
	opciones_2[1][1] = char(56);
	opciones_2[1][2] = char(56);
	opciones_2[2][9] = char(56);
	opciones_2[0][2] = char(100);
	opciones_2[1][0] = char(100);
	opciones_2[5][0] = char(100);
	opciones_2[4][3] = char(100);
	opciones_2[3][6] = char(100);
	opciones_2[0][1] = char(46);
	opciones_2[0][8] = char(46);
	opciones_2[3][5] = char(46);
	opciones_2[4][1] = char(46);
	opciones_2[1][3] = char(80);
	opciones_2[5][3] = char(80);
	opciones_2[3][9] = char(80);
	opciones_2[4][7] = char(80);
	opciones_2[4][8] = char(34);
	opciones_2[5][4] = char(34);
	opciones_2[6][3] = char(34);
	opciones_2[0][7] = char(98);
	opciones_2[1][9] = char(98);
	opciones_2[1][6] = char(89);
	opciones_2[4][2] = char(111);

	// )
	for (int i = 2; i <= 5; i++) {
		opciones_2[i][14] = char(56);
		opciones_2[i][15] = char(56);
	}

	opciones_2[0][11] = char(56);
	opciones_2[0][12] = char(56);
	opciones_2[1][13] = char(56);
	opciones_2[1][14] = char(56);
	opciones_2[3][16] = char(56);
	opciones_2[4][16] = char(56);
	opciones_2[6][13] = char(56);
	opciones_2[6][14] = char(56);
	opciones_2[7][11] = char(56);
	opciones_2[7][12] = char(56);
	opciones_2[0][13] = char(98);
	opciones_2[0][14] = char(46);
	opciones_2[1][11] = char(34);
	opciones_2[1][12] = char(89);
	opciones_2[1][15] = char(98);
	opciones_2[2][13] = char(89);
	opciones_2[2][16] = char(98);
	opciones_2[5][13] = char(100);
	opciones_2[5][16] = char(80);
	opciones_2[6][11] = char(46);
	opciones_2[6][12] = char(100);
	opciones_2[6][15] = char(80);
	opciones_2[7][13] = char(80);
	opciones_2[7][14] = char(34);

	//r
	for (int i = 0; i <= 7; i++) {
		opciones_2[i][18] = char(56);
		opciones_2[i][19] = char(56);
		opciones_2[i][20] = char(56);
	}

	for (int j = 21; j <= 24; j++) {
		opciones_2[0][j] = char(56);
	}

	for (int i = 1; i <= 3; i++) {
		opciones_2[i][25] = char(56);
		opciones_2[i][26] = char(56);
	}
	for (int j = 21; j <= 24; j++) {
		opciones_2[4][j] = char(56);
	}

	opciones_2[5][23] = char(56);
	opciones_2[5][24] = char(56);
	opciones_2[6][24] = char(56);
	opciones_2[6][25] = char(56);
	opciones_2[7][25] = char(56);
	opciones_2[7][26] = char(56);
	opciones_2[2][27] = char(56);
	opciones_2[0][25] = char(98);
	opciones_2[0][26] = char(46);
	opciones_2[1][24] = char(89);
	opciones_2[1][27] = char(98);
	opciones_2[3][24] = char(100);
	opciones_2[3][27] = char(80);
	opciones_2[4][25] = char(80);
	opciones_2[4][26] = char(34);
	opciones_2[5][22] = char(84);
	opciones_2[5][25] = char(98);
	opciones_2[6][23] = char(84);
	opciones_2[6][26] = char(98);
	opciones_2[7][24] = char(84);
	opciones_2[7][27] = char(98);
	//e
	for (int j = 28; j <= 35; j++) {
		opciones_2[5][j] = char(56);
	}

	opciones_2[3][29] = char(46);
	opciones_2[3][30] = char(100);
	opciones_2[3][31] = char(56);
	opciones_2[3][32] = char(56);
	opciones_2[3][33] = char(98);
	opciones_2[3][34] = char(46);
	opciones_2[4][28] = char(100);
	opciones_2[4][29] = char(56);
	opciones_2[4][30] = char(80);
	opciones_2[4][33] = char(89);
	opciones_2[4][34] = char(56);
	opciones_2[4][35] = char(98);
	opciones_2[6][28] = char(89);
	opciones_2[6][29] = char(56);
	opciones_2[6][30] = char(98);
	opciones_2[6][31] = char(46);
	opciones_2[7][29] = char(34);
	opciones_2[7][30] = char(89);

	for (int j = 31; j <= 34; j++) {
		opciones_2[7][j] = char(56);
	}

	//g
	for (int i = 4; i <= 9; i++) {
		opciones_2[i][42] = char(56);
		opciones_2[i][43] = char(56);
		opciones_2[i][44] = char(56);
	}

	for (int i = 4; i <= 6; i++) {
		opciones_2[i][37] = char(56);
		opciones_2[i][38] = char(56);
		opciones_2[i][39] = char(56);
	}

	opciones_2[3][40] = char(56);
	opciones_2[3][41] = char(56);
	opciones_2[7][40] = char(56);
	opciones_2[7][41] = char(56);
	opciones_2[10][40] = char(56);
	opciones_2[10][41] = char(56);
	opciones_2[9][38] = char(56);
	opciones_2[6][37] = char(89);
	opciones_2[9][37] = char(89);
	opciones_2[7][39] = char(89);
	opciones_2[10][39] = char(89);
	opciones_2[7][38] = char(34);
	opciones_2[10][38] = char(34);
	opciones_2[4][41] = char(34);
	opciones_2[10][43] = char(34);
	opciones_2[6][40] = char(98);
	opciones_2[9][39] = char(98);
	opciones_2[3][42] = char(98);
	opciones_2[4][44] = char(98);
	opciones_2[4][40] = char(80);
	opciones_2[10][42] = char(80);
	opciones_2[9][44] = char(80);
	opciones_2[4][37] = char(100);
	opciones_2[9][41] = char(100);
	opciones_2[3][39] = char(100);
	opciones_2[3][38] = char(46);
	opciones_2[3][43] = char(46);

	//l
	for (int i = 0; i <= 7; i++) {
		opciones_2[i][46] = char(56);
		opciones_2[i][47] = char(56);
		opciones_2[i][48] = char(56);
	}

	//a
	for (int i = 4; i <= 7; i++) {
		opciones_2[i][55] = char(56);
		opciones_2[i][56] = char(56);
		opciones_2[i][57] = char(56);
	}

	for (int j = 52; j <= 54; j++) {
		opciones_2[3][j] = char(56);
		opciones_2[5][j] = char(56);
		opciones_2[7][j] = char(56);
	}

	opciones_2[3][51] = char(56);
	opciones_2[6][50] = char(56);
	opciones_2[6][51] = char(56);
	opciones_2[6][52] = char(56);
	opciones_2[3][55] = char(98);
	opciones_2[4][57] = char(98);
	opciones_2[3][56] = char(46);
	opciones_2[5][50] = char(46);
	opciones_2[4][54] = char(34);
	opciones_2[7][50] = char(34);
	opciones_2[5][51] = char(100);
	opciones_2[7][51] = char(89);

	//s
	for (int j = 61; j <= 64; j++) {
		opciones_2[3][j] = char(56);
		opciones_2[5][j] = char(56);
		opciones_2[7][j] = char(56);
	}

	opciones_2[4][59] = char(56);
	opciones_2[4][60] = char(56);
	opciones_2[7][60] = char(56);
	opciones_2[6][65] = char(56);
	opciones_2[6][66] = char(56);
	opciones_2[3][65] = char(98);
	opciones_2[5][65] = char(98);
	opciones_2[3][59] = char(46);
	opciones_2[5][66] = char(46);
	opciones_2[7][65] = char(80);
	opciones_2[6][64] = char(88);
	opciones_2[4][61] = char(75);
	opciones_2[3][60] = char(100);
	opciones_2[5][60] = char(89);
	opciones_2[5][59] = char(34);

	//---------------------------------------
	//3
	for (int i = 1; i <= 6; i++) {
		opciones_3[i][7] = char(56);
	}
	for (int j = 3; j <= 6; j++) {
		opciones_3[0][j] = char(56);
	}
	for (int j = 3; j <= 6; j++) {
		opciones_3[7][j] = char(56);
	}
	for (int i = 5; i <= 6; i++) {
		opciones_3[i][1] = char(56);
		opciones_3[i][2] = char(56);
	}
	for (int j = 4; j <= 6; j++) {
		opciones_3[3][j] = char(56);
	}
	opciones_3[1][1] = char(56);
	opciones_3[1][2] = char(56);
	opciones_3[5][0] = char(56);
	opciones_3[1][8] = char(56);
	opciones_3[2][8] = char(56);
	opciones_3[5][8] = char(56);
	opciones_3[6][8] = char(56);
	opciones_3[5][9] = char(56);
	opciones_3[1][0] = char(100);
	opciones_3[0][2] = char(100);
	opciones_3[2][6] = char(100);
	opciones_3[6][6] = char(100);
	opciones_3[0][1] = char(46);
	opciones_3[0][8] = char(46);
	opciones_3[2][5] = char(46);
	opciones_3[4][9] = char(46);
	opciones_3[0][7] = char(98);
	opciones_3[1][9] = char(98);
	opciones_3[4][8] = char(98);
	opciones_3[6][3] = char(98);
	opciones_3[6][0] = char(89);
	opciones_3[7][2] = char(89);
	opciones_3[1][6] = char(89);
	opciones_3[4][6] = char(89);
	opciones_3[7][1] = char(34);
	opciones_3[4][5] = char(34);
	opciones_3[3][8] = char(34);
	opciones_3[7][8] = char(34);
	opciones_3[1][3] = char(80);
	opciones_3[7][7] = char(80);
	opciones_3[2][9] = char(80);
	opciones_3[6][9] = char(80);

	//)
	for (int i = 2; i <= 5; i++) {
		opciones_3[i][14] = char(56);
		opciones_3[i][15] = char(56);
	}
	opciones_3[0][11] = char(56);
	opciones_3[0][12] = char(56);
	opciones_3[1][13] = char(56);
	opciones_3[1][14] = char(56);
	opciones_3[6][13] = char(56);
	opciones_3[6][14] = char(56);
	opciones_3[7][11] = char(56);
	opciones_3[7][12] = char(56);
	opciones_3[3][16] = char(56);
	opciones_3[4][16] = char(56);
	opciones_3[0][13] = char(98);
	opciones_3[1][15] = char(98);
	opciones_3[2][16] = char(98);
	opciones_3[5][16] = char(80);
	opciones_3[6][15] = char(80);
	opciones_3[7][13] = char(80);
	opciones_3[1][12] = char(89);
	opciones_3[2][13] = char(89);
	opciones_3[5][13] = char(100);
	opciones_3[6][12] = char(100);
	opciones_3[0][14] = char(46);
	opciones_3[6][11] = char(46);
	opciones_3[1][11] = char(34);
	opciones_3[7][14] = char(34);

	//C
	for (int i = 1; i <= 6; i++) {
		opciones_3[i][19] = char(56);
		opciones_3[i][20] = char(56);
	}

	for (int i = 2; i <= 5; i++) {
		opciones_3[i][18] = char(56);
	}

	for (int j = 21; j <= 24; j++) {
		opciones_3[0][j] = char(56);
	}

	for (int j = 21; j <= 24; j++) {
		opciones_3[7][j] = char(56);
	}

	for (int j = 25; j <= 27; j++) {
		opciones_3[2][j] = char(56);
	}

	for (int j = 25; j <= 27; j++) {
		opciones_3[5][j] = char(56);
	}

	for (int j = 25; j <= 26; j++) {
		opciones_3[1][j] = char(56);
	}

	for (int j = 25; j <= 26; j++) {
		opciones_3[6][j] = char(56);
	}

	opciones_3[0][25] = char(98);
	opciones_3[1][27] = char(98);
	opciones_3[6][21] = char(98);
	opciones_3[0][20] = char(100);
	opciones_3[1][18] = char(100);
	opciones_3[6][24] = char(100);
	opciones_3[1][24] = char(89);
	opciones_3[6][18] = char(89);
	opciones_3[7][20] = char(89);
	opciones_3[1][21] = char(80);
	opciones_3[6][27] = char(80);
	opciones_3[7][25] = char(80);
	opciones_3[7][19] = char(34);
	opciones_3[7][26] = char(34);
	opciones_3[0][19] = char(46);
	opciones_3[0][26] = char(46);
	//r
	for (int i = 3; i <= 7; i++) {
		opciones_3[i][29] = char(56);
		opciones_3[i][30] = char(56);
		opciones_3[i][31] = char(56);
	}

	opciones_3[3][33] = char(56);
	opciones_3[3][34] = char(56);
	opciones_3[3][35] = char(56);
	opciones_3[3][32] = char(100);
	opciones_3[4][32] = char(80);
	opciones_3[4][33] = char(34);

	//e
	for (int j = 36; j <= 43; j++) {
		opciones_3[5][j] = char(56);
	}

	opciones_3[3][37] = char(46);
	opciones_3[3][38] = char(100);
	opciones_3[3][39] = char(56);
	opciones_3[3][40] = char(56);
	opciones_3[3][41] = char(98);
	opciones_3[3][42] = char(46);
	opciones_3[4][36] = char(100);
	opciones_3[4][37] = char(56);
	opciones_3[4][38] = char(80);
	opciones_3[4][41] = char(89);
	opciones_3[4][42] = char(56);
	opciones_3[4][43] = char(98);
	opciones_3[6][36] = char(89);
	opciones_3[6][37] = char(56);
	opciones_3[6][38] = char(98);
	opciones_3[6][39] = char(46);
	opciones_3[7][37] = char(34);
	opciones_3[7][38] = char(89);

	for (int j = 39; j <= 42; j++) {
		opciones_3[7][j] = char(56);
	}

	//d
	for (int i = 0; i <= 7; i++) {
		opciones_3[i][50] = char(56);
		opciones_3[i][51] = char(56);
		opciones_3[i][52] = char(56);
	}

	for (int i = 4; i <= 6; i++) {
		opciones_3[i][45] = char(56);
		opciones_3[i][46] = char(56);
		opciones_3[i][47] = char(56);
	}

	for (int j = 48; j <= 49; j++) {
		opciones_3[3][j] = char(56);
		opciones_3[7][j] = char(56);
	}

	opciones_3[3][47] = char(100);
	opciones_3[4][45] = char(100);
	opciones_3[4][48] = char(34);
	opciones_3[7][46] = char(34);
	opciones_3[6][45] = char(89);
	opciones_3[7][47] = char(89);
	opciones_3[6][48] = char(98);
	opciones_3[4][47] = char(80);
	opciones_3[3][46] = char(46);

	//i
	for (int i = 3; i <= 7; i++) {
		opciones_3[i][54] = char(56);
		opciones_3[i][55] = char(56);
		opciones_3[i][56] = char(56);
	}

	opciones_3[0][55] = char(56);
	opciones_3[1][55] = char(56);
	opciones_3[0][54] = char(100);
	opciones_3[1][54] = char(89);
	opciones_3[0][56] = char(98);
	opciones_3[1][56] = char(80);

	//t
	for (int i = 0; i <= 6; i++) {
		opciones_3[i][58] = char(56);
		opciones_3[i][59] = char(56);
		opciones_3[i][60] = char(56);
	}

	for (int j = 61; j <= 63; j++) {
		opciones_3[3][j] = char(56);
		opciones_3[7][j] = char(56);
	}

	opciones_3[6][58] = char(89);
	opciones_3[7][60] = char(89);
	opciones_3[6][61] = char(98);
	opciones_3[6][62] = char(46);
	opciones_3[7][59] = char(34);

	//o
	for (int i = 4; i <= 6; i++) {
		opciones_3[i][64] = char(56);
		opciones_3[i][65] = char(56);
		opciones_3[i][66] = char(56);
		opciones_3[i][69] = char(56);
		opciones_3[i][70] = char(56);
		opciones_3[i][71] = char(56);
	}

	for (int j = 67; j <= 68; j++) {
		opciones_3[3][j] = char(56);
		opciones_3[7][j] = char(56);
	}

	opciones_3[3][66] = char(100);
	opciones_3[4][64] = char(100);
	opciones_3[6][64] = char(89);
	opciones_3[7][66] = char(89);
	opciones_3[4][67] = char(34);
	opciones_3[4][68] = char(34);
	opciones_3[7][65] = char(34);
	opciones_3[7][70] = char(34);
	opciones_3[3][65] = char(46);
	opciones_3[3][70] = char(46);
	opciones_3[6][67] = char(46);
	opciones_3[6][68] = char(46);
	opciones_3[6][71] = char(80);
	opciones_3[7][69] = char(80);
	opciones_3[3][69] = char(98);
	opciones_3[4][71] = char(98);

	//s
	for (int j = 75; j <= 78; j++) {
		opciones_3[3][j] = char(56);
		opciones_3[5][j] = char(56);
		opciones_3[7][j] = char(56);
	}

	opciones_3[4][73] = char(56);
	opciones_3[4][74] = char(56);
	opciones_3[7][74] = char(56);
	opciones_3[6][79] = char(56);
	opciones_3[6][80] = char(56);
	opciones_3[3][79] = char(98);
	opciones_3[5][79] = char(98);
	opciones_3[3][73] = char(46);
	opciones_3[5][80] = char(46);
	opciones_3[7][79] = char(80);
	opciones_3[6][78] = char(88);
	opciones_3[4][75] = char(75);
	opciones_3[3][74] = char(100);
	opciones_3[5][74] = char(89);
	opciones_3[5][73] = char(34);

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 54; j++) {
			cout << opciones_1[i][j];
		}

		cout << endl;
	}

	cout << endl << endl;

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 67; j++) {
			cout << opciones_2[i][j];
		}

		cout << endl;
	}

	cout << endl << endl;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 81; j++) {
			cout << opciones_3[i][j];
		}

		cout << endl;
	}
}

void menu() {
	do {
		cls;
		molino_banner();

		cout << endl;

		opciones_banner();

		cout << endl << endl;
		cout << "OPCION: ";
		cin >> opcion;

		switch (opcion) {
		case '1':
			cls;
			jugar();
			break;

		case '2':
			cls;

			reglas_banner();

			_getch();

			menu();
			break;

		case '3':
			cls;

			upc_banner();

			_getch();

			menu();
			break;
		}
	} while (opcion != '1');
}

void limpiar_memoria() {
	for (int i = 0; i < 20; i++)
		delete[] molino[i];

	delete[] molino;

	for (int i = 0; i < 6; i++)
		delete[] upc[i];

	delete[] upc;

	for (int i = 0; i < 6; i++)
		delete[] reglas[i];


	delete[] reglas;

	for (int i = 0; i < 11; i++)
		delete[] opciones_1[i];

	delete[] opciones_1;

	for (int i = 0; i < 11; i++)
		delete[] opciones_2[i];

	delete[] opciones_2;

	for (int i = 0; i < 8; i++)
		delete[] opciones_3[i];

	delete[] opciones_3;

	for (int i = 0; i < 25; i++)
		delete[] tablero[i];

	delete[] tablero;

	for (int i = 0; i < 9; i++)
		delete[] fichas[i];

	delete[] fichas;
}