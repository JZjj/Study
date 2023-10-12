//
//  main.c
//  Exercise21
//
//  Created by jiajing zheng on 05/26/23.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a[3][3] = {1,2,3,
        4,5,6,
        7,8,9};
    int i = 0;
    int j = 0;
    int sum = 0;
    for(i=0; i < 3;i++){
        sum+=a[i][i];
    }
    printf("sum = %d\n",sum);
    return 0;
}
