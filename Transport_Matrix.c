#include <stdio.h>
#include <malloc.h>
void Transport(float** Random_Matrix,int rows,int collumns);

int main(void)
{	float** Matrix;
	int rows,collumns;
	printf("Rows: ");scanf("%d",&rows);
	printf("Collumns: ");scanf("%d",&collumns);
	printf("Matrix: \n");
	Matrix = malloc(rows*sizeof(float*));
	for(int i = 0;i<rows;i++){
		Matrix[i] = malloc(collumns*sizeof(float));
		for(int j = 0;j<collumns;j++){
			scanf("%f",&Matrix[i][j]);
			}
		}
	Transport(Matrix,rows,collumns);
	printf("Transpote_Matrix: \n");
	for(int i = 0;i<rows;i++){
		for(int j = 0;j<collumns;j++){
			printf(" Matrix[%d][%d] = %f",i,j,Matrix[i][j]);
			}
		printf("\n");
		}	
	getchar();
	return 0;
}

void Transport(float** Random_Matrix,int rows,int collumns){
	float Number ;
	if(rows<=collumns){
	for(int j = 0;j<collumns;j++){
		for(int i = j;i<rows;i++){
			if(i != j){
				Number = Random_Matrix[i][j];
				Random_Matrix[i][j] = Random_Matrix[j][i];
				Random_Matrix[j][i] = Number;
				}
			 
			}}}
	else{printf("Incorrect Matrix! \n");}
	}

