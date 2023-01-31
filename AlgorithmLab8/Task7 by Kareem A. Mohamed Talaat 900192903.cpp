#include <iostream>
#include <vector>
using namespace std;

int ** matrix_add(int ** a, int** b, int n)
{
	int** z;
	z = new int*[n];
	for (int i = 0; i < n; i++)
	{
		z[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			z[i][j] = a[i][j] + b[i][j];
		}
	}
	return z;
}

int** matrix_subtract(int** a, int** b, int n)
{
	int** z;
	z = new int* [n];
	for (int i = 0; i < n; i++)
	{
		z[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			z[i][j] = a[i][j] - b[i][j];
		}
	}
	return z;
}

void Matrix_display(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
}



int ** matrix_small_multiply(int**  a, int**  b)
{
	int** z;
	z = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		z[i] = new int[2];
	}

	z[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
	z[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
	z[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
	z[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

	return z;
}

int** matrix_multiply(int ** x, int ** y, int n)
{
	if (n == 2)
	{
		return matrix_small_multiply(x, y);
	}
	else
	{
		if (n % 2 == 0)
		{
			int** z;
			z = new int* [n];
			for (int i = 0; i < n; i++)
			{
				z[i] = new int[n];
			}

			int** p1;
			int** p2;
			int** p3;
			int** p4;
			int** p5;
			int** p6;
			int** p7;

			int** z11;
			int** z12;
			int** z21;
			int** z22;

			int** temp1;
			int** temp2;
			int** temp3;
			int** temp4;
			int** temp5;
			int** temp6;
			int** temp7;
			int** temp8;

			temp1 = new int* [n / 2];
			temp2 = new int* [n / 2];
			temp3 = new int* [n / 2];
			temp4 = new int* [n / 2];
			temp5 = new int* [n / 2];
			temp6 = new int* [n / 2];
			temp7 = new int* [n / 2];
			temp8 = new int* [n / 2];

			for (int i = 0; i < n / 2; i++)
			{
				temp1[i] = new int[n / 2];
				temp2[i] = new int[n / 2];
				temp3[i] = new int[n / 2];
				temp4[i] = new int[n / 2];
				temp5[i] = new int[n / 2];
				temp6[i] = new int[n / 2];
				temp7[i] = new int[n / 2];
				temp8[i] = new int[n / 2];
			}

			for (int i = 0; i < n / 2; i++)
			{
				for (int j = 0; j < n / 2; j++)
				{
					temp1[i][j] = x[i][j];
					temp2[i][j] = x[i][j + (n / 2)];
					temp3[i][j] = x[i + (n / 2)][j];
					temp4[i][j] = x[i + (n / 2)][j + (n / 2)];
					temp5[i][j] = y[i][j];
					temp6[i][j] = y[i][j + (n / 2)];
					temp7[i][j] = y[i + (n / 2)][j];
					temp8[i][j] = y[i + (n / 2)][j + (n / 2)];
				}
			}

			p1 = matrix_multiply(temp1, (matrix_subtract(temp6, temp8, n / 2)), n / 2);
			p2 = matrix_multiply((matrix_add(temp1, temp2, n / 2)), temp8, n / 2);
			p3 = matrix_multiply((matrix_add(temp3, temp4, n / 2)), temp5, n / 2);
			p4 = matrix_multiply(temp4, (matrix_subtract(temp7, temp5, n / 2)), n / 2);
			p5 = matrix_multiply((matrix_add(temp1, temp4, n / 2)), (matrix_add(temp5, temp8, n / 2)), n / 2);
			p6 = matrix_multiply((matrix_subtract(temp2, temp4, n / 2)), (matrix_add(temp7, temp8, n / 2)), n / 2);
			p7 = matrix_multiply((matrix_subtract(temp1, temp3, n / 2)), (matrix_add(temp5, temp6, n / 2)), n / 2);

			z11 = matrix_subtract(matrix_add(matrix_add(p5, p4, n / 2), p6, n / 2), p2, n / 2);
			z12 = matrix_add(p1, p2, n / 2);
			z21 = matrix_add(p3, p4, n / 2);
			z22 = matrix_subtract(matrix_add(p1, p5, n / 2), matrix_add(p3, p7, n / 2), n / 2);

			for (int i = 0; i < n / 2; i++)
			{
				for (int j = 0; j < n / 2; j++)
				{
					z[i][j] = z11[i][j];
					z[i][j + n / 2] = z12[i][j];
					z[i + n / 2][j] = z21[i][j];
					z[i + n / 2][j + n / 2] = z22[i][j];
				}
			}
			return z;
		}
	}
}



int main()
{
	int** a;
	a = new int *[4];
	int** b;
	b = new int* [4];
	int** z;
	z = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		a[i] = new int[4];
		b[i] = new int[4];
		z[i] = new int[4];
	}
	int k = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
				a[i][j] = k;
				b[i][j] = -k;
				k++;
		}
	}
	
	cout << "matrix A = " << endl;
	Matrix_display(a, 4);
	cout << endl << endl;

	cout << "matrix B = " << endl ;
	Matrix_display(b, 4);
	cout << endl << endl;

	cout << "matrix AxB = " << endl ;
	z = matrix_multiply(a, b, 4);
	Matrix_display(z, 4);
	cout << endl << endl;

	system("pause");
	return 0;
}