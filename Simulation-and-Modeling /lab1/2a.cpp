//2. Calculating the probability of getting a 3 heads 6 heads or 9 heads using monte carlo method.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int j,count=0,limit,i=0,head,tail;
    float y,answer,h=2.5;
    double error;

    printf("Enter the limit amount:");
    scanf("%d",&limit);

    while(i<=limit){
        i++;
        head=0;
        tail=0;
        for(j=0;j<10;j++){
            y=(float)((rand()% 65535)/65535.0f)*10;
            //printf("%f\n",y);
            if(y<h)
                head+=1;
            else
            tail+=1;
        }
        if((head==3) || (head==6) || (head==9))
        count+=1;
    }
    answer=(float)count/limit;
    printf("The limit is = %d\n and the probability is = %f",limit,answer);
    error=fabs((answer-0.33)/0.33)*100;
    printf("\nThe error precentage is :%.3f",error);
    return 0;
}