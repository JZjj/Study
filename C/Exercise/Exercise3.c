//
//  main.c
//  Exercise3
//
//  Created by jiajing zheng on 05/11/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a,b,c;
    printf("Return three int:");
    scanf("%d %d %d", &a,&b,&c);
    
    printf("%d\n",a<b?a:b);
    printf("smallest %d\n",(a<b?a:b)<c?(a<b?a:b):c);
    
    return 0;
}
