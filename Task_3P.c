#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <omp.h>
#include <time.h>

//Компиляция: Win + R -> команда cmd
//Команда: gcc -o "Имя файла" -fopenmp "Имя файла".c

int main()
{
	float** Matrix_1;
	float** Matrix_2;
	float** Matrix_3;
	int i,j;
	int rows = 10;
	int collums = 10;
	clock_t start , finish;
	srand(time(NULL));
	//Выделение памяти под матрицы.
	Matrix_1 = malloc(rows*sizeof(float*));
	Matrix_2 = malloc(rows*sizeof(float*));
	Matrix_3 = malloc(rows*sizeof(float*));
	for(i = 0; i < rows ;i++){
	    Matrix_1[i] = malloc(collums*sizeof(float));
	    Matrix_2[i] = malloc(collums*sizeof(float));
	    Matrix_3[i] = malloc(collums*sizeof(float));
	}
	//Генерация матриц.
	for(i = 0; i < rows ;i++){
	    for(j = 0 ; j < collums ; j++){
	        Matrix_1[i][j] = rand()%10 + (rand()%100)*0.01;
	        Matrix_2[i][j] = rand()%10 + (rand()%100)*0.01;   
	    }
	}
	
	start = clock();//Проверка на правильность параллельности по времени.
//Начало параллельных вычислений. Используется 4 потока: ...'num_threads(2)'
omp_set_num_threads(2);
	//Запись новой матрицы.
	#pragma omp parallel for shared(Matrix_1,Matrix_2,Matrix_3,rows,collums)
	for(i = 0; i < rows ;i++){
	    for(j = 0 ; j < collums ; j++){
	        Matrix_3[i][j] = Matrix_1[i][j] - Matrix_2[i][j];  
	    }
	}
//Конец параллельных вычислений.
	finish = clock();
	printf("\nTime: %f\n",(double)(finish - start)/CLOCKS_PER_SEC);
// /*
	//Вывод полученной матрицы:
	printf("\nMatrix_1 : \n");
	for(i = 0; i < rows ;i++){
		for(j = 0 ; j < collums ; j++){
			printf("  %2.3f",Matrix_1[i][j]);   
		}
		printf("\n");
	}
	printf("\nMatrix_2 : \n");
	//Вывод полученной матрицы:
	for(i = 0; i < rows ;i++){
		for(j = 0 ; j < collums ; j++){
			printf("  %2.3f",Matrix_2[i][j]);   
		}
		printf("\n");
	}
	printf("\nMatrix_3 : \n");
	//Вывод полученной матрицы:
	for(i = 0; i < rows ;i++){
		for(j = 0 ; j < collums ; j++){
			printf("  %2.3f",Matrix_3[i][j]);   
		}
		printf("\n");
	}
// */	
	int exit;
    printf("\nInsert 0 to exit: ");scanf("%d",&exit);
	
	return 0;
}

