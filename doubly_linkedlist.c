#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* getNewNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

void InsertAtHead(int data){
    struct Node* node = getNewNode(data);

    if(head){
        node->next = head;
        head->prev = node;
        head = node;
        return;
    }
    head = node;
}

void InsertAtTail(int data){
    struct Node* node = getNewNode(data);

    if(head == NULL) {
        head = node;
        return;
    }
    struct Node* temp = head;
    while(temp->next){ temp = temp->next; }
    temp->next = node;
    node->prev = temp;
}

void print(){
    struct Node* node = head;
    
    printf("list: ");
    while(node){
        printf(" ==> %d %d, %d  (%d)", (int)node->prev, node->data, (int)node->next, (int)node);
        node = node->next;
    }
    printf("\n");
}

int main() {
    head = NULL;

    InsertAtHead(9); print();
    InsertAtTail(4); print();
    InsertAtHead(7); print();
    InsertAtTail(8); print();
    InsertAtTail(3); print();
    InsertAtHead(10); print();
}
