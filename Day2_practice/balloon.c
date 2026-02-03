#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;         // 풍선 번호
    int value;      // 종이에 적힌 값
    struct Node *prev;
    struct Node *next;
} Node;

// 새 노드 생성 함수
Node* createNode(int id, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

int main() {
  int N;
  printf("풍선 갯수 입력: ");
  scanf("%d", &N);

  Node *head = NULL, *tail = NULL;

  // 1. 원형 이중 연결 리스트 생성
  for (int i = 1; i <= N; i++) {
    int val;
    scanf("%d", &val);
    Node* newNode = createNode(i, val);

    if (head == NULL) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }
  // 원형 연결 (처음과 끝 연결)
  tail->next = head;
  head->prev = tail;

  Node* curr = head;

  // 2. 풍선 터뜨리기 루프
  for (int i = 0; i < N; i++) {
    printf("%d ", curr->id);
    int move = curr->value;

    if (i == N - 1) { // 마지막 풍선이면 메모리 해제 후 종료
      free(curr);
      break;
    }

    // 터진 풍선 리스트에서 제거
    Node* toDelete = curr;
    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    // 이동 방향 결정
    if (move > 0) {
      curr = toDelete->next;
      for (int j = 1; j < move; j++) {
        curr = curr->next;
      }
    } else {
      curr = toDelete->prev;
      for (int j = 1; j < -move; j++) {
        curr = curr->prev;
      }
    }

    free(toDelete); // 터뜨린 풍선 메모리 해제
  }

  return 0;
}