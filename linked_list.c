#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

void traversel(struct node *head){
    struct node *current = head;
    int i = 1;
    while(current != NULL){
        if(i == 1){
            printf("%dst element value is %d\n", i, current->val);
            current = current->next;
            i++;
        }
        if(i == 2){
            printf("%dnd element value is %d\n", i, current->val);
            current = current->next;
            i++;
        }
        if(i == 3){
            printf("%drd element value is %d\n", i, current->val);
            current = current->next;
            i++;
        }
        printf("%dth element value is %d\n", i, current->val);
        current = current->next;
        i++;
    }
}

//Insertion inside a linked list

struct node *insertionatbeginning(struct node *head, int value){
    struct node *nexthead = malloc(sizeof(struct node));
    // Exception handling of what if the stack is full 
    // and no more memory can allocated
    if(nexthead == NULL){
        printf("Memory allocation failed. \n");
        return head;
    }
    nexthead->val = value;
    nexthead->next = head;
    return nexthead;
}

void insertionatbetween(struct node *head, int position,int value){
    struct node *ptr = malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Memory allocation failed. \n");
        return;
    }
    struct node *current = head;
    for(int i = 0; i<position-1 && current != NULL; i++){
        current = current->next;
    }
    if(current == NULL){
        printf("Enter valid position for insertion.\n");
        free(ptr);
        return;
    }
    ptr->val = value;
    ptr->next = current->next;
    current->next = ptr;
}

struct node * insertionatend(struct node *head, int value){
    struct node *ptr = malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Memory allocation failed. \n");
        return head;
    }
    struct node *current = head;
    ptr->val = value;
    ptr->next = NULL;
    if(head == NULL){
        return ptr;
    }
    while(current->next != NULL){
        current = current->next;
    }
    current->next = ptr;

    return head;
}

struct node *deleteatbeginning(struct node *head, int value){
    struct node *nexthead = malloc(sizeof(struct node));
    // Exception handling of what if the stack is full 
    // and no more memory can allocated
    if(nexthead == NULL){
        printf("Memory allocation failed. \n");
        return head;
    }
    nexthead->val = value;
    nexthead->next = head;
    return nexthead;
}


int main(){

    struct node *one = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node *three = malloc(sizeof(struct node));
    struct node *four = malloc(sizeof(struct node));
    struct node *five = malloc(sizeof(struct node));

    one->val = 1;
    one->next = two;
    two->val = 2;
    two->next = three;
    three->val = 3;
    three->next = four;
    four->val = 4;
    four->next = five;
    five->val = 5;
    five->next = NULL;

    traversel(one);
    // one = insertionatbeginning(one, 0);
    //insertionatbetween(one, 36, 34);
    //printf("Traversal after insertion of values : \n");
    printf("Traversal after insertion of values : \n");
    one = insertionatend(one, 6);
    traversel(one);
    
    return 0;
}
