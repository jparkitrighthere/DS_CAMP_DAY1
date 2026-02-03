#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char name[50];
    struct Node *next;
};

struct Node* joinQueue (struct Node* head, char *name){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
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

struct Node* insertVip(struct Node* head, char* name){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name,name);
    newNode->next = NULL;
    
    if (head==NULL) {
        head = newNode;
    }
    else{
        newNode-> next = head->next;
        head->next = newNode;
    }
    return head;
}

struct Node* serveNext(struct Node* head){
    struct Node* second;

    if(head == NULL){
        printf("현재 대기중인 손님이 없습니다.\n");
        return NULL;
    }
    second = head->next;

    printf("%s님 입장하세요\n",head->name);
    free(head);

    return second;
}

void countNodes(struct Node* head){
    struct Node* curr;
    int count;
    curr = head;

    while(curr!=NULL){
        count++;
        curr = curr->next;
    }

    printf("현재 대기 팀은 총 %d팀입니다.\n",count);
}



int main(){
    struct Node* head = NULL;
    char name[50];

    head = joinQueue(head, "박진수");
    head = joinQueue(head, "임성열");
    head = joinQueue(head, "윤석열");

    countNodes(head);

    head = insertVip(head, "카리나");
    head = joinQueue(head, "윈터");

    head = serveNext(head);
    head = serveNext(head);

    countNodes(head);

    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Node{
//   char name[50];
//   struct Node* next;
// };

// void countNodes(struct Node* head);
// struct Node* serveNext(struct Node* head);
// struct Node* insertVIP(struct Node* head, char* name);
// struct Node* joinQueue(struct Node* head, char* name);


// int main(){
//   struct Node* head;
//   char name[50];
  

//   strcpy(name, "김예준");
//   head = joinQueue(head, name);
//   strcpy(name, "차은우");
//   head = joinQueue(head, name);

//   countNodes(head);

//   strcpy(name, "카리나");
//   head = insertVIP(head, name);
//   strcpy(name, "윈터");
//   head = joinQueue(head, name);

//   head = serveNext(head);
//   head = serveNext(head);

//   countNodes(head);

//   return 0;
// }

// void countNodes(struct Node* head){
//   struct Node* curr;
//   int count = 0;
//   curr = head;

//   while(curr!= NULL){
//     count++;
//     curr = curr->next;
//   }

//   printf("현재 대기 팀은 총 %d 팀 입니다.\n", count);

// }

// struct Node* serveNext(struct Node* head){
//   struct Node* second;

//   if(head == NULL){
//     printf("현재 대기중인 손님이 없습니다.\n");
//     return NULL;
//   }

//   second = head->next;

//   printf("%s님 입장하세요!\n", head->name);

//   free(head);

//   return second;
// }

// struct Node* insertVIP(struct Node* head, char* name) {
//   // 1. 새 노드 생성
//   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//   strcpy(newNode->name, name);
//   newNode->next = NULL;

//   if(head == NULL){
//     head = newNode;
//   }
//   else {
//     newNode->next = head->next;
//     head->next = newNode;
//   }

//   return head;
// }

// struct Node* joinQueue(struct Node* head, char* name){
//   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//   strcpy(newNode->name, name);
//   newNode->next = NULL;

//   // 2. [예외 처리] 리스트가 비어 있는 경우
//   // 이 경우 새 노드가 곧 시작점이 됩니다.
//   if (head == NULL) {
//     return newNode; 
//   }

//   // 3. 리스트가 비어 있지 않은 경우 (마지막 노드 찾기)
//   // head를 직접 움직이면 시작점을 잃어버리므로 temp를 사용합니다.
//   struct Node* temp = head;
//   while (temp->next != NULL) {
//       temp = temp->next; // 다음 칸으로 이동
//   }

//   // 4. 마지막 노드(temp)의 next에 새 노드를 연결
//   temp->next = newNode;

//   // 5. 시작점(head)은 변하지 않았으므로 그대로 반환
//   return head;
// }