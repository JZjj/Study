#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>

enum Direction {enum_east, enum_south, enum_west, enum_north};

#define X 20
#define Y 20

struct snake{
    int x,y;
    enum Direction direction; 
};

struct body{
    struct snake S;
    int length;
    struct body* Head;
    struct body* Next;
};

struct body* snakeHead = NULL;
struct body* snakeEnd = NULL;


char background[X][Y];
int snakequit = -1;
int snakestop = -1;
int snakespeed = 500;

struct Record{
    time_t t;
    int score;
};

void head(void);
void frame(void);
void move(unsigned short row, unsigned short col);
void createsnake(int length);
void spacefree(void); //if snake dies also call the function
void drawing(void);
void action(void);
void dropping(void);
void snakestate(void);
void apple(void);
void grow(void);
bool eatfood(void);
bool isdie(void);
void calscore(void);
void newgame(void);
void changing(void);
void saving(void);
void reading(void);


int main(){
   
    srand(0);
    head();
    frame();
    snakestate();
    createsnake(3);
    drawing();
    apple();
    calscore();
    while (1){
        snakestate();
        if (1 == snakequit)
        break;
        if (1 == snakestop){
            if (true == eatfood()){
                calscore();
                apple();
            }
            if (true == isdie()){
                saving();
                system("pause>0");
                continue;
            }
            dropping();
            action();
            drawing();
        }
        Sleep(snakespeed);
    }
    spacefree();
    return 0;
}

void reading(void){
    struct Record re;

	FILE* pFile = NULL;
	errno_t res = fopen_s(&pFile, "record.dat", "r");
	if (res != 0 || NULL == pFile)
		return;
	int hang = 9;
	while (0 != fread(&re, sizeof(re), 1, pFile))
	{
		move(hang++, 76);
		char str[50] = {0};
		ctime_s(str, 50, &re.t);
		printf("The previous score is%d, %s", re.score, str);
	}

	fclose(pFile);
}

void saving(void)
{
	struct Record re;
	re.score = snakeHead->length;
	re.t = time(NULL);

	FILE* pFile = NULL;
	errno_t res = fopen_s(&pFile, "record.dat", "a");
	if (res != 0 || NULL == pFile)
		return;
	fwrite(&re, sizeof(re), 1, pFile);
	fclose(pFile);
}

void changing(void)
{
	static int g = 1;

	switch (g % 3)
	{
	case 1:  
		move(5, 60);
        snakespeed = 350;
		printf("easy");
		break;
	case 2: 
		move(5, 60);
        snakespeed = 200;
		printf("medium");
		break;
	case 0: 
		move(5, 60);
        snakespeed = 500;
		printf("hard");
	}
	g++;
}

void newgame(void){
    system("cls");
    spacefree();
	head();
	frame();
	createsnake(3);
	drawing();
	apple();
	calscore();
}

void calscore(void){
    move(6,59);
    printf("%d",snakeHead->length);
}

bool isdie(void){
    if (1 == background[snakeHead->S.x][snakeHead->S.y])
	{
		move(18, 50);
		printf("Game Over!");
		return true;
	}
	return false;
}

bool eatfood(void){

    if (2 == background[snakeHead->S.x][snakeHead->S.y]){
        background[snakeHead->S.x][snakeHead->S.y] = 0;
        grow();
        return true;
    }
    return false;
}

void grow(void){

	struct body* pTemp = (struct body*)malloc(sizeof(struct body));
	if (NULL == pTemp)
		return;

    snakeHead->length++;

	pTemp->Head = NULL;
	pTemp->Next = NULL;
	pTemp->S.direction = snakeEnd->S.direction;
	
    switch (snakeEnd->S.direction){
	case enum_east:
		pTemp->S.x = snakeEnd->S.x;
		pTemp->S.y = snakeEnd->S.y - 1;
		break;
	case enum_south:
		pTemp->S.x = snakeEnd->S.x - 1;
		pTemp->S.y = snakeEnd->S.y;
		break;
	case enum_west:
		pTemp->S.x = snakeEnd->S.x;
		pTemp->S.y = snakeEnd->S.y + 1;
		break;
	case enum_north:
		pTemp->S.x = snakeEnd->S.x + 1;
		pTemp->S.y = snakeEnd->S.y;
	}

	pTemp->Head = snakeEnd;
	snakeEnd->Next = pTemp;
	snakeEnd = pTemp;
}

void apple(void){
	
    while (1){
        //create x,y
		int x = rand() % (X-2) + 1;
		int y = rand() % (Y-2) + 1;

		struct body* pT = snakeHead;
		while (pT != NULL){
			if (x == pT->S.x && y == pT->S.y)
				break;
			pT = pT->Next;
        }
		if (NULL != pT)
			continue;
        //if does not exist, then appropriate location
		else{
            //draw apple 
			background[x][y] = 2;
			move(9 + x, 35 + y * 2);
			printf("°ı");
			break;
		}
	}
} 

void snakestate(void){
    if (GetAsyncKeyState(VK_UP)){
		//if (snakeHead->S.direction != enum_south)
        snakeHead->S.direction = enum_north;
		
	}
	else if (GetAsyncKeyState(VK_DOWN)){
        snakeHead->S.direction = enum_south;
	}
	else if (GetAsyncKeyState(VK_LEFT)){
        snakeHead->S.direction = enum_west;
	}
	else if (GetAsyncKeyState(VK_RIGHT)){
        snakeHead->S.direction = enum_east;
	}
	else if (GetAsyncKeyState('Q')){
		saving();
		newgame();
	}
	else if (GetAsyncKeyState(VK_ESCAPE)){
		saving();
		snakequit = 1;
	}
	else if (GetAsyncKeyState(VK_RETURN)){
		snakestop = -snakestop;
	}
	else if (GetAsyncKeyState(VK_TAB)){
		changing();
	}
	else if (GetAsyncKeyState('1')){
		reading();
	}
}

void dropping(void){
    move(9+snakeEnd->S.x, 35 +snakeEnd->S.y*2);
    printf(" ");
}

void action(void){
    if (NULL == snakeHead)
    return;
    struct body* pT = snakeEnd;
    while (pT != snakeHead){
        pT ->S = pT->Head->S;
        pT = pT->Head;
    }
    switch (snakeHead->S.direction)
	{
	case enum_east:
            snakeHead->S.y++;
		break;
	case enum_south:
            snakeHead->S.x++;
		break;
	case enum_west:
            snakeHead->S.y--;
		break;
	case enum_north:
            snakeHead->S.x--;
		break;
    }
}

void drawing(void){
    if (NULL == snakeHead)    return;

    struct body* pT = snakeHead;
    while (pT != NULL){
        move(9 + pT->S.x, 35+pT->S.y *2);
        printf("●");
        pT = pT->Next;
    }
}

void createsnake(int length){
    //check
    if (length <=0)
    return;
    //create
    for (int i =0; i <length; i++){
        struct body* pT = (struct body*)malloc(sizeof(struct body));
        if (NULL == pT)
        return;
        pT->length = 0;
        pT->Head = NULL;
        pT->Next = NULL;
        pT->S.direction = enum_south;
        pT->S.x = 0;
        pT->S.y = 0;
        if (NULL == snakeHead){
            snakeHead = pT;
            snakeEnd = pT;
            snakeHead->length = 1;
            snakeHead->S.x = rand()%(X - 2) + 1;
            snakeHead->S.y = rand() % (Y - length - 1) + 1;
        }
        else{
            snakeEnd->Next = pT;
            pT->Head = snakeEnd;
            snakeEnd = pT;

            snakeHead->length+=1;
            snakeEnd->S.x = snakeEnd->Head->S.x;
            snakeEnd->S.y = snakeEnd->Head->S.y + 1;
        }
    }
}

void spacefree(void){
    if (NULL == snakeHead) 
        return;
    struct body* pT = snakeHead;
    while (NULL != pT)
    {   //record
        struct body* pp = pT;
        //move to next
        pT = pT->Next;
        //free space
        free(pp);
    }
    snakeHead = NULL;
    snakeEnd = NULL;
}

void move(unsigned short row, unsigned short col){
    COORD cd = {col, row};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void frame(void){
    //give frame value
    for (int i = 0; i < X; i++){
        for (int j = 0; j < Y; j++){
            if (0 == i || 0 == j || i == X - 1 || j == Y-1)
                background[i][j] = 1;
            else
                background[i][j] = 0;
        }
    }

    //输出
    for (int i = 0; i<X; i++){
        move(i+9,35);
        for (int j = 0; j < Y; j++){
            if (1 == background[i][j])
                printf("■");
            else
            printf(" ");
        }
        putchar('\n');
    }
}

void head(void){
    printf("\t\t\t\t\t>>>>>>>>>>>>>>>贪吃蛇<<<<<<<<<<<<<<<<\n");
    printf("\t\t\t\t\t>>>>>>>>>>>  Enter 启动/暂停<<<<<<<<<\n");
    printf("\t\t\t\t\t>>>>>>>>>>>> ⬆️⬇️⬅️➡️方向  <<<<<<<<<<<\n");
    printf("\t\t\t\t\t>>>>>>>>>>>  1 查看历史记录   <<<<<<<<\n");
    printf("\t\t\t\t\t>>>>>>>>>>>  Q 重新开始     <<<<<<<<<\n");
    printf("\t\t\t\t\t>>>>>>>>>>   tab 切换难度:   <<<<<<<<\n");
    printf("\t\t\t\t\t>>>>>>>>>>   当前长度：0     <<<<<<<<\n");
    printf("\t\t\t\t\t>>>>>>>>>>   Exit Game      <<<<<<<<\n");
    printf("\t\t\t\t\t>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<\n");
}