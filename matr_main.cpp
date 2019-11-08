#include <iostream>
#include "cMatrix.h"
#include "cMatrix.cpp"
using namespace std;

int main()
{
	cMatrix A;
	cout << A << endl;
	cMatrix B(2, 2);
	cout << B << endl;
	double N[4] = { 1, 4.56, 23, 56.78 };
	cMatrix C(2, 2, N);
	cout << C << endl;
	cout << endl;
	system("pause");
}