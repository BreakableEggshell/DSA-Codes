#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 8
#define TEXT_MENU_CHOICES 4

typedef unsigned char Set; 

void initialize(unsigned char *set) {
    *set = 0;
}

bool isFull(unsigned char *set) {
    return (*set == 0xFF);
}

bool isEmpty(unsigned char *set) {
    return (*set == 0);
}

void insert(unsigned char *set, int element) {
    if(isFull(set)) {
        printf("Set is full\n");
        return;
    }

    unsigned char mask = 1 << element;
    *set |= mask;
}

void delete(unsigned char *set, int element) {
    if(isEmpty(set)) {
        printf("Set is empty\n");
        return;
    }

    unsigned char mask = 1 << element;
    *set &= ~mask;
}

int find(Set set, int element) {
    if(isFull(set)) return 0;

    return (set >> element) & 1;
}

Set setUnion(Set A) {

    return A;
}

void display(unsigned char set) {
    for(int i = 7; i >= 0; i--) {
        printf("%d", (set >> i) & 1);
    }
    printf(" / %u\n", set);
}



int main() {
    Set set;
    initialize(&set);

    char textMenu[TEXT_MENU_CHOICES][50] = {"Insert", "Delete", "Display", "Exit"};
    int choice = -1, value;

    do {
        printf("\n--------------- Array Bit Vector V1 ---------------\n");
        for(int i = 0; i < TEXT_MENU_CHOICES; i++) {
            printf("[%d] %s\n", i + 1, textMenu[i]);
        }
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Value to insert: ");
                scanf("%d", &value);
                insert(&set, value);
                break;
            case 2:
                printf("Value to delete from the set: ");
                scanf("%d", &value);
                delete(&set, value);
                break;
            case 3:
                display(set);
                break;
            case 4:
                printf("Exiting program...");
                return 0;
            default:
                printf("Invalid option.\n");

        }
    } while (choice != 0);
    display(set);

    return 0;
}
