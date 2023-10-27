#include<stdio.h>
main(){
    int n,sum=0;
    while(1){
        printf("Please enter n:");
        scanf("%d",&n);
        if(n<0)
            goto end;
        sum+=n;
    }
end: printf("sum is %d\n",sum);
}
//goto 可以从多重循环中跳出