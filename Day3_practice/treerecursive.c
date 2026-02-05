#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// [전위 순회: Root -> L -> R]
void preorder(TreeNode* root){
    if (root == NULL) return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}



// [중위 순회: L -> Root -> R]
void inorder(TreeNode* root){
    if (root == NULL) return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

// [후위 순회: L -> R -> Root]
void postorder(TreeNode* root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

int main() {
    printf("=== Step 3: 전위, 중위, 후위 순회 ===\n\n");
    
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Pre-order (전위): ");
    preorder(root);
    printf("\n");

    printf("In-order  (중위): ");
    inorder(root);
    printf("\n");

    printf("Post-order(후위): ");
    postorder(root);
    printf("\n");

    return 0;
}

TreeNode* insertBST(TreeNode* root, int key){
    if(root == NULL) return createNode(key);

    if(key < root->data){
        root->left = insertBST(root->left, key);
    }else if(key > root->data){
        root->right = insertBST(root->right,key);
    }

    return root;
}

TreeNode* searchBST(TreeNode* root, int key){
    if(root == NULL) return NULL;
    if(key ==root->data) return root;

    if(key < root->data)
        return searchBST(root->left,key);
    else
        return searchBST(root->right,key);
}



TreeNode* findMinNode(TreeNode* node){
    TreeNode* current = node;

    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}


// Delete 함수
TreeNode* deleteBST(TreeNode* root, int key){
    // 1. 기본 처리: 트리가 비었으면 종료
    if (root == NULL) return root;

    // 2. 삭제할 노드 찾기 (탐색과 동일))
    if (key < root->data){
        root->left = deleteBST(root->left, key);
    }else if (key > root-> data){
        root->right = deleteBST(root->right, key);
    }

    // 3. 드디어 찾았다! (key == root->data)
    else{
        // Case 1 & 2: 자식이 없거나 하나만 있는 경우
        if (root->left == NULL){
            TreeNode* temp = root->right;
            free(root); //메모리 해제
            return temp; // 자식 (혹은 NULL)을 부모에게 리턴
        }
        else if(root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: 자식이 둘 다 있는 경우
        // 오른쪽 서브트리에서 가장 작은 값(후계자)을 찾음
        TreeNode* temp = findMinNode(root->right);

        //후계자의 값을 현재 노드로 복사 (값만 교체)
        root->data = temp->data;

        //이제 쓸모 없어진 원래 후계자 노드를 오른쪽 서브트리에서 삭제
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}