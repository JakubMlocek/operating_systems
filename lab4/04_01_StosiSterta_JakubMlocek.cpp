#include <iostream>
#include <new>

using namespace std;

void statyczna() {

	cout << "Pamięć statyczna" << endl;
	double tablica[1000000];
	for (int i = 0; i < 1000000; i++) {
		tablica[i] = 2.0;
	}
	cin.get();
}

void dynamiczna() {

	cout << "Pamięć dynamiczna" << endl;
	double *tablica = new double[1000000];
	for (int i = 0; i < 1000000; i++) {
		tablica[i] = 3.0;
	}
	cin.get();
	delete[] tablica;
}


int main() {

	statyczna();	
	cout << "Usunieta pamięć statyczna" << endl;

	cin.get();

	dynamiczna();
	cout << "Usunieta pamięć dynamiczna" << endl;
    
    return 0;
}
