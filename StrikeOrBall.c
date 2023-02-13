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
#include<time.h>
void textcolor(int colorNum, int colorNum2) {  //텍스트 컬러
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}
void gotoxy(int x, int y) { //좌표지정
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Safe(int x, int y) { //금고구현
    textcolor(WHITE, BLACK);
    gotoxy(x, y);     printf("┌──────────────────────────┐┐");
    gotoxy(x, y + 1); printf("│                           ││");
    gotoxy(x, y + 2); printf("│                           ││");
    gotoxy(x, y + 3); printf("│                           ││");
    gotoxy(x, y + 4); printf("│                           ││");
    gotoxy(x, y + 5); printf("│                           ││");
    gotoxy(x, y + 6); printf("└──────────────────────────┘┘");
    gotoxy(0, 30);
    textcolor(WHITE, BLACK);
}
int answer(int quiz,int num) {  
    int y = 5;
    int x = 30;
    int result = 0;
    for (int i=0; i < 4; i++) {
        if (num % 10 == quiz % 10) {  //숫자자리수 맞으면 초록불
            gotoxy(x, y); textcolor(GREEN, BLACK);
            printf("●");
            textcolor(WHITE, BLACK);
            result++;
        }
        else {
            gotoxy(x, y); textcolor(RED, BLACK);  // 틀리면 빨간불
            printf("●");
            textcolor(WHITE, BLACK);
        }
        num /= 10;
        quiz /= 10;
        x -= 4;
    }
    if (quiz == num) {

    }
}
void quizBox(int x, int y, int* answerNum) {  //답을 입력
    gotoxy(x, y - 1); textcolor(MAGENTA, BLUE); printf("자릿수 맞으면 초록불 아니면 빨간불"); textcolor(WHITE, BLACK);
    gotoxy(x, y); printf("답을 입력하세요 :"); scanf_s("%d", answerNum);

}

int main() {
    SetConsoleTitle("StrikeNumber");
    int whatNum;  //난수생성
    int answerNum;  //정답입력
    int chance = 15;
    gotoxy(13, 2); textcolor(LIGHTBLUE, WHITE); printf("야구숫자맞추기!!"); textcolor(WHITE, BLACK);
    Safe(10, 3);
    gotoxy(0, 30);
    srand(time(NULL));
    whatNum = rand() % 10000;
    while (1) {
        gotoxy(50, 6); textcolor(YELLOW, YELLOW); printf("남은기회: %d", chance); textcolor(WHITE, BLACK);
        quizBox(50, 5, &answerNum);
        answer(whatNum, answerNum);
        if(whatNum == answerNum){
            gotoxy(10, 11);
            textcolor(GREEN, YELLOW);
            printf("정답입니다!!");
            textcolor(WHITE, BLACK);
            break;
        }
        chance--;
        if (!chance) {
            gotoxy(10, 11);
            textcolor(RED, YELLOW);
            printf("기회를 모두 잃었습니다. 다시 시도하세요!");
            textcolor(WHITE, BLACK);
            break;
        }
        
    }
    return 0;
}
