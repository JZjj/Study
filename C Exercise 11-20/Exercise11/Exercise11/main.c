//
//  main.c
//  Exercise11
//
//  Created by jiajing zheng on 05/14/23.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    for(int i = 0; i<=3; i++){
        for(int j = 0;j<=3-i;j++){
            printf(" ");
        }
        for (int k=0; k<2*i+1; k++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
