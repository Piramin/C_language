#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

double** memory_allocation(int i, int j, double** new_matrix);
void inputing(int i, int j, double** matrix);
void outputing(int i, int j, double** matrix);
void calculation(int i, int j, double** matrix, double* min, double* max);
void summation(int i, int j, double** matrix_1, double** matrix_2, double** matrix_new);

struct
{
	double** mat;
	double min;
	double max;
} matr_a, matr_b, matr_s;


int main()
{
	int i,j;
	printf("enter size of the matrixes \n");
	scanf("%d", &i);
	scanf("%d", &j);
	matr_a.mat = memory_allocation(i, j, matr_a.mat);
	matr_b.mat = memory_allocation(i, j, matr_b.mat);
	matr_s.mat = memory_allocation(i, j, matr_s.mat);
	inputing(i, j, matr_a.mat);
	inputing(i, j, matr_b.mat);
	calculation(i, j, matr_a.mat, &matr_a.min, &matr_a.max);
	calculation(i, j, matr_b.mat, &matr_b.min, &matr_b.max);
	summation(i, j, matr_a.mat, matr_b.mat, matr_s.mat);

	calculation(i, j, matr_s.mat, &matr_s.min, &matr_s.max);
	outputing(i, j, matr_a.mat);
	outputing(i, j, matr_b.mat);
	outputing(i, j, matr_s.mat);
	free(matr_a.mat); free(matr_b.mat); free(matr_s.mat);
	
	getchar();
	return 0;
}


double** memory_allocation(int i, int j ,double** new_matrix)
{
	new_matrix = (double**)malloc(i * sizeof(double*));
	for (int row = 0; row < i; row++)
	{
		new_matrix[row] = (double*)malloc(j * sizeof(double));}
	return new_matrix;
}
void inputing(int i, int j, double** matrix)
{
	printf("Enter the Matrix: \n");
	for (int row = 0;row < i; row++)
	{
		for (int col = 0; col < j; col++)
		{
			scanf("%lg", &matrix[row][col]);
		}
	}
}
void outputing(int i, int j, double** matrix)
{
	printf("The Matrix: \n");
	for (int row = 0; row < i; row++)
	{
		for (int col = 0; col < j; col++)
		{
			printf(" ");
			printf("%lg", matrix[row][col]);
		}
		printf("\n");
	}
}
void calculation(int i, int j, double** matrix, double* min, double* max)
{
	*min = matrix[0][0];
	*max = matrix[0][0];
	for (int row = 0; row < i; row++)
	{
		for (int col = 0; col < j; col++)
		{
			if (*min > matrix[row][col])
			{
				*min = matrix[row][col];
			}
		}
	}
	for (int row = 0; row < i; row++)
	{
		for (int col = 0; col < j; col++)
		{
			if (*max < matrix[row][col])
			{
				*max = matrix[row][col];
			}
		}
	}
}
void summation(int i, int j, double** matrix_1, double** matrix_2,double** matrix_new)
{
	for (int row = 0; row < i; row++)
	{
		for (int col = 0; col < j; col++)
		{
			matrix_new[row][col] = matrix_1[row][col] + matrix_2[row][col];
		}
	}
}

