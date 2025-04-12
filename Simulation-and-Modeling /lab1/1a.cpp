//Lab -1 Implementing application of monte carlo methods.
//1. Calculating pi with the monte carlo method. Also calulate the percentage of error for different sample size (100, 250, 500, 1000,1500).

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define SEED 35791246
#define PI 3.14159

int main(){
    int N=0;
    double x,y;
    int i,n=0;
    double z;
    double pi, error;
    printf("Enter the number of iterations used to estimate pi:");
    scanf("%d",&N);

    srand(SEED);
    n=0;
    for(i=0; i<N;i++){
        x=(double) rand() / RAND_MAX;
        y=(double) rand()/RAND_MAX;
        z=x*x+y*y;
        if(z<=1)
            n++;
    }
    pi=(double)n/N*4;
    printf("# of tirals =%d,estimate of pi id %g \n",N,pi);

    // % error:
    error= fabs((PI - pi)/ PI)*100;
    printf("percentage of error is: %.3f.",error);
    
    return 0;
}