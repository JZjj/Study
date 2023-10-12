//
//  main.c
//  Exercise9
//
//  Created by jiajing zheng on 05/13/23.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int a = 1997;
    int b = 615;
    int r;
    
    r = a%b;
    while(r!=0){
        a = b;
        b = r;
        r = a%b;
    }
    return 0;
}
