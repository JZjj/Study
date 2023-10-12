//
//  main.c
//  Exercise12
//
//  Created by jiajing zheng 05/14/23.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int day;
    int y=0;
    int x=1;
    for(day=9;day>=1;day--){
        y = (x+1)*2;
        x=y;
    }
    printf("y = %d\n",y);
    return 0;
}
