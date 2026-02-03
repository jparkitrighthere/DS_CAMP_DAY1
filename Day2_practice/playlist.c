#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char songName[50];
    struct Node *next;
};

struct Node* addSong (struct Node* head, char *name){
    struct Node* newSong = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newSong->songName, name);
    newSong->next = NULL;

if (head == NULL){
    return newSong;
}

struct Node* temp = head;
while (temp->next != NULL){
    temp = temp -> next;
}

temp->next = newSong;

return head;
}

void showPlaylist (struct Node* head){
    struct Node* curr = head;
    while (curr != NULL){
        printf("%s -> ", curr-> songName);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;

    head = addSong(head, "Famous");
    head = addSong(head, "Wicked");
    head = addSong(head, "Marry Me");

    showPlaylist(head);


    return 0;
}

//remove는 strcmp사용