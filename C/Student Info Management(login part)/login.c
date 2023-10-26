#include "login.h"
struct User user = {};

bool login(void){

    loginmenu();
    while (1)
    {
        /* code */
    }
    
}
void orderwrong

void Countdown(short row, short col, int t, char start){
    for (int i = 1; i<= start - '0'; i++){
        Sleep(t);
        move_m(row, col);
        putchar(start - i);
    }
    Sleep(t);
}


void register_user(void){
    move_m(11,0);
    printf("\t\t\t\t\t*       user name :                *\n");
	printf("\t\t\t\t\t*         password:                *\n");
	printf("\t\t\t\t\t************************************\n");
	move_m(11, 60);
}

void register_fail(void){
    move_m(14,0);
    printf("\t\t\t\t\t*       Register Fail!!            *\n");
	printf("\t\t\t\t\t************************************\n");
	move_m(9, 67);
}

void register_success(void){
    move_m(14,0);
    printf("\t\t\t\t\t*      Register Success!!!         *\n");
	printf("\t\t\t\t\t************************************\n");
	CountDown(14, 57, 1000, '3');
}

void loginuser(void){
    move_m(11,0);
    printf("\t\t\t\t\t*         User name :              *\n");
	printf("\t\t\t\t\t*          Password :              *\n");
	printf("\t\t\t\t\t************************************\n");
	move_m(11, 60);
}

void loginfail(void){
    move_m(14,0);
    printf("\t\t\t\t\t*           Login Fail!!           *\n");
	printf("\t\t\t\t\t************************************\n");
	move_m(9, 67);
}

void loginsuccess(void){
    move_m(14,0);
    printf("\t\t\t\t\t*          Login Success!!         *\n");
	printf("\t\t\t\t\t************************************\n");
	Countdown(14, 57, 1000, '3');
}

void loginmenu(void){
    move_m(2,0);
  	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t*       Welcome to the system      *\n");
	printf("\t\t\t\t\t*   Please enter relevant command  *\n");
	printf("\t\t\t\t\t*          1: User login           *\n");
	printf("\t\t\t\t\t*    2: New user registration      *\n");
	printf("\t\t\t\t\t*         3: Guest login           *\n");
	printf("\t\t\t\t\t*         4: Exit system           *\n");
	printf("\t\t\t\t\t*          Enter(1/2/3/4):         *\n");
	printf("\t\t\t\t\t************************************\n");
    
    move_m(9,67);
}

void move_m(short row, short col){
    COORD cd = {col , row };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd); 
}