//
//  main.c
//  Exercise19
//
//  Created by jiajing zheng on 05/29/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char s[] = "123456789";
    int len = 0;
    char *p = s;
    
    while (*p !='\0') {
        len++;
        p++;
    }
    
    printf("%d\n",len);
    
    int c,b=3;
    c = ++b;
    printf("b=%d %d %d\n", c, ++b, b);
    
    int i;
    char temp;
    for(i = 0; i <len/2;i++){
        temp = *(s+i);
        *(s+i) = *(s+len-1-i);
        *(s+len-1-i) = temp;
    }
    printf("%s\n",s);
    return 0;
}
