/*
Reverse a string using stack
*/
#include<stdio.h>
#include<stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top;

void Push(char data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = data;
    temp->next = top;
    top = temp;
}

void Pop(){
    if (top == NULL) return;
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

char Top(){
    if(top == NULL) return '\0';
    return top->data;
}

void reverse(char str[], int length){
    for(int i = 0; i < length; i++){
        Push(str[i]);
    }

    int count = 0;
    struct Node* temp = top;
    while(temp){
        str[count] = Top();
        Pop();
        count++;
        temp = temp->next;
    }
    for(int j = 0; j < length; j++){
        printf("%c", str[j]);
    }
    printf("\n");

}

int main(){
    char str[] = "rytvidu";
    reverse(str, 7);
    return 0;
}
