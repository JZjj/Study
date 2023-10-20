//
//  main.c
//  Exercise13
//
//  Created by jiajing zheng on 05/26/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i;
    float sum;
    float a=2;
    float b=1;
    int t;
    for(i = 0; i<20; i++){
        sum += a/b;
        t = a;
        a = a+b;
        b = t;
    }
    printf("%.2f\n",sum);
    return 0;
}
