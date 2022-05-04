#include "Matrix.h"
Matrix::Matrix()
{
	m = 0;
	n = 0;
	elements = NULL;
}

Matrix::~Matrix()
{
	if (elements == NULL)
		return;
	for (int i = 0; i < m; i++)
	{
		delete[] elements[i];
		elements[i] = NULL;
	}
	delete[] elements;
	elements = NULL;
}

Matrix::Matrix(const Matrix& a)
{
	m = a.m;
	n = a.n;
	elements = new double* [m]; // cấp phát m dòng
	for (int i = 0; i < m; i++)
		elements[i] = new double[n]; // cấp phát n cột
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			elements[i][j] = a.elements[i][j];
}

int Matrix::Cong(const Matrix& a)
{
	if (!(n == a.n && m == a.m))
		return 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			elements[i][j] += a.elements[i][j];
	return 1;
}

void Matrix::Nhan(const double& k)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			elements[i][j] *= k;
}

int Matrix::Nhan(const Matrix& a)
{
	if (n != a.m)
		return 0;

	double** elementsNew = new double* [m]; // tạo vùng nhớ chứa ma trận mới
	for (int i = 0; i < m; i++)
		elementsNew[i] = new double[a.n];

	for (int i = 0; i < m; i++) // nhân
	{
		for (int j = 0; j < a.n; j++)
		{
			elementsNew[i][j] = 0;
			for (int k = 0; k < n; k++)
				elementsNew[i][j] = elementsNew[i][j] + elements[i][k] * a.elements[k][j];
		}
	}
	// xóa vùng nhớ cũ
	for (int i = 0; i < m; i++)
		delete[] elements[i];
	delete[] elements;
	// cập nhật lại kích thước ma trận
	m = m;
	n = a.n;
	elements = elementsNew; // gán lại vùng nhớ mới.
	return 1;
}

istream& operator>>(istream& is, Matrix& mt)
{
	is >> mt.m >> mt.n;
	mt.elements = new double* [mt.m]; // cấp phát m dòng
	for (int i = 0; i < mt.m; i++)
		mt.elements[i] = new double[mt.n]; // cấp phát n cột
	for (int i = 0; i < mt.m; i++)
		for (int j = 0; j < mt.n; j++)
			is >> mt.elements[i][j];
	return is;
}

ostream& operator<<(ostream& os, Matrix& mt)
{
	os << "Matrix: \n";
	for (int i = 0; i < mt.m; i++)
	{
		for (int j = 0; j < mt.n; j++)
			cout << mt.elements[i][j] << " ";
		os << endl;
	}
	return os;
}
