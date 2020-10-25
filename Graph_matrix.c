#include <stdio.h>
#include <malloc.h>
#include <time.h>

int main(void)
{	
	int N,M;
	time_t T[4];
	scanf("%d",&N);
	scanf("%d",&M);
	
	T[0] = time(0);
	int** R = malloc(N*sizeof(int*));
	for(int i = 0;i<N;i++){
		R[i] = malloc(N*sizeof(int));
		}
	// Составление матрицы смежности, которая преобразуется в матрицу достижимости.
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			//Вершина достижима сама из себя.
			if(i == j){R[i][j] = 1;}
			else{R[i][j] = 0;}
			}
		}
	T[1] = time(0);
	//Ввод ребер.
	int row;
	int col;
	for(int i = 0;i<M;i++){
		scanf("%d %d",&col,&row);
		R[row][col] = 1;
		
		}
	T[2] = time(0);
	//Поиск путей.
	for(int k = 0;k<N;k++){
		for(int i = 0;i<N;i++){
			for(int j = 0;j<N;j++){
				if (R[i][j] == 0){
					if((R[k][j] == 1) && (R[i][k] == 1)){
						R[i][j] = 1;
						}
					}
				}
			}
		}
	T[3] = time(0);
	//Вывод матрицы.
	printf("\n");
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			printf("%d",R[i][j]);
			}
		printf("\n");
		}
	//Очистка памяти.
	for(int i = 0;i<N;i++){
		free(R[i]);
		}
	free(R);
	printf("Time = %f",difftime(T[3],T[2]));
	
	return 0;
}
