//
//  main.c
//  Exercise15
//
//  Created by jiajing zheng on 05/15/23.
//

#include <stdio.h>

int f(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n*f(n-1);
    }
    return f(n);
}
int main(int argc, const char * argv[]) {
    int f(int n);
    int m=10;
    printf("%d\n",f(m));
    return 0;
}
