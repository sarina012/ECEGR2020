#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    float information;
    struct Queue* nextElement;
} Queue;

Queue* element1 = NULL;
Queue* newElementueue(float in){
    Queue* newElement = (Queue*)malloc(sizeof(Queue));
    if (newElement != NULL){
        newElement->information = in;
        newElement->nextElement = NULL;
    }
    return newElement;
}
 
int size() {
    Queue* node = element1;
    int count = 0;
    while(node != NULL){
        count++;
        node = node->nextElement;
    }
    return count;
}
 
int isEmpty() {
    return (element1 == NULL);       
}
 
int isFull() {
    return (malloc(sizeof(Queue)) == NULL);  
}
 
int insert(float x){
    if (isFull()){
        printf("Queue Full!\n");
        return -1;
    }
    Queue* newNode = newElementueue(x); 
    printf("Entering a new element %f\n", x);

    if(element1 == NULL){
        element1 = newNode;
        return 0;
    }
    Queue* currentNode = element1;
    while(currentNode->nextElement != NULL){
        currentNode = currentNode->nextElement;
    }
    currentNode->nextElement = newNode;
    newNode->nextElement = NULL;
    
    return 0;
}
 
int removeQueue(){
    if (isEmpty()) {
        printf("Queue Empty!\n");
        return -1;
    }
    printf("Removing an element %f\n", element1->information);
    Queue* temp = element1;
    element1 = element1->nextElement;
    free(temp);
    return 0;
}
 
int peek(float* x){
    if (isEmpty()){
        printf("Queue Empty!\n");
        return -1;
    }
    *x = element1->information;
    return 0;
}
 
int main(){
    float  value;
 
    insert(1.0);
    insert(2.0);
    insert(3.0);
    printf("\nThe queue size is %d\n", size());
    peek(&value);
    printf("The top value in queue is %f\n\n", value);
    removeQueue();
    removeQueue();
    removeQueue();
 
    if (isEmpty()) {
        printf("The queue is now empty\n\n");
    }
    else {
        printf("The queue is not empty\n");
    }
 
    return 0;
}