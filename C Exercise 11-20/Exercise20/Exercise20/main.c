//
//  main.c
//  Exercise20
//
//  Created by jiajing zheng on 05/26/23.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int m = 400;
    int n;
    int res = 0;
    for (n=1; n<m; n++) {
        if (m%n==0) {
            res+=n;
        }
    }
    
    if (m==res) {
        printf("True\n");
    }else{
        printf("Not True\n");
    }
    return 0;
}
