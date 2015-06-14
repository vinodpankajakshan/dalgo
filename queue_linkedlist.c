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
// Deletes from the end
void DeQueue() {
    if(tail == NULL || head == NULL){
        printf("Queue is empty\n");
        return;
    }
    else if(head == tail) {
        free(tail);
        return;
    }
    else {
        struct Node* temp = tail->prev;

        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}

void print() {
    struct Node* temp = head;

    while(temp) {
        printf("--> (%d, %d, %d)%d ",(int)temp->prev, temp->data, (int)temp->next, (int)temp);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    EnQueue(5);  print();
    EnQueue(10); print();
    EnQueue(3);  print();
    EnQueue(23); print();
    printf("\n=====DeQueue Ops=====\n");
    DeQueue();   print();
    DeQueue();   print();
    DeQueue();   print();
    DeQueue();   print();
}
