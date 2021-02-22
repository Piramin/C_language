#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

struct Matrix
{
	int h;
	int w;
	double* pMat;
};

struct Matrix CreateMat(int Rows,int Collums,double** Matrix_Values)
{	
	struct Matrix New_Struct_Matrix;
	New_Struct_Matrix.h = Rows;
	New_Struct_Matrix.w = Collums;
	
	New_Struct_Matrix.pMat = malloc(New_Struct_Matrix.h*New_Struct_Matrix.w*sizeof(double));
	int i,j,k;
	k = 0;
	for(i = 0; i < New_Struct_Matrix.h ;i++)
	{
		for(j = 0; j < New_Struct_Matrix.w; j++)
		{
			New_Struct_Matrix.pMat[k] = Matrix_Values[i][j];
			k++;	
		}
	}
	
	return New_Struct_Matrix;
}

void DisplayMat(struct Matrix struct_matrix)
{
	int i;
	for(i = 0; i < struct_matrix.h*struct_matrix.w; i++){printf("%f ",struct_matrix.pMat[i]);}
	printf("\n");
}

void ToFile(FILE* in_file ,struct Matrix struct_matrix)
{
	int i,j;
	int k = 0;
	fprintf(in_file,"%d %d",struct_matrix.h,struct_matrix.w);
	fprintf(in_file,"\n");
	for(i = 0; i < struct_matrix.h; i++)
	{
		for(j = 0; j < struct_matrix.w; j++)
		{ 
			fprintf(in_file,"%1.1f ",struct_matrix.pMat[k]); 
			k++;
		}
		fprintf(in_file,"\n");
	}
	fprintf(in_file,"\n");
}

int CountMatrix(FILE* in_file)
{
	float add_number;
	int count = 0;
	int rows,collums,i,j;
	while((fscanf(in_file,"%d %d",&rows,&collums)) != EOF){
		for(i = 0; i< rows;i++)
		{
			for(j = 0; j < collums;j++)
			{
				fscanf(in_file,"%f ",&add_number);
			}
		}
		count++;
		}
	
	return count;
}

int main()
{
	srand(time(NULL));
	int i , j;
	int rows = 3;
	int collumns = 2;
	
	//Создает случайную матрицу.
	double** Matrix_Values; 
	Matrix_Values = malloc(rows*sizeof(double*));
	for(i = 0;i<rows;i++){
		Matrix_Values[i] = malloc(collumns*sizeof(double));
		for(j = 0;j<collumns;j++){
			Matrix_Values[i][j] = rand()%10 + (rand()%10)*0.1;
			}
		}
	
	struct Matrix New_Matrix = CreateMat(rows,collumns,Matrix_Values);
	FILE * test_file;
	
	//Запись структуры.
	test_file = fopen("Matrixs.txt","a+");
	ToFile(test_file,New_Matrix);
	fclose(test_file);
	
	//Вызов функции Count.
	test_file = fopen("Matrixs.txt","r");
	printf("Count = %d",CountMatrix(test_file));
	fclose(test_file);
	return 0;
}

