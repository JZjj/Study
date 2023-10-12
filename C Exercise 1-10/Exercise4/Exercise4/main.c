//
//  main.c
//  Exercise4
//
//  Created by jiajing zheng on 05/11/23.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int m = 5;
    for(int i = 0; i<m; i++){
        printf("*");
    }
    printf("\n");
    
    for (int i = 0; i<m-1; i++) {
        printf("*\n");
    }
    
    for(int i = 0; i<m; i++){
        printf("*");
    }
    printf("\n");
    return 0;
}
