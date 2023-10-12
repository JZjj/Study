//
//  main.c
//  Exercise8
//
//  Created by jiajing zheng on 05/13/23.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int m =90;
    int i;
    for(i=2;i<=m;i++){
        while(m%i==0){
            printf("%d ",i);
            m = m/i;
        }
    }
    return 0;
}
