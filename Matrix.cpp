#include "Matrix.h"
#include <math.h>
using namespace std;

Matrix::Matrix(): row(0), col(0), M(NULL)
{
}

Matrix::Matrix(int m, int n): row(m), col(n)
{
	create_matr(m, n);
	/*N(new int[row*col]);
	M = new int*[row];
	for (int i = 0; i < row; i++)
		M[i] = new int[col];*/
}

Matrix::Matrix(int m, int n, double*N):row(m), col(n), N(new double[m*n])
{
}

Matrix::Matrix(const Matrix& copy)
{
	row = copy.row;
	col = copy.col;
	//M = new int*[row];
	for (int i = 0; i < row; i++) {
		M[i] = new double[col];
		for (int j = 0; j < col; j++)
			M[i][j] = copy.M[i][j];
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < row; i++)
		delete[] M[i];
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
			M[i] = new double[col];
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
			//S[i] = new double[col];
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
		//D[i] = new double[col];
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
		for (int j = 0; j < col; j++)
			T[j][i] = M[i][j];
	}
	return T;
}

inline Matrix::Row Matrix::operator [](int index)
{
	if(index <= col)
		return Row(N + (col*index), col);
	else throw;
}
inline double& Matrix::Row::operator[](int index)
{
	if (index <= cols)
		return elem[index];
	else throw;
}

inline double** Matrix::create_matr(int row, int col)
{
	double**M = new double*[row];
	for (int i = 0; i < row; i++)
		M[i] = new double[col];
	return M;
}

ostream& operator <<(ostream& out, Matrix& obj) {
	for (int i = 0; i < obj.row; i++) {
		for (int j = 0; j < obj.col; j++)
			out << obj.M[i][j] << " ";
	}
	return out;
}

int main()
{
	Matrix A;
	cout << A << endl;
	Matrix B(2, 2);
	cout << B << endl;

	cout << endl;
	system("pause");
}