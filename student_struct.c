#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//학생 정보 구조체
typedef struct{
    char name[50];
    int age;
    int score;
    double height;
}Student;

//평균점수 구하기
double ave_score(int a, int n);

//점수 합계 구하기
int score_sum(Student stu[],int n);
int main(void){
    int num; //학생수
    int sum; //점수총합
    printf("학생수:"); scanf("%d",&num);
    Student student;
    Student* stu = &student; //구조체 배열선언
    stu = calloc(num,sizeof(Student)); //배열크기 동적할당
  
  //구조체 배열 요소 입력
    for(int i=0; i<num; i++){
        printf("이름: "); scanf("%s",&stu[i].name);
        printf("나이: "); scanf("%d",&stu[i].age);
        printf("키: "); scanf("%lf",&stu[i].height);
        printf("점수: "); scanf("%d",&stu[i].score);
    }
  
  //점수합계 값 넣어주기
    sum = score_sum(stu,num);
    printf("점수 총합은 : %d\n",sum);
    printf("점수 평균은 : %.2lf\n",ave_score(sum,num));
    free(stu);
    return 0;
}

//평균내기 함수
double ave_score(int a, int n){
    return a/n;
}

//점수 총합내기 함수
int score_sum(Student stu[],int n){
    int i;
    int sum = 0;
    for(i=0; i<n; i++){
        sum += stu[i].score;
    }
    return sum;
}
