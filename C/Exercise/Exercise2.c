//
//  main.c
//  Exercise2
//
//  Created by jiajing zheng on 05/11/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int day, month, year;
    int sum=0;
    printf("input the year, month, and day:");
    scanf("%d,%d,%d",&year,&month,&day);
    
    switch (month) {
        case 1:
            sum = 0;
            printf("Jan\n");
            break;
        case 2:
            sum = 31;
            printf("Feb\n");
            break;
        case 3:
            sum = 59;
            printf("Mar\n");
            break;
        case 4:
            sum = 90;
            printf("Apr\n");
            break;
        case 5:
            sum = 120;
            printf("May\n");
            break;
        case 6:
            sum = 151;
            printf("Jun\n");
            break;
        case 7:
            sum = 181;
            printf("Jul\n");
            break;
        case 8:
            sum = 212;
            printf("Aug\n");
            break;
        case 9:
            sum = 243;
            printf("Sep\n");
            break;
        case 10:
            sum = 273;
            printf("Oct\n");
            break;
        case 11:
            sum = 304;
            printf("Nov\n");
            break;
        case 12:
            sum = 334;
            printf("Dec\n");
            break;
        default:
            break;
            
    }
    sum = sum + day;
    printf("The total number of day is: %d\n", sum);
    return 0;
}
