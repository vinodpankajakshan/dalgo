#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;
struct Node* prev;
struct Node* tail;

// linked list insert
// Insert happens in the head
void EnQueue(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = NULL;

    if(head == NULL && tail == NULL && prev == NULL){
        temp->next = NULL;
        head = tail = prev = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

// linked list delete
void DeQueue() {
    if(head == tail){
        head = tail = NULL;
        return;
    }
}

void print() {
    struct Node* temp = head;
    printf("tail: %d", (int)tail);

    while(temp) {
        printf("--> (%d, %d, %d)%d\n",(int)temp->prev, temp->data, (int)temp->next, (int)temp);
        if (temp == tail) {
            printf("hit the tail. temp: %d, tail: %d\n", (int)temp, (int)tail);
        }
        temp = temp->next;
    }
}

int main() {
    EnQueue(5);  print();
    EnQueue(10); print();
    EnQueue(3);  print();
    EnQueue(23); print();
}
