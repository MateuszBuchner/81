#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

const int SIZE = 100;
int tab[SIZE][6];

void z4() {
	cout << "Zadanie 4:" << endl;
	int counter = 0;
	double d1, d2, d3;
	for (int i = 0; i < SIZE; i++) {
		d1 = pow(tab[i][0] - tab[i][2], 2) + pow(tab[i][1] - tab[i][3], 2);
		d2 = pow(tab[i][0] - tab[i][4], 2) + pow(tab[i][1] - tab[i][5], 2);
		d3 = pow(tab[i][2] - tab[i][4], 2) + pow(tab[i][3] - tab[i][5], 2);
		if (d1 + d2 == d3 || d1 + d3 == d2 || d3 + d2 == d1) {
			counter++;
		}
	}
	cout << counter << endl << endl;
}


void z5() {
	
	/*
	 xd = xa+xc-xb;
	 yd = ya+yc-yb;
	 if (xd == yd) {
	 liczba++;
	 } 
	 */
	cout << "Zadanie 5:" << endl;
	int deltaAx, deltaAy, xDelta, yDelta;
	for (int i = 0; i < SIZE; i++) {
 		xDelta = tab[i][0] + tab[i][4] - tab[i][2]; //xDelta = xa+xc-xb; 
		yDelta = tab[i][1] + tab[i][5] - tab[i][3]; //yDelta = ya+yc-yb; 
		if (xDelta == yDelta) {
			cout << tab[i][0] << "," << tab[i][1] << "; ";
			cout << tab[i][2] << "," << tab[i][3] << "; ";
			cout << tab[i][4] << "," << tab[i][5] << "; ";
			cout << xDelta << "," << yDelta << endl;
		}
	}
	cout << endl;
}

int main() {
	ifstream in("wierzcholki.txt");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < 6; j++) {
			in >> tab[i][j];
		}
	}
	in.close();
	
	
	in.open("wierzcholkiTR.txt");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < 6; j++) {
			in >> tab[i][j];
		}
	}
	in.close();
	

	z4();
	z5();
}
