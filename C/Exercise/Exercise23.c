#include<stdio.h>

int main(){
    int i,a,b,count=0;
    for (i=100;i<=999;i++){
        a = i%10;
        b = i/100%10;
        if (a+b ==9){
            printf("%7d",i);
            count++;
            if (count % 8 ==0)
                printf("\n");
        }
    }
    return 0;
}
