#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <omp.h>
#include <time.h>

int main()
{

    float** Matrix;
    float* Vector;
	int rows,collums,i,j;
	float Middle_Number = 0.0;
	clock_t start , finish;
	srand(time(NULL));
	collums = 1800;
	rows = abs(rand()%25000 - rand()%24000);
	//rows = 10;
	//collums = 10;
	//Выделение памяти под матрицу и вектор.
	Vector = malloc(rows*sizeof(float));
	Matrix = malloc(rows*sizeof(float*));
	for(i = 0; i < rows ;i++){
	    Matrix[i] = malloc(collums*sizeof(float));
	}
	//Генерация матрицы.
	for(i = 0; i < rows ;i++){
	    for(j = 0 ; j < collums ; j++){
	        Matrix[i][j] = rand()%10 + (rand()%100)*0.01;   
	    }
	}
	start = clock();
	//Подсчет вектора средних значений и в целом среднего значения матрицы.
    for(i = 0; i < rows ;i++){
        Vector[i] = 0;
        for(j = 0; j < collums ;j++){
            Vector[i] += Matrix[i][j];
        }
        Vector[i] /= collums;
        Middle_Number += Vector[i];
    }
    Middle_Number /= rows;
    finish = clock();
    //Вывод полученной матрицы на экран.
    if((rows < 20)&(collums < 20)){ //
	printf("Matrix: \n");
	for(i = 0; i < rows ;i++){
		for(j = 0 ; j < collums ; j++){
			printf("  %2.3f",Matrix[i][j]);   
		}
		printf("\n");
	}
	} //
    //Вывод вектора и среднего матрицы.
    if(rows < 20){//
		printf("\nVector:");
		for(i = 0; i < rows ;i++){
			printf("  %2.3f",Vector[i]);
		}
	}//
    printf("\nMiddle Number = %f",Middle_Number);
    printf("\n Rows = %d , Collums = %d",rows,collums);
    printf("\nTime: %f",(double)(finish - start)/CLOCKS_PER_SEC);
    int exit;
    printf("\nInsert 0 to exit: ");scanf("%d",&exit);
    return 0;
	
}
