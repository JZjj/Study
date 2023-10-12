//
//  main.c
//  Exercise10
//
//  Created by jiajing zheng on 05/14/23.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int number = 0;
    int letter = 0;
    int space = 0;
    char c;
    int others = 0;
    c = getchar();
    while (c!='\n') {
        if((c>='a' && c<='z') ||(c>='A' && c<='Z')){
            letter++;
        }else if(c >='0' && c<='9'){
            number++;
        }else if(c ==' '){
            space++;
        }
    }
    
    
    printf("Letter: %d, Number: %d, Space: %d", letter, number, space);
    return 0;
}
