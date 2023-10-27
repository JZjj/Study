#include<stdio.h>
int main(){
    int i, m, flag = 1;
    printf("Input a postive integer:\n");
    scanf("%d",&m);
    for (i = 2; i<= m-1;i++)
        if(m%i==0){
            flag = 0;
        }
    if (flag ==1 )
        printf("%d is a prime \n",m);
    else 
        printf("%d is not a prime \n",m);
    return 0;
}