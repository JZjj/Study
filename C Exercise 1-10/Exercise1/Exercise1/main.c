//
//  main.c
//  Exercise1
//
//  Created by jiajing zheng 05/11/23.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int hund, ten, decimal;
    int count = 0;
    for(hund=1;hund<5;hund++){
        for(ten=1;ten<5;ten++){
            for(decimal=1;decimal<5;decimal++){
                if(hund!=ten && ten!=decimal && hund!=decimal){
                    printf("%d,%d,%d\n",hund,ten,decimal);
                    count++;
                }
                
            }
        }
    }
    return 0;
}

