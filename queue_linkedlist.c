#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;
struct Node* tail;

// linked list insert
// Insert happens in the head
void EnQueue(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    if(head == NULL && tail == NULL){
        temp->next = NULL;
        head = tail = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

// linked list delete
void DeQueue() {
}

void print() {
    struct Node* temp = head;

    while(temp) {
        printf("--> val - %d, next - %d, current Addr - %d\n", temp->data, (int)temp->next, (int)temp);
        if (temp == tail) {
            printf("hit the tail\n");
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
