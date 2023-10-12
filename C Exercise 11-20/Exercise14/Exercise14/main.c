//
//  main.c
//  Exercise14
//
//  Created by jiajing zheng on 05/15/23.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i;
    int j;
    int sum=0;
    int num=1;
    for(i = 1;i<=20;i++){
        for (j=1; j<=i; j++) {
            num*=j;
        }
        sum += num;
    }
    printf("Result is %d\n",sum);
    return 0;
}
