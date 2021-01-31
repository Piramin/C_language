#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <omp.h>
#include <time.h>

//Компиляция: Win + R -> команда cmd
//Команда: gcc -o "Имя файла" -fopenmp "Имя файла".c

float Multiplication(float Vector_1[],float Vector_2[],int Number,int Threads_Number){
	int i;
	float Result;
	omp_set_num_threads(Threads_Number);
	#pragma omp parallel for reduction(+:Result) shared(Vector_1,Vector_2,Number)
	for(i = 0;i < Number;i++){
		Result += Vector_1[i] * Vector_2[i];
		}
	return Result;
	}
int main()
{
	float* Vector_1;
	float* Vector_2;
	int i,Number;
	float Result_1,Result_2;
	Number = 100000;
	clock_t start , finish;
	srand(time(NULL));
	//Выделение памяти под векторы.
	Vector_1 = malloc(Number*sizeof(float));
	Vector_2 = malloc(Number*sizeof(float));
	//Генерация векторов.
	for(i = 0; i < Number ;i++){
		Vector_1[i] = rand()%10 + (rand()%100)*0.01;
		Vector_2[i] = rand()%10 + (rand()%100)*0.01;
	}
	
	start = clock();//Проверка на правильность параллельности по времени.	
//Начало параллельных вычислений. Используется 2 потока: Summation(...,'2');
	Result_1 = Multiplication(Vector_1,Vector_2,Number,2);
//Конец параллельных вычислений.
	finish = clock();
	printf("\nTime 1: %f\n",(double)(finish - start)/CLOCKS_PER_SEC);

	start = clock();//Проверка на правильность параллельности по времени.
//Начало параллельных вычислений. Используется 4 потока: Summation(...,'4');
	Result_2 = Multiplication(Vector_1,Vector_2,Number,4);
//Конец параллельных вычислений.
	finish = clock();
	printf("\nTime 2: %f\n",(double)(finish - start)/CLOCKS_PER_SEC);
  /*
	printf("\n Vector_1: ");
	for(i = 0 ; i < Number ; i++){
			printf("  %2.3f",Vector_1[i]);   
		}
	printf("\n");
	printf("\n Vector_2: ");
	for(i = 0 ; i < Number ; i++){
			printf("  %2.3f",Vector_2[i]);   
		}
	printf("\n");
	printf("Result 1 = %2.3f",Result_1);
	
	printf("\n");
	printf("Result 2 = %2.3f",Result_2);
  */	
	int exit;
    printf("\nInsert 0 to exit: ");scanf("%d",&exit);
 
	return 0;
}
