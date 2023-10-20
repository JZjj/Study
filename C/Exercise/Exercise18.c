//
//  main.c
//  Exercise18
//
//  Created by jiajing zheng on 05/29/22.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char s[] = "123456789";
    int len = 0;
    len = strlen(s);
    printf("%d\n",len);
    
    int i;
    char temp;
    for(i = 0; i <len/2;i++){
        temp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = temp;
    }

    printf("%s\n",s);
    return 0;
}
