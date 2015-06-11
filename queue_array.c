#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool IsEmpty(){
    if(front == -1 && rear == -1)
        return true;
    return false;
}

bool IsFull(){
    if(((1+rear) % MAX_SIZE) == front)
        return true;
    return false;
}

void EnQueue(int x){
    if(IsEmpty()){
        front = rear = 0;
    }
    else if(IsFull()){
        printf("Queue is full\n");
        return;
    }
    else
        rear = (1+rear) % MAX_SIZE;

    queue[rear] = x;
}

int DeQueue(){
    if(IsEmpty()){
        printf("Queue is empty\n");
        return -1;
    }
    int out = queue[front];

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;

    return out;
}

void print(int out){
    if(out == -1)
        printf("front - %d, rear - %d, front value - %d\n", front, rear, queue[rear]);
    else
        printf("front - %d, rear - %d, Dequeued value - %d\n", front, rear, out);
}

void insert(){
    int minusOne = -1;
    EnQueue(5);  print(minusOne);
    EnQueue(3);  print(minusOne);
    EnQueue(12); print(minusOne);
    EnQueue(9);  print(minusOne);
    EnQueue(3);  print(minusOne);
    EnQueue(4);  print(minusOne);

    int out;
    out = DeQueue(); print(out);

    EnQueue(10); print(minusOne);

    out = DeQueue(); print(out);
    
    EnQueue(32); print(minusOne);
}

int main(){
    insert();
}
