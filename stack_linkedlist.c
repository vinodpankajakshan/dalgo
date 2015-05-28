/*
Array implementation using linked list
Items are inserted to the beginning of the linked list in this implementation - Time complexity is O(1)
Time complexity to push to the end of linked list will be O(n)
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top;

bool IsEmpty() {
    if(top == NULL) return true;
    return false;
}

void Push(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = top;
    top = temp;
    printf("%d pushed into the stack\n", data);
}

void Pop() {
    if(IsEmpty()){
        printf("stack is empty\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("%d popped from the stack\n", top->data);
    free(temp);
}

int Top() {
    if(IsEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void PrintPrompt() {
    printf("> ");
}

int main() {
    int opt, input;

    do {
        printf("Options\n");
        printf("-------\n");
        printf("1. Push to stack\n");
        printf("2. Pop from stack\n");
        printf("3. Print the top\n");
        printf("4. Exit\n");
        PrintPrompt();

        scanf("%d", &opt);
        printf("\n");

        switch(opt) {
            case 1:
                printf("Enter the input\n");
                PrintPrompt();
                scanf("%d", &input);
                Push(input);
                printf("\n");
                break;

            case 2:
                Pop();
                break;

            case 3:
                printf("%d is on top of the stack\n\n", Top());
                break;

            case 4:
                printf("Exiting.... Bye!!! \n\n");
                break;

            default:
                printf("Wrong Option. Try again\n\n");
        }
    } while(opt < 4 || opt > 4);

    return 0;
}
