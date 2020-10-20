#include <stdio.h>

int main(void)
{	
	char N[65];
	char M[65];
	int i1,i2;
	gets(N);
	gets(M);
	scanf("%d",&i1);
	scanf("%d",&i2);

	//Определение длины первого введенного числа.
	int N_lenght = 0;
	for(int i = 0;i<65;i++){
		if (N[i] == '\0'){
			N_lenght = i;
			break;
			}
		}
	//Определение длины второго введенного числа.
	int M_lenght = 0;
	for(int i = 0;i<65;i++){
		if (M[i] == '\0'){
			M_lenght = i;
			break;
			}
		}
	//Отсеивание нулевого числа.
	if(N[0] == '0'){
		for(int i = 0;i<=(i2-i1);i++){
			printf("%c",M[i]);
			}
		}
	else{
		//Определение результирующей строки.
		int Result_lenght = 0;
		if (N_lenght>M_lenght){
			Result_lenght = N_lenght;}
		else{Result_lenght = M_lenght;}
	
		char Result[Result_lenght];
		int j = 0;
		for(int i = 0;i<Result_lenght;i++){
			if(((N_lenght - 1 - i2)<=i)&&(i<=(N_lenght - 1 - i1))){
				//printf("%c",M[j]);
				Result[i] = M[j];
				if(j == (M_lenght - 1)){ 
					j = 0;}
				else{
					j++;}
				}
			else{ 
				//printf("%c",N[i]);
				Result[i] = N[i]; 
				}
			}
		//Вывод необходимого числа.
		int key = 0 ; 
		for(int i =0;i<N_lenght;i++){
			if(Result[i] != '0'){key = 1;}
			if(key && (Result[i] != '\0')){
				printf("%c",Result[i]);
				}
			}
		}
		
	return 0;
}
