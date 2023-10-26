#pragma once
#include <stdio.h>

void login_menu(void);
void move_m(short row, short col);

void login_menu(void){
    move_m(0,0);
}

void move_m(short row, short col){
    COORD cd = {col, row};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}