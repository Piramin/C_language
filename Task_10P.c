#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <omp.h>
#include <time.h>

//Компиляция: Win + R -> команда cmd
//Команда: gcc -o "Имя файла" -fopenmp "Имя файла".c

void Multiplication(float Vector_1[],float* Vector_2,int Multiplication_Number,int Number,int Threads_Number){
	int i;
	omp_set_num_threads(Threads_Number);
	#pragma omp parallel for shared(Vector_1,Vector_2,Multiplication_Number,Number)
	for(i = 0;i < Number;i++){
		Vector_2[i] = Vector_1[i] * Multiplication_Number;
		}
	
	}
int main()
{
	float* Vector_1;
	float* Vector_2;
	int i,Number,Threads_Number;
	float Multiplication_Number = 18;
	Number = 100000;
	//Number = 8;
	clock_t start , finish;
	srand(time(NULL));
	//Выделение памяти под векторы.
	Vector_1 = malloc(Number*sizeof(float));
	Vector_2 = malloc(Number*sizeof(float));
	//Генерация векторов.
	for(i = 0; i < Number ;i++){
		Vector_1[i] = rand()%10 + (rand()%100)*0.01;
	}
	
	start = clock();//Проверка на правильность параллельности по времени.	
//Начало параллельных вычислений. Используется 2 потока: Threads_Number = 2;
	Threads_Number = 4;
	Multiplication(Vector_1,Vector_2,Multiplication_Number,Number,Threads_Number);
//Конец параллельных вычислений.
	finish = clock();
	printf("\nTime : %f\n",(double)(finish - start)/CLOCKS_PER_SEC);
	printf("\nNumber of threades : %d\n",Threads_Number);
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
  */	
	int exit;
    printf("\nInsert 0 to exit: ");scanf("%d",&exit);
 
	return 0;
}
