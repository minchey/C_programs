#include<stdio.h>
#include<string.h>
void msg_box(void);
int main(void){
    msg_box();

    return 0;
}
void msg_box(void){
    int i;
    int x;
    char message[250];
    char answer;
    while(1){
        scanf("%s",message);
        getchar();
        for(i=0;i<50+strlen(message);i++){
            printf("*");
        }
        printf("\n*");
        for(x=0;x<48+strlen(message);x++){
            printf(" ");
        }
        printf("*\n");
        printf("*");
        for(x=0;x<48+strlen(message);x++){
            printf(" ");
            if(x==(50+strlen(message))/2-strlen(message)/3){
                printf("%s",message);
                x += strlen(message)-strlen(message)/3;
            }
        }
        printf("*\n");
        printf("*");
        for(x=0;x<43+strlen(message);x++){
            printf(" ");
        }
        printf("y/n  ");
        printf("*\n");
        for(i=0;i<50+strlen(message);i++){
            printf("*");
        }
        printf("\n");
        scanf("%c",&answer);
        getchar();
        if(answer=='y')
            continue;
        else
            break;
    }
}
