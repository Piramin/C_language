#include <stdio.h>
#include <malloc.h>

void Sort(int* Vector,int Len,char Operation);

int main(void)
{
	int N; 
	printf("Size of vector: ");
	scanf("%d",&N);
	printf("Old Vector: ");
	int* Vector = malloc(N*sizeof(int));
	for(int i = 0;i<N;i++){scanf("%d",&Vector[i]);}
	printf("\n");
	//Подсчет кол-ва цифр, >0,=0,<0.
	int Number[3] = {0,0,0};
	for(int i = 0;i<N;i++){
		if(Vector[i] <0){
			Number[0] += 1;
			}
		if(Vector[i] == 0){
			Number[1] += 1;
			}
		if(Vector[i] > 0){
			Number[2] += 1;
			}			
		}
	//Составляем 3 массива по кол-ву цифр разных знаков.
	int* Vector_0 = malloc(Number[0]*sizeof(int));
	int* Vector_1 = malloc(Number[1]*sizeof(int));
	int* Vector_2 = malloc(Number[2]*sizeof(int));
	int j = 0;
	for(int i = 0;i<N;i++){
		if(Vector[i]<0){
		Vector_0[j] = Vector[i];
		j++;
		}}
	j = 0;
	for(int i = 0;i<N;i++){
		if(Vector[i]==0){
		Vector_1[j] = Vector[i];
		j++;
		}}
	j = 0;
	for(int i = 0;i<N;i++){
		if(Vector[i]>0){
		Vector_2[j] = Vector[i];
		j++;
		}}
	//Сортируем массивы.
	Sort(Vector_0,Number[0],'<');Sort(Vector_2,Number[2],'>');
	//Перезаписываем исходный массив как хотим.
	j = 0;
	for(int i = 0;i<Number[0];i++){
		Vector[j] = Vector_0[i];
		j++;
		}
	for(int i = 0;i<Number[2];i++){
		Vector[j] = Vector_2[i];
		j++;
		}
	for(int i = 0;i<Number[1];i++){
		Vector[j] = Vector_1[i];
		j++;
		}
	//Чистка памяти от промежуточных массивов.
	free(Vector_0);free(Vector_1);free(Vector_2);
	printf("Sorted Vector:");
	for(int i = 0;i<N;i++){printf(" %d",Vector[i]);}
	free(Vector);	
	return 0;
}

//Метод пузырька. >0 - по возрастанию, <0 - по убыванию.
void Sort(int* Vector,int Len,char Operation){
		for(int i = 0;i< Len - 1;i++){
			for(int j = 0;j< Len - 1 - i;j++){
				if (Operation == '>'){
					if (Vector[j] > Vector[j+1]){
						int num = Vector[j];
						Vector[j] = Vector[j+1];
						Vector[j+1] = num;
						}
					}
				if (Operation == '<'){
					if (Vector[j] < Vector[j+1]){
						int num = Vector[j];
						Vector[j] = Vector[j+1];
						Vector[j+1] = num;
						}
					}
				}
			}
}








