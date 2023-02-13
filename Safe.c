#define BLACK 0 //컬러 상수지정
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

void textcolor(int foreground, int background) //글자색,배경색 순서
{ 
int color=foreground+background*16; 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}
void gotoxy(int x, int y){
  COORD pos = {x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void Safe(){
    gotoxy(x,y);   printf("┌────────────────────┐");
    gotoxy(x,y+1); printf("│               ●    ●    ●    ●     │");
    gotoxy(x,y+2); printf("│                                        │");
    gotoxy(x,y+3); printf("└────────────────────┘");
}


int main(){
    Safe(15,15);
}
