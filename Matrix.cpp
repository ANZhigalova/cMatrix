#include "Matrix.h"
#include <math.h>
using namespace std;

Matrix::Matrix(): row(0), col(0), M(NULL)
{
}

Matrix::Matrix(int m, int n): row(m), col(n)
{	
}

Matrix::Matrix(int m, int n, double*arr): row(m), col(n)
{

}

Matrix::Matrix(const Matrix& copy)
{
	row = copy.row;
	col = copy.col;
	//M = new double*[row];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			M[i][j] = copy.M[i][j];
	}
}

Matrix::~Matrix()
{
	delete[] M;
}

Matrix& Matrix::operator = (const Matrix& other)
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
			//M[i] = new int[col];
			for (int j = 0; j < col; j++)
				M[i][j] = other.M[i][j];
		}
		return *this;
	}
}

Matrix Matrix::operator + (const Matrix& other) const
{
	if (row == other.row or col == other.col) {
		Matrix S(row, col);
		for (int i = 0; i < row; i++) {
			//S[i] = new int[col];
			for (int j = 0; j < col; j++)
				S[i][j] = M[i][j] + other.M[i][j];
		}
		return S;
	}
	else throw;
}

Matrix Matrix::operator - (const Matrix& other) const
{
	
	if (row == other.row or col == other.col) {
		Matrix D(row, col);
	for (int i = 0; i < row; i++) {
		//D[i] = new int[col];
		for (int j = 0; j < col; j++)
			D[i][j] = M[i][j] - other.M[i][j];
	}
	return D;
	}
	else throw;
}

Matrix Matrix::operator * (double l) const
{
	Matrix m(row, col);
	for (int i = 0; i < row; i++) {
		//m[i] = new int[col];
		for (int j = 0; j < col; j++)
			m[i][j] = M[i][j] * l;
	}
	return m;
}

Matrix Matrix::operator * (const Matrix& other) const
{
	if (col == other.row) {
		Matrix mul(row, col);
		for (int i = 0; i < row; i++) {
			//mul[i] = new int[col];
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

Matrix Matrix::operator ! ()
{
	Matrix T(row, col);
	for (int i = 0; i < row; i++) {
		//T[i] = new int[col];
		for (int j = 0; j < col; j++)
			T[j][i] = M[i][j];
	}
	return T;
}

inline Matrix::Row Matrix::operator [](int index)
{
	if(index <= col)
		return Row(M + (col*index), col);
	else throw;
}

inline double& Matrix::Row::operator[](int index)
{
	if (index <= cols)
		return elem[index];
	else throw;
}

inline double** Matrix::create_matr(int m, int n) {
	double**N = new double*[row];
	for (int i = 0; i < row; i++)
		N[i] = new double[row];
	return N;
}
ostream& operator <<(ostream& out, Matrix& obj) {
	for (int i = 0; i < obj.row; i++) {
		for (int j = 0; j < obj.col; j++)
			out << obj.M[i][j] << " ";
	}
	return out;
}