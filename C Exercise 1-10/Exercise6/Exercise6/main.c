//
//  main.c
//  Exercise6
//
//  Created by jiajing zheng on 05/11/23.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a = 1;
    int b = 1;
    
    for(int i =1;i<=10;i++){
        printf("%d,%d,",a,b);
        if(i%2==0)printf("\n");
        a = a+b;
        b = b+a;
        
    }
    return 0;
}
