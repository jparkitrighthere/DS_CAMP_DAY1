#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TreeNode {
    char name[100];
    int priority;   

    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(char name[],int priority) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->name, name);
    newNode->priority = priority;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

TreeNode* addTask(TreeNode* root, char name[], int priority){
    if(root == NULL) return createNode(name, priority);

    if(priority < root->priority){
        root->left = addTask(root->left, name, priority);
    }else if(priority > root->priority){
        root->right = addTask(root->right,name, priority);
    }

    return root;
}

TreeNode* checkTask(TreeNode* root, int key) {
    if (root == NULL) return NULL;
    if (key == root->priority) return root;
    if (key < root->priority) return checkTask(root->left,key);
    else return checkTask(root->right,key);
}

void showInfo(TreeNode* root) { // 중요도 순으로 출력 (중위 순회)
    if (root == NULL) return;
    showInfo(root->left);
    printf("- %s | 중요도=%d\n", root->name, root->priority);
    showInfo(root->right);
}

TreeNode* findMin(TreeNode* node) {
    TreeNode* current = node;

    while (current && current->left != NULL){
        current = current->left;
    } 
    return current;
}

TreeNode* deleteTask(TreeNode* root, int priority) {
    if (root == NULL) return root;

    if (priority < root->priority) {
        root->left = deleteTask(root->left, priority);
    }
     else if (priority > root->priority) {
        root->right = deleteTask(root->right, priority);
    } 
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        } 
        
        TreeNode* temp = findMin(root->right);
        strcpy(root->name, temp->name);
        root->priority = temp->priority;
        root->right = deleteTask(root->right, temp->priority);
    }
    return root;
}

int main() {
    TreeNode* root = NULL;

    while (1) {
        int menu;

        printf("\n1) 추가  2) 삭제  3) 출력  0) 종료\n> ");
        scanf("%d",&menu);

        if (menu == 0) break;

        if (menu == 1) {
            char name[100];
            int priority;

            printf("할 일을 추가하세요: ");
            scanf(" %s]", name);

            printf("우선순위를 입력하세요: ");
            scanf("%d", &priority);
                
            if (checkTask(root, priority) != NULL) {
                printf("중복 priority=%d 입니다. 다시 입력하세요.\n", priority);
            }else{
                root = addTask(root, name, priority);
                printf("추가 완료~\n");
            }

        }
        else if (menu == 2) {
            int priority;

            printf("삭제할 priority를 입력하세요: ");
            scanf("%d",&priority);

            if (checkTask(root, priority) == NULL) {
                printf("해당 priority(%d) 없음\n", priority);
            } else {
                root = deleteTask(root, priority);
                printf("삭제 완료~\n");
            }
        }
        else if (menu == 3) {
            showInfo(root);
        }
        else {
            printf("없는 메뉴입니다.\n");
        }
    }

    return 0;
}