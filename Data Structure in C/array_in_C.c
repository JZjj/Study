#include "array_in_C.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(array_in_C *array, int pos1, int pos2);

void swap(array_in_C *array, int pos1, int pos2){
    int t = array -> array[pos1];
    array->array[pos1] = array -> array[pos2];
    array->array[pos2] = t;
}
array_in_C *get_size(int size){
    array_in_C *array = (array_in_C *)malloc(sizeof(array_in_C));
    array->array = (int *)malloc(sizeof(int)*size);
    array->size = size;
    int i;
    for(i=0;i<size;i++){
        array->array[i]=0;
    }
    return array;
}

array_in_C *get_copy(array_in_C *arr){
    array_in_C *array = (array_in_C *)malloc(sizeof(array_in_C));
    array->array = (int *)malloc(sizeof(int)*arr->size);
    array->size = arr->size;
    int i;
    for (i=0; i< arr->size; i++){
        array -> array[i] = arr->array[i];
    }
    return array;
}

//For input/output
int insert_array_in_C(array_in_C*array, int pos, int input){
    if (pos >= 0 && pos<array->size){
        if (array->array[pos]==0){
            array->array[pos]=input;
            return success;
        }else return posInit;
        
    }return invalidPos;
}

int remove_array_in_C(array_in_C *array, int pos){
    if (pos >=0 && pos < array->size){
        if (array->array[pos]!=0){
            array->array[pos]=0;
        }else return posEmpty;
    }return invalidPos;
}
int push_array_in_C(array_in_C *array, int input){
    int i, j=0;
    for (i=0;i<array->size;i++){
        if (array->array[i]==0){
            array->array[i]=input;
            j=1;
            break;
        }
    }
    if (j==1)
    return success;
    else 
    return fullArray;
}


int update_array_in_C(array_in_C *array, int pos, int input){
    if (pos >=0 && pos<array->size){
        if (array->array[pos]!=0){
            array->array[pos] = input;
            return success;
        }
        else
        return posNotInit;
    }
    return invalidPos;
}

//Erase
int erase_array_in_C(array_in_C *array){
    int i;
    for (i=0;i<array->size;i++){
        array->array[i]=0;
    }
    return 0;
}

//Sorting
int bubble_sort_array_in_C(array_in_C *array){
    int i,j;
    for (i=0;i<array->size-1;i++){
        for (j=0;j<array->size-i-1;j++){
            if (array->array[j]>array->array[j+1]){
                swap(array,j,j+1);
            }
        }
    }
    return 0;
}
int selection_sort_array_in_C(array_in_C *array){
    int i,j,k;
    for (i=0; i< array->size-1; i++){
        k = i;
        for (j=i+1; j < array->size;j++)
            if (array->array[j]<array->array[k])
                k = j;
        swap(array, k, i);
    }
    return 0;
}
int insertion_sort_array_in_C(array_in_C *array){
    int i, j, k;
    for (i=1; i < array -> size; i++){
        k = array->array[i];
        j = i-1;
        while (j>=0 && array->array[i]>k){
            array->array[j+1] = array->array[j];
            j--;
        }
        array->array[j+1]=k;
    }
}

//Show
int show_array_in_C(array_in_C *array){
    int i;
    printf("\narray in C");
    for (i=0;i<array->size;i++){
        printf("%d",array->array[i]);
    }
    printf("\n");
    return 0;
}
