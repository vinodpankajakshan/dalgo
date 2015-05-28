// Stack implementation using array

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 101 // Initial size of the stack
int stack[MAX_SIZE];
int top = -1; // Emtpy stack

bool IsEmpty() {
    if(top == -1) return true;
    else return false;
}

//TODO: implement dynamic memory allocation incase of stack overflow
void push(int data) {
    if(IsEmpty()) top = 0;

    if(top == MAX_SIZE - 1){
        printf("Error: StacK Overflow\n");
    }
    stack[++top] = data;
    printf("Push successful\n");
}

int pop() {
    //TODO: If stack is empty throw error message instead of returning -1
    // -1 maybe valid value in the stack
    int out = -1;

    if(!IsEmpty()) {
        out = stack[top];
        top--;
        printf("Pop successful\n");
    }
    printf("Stack is empty\n");
    return out;
}

int Top() {
    if(!IsEmpty()) {
        return stack[top];
    }
    printf("Stack is empty\n");
    return -1;
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
                push(input);
                printf("\n");
                break;

            case 2:
                printf("%d is poped from stack\n\n",pop());
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
