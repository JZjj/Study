#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int count, inner, outer, ifswap, temp;
    int nums[10];
    time_t t;

    srand(time(&t));

    for (count = 0; count < 10; count ++){
        nums[count] = (rand()%99)+1;
    }
    puts("\nHere is the list before the sort:");
    for (count = 0; count < 10; count++)
    {
        printf("%d\n",nums[count]);
    }

    //sort the array

    for (outer = 0; outer<9; outer++){
        ifswap = 0; //1 if the list is not yet ordered
        for (inner = outer; inner <10; inner++)
        {
            if (nums[inner]<nums[outer]){
                temp = nums[inner];
                nums[inner] = nums[outer];
                nums[outer] = temp;
                ifswap = 1;
            }
        }
        if (ifswap == 0){
            break;
        }
    }
    // List the array as it currently is after sorting

    puts("\nHere is the list after the sort:");
    
    for (count = 0; count < 10; count ++){
        printf("%d\n",nums[count]);
    }
    return(0);
    
}