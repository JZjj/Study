#include<stdio.h>
#include<math.h>
int main(){
    int s =1;
    float n=1,t=1,pi,sum=0.0;
    while (fabs(t)>=1e-6)
    {
        sum = sum+t;
        n = n+2;
        s = -s;
        t = s/n;
    }
    pi = sum*4;
    printf("pi = %f\n", pi);
    
}