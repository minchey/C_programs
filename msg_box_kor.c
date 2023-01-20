//한국어 대화상자
#include<stdio.h>
#include<string.h>
void msg_box(void);
int main(void){
    msg_box();

    return 0;
}
void msg_box(void){
    int i; //기본 대화상자너비
    int x; //대화내용만큼 상자 크기조절
    char message[250];
    while(1){ //무한대화루프
        scanf("%s",message); //말 입력받기
        for(i=0;i<50+strlen(message);i++){   //상자 상단부분
            printf("*");
        }
        printf("\n*");
        for(x=0;x<48+strlen(message);x++){
            printf(" ");
        }
        printf("*\n");
        printf("*");
        for(x=0;x<48+strlen(message);x++){ //입력한 말 상자 중앙에 출력하기
            printf(" ");
            if(x==(50+strlen(message))/2-strlen(message)/3){
                printf("%s",message);
                x += strlen(message)-strlen(message)/3;
            }
        }
        printf("*\n");
        printf("*");
        for(x=0;x<48+strlen(message);x++){
            printf(" ");
        }
        printf("*\n");
        for(i=0;i<50+strlen(message);i++){
            printf("*");
        }
        printf("\n");
        
    }
}
