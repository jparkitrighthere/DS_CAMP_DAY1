#include <stdio.h>
#include <string.h>

int number[100001];
int count = 0;

// push X: 정수 X를 스택에 넣는 연산
void push(int num) {
    number[count] = num;   
    count++;   
}

// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.
void pop() {
    if (count == 0) {
        printf("-1\n");
        return;
    }
    count--;
    printf("%d\n", number[count]);
}

// top: 스택의 가장 위에 있는 정수를 출력
void top() {
    if (count != 0) {
        printf("%d\n", number[count - 1]);
    } else {
        printf("-1\n");
    }
}

// size: 스택에 들어있는 정수의 개수를 출력
void size() {
    printf("%d\n", count);
}

// empty: 스택이 비어있으면 1, 아니면 0 출력
void empty() {
    if (count == 0) {
        printf("1\n");   
    } else {
        printf("0\n");   
    }
}

int main() {
    int n;
    char cmd[10];

    printf("명령을 입력하세요:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);  

        if (strcmp(cmd, "push") == 0) {
            int num;
            scanf("%d", &num);
            push(num);
            printf("%d\n", num);
        } else if (strcmp(cmd, "pop") == 0) {
            pop();
        } else if (strcmp(cmd, "top") == 0) {
            top();
        } else if (strcmp(cmd, "size") == 0) {
            size();
        } else if (strcmp(cmd, "empty") == 0) {
            empty();
        }
    }

    return 0;
}