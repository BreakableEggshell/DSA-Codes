#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 8
#define TEXT_MENU_CHOICES 8

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

    unsigned char mask = (unsigned char)1u << element;
    *set |= mask;
    printf("Inserted");
}

void delete(unsigned char *set, int element) {
    if(isEmpty(set)) {
        printf("Set is empty\n");
        return;
    }

    unsigned char mask = (unsigned char)1u << element;
    *set &= ~mask;
}

bool find(Set set, int element) {
    return (set >> element) & 1u;
}

unsigned char setUnion(unsigned char A, unsigned char B) {
    return (A | B);
}

unsigned char intersection(unsigned char A, unsigned char B) {
    return (A & B);
}

unsigned char difference(unsigned char A, unsigned char B) {
    return (A & ~B);
}

void display(unsigned char set) {
    for(int i = 7; i >= 0; i--) {
        printf("%d", (set >> i) & 1);
    }
    printf(" / %u\n", set);
}

int main() {
    Set set[3];
    initialize(&set);

    char textMenu[TEXT_MENU_CHOICES][50] = {"Insert", "Delete", "Find", "Set union",
                                            "Set Intersection", "Difference", "Display", "Exit"};
    int choice = -1, value, setChoice = -1;

    do {
        printf("\n--------------- Array Bit Vector V1 ---------------\n");
        for(int i = 0; i < TEXT_MENU_CHOICES; i++) {
            printf("[%d] %s\n", i + 1, textMenu[i]);
        }
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Value to insert [MAX 8]: ");
                scanf("%d", &value);
                printf("Set you want to insert the element to: ");
                scanf("%d", &setChoice);

                insert(&set[setChoice], value);
                break;
            case 2:
                printf("Value to delete from the set [MAX 8]: ");
                scanf("%d", &value);
                printf("Set you want to find the element from: ");
                scanf("%d", &setChoice);

                delete(&set[setChoice], value);
                break;
            case 3:
                printf("Value to find from the set [MAX 8]: ");
                scanf("%d", &value);
                printf("Set you want to find the element from: ");
                scanf("%d", &setChoice);

                find(&set[setChoice], value);
                break;
            case 4:
                printf("Set A: ");
                display(set[0]);
                printf("Set B: ");
                display(set[1]);
                
                set[2] = setUnion(set[0], set[1]);
                printf("Union of the sets: ");
                display(set[2]);

                return 0;
                break;
            case 5:
                //intersection
                break;
            case 6:
                //Difference
            case 7:
                //Display
                break;
            case 8:
                printf("Exiting...\n");
                return;
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 9);
    display(set);

    return 0;
}
