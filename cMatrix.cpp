#include "cMatrix.h"
#include <math.h>
using namespace std;

cMatrix::cMatrix(): row(0), col(0), M(NULL)
{
}

cMatrix::cMatrix(int m, int n) : row(m), col(n)
{
	M = new double*[row];
	for (int i = 0; i < row; i++) {
		M[i] = new double[col];
		for (int j = 0; j < col; j++)
			M[i][j] = 0;
	}
}

cMatrix::cMatrix(int m, int n, double*N) :row(m), col(n)
{
	M = new double*[row];
	for (int i = 0; i < row; i++) {
		M[i] = new double[col];
		for (int j = 0; j < col; j++)
			M[i][j] = N[i*col + j];
	}
}

cMatrix::cMatrix(const cMatrix& copy)
{
	row = copy.row;
	col = copy.col;
	for (int i = 0; i < row; i++) {
		M[i] = new double[col];
		for (int j = 0; j < col; j++)
			M[i][j] = copy.M[i][j];
	}
}

cMatrix::~cMatrix()
{
	for (int i = 0; i < row; i++)
		delete[] M[i];
	delete[] M;
}

cMatrix& cMatrix::operator = (const cMatrix& other)
{
	if (this == &other)
		return *this;
	else {
		for (int i = 0; i < row; i++)
			delete[] M[i];
		delete[]M;
		row = other.row;
		col = other.col;
		for (int i = 0; i < row; i++) {
			M[i] = new double[col];
			for (int j = 0; j < col; j++)
				M[i][j] = other.M[i][j];
		}
		return *this;
	}
}

cMatrix cMatrix::operator + (const cMatrix& other) const
{
	if (row == other.row or col == other.col) {
		cMatrix S(row, col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				S[i][j] = M[i][j] + other.M[i][j];
		}
		return S;
	}
	else throw;
}

cMatrix cMatrix::operator - (const cMatrix& other) const
{

	if (row == other.row or col == other.col) {
		cMatrix D(row, col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				D[i][j] = M[i][j] - other.M[i][j];
		}
		return D;
	}
	else throw;
}

cMatrix cMatrix::operator * (double l) const
{
	cMatrix m(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			m[i][j] = M[i][j] * l;
	}
	return m;
}

cMatrix cMatrix::operator * (const cMatrix& other) const
{
	if (col == other.row) {
		cMatrix mul(row, col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				mul[i][j] = 0;
				for (int k = 0; k < col; k++)
					mul[i][j] += M[i][k] * other.M[k][j];
			}
		}
		return mul;
	}
	else throw;
}

cMatrix cMatrix::operator ! ()
{
	cMatrix T(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			T[j][i] = M[i][j];
	}
	return T;
}

inline cMatrix::Row cMatrix::operator [](int index)
{
	if (index <= col)
		return Row(M[index], col);
	else throw;
}

inline double& cMatrix::Row::operator[](int index)
{
	if (index <= cols)
		return elem[index];
	else throw;
}

ostream& operator <<(ostream& out, cMatrix& obj) {
	for (int i = 0; i < obj.row; i++) {
		for (int j = 0; j < obj.col; j++)
			out << obj.M[i][j] << " ";
	}
	return out;
}

