#pragma once
# include <iostream>
using namespace std;

class Matrix
{
	class Row
	{
		friend class Matrix;
		double* elem;
		int cols;
		Row(double *p, int _cols): elem(p), cols(_cols){}
	public:
		double &operator[](int index);
	};
	int row, col;
	double **M;
	double *N;
public:
	Row operator [](int index);
	double** create_matr(int m,int n);
	Matrix();
	~Matrix();
	Matrix(int row, int col);
	Matrix(int row, int col, double*N);
	Matrix(const Matrix& copy);
	Matrix& operator = (const Matrix& other);
	Matrix operator + (const Matrix& other) const;
	Matrix operator - (const Matrix& other) const;
	Matrix operator * (double l) const;
	Matrix operator * (const Matrix& other) const;
	Matrix operator ! ();//оператор транспонирования матрицы
	friend ostream& operator <<(ostream& out, Matrix& obj);
};
