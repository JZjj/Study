#include <stdio.h>
int main(){
    int i =1;
    double a = 1, total = 0;
    for(i=1;i<=64;i++){
        total += a;
        a = a*2;
        printf("i=%d, total=%.0lf\n",i,total);
    }
    return 0;
}
