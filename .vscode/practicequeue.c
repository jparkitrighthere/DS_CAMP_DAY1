#include <stdio.h>

int main(void) {
    int num = 0;
    int queue[500000];

    printf("정수를 입력하시오: ");
    scanf("%d",&num);

    return 0;
}

//queue insert
void insert(int num){
    int rear = 0;

    for(int i=num;i<0;i--){
        queue[rear] = num;
        rear++;
    }
}