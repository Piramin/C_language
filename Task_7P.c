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
	srand(time(NULL));
	int a,b;
	a = rand()%99897 + 101;
	b = rand()%(99999-a) + a;
	
	//a = rand()%10;
	//b = rand()%(30 - a) + a;
	clock_t start , finish;	
	start = clock();//Проверка на правильность параллельности по времени.
	
//Начало параллельных вычислений. Используется 4 потока: ...'num_threads(4)'
	printf("Vector: ");
	int j = 0;
	int i = 0;
	omp_set_num_threads(2);
#pragma omp parallel for reduction(+:j) private(i) shared(a,b) ordered   //Подправить параллельный цикл через независимую переменную.
	for(i = a ; i <= b ; i++){
		j++;
#pragma omp ordered
		printf(" %d",i);
	}
//Конец параллельных вычислений.
	finish = clock();
	printf("\nTime: %f\n",(double)(finish - start)/CLOCKS_PER_SEC);
	printf("Variables A = %d , B = %d\n",a,b);
	printf("Number = %d\n",j);
	int exit;
    printf("\nInsert 0 to exit: ");scanf("%d",&exit);
	
	return 0;
}

