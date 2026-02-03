#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

struct Node* addNode (struct Node* cursor, char data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->prev = cursor;
    newNode->next = cursor->next;
    cursor->next = newNode;
    if(newNode->next!=NULL){
        newNode->next->prev = newNode;
    }

    return newNode;
}

struct Node* deleteLeft(struct Node* cursor, struct Node* head) {
    if (cursor == head) return cursor; // 문장 맨 앞이면 리턴

    struct Node* left = cursor->prev;
    struct Node* right = cursor->next;

    left->next = right; // cursor 건너뛰고 연결
    if (right != NULL) right->prev = left; // right 이전도 연결

    free(cursor);
    return left; // 커서는 한 칸 왼쪽으로
}

int main(){

    // 편집기에 문자열 입력
    char N[100001];
    scanf("%s",N);

    // 입력할 명령어 개수 입력
    int M = 0;
    scanf("%d",&M);

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;

    // 커서를 문장 끝으로
    struct Node* cursor = head;
    for (int i = 0; i<N[i]; i++) {
        cursor = addNode(cursor, N[i]);
    }

    for (int i = 0; i < M; i++) {
        char cmd;
        scanf(" %c", &cmd);

        if (cmd == 'L') {
            if (cursor != head) cursor = cursor->prev; // 맨 앞 무시하고 한 칸 왼쪽으로
        } else if (cmd == 'D') {    
            if (cursor->next != NULL) cursor = cursor->next; // 마지막 아니면 한 칸 오른쪽으로
        } else if (cmd == 'B') {
            cursor = deleteLeft(cursor, head);
        } else if (cmd == 'P') { // 문자를 입력받아 커서와 다음 문자 사이에 삽입
            char $;
            scanf(" %c", &$);
            cursor = addNode(cursor, $);
        }
    }

    struct Node* curr = head;
    while (curr != NULL){
        printf("%c", curr-> data);
        curr = curr->next;
    }

    return 0;
}

