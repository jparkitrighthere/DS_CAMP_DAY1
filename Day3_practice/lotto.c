#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 노드 생성
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// [핵심 로직] BST 삽입 (중복 체크 포함)
// 10 5 15 20
TreeNode* insertLotto(TreeNode* root, int key) {
    // 1. 빈 자리면 저장 (성공)
    if (root == NULL) {
        printf(" -> %d 입력 완료!\n", key);
        return createNode(key);
    }

    // 2. 중복 체크: 이미 있는 값이면 경고 메시지 출력 후 아무것도 안 함
    if (key == root->data) {
        printf(" -> [경고] %d는 이미 존재하는 번호입니다.\n", key);
        return root;
    }

    // 3. 자리 찾기 (작으면 왼쪽, 크면 오른쪽)
    if (key < root->data) {
        root->left = insertLotto(root->left, key);
    } 
    else if (key > root->data) {
        root->right = insertLotto(root->right, key);
    }

    return root;
}

// [핵심 로직] 중위 순회 (자동 정렬 출력)
// L(작은거) -> Root(중간) -> R(큰거) 순서이므로 자동으로 오름차순이 됨
void printSorted(TreeNode* root) {
    if (root == NULL) return;
    printSorted(root->left);
    printf("%d ", root->data);
    printSorted(root->right);
}

int main() {
    TreeNode* root = NULL;
    int input;

    printf("=== 로또 번호 자동 정렬기 (BST) ===\n");
    printf("1~45 사이의 숫자를 입력하세요.\n");
    printf("중복된 숫자는 걸러지며, -1을 입력하면 결과를 보여줍니다.\n\n");

    while (1) {
        printf("번호 입력: ");
        scanf("%d", &input);

        if (input == -1) break; // 종료 조건

        // 범위 체크 (선택 사항)
        if (input < 1 || input > 45) {
            printf(" -> [오류] 1~45 사이의 숫자만 가능합니다.\n");
            continue;
        }

        root = insertLotto(root, input);    
    }

    printf("\n--------------------------\n");
    printf("최종 결과 (오름차순 정렬): ");
    printSorted(root);
    printf("\n--------------------------\n");

    return 0;
}