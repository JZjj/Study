#include <stdio.h>
int main(){
    
    float x,y;
    printf("Input x:\n");
    scanf("%f",&x);

    if(x<0)
        y = 0;
    if(x>=0 && x<1)
        y = x*x*x;
    if(x>=1)
        y = 8*x+9;

    printf("x=%f,y=%f\n",x,y);
    return 0;

}