#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    float information;
    struct Stack* next;
} Stack;
 
Stack* element1 = NULL;

Stack* newStack(float input){
    Stack* newElement = (Stack*) malloc(sizeof(Stack));
    if(newElement != NULL){
        newElement->information = input;
        newElement->next = NULL;
    }
    return newElement;
}
 
int size() {
    Stack* node = element1;
    int count = 0;
    while(node != NULL){
        count++;
        node = node->next;
    }
    return count;
}
 
int isEmpty() {
    return element1 == NULL;
}
 
int isFull() {
    return (malloc(sizeof(Stack)) == NULL);
}
 
int push(float x){
    if (isFull()){
        printf("Stack Full!\n");
        return -1;
    }    
    Stack* newElement2 = newStack(x);
    printf("Inserting %f\n", x);
    
    if(element1 == NULL){
        element1 = newElement2;
        return 0;
    }
    newElement2->next = element1;
    element1 = newElement2;
    return 0;
}
 
int pop(){
    if (isEmpty())
    {
        printf("Stack Empty!\n");
        return -1;
    }
    printf("Removing %f\n", element1->information);
    Stack* temp = element1;
    element1 = element1->next;
    free(temp);
    
    return 0;
}
 
int peek(float* x){
    if (isEmpty()){
        printf("Stack Empty!\n");
        return -1;
    }
    *x = element1->information;
    return 0;
}
 
int main(){
    float  value;
    push(1.0);
    push(2.0);
    push(3.0);
    printf("\nThe stack size is %d", size());
    peek(&value);
    printf("\nThe top value in the stack is %f\n\n", value);
    pop();
    pop();
    pop();
    if (isEmpty()) {
        printf("The stack is empty\n");
    }
    else {
        printf("The stack is not empty\n");
    }
    return 0;
}
