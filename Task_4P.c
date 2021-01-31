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
	int* Vector_1;
	int* Vector_2;
	int** Matrix;
	
	int i,j;
	int rows = 1000;
	int collums = 1000;
	clock_t start , finish;
	
	srand(time(NULL));
	
	//Выделение памяти под матрицы.
	Vector_1 = malloc(collums*sizeof(float));
	Vector_2 = malloc(collums*sizeof(float));
	Matrix = malloc(rows*sizeof(float*));
	for(i = 0; i < rows ;i++){
	    Matrix[i] = malloc(collums*sizeof(float));
	}
	
	//Генерация матрицы.
	for(i = 0; i < rows ;i++){
	    for(j = 0 ; j < collums ; j++){
	        Matrix[i][j] = rand()%10;   
	    }
	}
	//Генерация вектора.
	for(i = 0; i<collums ;i++){
		Vector_1[i] = rand()%10;
		}
	
	start = clock();//Проверка на правильность параллельности по времени.
	
//Начало параллельных вычислений. Используется 4 потока: ...'num_threads(4)'
	int Result; //Инициализация переменной для каждого потока в параллельности для условия firstprivate.
	Result = 0;
omp_set_num_threads(4);
	//Запись новой матрицы.
	#pragma omp parallel for firstprivate(Result) shared(Vector_1,Vector_2,Matrix,rows,collums)    //Подправить параллельный цикл через независимую переменную.
	for(j = 0; j < collums ;j++){
		Result = 0;
	    for(i = 0 ; i < rows ; i++){
	        Result += Vector_1[i] * Matrix[i][j];  
	    }
	    Vector_2[j] = Result;
	}
//Конец параллельных вычислений.
	finish = clock();
	printf("\nTime: %f\n",(double)(finish - start)/CLOCKS_PER_SEC);
 /*
	//Вывод полученной матрицы:
	printf("\nMatrix : \n");
	for(i = 0; i < rows ;i++){
		for(j = 0 ; j < collums ; j++){
			printf("  %2d",Matrix[i][j]);   
		}
		printf("\n");
	}
	printf("\nVector_1 : \n");
	//Вывод полученного вектора:
	for(j = 0 ; j < collums ; j++){
		printf("  %2d",Vector_1[j]);   
	}
	printf("\n");
	printf("\nVector_2 : \n");
	//Вывод полученного вектора:
	for(j = 0 ; j < collums ; j++){
		printf("  %2d",Vector_2[j]);   
	}
		
 */	
	int exit;
    printf("\nInsert 0 to exit: ");scanf("%d",&exit);
	
	return 0;
}

