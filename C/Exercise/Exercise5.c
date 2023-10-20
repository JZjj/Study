//
//  main.c
//  Exercise5
//
//  Created by jiajing zheng on 05/13/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i = 10;
    int j = 0;
    
    for(j=1;j<9;j++){
        for(i=1;i<=j;i++){
            printf("%dx%d=%d ",j,i,j*i);
            
        }
        printf("\n");
    }
    return 0;
}
