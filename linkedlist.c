#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* head;

void insertLast(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = NULL;

    if (head != NULL) { 
        struct Node* temp1 = head;
        while (temp1->link != NULL) {
            temp1 =  temp1->link;
        }
        temp1->link = temp;
        return;
    }
    head = temp;
}

void insertFirst(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = x;           //Dereferencing - Alternate syntax - temp->data = data;
    (*temp).link = head;        //Dereferencing - Alternate syntax - temp->link = head;

    head = temp;
}

//TODO: check for valid position
void insertAt(int x, int pos) {
    if (pos == 1){
        insertFirst(x);
        return;
    }

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;

    struct Node* temp1 = head;
    for (int i=0 ; i < pos-2 ; i++) {
        temp1 = temp1->link;
    }
    temp->link = temp1->link;
    temp1->link = temp;
}

//TODO: check for valid position
void deleteAt(int pos) {
    struct Node* temp = head;

    if (pos == 1) {
        head = temp->link;
        free(temp);
        return;
    }
    for (int i=0; i < pos-2; i++) {
        temp = temp->link;
    }
    struct Node* temp1 = temp->link;
    temp->link = temp1->link;
    free(temp1);
}

void reverse_list() {
    struct Node *prev = NULL;
    struct Node *next = NULL;
    struct Node *temp = head;

    while(temp){
        if (temp->link != NULL) {
            struct Node *temp1 = temp->link;
            next = temp1->link;
            temp1->link = temp;
            temp->link = prev;
            prev = temp1;
            temp = next;
        } else{
            return;
        }
    }
    head = prev;
}

void reverse() {
    struct Node* prev = NULL;
    struct Node* next = NULL;
    struct Node* current = head;

    while(current) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// function that starts with 'r' is recursive
struct Node* rreverse(struct Node* current, struct Node* prev, struct Node* next){
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;

    if (next == NULL) {
        return prev;
    }
    return rreverse(current, prev, next);
}

// Recursively reversing linked list. 
void rrreverse(struct Node* node) {
    if(node->link == NULL) {
        head = node;
        return;
    }
    rrreverse(node->link);
    struct Node* temp = node->link;         // node->link->link = node;
    temp->link = node;
    node->link = NULL;
}

void print() {
    struct Node* temp1 = head;
    printf("list: ");

    while(temp1){
        printf(" -> %d, %d (%d)",temp1->data, (int)temp1->link, (int)temp1);
        temp1 = temp1->link;
    }
    printf("\n");
}

void rprint(struct Node* node) {
    if(node == NULL) {
        printf("\n");
        return;
    }
    printf(" -> %d, %d (%d)", node->data, (int)node->link, (int)node);
    return rprint(node->link);
}

void rReversePrint(struct Node* node) {
    if (node == NULL) {
        printf("\n");
        return;
    }
    rReversePrint(node->link);
    printf(" => %d, %d (%d)", node->data, (int)node->link, (int)node);
}

void testInsertAt(){
    printf("----Insert At testing Begins----\n");
    insertLast(1);
    insertLast(2);
    insertLast(4);
    print();
    insertAt(3,3);
    print();
    insertAt(0,1);
    print();
    insertAt(5,6);
    print();
    printf("----Insert At testing Ends----\n");
}


void testDeleteAt() {
    printf("----Delete At testing Begins----\n");
    print();
    deleteAt(4); print();
    deleteAt(1); print();
    deleteAt(4); print();
    printf("----Delete At testing Ends----\n");
}

int main() {
    head = NULL;
    insertFirst(5);
    insertFirst(6);
    insertFirst(4);
    insertFirst(2);
    //print();
    rprint(head);
    rrreverse(head);
    rprint(head);
    // reverseLinkedList();
    // reverse();
    // head = rreverse(head, NULL, NULL);
    rReversePrint(head);
    // print();
    /* int no, ou;
    printf("How many input(s): ");
    scanf("%d", &no);

    for (int i=0; i < no; i++) {
        printf("Enter the %d input: ", i + 1);
        scanf("%d", &ou);
        insertFirst(ou);
        print();
    }*/
}
