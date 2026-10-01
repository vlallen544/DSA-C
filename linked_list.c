#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

void traversel(struct node *head){
    struct node *current = head;
    int i = 1;
    while(current != NULL) {
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

struct node *deleteatbeginning(struct node *head){
    if(head == NULL){
        printf("lineked list is empty\n");
        return NULL;
    }
    struct node *ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
}

struct node * deleteatbetween(struct node *head, int position){
    struct node *current = head;
    if(current == NULL){
        printf("lineked list is empty\n");
        return NULL;
    }
    if(position <= 1){
        printf("Invalid position\n");
        return head;
    }
    for(int i = 0; i<position-1 && current != NULL; i++){
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Invalid position\n");
        return head;
    }

    struct node *temp = current->next;
    current->next = temp->next;
    free(temp);

    return head;
}

struct node * deletionatend(struct node * head){
    struct node *current = head;
    if(current == NULL){
        printf("lineked list is empty\n");
        return NULL;
    }
    while(current->next->next != NULL){
        current = current->next;
    }

    struct node *temp = current->next;
    current->next = NULL;
    free(temp);

    return head;
}

void searching(struct node *current1, int value){
    struct node *current = current1;
    int i = 0;
    while(current != NULL){
        if(current->val == value){
            printf("found %d at %d position of the linked list", value, i+1);
        }
        i++;
        current = current->next;
    }
}

int main(){

    struct node *one = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node *three = malloc(sizeof(struct node));
    struct node *four = malloc(sizeof(struct node));
    struct node *five = malloc(sizeof(struct node));

    one->val = 1;
    one->next = two;
    two->val = 3;
    two->next = three;
    three->val = 2;
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
    // one = insertionatend(one, 6);
    // traversel(one);
    // printf("Traversal after deletion of values at beginning : \n");
    // one = deleteatbeginning(one);
    // traversel(one);
    // printf("Traversal after deletion of values in between : \n");
    // one = deleteatbetween(one, 3);
    // traversel(one);
    // printf("Traversal after deletion of values at end : \n");
    // one = deletionatend(one);
    // traversel(one);

    searching(one, 2);
    
    return 0;
}
