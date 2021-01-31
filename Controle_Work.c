#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
struct Sequence
{
	int* pSeq;
	int Number;
};

struct Sequence Create(int Vector[],int Number)
{	
	int i;
	struct Sequence sequence;
	sequence.pSeq = malloc(Number*sizeof(int));
	for(i = 0; i < Number;i++){
		sequence.pSeq[i] = Vector[i];
		}
	sequence.Number = Number;
	return sequence;
}

void Display(struct Sequence sequence){
	int i;
	for(i = 0;i<sequence.Number;i++){printf(" %d",sequence.pSeq[i]);}
	printf("\n");
}

struct Sequence Copy(struct Sequence sequence)
{	
	int i;
	struct Sequence copy_sequence;
	copy_sequence.pSeq = malloc(sequence.Number*sizeof(int));
	for(i = 0; i < sequence.Number ;i++){copy_sequence.pSeq[i] = sequence.pSeq[i];}
	copy_sequence.Number = sequence.Number;
	return copy_sequence;
}

struct Sequence Once(struct Sequence A)
{
	int i,j,Number_Loc,Number_In;
	int Number_All = 0;
	for(j = 0;j < A.Number;j++){
		Number_In = A.pSeq[j];
		Number_Loc = 0;
		for(i = 0;i < A.Number;i++){
			if(Number_In == A.pSeq[i]){Number_Loc++;}
		}
		if(Number_Loc == 1){Number_All++;}
	}
	struct Sequence B;
	B.pSeq = malloc(Number_All*sizeof(int));
	B.Number = Number_All;
	Number_All = 0;
	for(j = 0;j < A.Number;j++){
		Number_In = A.pSeq[j];
		Number_Loc = 0;
		for(i = 0;i < A.Number;i++){
			if(Number_In == A.pSeq[i]){Number_Loc++;}
		}
		if(Number_Loc == 1){B.pSeq[Number_All] = Number_In; Number_All++;}
	}
	return B;
}

void ToFile(FILE* in_file ,struct Sequence sequence)
{
	int i;
	for(i = 0;i<sequence.Number;i++){fprintf(in_file," %d",sequence.pSeq[i]);}
	fprintf(in_file,"\n");
}

void FromFile(FILE* out_file,int All_Number )
{
	int File_Number,i;
	for(i = 0;i<All_Number;i++){
		fscanf(out_file," %d",&File_Number);
		printf(" %d",File_Number);
		}
	printf("\n");
			

	
}
int main()
{
	int Vector_1[9] = {0,3,8,3,1,9,0,1,1};
	int Vector_2[5] = {1,1,5,9,13};
	int Vector_3[3] = {10,9,8};
	struct Sequence AA,BB,CC;
	AA = Create(Vector_1,9);
	BB = Create(Vector_2,5);
	CC = Create(Vector_3,3);
	printf("Do operacii:\n");
	Display(AA);
	Display(BB);
	Display(CC);
	
	printf("Posle operacii:\n");
	Display(Once(AA));
	Display(BB);
	Display(CC);	
	
	FILE * test_file;
	
	//Запись структур.
	test_file = fopen("data.txt","w+");
	ToFile(test_file,AA);
	ToFile(test_file,BB);
	ToFile(test_file,CC);
	fclose(test_file);
	
	//Считывание структур.
	printf("Posle zapisi:\n");
	test_file = fopen("data.txt","r");
	FromFile(test_file,AA.Number+BB.Number+CC.Number);
	fclose(test_file);
	return 0;
}

