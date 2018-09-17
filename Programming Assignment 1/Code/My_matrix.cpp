/*
Implementation of the clas My_matrix
*/

#include "My_matrix.h"
#include <stdexcept>

My_matrix::My_matrix()
{
	int m = 0;
	int n = 0;
	int **ptr;
	ptr = nullptr;
	
}

void My_matrix::allocate_memory()
{
	// add your code here
}

My_matrix::My_matrix(int n1, int m1)
{
	int n = n1;
	int m = m1;
	int **ptr;
	ptr = new int*[n1];
	for (int i = 0; i < n1; i++) {
		ptr[i] = new int[m1];
	}
}

My_matrix::My_matrix(const My_matrix& mat)
{
	// add your code here
	// int **ptr2 = mat.elem();

	ptr = new int*[mat.number_of_rows()];
	for (int i = 0; i < mat.number_of_rows(); i++) {
		ptr[i] = new int[mat.number_of_columns()];
	}
	for (int i = 0; i < mat.number_of_rows(); i++) {
		for (int j = 0; j < number_of_columns(); j++) {
			ptr[i][j] = mat.elem(i, j);
		}
	}
}

// move constructor (optional)
My_matrix::My_matrix(My_matrix&& mat)
{
	// add your code here
}

My_matrix::~My_matrix()
{
	delete[] ptr[n];
	delete[] ptr;
}
/*
My_matrix& My_matrix::operator=(const My_matrix& mat)
{
	// add your code here
}

// move assignment operator (optional)
My_matrix& My_matrix::operator=(My_matrix&& mat)
{
	// add your code here
}

int My_matrix::number_of_rows() const
{
	return n;
}

int My_matrix::number_of_columns() const
{
	return m;
}

int* My_matrix::operator()(int i) const
{
	// add your code here
}

int& My_matrix::operator()(int i, int j) const
{
	return ptr[i];
}

int My_matrix::operator()(int i, int j)
{
	return ptr[i][j];
}

int My_matrix::elem(int i, int j) const
{
	if (i < 0 || i >= n) throw out_of_range("Out of range");
	if (j < 0 || j >= m) throw out_of_range("Out of range");
	// add your code here
	return ptr[i][j];
}

int& My_matrix::elem(int i, int j)
{
	// add your code here

	return ptr[i][j];
}

ostream& operator<<(ostream& out, const My_matrix& mat)
{
	int **ptr = mat.elem();
	int n = mat.number_of_rows();
	int m = mat.number_of_columns();
	for (int i; i < n; i++) {
		for (int j; j < m; j++) {
			out << ptr[i][j];
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, My_matrix& mat)
{
	int **ptr = mat.elem();
	int n = mat.number_of_rows();
	int m = mat.number_of_columns();
	for (int i; i < n; i++) {
		for (int j; j < m; j++) {
			in >> ptr[i][j];
		}
		in >> endl;
	}
}

My_matrix operator+(const My_matrix& mat1, const My_matrix& mat2)
{
	int **ptr1 = mat1.elem();
	int **ptr2 = mat2.elem();
	int n = mat1.number_of_rows();
	int m = mat2.number_of_rows();
	My_matrix m3(n, m);
	int ptr3 = m3.elem();
	if (mat1.number_of_rows() == mat2.number_of_rows() && mat1.number_of_columns() == mat2.number_of_columns()) {

		for (int i; i < n; i++) {
			for (int j; j < m; j++) {
				ptr3[i]][j] = (ptr2[i][j] + ptr1[i][j]);
			}
		}

	}

	My_matrix operator*(const My_matrix& mat1, const My_matrix& mat2)
	{

	}
	*/