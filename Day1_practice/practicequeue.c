#include <stdio.h>

#define MAX 1000000

int queue[MAX];
int front = 0;
int rear = 0;

void insert(int x) {
    queue[rear] = x;
    rear++;
}

int delete() {
    int value = queue[front];
    front++;
    return value;
}

int size() {
    return rear - front;
}

int main() {
    int N;
    scanf("%d", &N);

    // 1부터 N까지 큐에 삽입
    for (int i = 1; i <= N; i++) {
        insert(i);
    }

    // 카드가 1장 남을 때까지 반복
    while (size() > 1) {
        // 제일 위 카드 버림
        delete();
    
        // 다음 카드 맨 아래로 이동
        int x = delete();
        insert(x);
    }
    
    // 마지막 남은 카드 출력
    printf("%d\n", delete());

    return 0;
}