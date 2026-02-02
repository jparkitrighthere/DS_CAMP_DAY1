#include <stdio.h>
#include <stdlib.h>

int main(){
    int days; //영입 일 수
    int *arr; //주소를 받을 포인터
    int sum=0;

    printf("분석할 영입일수를 입력하세요: ");
    scanf("%d", &days);

    arr = (int *)malloc(sizeof(int) * days);

    if (arr == NULL){
        printf("메모리가 부족합니다.\n");
        return 1;
    }

    for (int i=0;i<days;i++){
        printf("%d일차 매출: ",i + 1);
        scanf("%d",&arr[i]);
        sum = sum + arr[i];
    }

    float avg = sum / days;

    printf("--- 분석 결과 ---\n");
    printf(" 평균 매출 : %.1f원\n",avg);

    for(int i=0;i<days;i++){
        if(avg>arr[i]){
            printf("[경고] %d일차 매출 부진 (%d원)\n", i+1,arr[i]);
        }
    }

    free(arr);

    arr = NULL;

    return 0;
}