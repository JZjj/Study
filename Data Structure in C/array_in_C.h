#pragma once

#define eraseArray -1
#define success 0
#define invalidPos 1
#define posInit 2
#define posNotInit 3
#define posEmpty 4
#define fullArray 5

typedef struct array_in_C
{
    int *array;
    int size;
} array_in_C;

//Return array
array_in_C *get_size(int size);
array_in_C *get_copy(array_in_C *array);

//For input/output
int insert_array_in_C(array_in_C*array, int pos, int input);
int remove_array_in_C(array_in_C *array, int pos);
int push_array_in_C(array_in_C *array, int input);
int update_array_in_C(array_in_C *array, int pos, int input);

//Erase
int erase_array_in_C(array_in_C *array);

//Sorting
int bubble_sort_array_in_C(array_in_C *array);
int selection_sort_array_in_C(array_in_C *array);
int insertion_sort_array_in_C(array_in_C *array);

//Show
int show_array_in_C(array_in_C *array);