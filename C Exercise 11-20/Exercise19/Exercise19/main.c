//
//  main.c
//  Exercise19
//
//  Created by jiajing zheng on 05/26/23.
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
