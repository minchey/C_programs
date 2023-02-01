#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define SPACE ' '
#define SWAP (type,x,y)  do{ type int t=x;x=y;y=t;}while(0) //요소변환
enum MONTH {Jan = 1,Feb = 2,Mar,Apl,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec}; //열거형

//공용체
typedef union{
    int a;
    double b;
}Share;

//구조체
typedef struct{
    int a;
    double b;
    char c[200];
}Student;

typedef struct{
    Student st; //구조체 안에 구조체
    int age;
    double height;
    char name[50];
}Personal;

int sum(int a,int b); //더하기 함수
void Hello();//출력함수

int main(void){
    Student stu; //구조체
    Personal pers; //구조체
    Personal* per = &pers; //구조체 포인터
    enum MONTH mo;
    int i = 0;
    int bingo[3][3]; //2차원배열
    int num;
    scanf("%d",&num);
    int* arr_; //메모리 동적할당
    arr_ = calloc(num,sizeof(int));
    for(i=0;i<num;i++){
        scanf("%d",&arr_[i]);
    }
    scanf("%s",stu.c); //구조체 멤버에 입력
    while(0){
        printf("%c",stu.c[i]);
        i++;
        if(stu.c[i]=='\0')
            break;
    }
    strcpy(per->name,"민제"); //string copy 이용
    per->age = 30; // 구조체 포인터 ->로 표현
    per->st.a = 25;
    //printf("%d\n",per->st.a);
    
    //2차원배열 만든것으로 빙고판 만들기 rand함수 사용
    srand(time(NULL));
    for(i=0;i<3;i++){
        for(int j=0;j<3;j++){
            bingo[i][j] = rand() % 10;
        }
    }
    
    
    
    Hello(); //결과적으로 이것만 출력
    
    return 0;
}

void Hello(){
    printf("Hello C World\n");
}
int sum(int a, int b){
    return a+b;
}
