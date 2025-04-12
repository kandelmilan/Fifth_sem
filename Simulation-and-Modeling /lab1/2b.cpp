//2b. Modify 2a and calculate the value of PI and % error for different iterations.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int j,count=0,limit[100],i=0,head,tail,r=0,ch=0,p;
    float y,answer,h=2.5;
    double error;
    do{
    printf("Enter the limt amount:");
    scanf("%d",&limit[r]);
    printf("\nEnter 0 if you want to continue with next iteration and 1 if you want to exit program:");
    scanf("%d",&ch);
    if(ch==0)
        r++;
    
    }while(ch!=1);
    printf("|Limit\t\t|Probability\t|Error in percent\t|\n");
    for(p=0;p<=r;p++){
    while(i<=limit[p]){
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
    answer=(float)count/limit[p];
    error=fabs((answer-0.33)/0.33)*100;
    printf("| %d\t\t|%.4f\t\t|%.3f\t\t\t|\n",limit[p],answer,error);
}
    return 0;
}