#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int main()
{
    FILE * test_file;
    int Rows,Collums,i,j;
    int** Old_Matrix_1;int** Old_Matrix_2;
    int** New_Matrix_1;int** New_Matrix_2;
    printf("Rows of Matrix = ");
    scanf("%d",&Rows);
    printf("Collums of Matrix = ");
    scanf("%d",&Collums);
    
    Old_Matrix_1 = (int**)malloc(Rows*sizeof(int*));
    for(i = 0;i<Rows;i++){
		Old_Matrix_1[i] = (int*)malloc(Collums*sizeof(int));
		}
	Old_Matrix_2 = (int**)malloc(Rows*sizeof(int*));
    for(i = 0;i<Rows;i++){
		Old_Matrix_2[i] = (int*)malloc(Collums*sizeof(int));
		}
    test_file = fopen("data.txt","w+");
    srand(time(NULL));
    printf("Old Matrix: \n");
    for(i = 0; i<Rows ;i++){
		for(j = 0;j<Collums;j++){
			Old_Matrix_1[i][j] = rand()%10;
			Old_Matrix_2[i][j] = rand()%10;
			fprintf(test_file, " [%d", Old_Matrix_1[i][j]);
			fprintf(test_file, ".%d]", Old_Matrix_2[i][j]);
			printf(" [%d.%d]",Old_Matrix_1[i][j],Old_Matrix_2[i][j]);
			fputc(' ',test_file);
			}
		printf("\n");
        //fprintf(test_file, "%с", n);
    }
    printf("\n");
    for(i = 0; i < Rows; i++){
		free(Old_Matrix_1[i]);
		}
    free(Old_Matrix_1);
    for(i = 0; i < Rows; i++){
		free(Old_Matrix_2[i]);
		}
    free(Old_Matrix_2);
    fclose(test_file);
    
   
    test_file = fopen("data.txt","r");
    New_Matrix_1 = (int**)malloc(Rows*sizeof(int*));
    for(i = 0;i<Rows;i++){
		New_Matrix_1[i] = (int*)malloc(Collums*sizeof(int));
		}
	New_Matrix_2 = (int**)malloc(Rows*sizeof(int*));
    for(i = 0;i<Rows;i++){
		New_Matrix_2[i] = (int*)malloc(Collums*sizeof(int));
		}
    printf("New Matrix: \n");
	for(i = 0; i<Rows ;i++){
		for(j = 0;j<Collums;j++){
			fscanf(test_file," [%d",&New_Matrix_1[i][j]);
			fscanf(test_file,".%d]",&New_Matrix_2[i][j]);
			printf(" [%d.%d]",New_Matrix_1[i][j],New_Matrix_2[i][j]);
			}
		printf("\n");
    }
	
	fclose(test_file);
    
    for(i = 0; i < Rows; i++){
		free(New_Matrix_1[i]);
		}
    free(New_Matrix_1);
    for(i = 0; i < Rows; i++){
		free(New_Matrix_2[i]);
		}
    free(New_Matrix_2);
    
    printf("Insert 0 to exit: ");
    int exit;
    scanf("%d",&exit); 
    
     
    return 0;
}
