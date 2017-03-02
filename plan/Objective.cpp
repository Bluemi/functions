// hier wird das C-Programm festgehalten, dass als nächstes in Functions implementiert werden soll

#include <iostream>

void printNumber(int n)
{
	std::cout << n << std::endl;
}

int main()
{
	int a; // Variable deklarieren
	a = 2; // eigene Variable auf dem Stack erzeugen
	printNumber(a);
	return 0;
}
