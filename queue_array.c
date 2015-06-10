#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 10
int queue[MAX_SIZE];
int front, rear = -1;

bool IsEmpty(){
    if(front == -1 && rear == -1) return true;
    return false;
}

bool IsFull(){
    if(rear >= MAX_SIZE) return true;
    return false;
}

void EnQueue(int x){
    if(IsEmpty()) front = rear = 0;
    else rear++;

    queue[rear] = x;
}

int DeQueue(){
    if(IsEmpty()){
        printf("Queue is empty\n");
        return -1;
    }
    int out = queue[front];

    if(front == rear) front = rear = -1;
    else front++;

    return out;
}


int main(){
    EnQueue(5);
    printf("front - %d, rear - %d, front value - %d\n", front, rear, queue[rear]);
    EnQueue(12);
    printf("front - %d, rear - %d, front value - %d\n", front, rear, queue[rear]);
    EnQueue(3);
    printf("front - %d, rear - %d, front value - %d\n", front, rear, queue[rear]);
    // DeQueue
    printf("rear - %d, Dequeued - %d, front - %d\n", rear, DeQueue(), front);
}
