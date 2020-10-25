#include <stdio.h>
#include <inttypes.h>

void Byte_Print(uint64_t Number);
void Byte_Scanf(uint64_t* Number);

int main(void)
{	int i1,i2;
	uint64_t N = 0;
	uint64_t M = 0;
	uint64_t K = 0; // 133128,27
	
	//Ввод данных:
	Byte_Scanf(&N);
	Byte_Scanf(&M);
	scanf("%d",&i1);
	scanf("%d",&i2);
	
	K = ((((N>>i2)<<(i2-i1))| M)<<i1) | ((~((N>>i1)<<i1))&(N));
	Byte_Print(K);
	return 0;
}
void Byte_Scanf(uint64_t* Number){
	char input;
	for(int i = 0;i<64;i++){
		input = getchar();
		if(input == '\n'){
			*Number >>= 1;
			break;
			}
		if(input == '1'){
			*Number = *Number | 1;
			}
		*Number <<= 1;
		}
	fflush(stdin);
}

void Byte_Print(uint64_t Number){
		if(Number >> 1){
			Byte_Print(Number >> 1);
			}
		if((Number&1) == 1){putchar('1');}
		else{putchar('0');}
	}
