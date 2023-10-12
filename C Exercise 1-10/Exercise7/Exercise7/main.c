//
//  main.c
//  Exercise7
//
//  Created by jiajing zheng on 05/11/23.
//

#include <stdio.h>
int isPrime(int m){
    int i;
    for(i=2;i<m;i++){
        if(m%i==0){
            break;
        }
    }
    
    if(i==m){
        return 1;
        
    }else{
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    int j;
    
    for(j=101;j<=200;j++){
        if(isPrime(j)){
            printf("%d ",j);
        }
    }
    
    return 0;
}
