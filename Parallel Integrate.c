#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <omp.h>
#include <time.h>

float function(float x);
int Runge_Rule(float A,float B,float* eps,float epsilon_default);
float Integrate(float x[],int size,float step);

//Программа использует метод трапеций. 2-й порядок точности.
int main()              
{
    float* X_Vector_Full_Step;
    float* X_Vector_Half_Step;
    float m,n,Step,Epsilon_default,Eps;
    float Integral_Full_Step , Integral_Half_Step;
    clock_t start , finish;
    int Size,i;
    printf("Tochnost:");scanf("%f",&Epsilon_default);
    m = 0;
    n = 100000;
    Size = (int)pow(10,3);
    Step = (float)(n - m)/Size;
    X_Vector_Full_Step = malloc(Size*sizeof(float));
    X_Vector_Half_Step = malloc(2*Size*sizeof(float));
    X_Vector_Full_Step[0] = m;
    X_Vector_Half_Step[0] = m;
    for(i = 1; i < Size;i++){
        X_Vector_Full_Step[i] = X_Vector_Full_Step[i - 1] + Step;
    }
    for(i = 1; i < 2*Size;i++){
        X_Vector_Half_Step[i] = X_Vector_Half_Step[i - 1] + 0.5*Step;    
    }
    
    int key = 1;
    int count = 0;
    start = clock();
    while(key != 0){
        Integral_Full_Step = Integrate(X_Vector_Full_Step,Size,Step);
        Integral_Half_Step = Integrate(X_Vector_Half_Step,2*Size,0.5*Step);
        if(Runge_Rule(Integral_Full_Step, Integral_Half_Step ,&Eps, Epsilon_default) == 0){
            key = 0;
        }
        else{
            printf("count = %d , epsilon = %f\n",count,Eps);
            free(X_Vector_Full_Step);
            free(X_Vector_Half_Step);
            Size *= 2;
            Step /= 2;
            X_Vector_Full_Step = malloc(Size*sizeof(float));
            X_Vector_Half_Step = malloc(2*Size*sizeof(float));
            X_Vector_Full_Step[0] = m;
            X_Vector_Half_Step[0] = m;
            for(i = 1; i < Size;i++){
                X_Vector_Full_Step[i] = X_Vector_Full_Step[i - 1] + Step;    
            }
            for(i = 1; i < 2*Size;i++){
                X_Vector_Half_Step[i] = X_Vector_Half_Step[i - 1] + 0.5*Step;    
            }
        }
        if(count > 15){
            printf("Error!Overcycle.");
            break;
        }
        count++;
    }
    finish = clock();
    printf("Integral = %f\n",Integral_Full_Step);
    printf("Integral Half Step = %f\n",Integral_Half_Step);
    printf("Step = %f\n",Step);
    printf("Eps = %f\n",Eps);
    printf("\nTime: %f",(double)(finish - start)/CLOCKS_PER_SEC);
    int exit;
    printf("\nInsert 0 to exit: ");scanf("%d",&exit);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
float function(float x){
    //return 3.0*x*x;
    if((pow(x,2) - pow(x,1.0/2.0)) == 0.0){
        return 0.0;
    }
    else{
        return x/(pow(x,2) - pow(x,1.0/2.0));
    }
}

int Runge_Rule(float A,float B,float* eps,float epsilon_default){
    *eps = fabs(fabs(A) - fabs(B))*1.0/(pow(2.0,2) - 1.0);
    if( *eps > epsilon_default){ return 1; }
    else{ return 0; }
    
}

float Integrate(float x[],int size,float step){
    float Integral = 0.5*fabs(function(x[0])) + 0.5*fabs(function(x[size - 1]));;
    int i;
    #pragma omp parallel for reduction(+:Integral) shared(x,i)
    for(i = 1; i < size - 1 ;i++){
        Integral += fabs(function(x[i]));
    }
    Integral *= step;
    return Integral;
}
