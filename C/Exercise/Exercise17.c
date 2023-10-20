//
//  main.c
//  Exercise17
//
//  Created by jiajing zheng on 05/29/22.
//
//
#include <stdio.h>

int age(int n){
    int c = 0;
    if(n==1){
        c = 10;
    }else{
        c = age(n-1)+2;
    }   return c;
}


int main(int argc, const char * argv[]) {
    int age(int n);
    printf("age(5)=%d\n",age(5));
    
    return 0;
}
