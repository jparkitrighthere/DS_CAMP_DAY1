#include <stdio.h>
#include <stdlib.h>

struct Node {
    //데이터
    int data;

    // 다음 노드의 주소를 저장하는 포인터 영역
    struct Node *next;
};

int main(){
    // 헤드라는 노드 만듬
    struct Node *head;

    //Step2: 첫번째 노드 추가 (list탄생)
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 10; //데이터 넣고
    newNode->next = NULL;
    head = newNode;

    //Step3: 두번째 노드 추가
    struct Node* secondNode = (struct Node*)malloc(sizeof(struct Node));
    secondNode -> data = 20;
    secondNode -> next = NULL;

    head->next = secondNode; //헤드의 next를 변경


    //Step4: 리스트 전체 순회 (Traversal)
    struct Node *current = head;
    while (current != NULL){
        current = current->next;
    }
}


struct Node* addNode (struct Node* head, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

if (head == NULL){
    return newNode;
}

struct Node* temp = head;
while (temp->next != NULL){
    temp = temp -> next;
}

temp->next = newNode;

return head;
}

int main(){
    struct Node* head = NULL;

    //단계별 추가
    head = addNode(head, 10);
    head = addNode(head, 20);
    head = addNode(head, 30);

    //확인 출력
    struct Node* curr = head;
    while (curr != NULL){
        printf("%d -> ", curr-> data);
        curr = curr->next;
    }
    printf("NULL\n");

    return 0;
}

struct Node* addfromHead(struct Node* head, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;

    return newNode;
}

//리스트에 있는 노드 삭제하기
struct Node* removeNode(struct Node* head, int target){
    if (head == NULL){ //리스트에 아무것도 없다는 뜻
        printf("리스트가 비어 있어 삭제할 수 없습니다.\n");
        return NULL;
    }

    struct Node* curr = head;
    struct Node* prev = NULL;

    //1. 삭제할 노드 찾기
    while(curr != NULL && curr->data != target){
        prev = curr; //현재를 이전으로 저장하고
        curr = curr -> next; //다음으로 이동
    }

    //2. 값을 찾지 못한 경우
    if (curr == NULL){
        printf("값 %d를 찾을 ㅅ ㅜ없습니다.\n", target);
        return head;
    }

    //3. 삭제할 노드가 헤드인 경우
    if (prev == NULL){
        head = curr->next;
    }
    //4. 삭제할 노드가 중간이나 끝인 경우
    else{
        prev->next = curr->next;
    }

    //5. 메모리 해제 및 반환
    free(curr);
    printf("노드 %d 삭제 완료\n", target);
    return head;
}

//리스트에 노드 삽입하기
struct Node* insertNode(struct Node* head,int index, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (index == 0) {
        newNode -> next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i=0;i<index-1;i++){
        if(temp=NULL){
            printf("인덱스 범위를 벗어났습니다.\n");
            free(newNode);
            return head;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

//리스트 메모리 해제
void clearList(struct Node* head){
    struct Node* curr = head;
    struct Node* nextNode;
    while (curr != NULL){
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
}

