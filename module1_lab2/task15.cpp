// module1_lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//обчислення координат з використанням косинусів
void f_cos(int ver_cuba[8], float M[8], float a, float m, float PI) {
	for (int i = 0; i <= 7; i++) {
		int b = ver_cuba[i];

		switch (b) {
		case 1: M[b - 1] = a * cos(m);  break;
		case 2:	M[b - 1] = a * sqrt(2) * cos(PI / 4 + m);  break;
		case 3:	M[b - 1] = a * cos(PI / 2 + m);  break;
		case 4:	M[b - 1] = 0;   break;
		case 5:	M[b - 1] = a * cos(m);  break;
		case 6:	M[b - 1] = a * sqrt(2) * cos(PI / 4 + m);  break;
		case 7:	M[b - 1] = a * cos(PI / 2 + m);  break;
		case 8:	M[b - 1] = 0;	 break;
		}

	}
}

//обчислення координат з використанням синусів
void f_sin(int ver_cuba[8], float M[8], float a, float m, float PI) {
	for (int i = 0; i <= 7; i++) {
		int b = ver_cuba[i];
		switch (b) {
		case 1: M[b - 1] = a * sin(m); break;
		case 2:	M[b - 1] = a * sqrt(2) * sin(PI / 4 + m); break;
		case 3:	M[b - 1] = a * sin(PI / 2 + m); break;
		case 4:	M[b - 1] = 0; break;
		case 5:	M[b - 1] = a * sin(m); break;
		case 6:	M[b - 1] = a * sqrt(2) * sin(PI / 4 + m); break;
		case 7:	M[b - 1] = a * sin(PI / 2 + m); break;
		case 8:	M[b - 1] = 0; break;
		}
	}
}

// заповнення координат, які не змінюються при повороті
void f_a(int ver_cuba[8], float M[8], float a) {
	for (int i = 0; i <= 7; i++) {
		int b = ver_cuba[i];
		switch (b) {
		case 1: M[b - 1] = 0; break;
		case 2:	M[b - 1] = 0; break;
		case 3:	M[b - 1] = 0; break;
		case 4:	M[b - 1] = 0; break;
		case 5:	M[b - 1] = a; break;
		case 6:	M[b - 1] = a; break;
		case 7:	M[b - 1] = a; break;
		case 8:	M[b - 1] = a; break;
		}
	}
}

//виведення координат вершин
void print_res(int ver_cuba[8], char S[8], float SX[8], float SY[8], float SZ[8]) {
	for (int i = 1; i <= 8; i++) {
		for (int j = 0; j <= 7; j++) {
			if (ver_cuba[j] == i) {
				cout << S[i - 1] << "(" << fixed << setprecision(2) << (SX[j]) << ";" << (SY[j]) << ";" << (SZ[j]) << ")" << endl;
			}
		}

	}
}

int main()
{
	const float PI = 3.14159263;
	float a, m, k;
	int n;
	char l[9];
	const int SIZE_ARR = 8;
	char A[SIZE_ARR];
	cout << "vvedit nazvy  kuba: ";
	cin >> l;
	for (int i = 0; i <= 7; i++) {  //введення назви куба
		A[i] = l[i];
	}


	cout << "Vvedit dovginy rebra: ";
	cin >> a;
	int ver_cuba_X[SIZE_ARR];   //визначення правила повороту вершини в залежності від вісі
	ver_cuba_X[0] = 3;
	ver_cuba_X[1] = 7;
	ver_cuba_X[2] = 8;
	ver_cuba_X[3] = 4;
	ver_cuba_X[4] = 2;
	ver_cuba_X[5] = 6;
	ver_cuba_X[6] = 5;
	ver_cuba_X[7] = 1;

	int ver_cuba_Y[SIZE_ARR];
	ver_cuba_Y[0] = 8;
	ver_cuba_Y[1] = 5;
	ver_cuba_Y[2] = 1;
	ver_cuba_Y[3] = 4;
	ver_cuba_Y[4] = 7;
	ver_cuba_Y[5] = 6;
	ver_cuba_Y[6] = 2;
	ver_cuba_Y[7] = 3;

	int ver_cuba_Z[SIZE_ARR];
	ver_cuba_Z[0] = 1;
	ver_cuba_Z[1] = 2;
	ver_cuba_Z[2] = 3;
	ver_cuba_Z[3] = 4;
	ver_cuba_Z[4] = 5;
	ver_cuba_Z[5] = 6;
	ver_cuba_Z[6] = 7;
	ver_cuba_Z[7] = 8;


	float X[SIZE_ARR]; //масив абсцис вершин куба
	float Y[SIZE_ARR];//масив ординат вершин куба
	float Z[SIZE_ARR];//масив аплікат вершин куба

	m = 0;                          //виведення початкового кубу з кутом повороту 0
	f_cos(ver_cuba_Z, X, a, m, PI);
	f_sin(ver_cuba_Z, Y, a, m, PI);
	f_a(ver_cuba_Z, Z, a);
	cout << endl;
	cout << "Pochatkovy kub" << endl;
	print_res(ver_cuba_Z, A, X, Y, Z);
	cout << endl;
	cout << "vyberit vis povorotu: " << endl; //введення параметрів повороту
	cout << "vis OX - 1" << endl;
	cout << "vis OY - 2" << endl;
	cout << "vis OZ - 3" << endl;
	cout << "vash vybir: ";
	cin >> n;

	cout << "Kut povorotu v gradusax: ";
	cin >> m;
	m = m * PI / 180;
	cout << "Vyberit napryamok povorotu: " << endl;
	cout << "Proty godynnykovou strilkou - 1 " << endl;
	cout << "Za godynnykovou strilkou - 2 " << endl;
	cin >> k;
	if (k == 2) k = -1;
	m = m * k;
	cout << endl;
	cout << "result: " << endl;
	switch (n) {
	case 1:                                     //виконання повороту навколо вісі ОХ
		f_cos(ver_cuba_X, Y, a, m, PI);
		f_sin(ver_cuba_X, Z, a, m, PI);
		f_a(ver_cuba_X, X, a);
		print_res(ver_cuba_X, A, X, Y, Z);
		break;
	case 2:                                  //виконання повороту навколо вісі ОY
		f_cos(ver_cuba_Y, Z, a, m, PI);
		f_sin(ver_cuba_Y, X, a, m, PI);
		f_a(ver_cuba_Y, Y, a);
		print_res(ver_cuba_Y, A, X, Y, Z);
		break;
	case 3:                                   //виконання повороту навколо вісі ОZ
		f_cos(ver_cuba_Z, X, a, m, PI);
		f_sin(ver_cuba_Z, Y, a, m, PI);
		f_a(ver_cuba_Z, Z, a);
		print_res(ver_cuba_Z, A, X, Y, Z);
		break;
	}
}

