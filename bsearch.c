#include<stdio.h>
#include<stdlib.h>

int cmp(const int* a,const int* b){
    if(*a<*b)
        return -1;
    else if(*a==*b)
        return 0;
    else
        return 1;
}
int main(void){
    int nx,ky;
    int* x;
    printf("요소의 개수:");
    scanf("%d",&nx);
    x = calloc(nx,sizeof(int));
    printf("x[0]: ");
    scanf("%d",&x[0]);
    for(int i=1;i<nx;i++){
        do{
            printf("x[%d]: ",i);
            scanf("%d",&x[i]);
        }while(x[i]<x[i-1]);
    }
    printf("구하는 수: ");
    scanf("%d",&ky);
    int* idx = bsearch(&ky,x,nx,sizeof(int),(int(*)(const void*, const void*))cmp);
    if(idx ==NULL)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.",ky,(int) (idx-x));
    
    free(x);
    return 0;
}
