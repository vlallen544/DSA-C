#include <stdio.h>
#include <stdlib.h>

struct stack {
    int arr[100];
    int top;
};

int isempty(struct stack* stack1){
    if(stack1->top == -1){
        return 1;
    }
    return 0;
}

int isfull(struct stack* stack1){
    if(stack1->top == 99){
        return 1;
    }
    return 0;
}

void display(struct stack* stack1){
    for(int i = 0; i<=stack1->top; i++){
        printf("%d value of the array is %d\n", i, stack1->arr[i]);
    }
}

void push(struct stack* stack1, int val){
    if(stack1->top == 99){
        printf("stack overflow");
        return;
    }
    else{
        stack1->top++;
        stack1->arr[stack1->top] = val;
    }
}

int pop(struct stack* stack1){
    if(stack1->top == -1){
        printf("stack underflow");
        return 0;
    }
    else{
        int popped = stack1->arr[stack1->top];
        stack1->top--;
        return popped;
    }
}

// peek(), isempty(), isfull()

int peek(struct stack* stack1){
    if(isempty(stack1)){
        printf("stack is empty hence return is zero");
        return 0;
    }
    return stack1->arr[stack1->top];
}

int *reversing_a_array(int *arr, struct stack* stack2){
    int *arr2 = (int *)malloc(10*sizeof(int));
    for(int i = 0; i<10; i++){
        push(stack2, arr[i]);
    }
    for(int j = 0; j<10; j++){
        int popped = pop(stack2);
        arr2[j] = popped;
    }
    return arr2;
}

int main(){
    struct stack *stack1 = (struct stack*)malloc(sizeof(struct stack));
    stack1->top = -1;
    
    struct stack *stack2 = (struct stack*)malloc(sizeof(struct stack));
    stack2->top = -1;
    
    stack1->arr[0] = 0;
    stack1->top++;
    stack1->arr[1] = 1;
    stack1->top++;

    printf("----------------------------------\n");
    display(stack1);

    // pushing a value into the stack
    push(stack1, 2);
    printf("----------------------------------\n");
    printf("After pushing value into an array\n");
    display(stack1);

    // popping value out of the stack
    printf("----------------------------------\n");
    printf("After popping value of an array\n");
    int popped;
    popped = pop(stack1);
    printf("The popped value is %d\n", popped);
    printf("----------------------------------\n");
    display(stack1);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *arr2 = reversing_a_array(arr, stack2);
    printf("Reversed array is : \n");
    for(int i = 0; i<10; i++){
        printf("%d array element is %d\n", i, arr2[i]);
    }
    free(stack1);
}