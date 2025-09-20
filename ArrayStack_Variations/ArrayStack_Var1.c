#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack *initialize() {
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    temp->top = -1;
    return temp;
}

bool isFull(Stack* s) {
    if(s->top == MAX - 1) {
        printf("Array is full.\n");
        return true;
    }else {
        return false;
    }
}

bool isEmpty(Stack* s) {
    if(s->top == -1) {
        printf("Array is empty.\n");
        return true;
    }else {
        return false;
    }
}

void push(Stack* s, int value) {
    if(isFull(s)) {
        return;
    }
    
    (s->top)++;
    s->items[s->top] = value;
}

void pop(Stack* s) {
    if(isEmpty(s)) {
        return;
    }
    
    printf("Deleting the last number input.");
    (s->top)--;
}

int peek(Stack* s) {
    if(isEmpty(s)) {
        return -1;
    }
    return s->items[s->top];
}

void display(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("{");
    for(int i = 0; i <= s->top; i++) {
        printf("%d", s->items[i]);
        if(i + 1 <= s->top) {
            printf(", ");
        }
    }
    printf("}\n\n");
}

int main() {
    Stack *S = initialize();
    int option, value = 0;
    char textMenu[4][20] = {"Push", "Pop", "Peek", "Display"};
    
    do {
        printf("\n\n~~~~~~~~~~~~~Option~~~~~~~~~~~~~\n");
        for(int i = 0; i < 4; i++) {
            printf("[%d] %s\n", i + 1, textMenu[i]);
        }
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &value);
                push(S, value);
                break;
            case 2:
                pop(S);
                break;
            case 3:
                if(peek(S) == -1) {
                }else {
                    printf("The value at the top of the stack: %d\n", peek(S));
                }
                break;
            case 4:
                printf("Displaying the list:\n");
                display(S);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid number, please write another one.\n");
        }
    } while(option != 0);
    
    return 0;
}

