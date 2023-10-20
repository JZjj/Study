//
//  main.c
//  Exercise16
//
//  Created by jiajing zheng on 05/29/22.
//

#include <stdio.h>

void f(int n){
    char c;
    if(n==1){
        c = getchar();
        putchar(c);
    }else{
        c = getchar();
        f(n-1);
        putchar(c);
    }
}



int main(int argc, const char * argv[]) {
    
    void f(int n);
    f(5);
    return 0;
}
