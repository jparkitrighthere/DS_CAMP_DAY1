#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person{
    char name[50];
    int age;
    float height;

    struct Person* left;
    struct Person* right;
}Person;

Person* createNode(char name[], int age, float height){
    Person* newPerson = (Person*)malloc(sizeof(Person));
    strcpy(newPerson->name, name);
    newPerson->age = age;
    newPerson->height = height;

    newPerson -> left = NULL;
    newPerson -> right = NULL;

    return newPerson;
}

int main(void){

    Person *root = createNode("jinsoo",25,173.5);
    Person *lChild = createNode("siu",40,185);
    Person *rChild = createNode("sui",39,187.5);

    root->left = lChild;
    root->right = rChild;

    printf("Name: %s Age: %d Height: %f\n", root-> name, root-> age, root-> height);

    return 0;
}