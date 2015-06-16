#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;
struct Node* tail;

void EnQueue(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(head == NULL && tail == NULL) {
        head = tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

void DeQueue() {
    if(head == NULL) {
        printf("Queue is empty\n");
        return;
    } else if (head == tail) {
        free(head);
        return;
    }

    struct Node* temp = head->next;
    free(head);
    head = temp;
}

void print() {
    struct Node* temp = head;

    while(temp) {
        printf("--> (%d, %d)%d ", temp->data, (int)temp->next, (int)temp);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    EnQueue(5);  print();
    EnQueue(32); print();
    EnQueue(12); print();

    DeQueue();  print(); 
    DeQueue();  print();
    DeQueue();  print();
}
