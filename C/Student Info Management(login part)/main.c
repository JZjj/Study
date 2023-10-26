#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void move_m(short row, short col);

int main(void){
    
    move_m(4,8);
    int i =
    printf("hello c3");

    //getchar();
    system("pause");
    return 0;
}




void move_m(short row, short col){
    COORD cd = {col, row};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}