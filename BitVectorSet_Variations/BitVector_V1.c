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

bool isWithinBounds(int element) {
    return (element >= 1) && (element <= 8);
}

bool isWithinSetBounds(int choice) {
    return (choice == 1) || (choice == 2);
}

void insert(unsigned char *set, int element) {
    if(!isWithinBounds(element)) {
        printf("Element should be between 1 - %d\n", MAX);
        return;
    }
    if(isFull(set)) {
        printf("Set is full\n");
        return;
    }

    *set |= 1u << (element - 1);
    printf("Inserted");
}

void delete(unsigned char *set, int element) {
    if(!isWithinBounds(element)) {
        printf("Element should be between 1 - %d\n", MAX);
        return;
    }
    if(isEmpty(set)) {
        printf("Set is empty\n");
        return;
    }

    *set &= ~(1u << (element - 1));
}

bool find(Set set, int element) {
    if(!isWithinBounds(element)) {
        printf("Element should be between 1 - %d\n", MAX);
        return false;
    }
    return (set >> (element - 1)) & 1u;
}

unsigned char setUnion(unsigned char A, unsigned char B) {
    return (A | B);
}

unsigned char setIntersection(unsigned char A, unsigned char B) {
    return (A & B);
}

unsigned char setDifference(unsigned char A, unsigned char B) {
    return (A & ~B);
}

void display(unsigned char set) {
    for(int i = 7; i >= 0; i--) {
        printf("%d", (set >> i) & 1u);
    }

    printf("{ ");
    for(int i = 7; i >= 0; i--) {
        if(((set >> i) & 1u) == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("}");
}

int main() {
    Set set[3];
    for(int i = 0; i < 3; i++) {
        initialize(&set[i]);
    }
    
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
                printf("Value to insert (MAX %d): ", MAX);
                scanf("%d", &value);
                printf("Set you want to insert the element to (1 for A, 2 for B): ");
                scanf("%d", &setChoice);
                if(!isWithinSetBounds(setChoice)) {
                    printf("Invalid choice\n");
                    break;
                }

                insert(&set[setChoice - 1], value);
                break;
            case 2:
                printf("Value to delete from the set (MAX %d): ", MAX);
                scanf("%d", &value);
                printf("Set you want to delete the element from (1 for A, 2 for B): ");
                scanf("%d", &setChoice);
                if(!isWithinSetBounds(setChoice)) {
                    printf("Invalid choice\n");
                    break;
                }

                delete(&set[setChoice - 1], value);
                break;
            case 3:
                printf("Value to find from the set (MAX %d): ", MAX);
                scanf("%d", &value);
                printf("Set you want to find the element from (1 for A, 2 for B): ");
                scanf("%d", &setChoice);
                if(!isWithinSetBounds(setChoice)) {
                    printf("Invalid choice\n");
                    break;
                }

                if(find(set[setChoice - 1], value)) {
                    printf("Element found in set\n");
                }else {
                    printf("Element not found in set\n");
                }
                break;
            case 4:
                printf("-------------- Union Set --------------");
                printf("\nSet A: ");
                display(set[0]);
                printf("\nSet B: ");
                display(set[1]);
                
                set[2] = setUnion(set[0], set[1]);
                printf("\nUnion: ");
                display(set[2]);
                printf("\n");
                break;
            case 5:
                printf("-------------- Intersection Set --------------");
                printf("\nSet A: ");
                display(set[0]);
                printf("\nSet B: ");
                display(set[1]);

                set[2] = setIntersection(set[0], set[1]);
                printf("\nIntersection: ");
                display(set[2]);
                printf("\n");
                break;
            case 6:
                printf("-------------- Difference Set --------------");
                printf("\nSet A: ");
                display(set[0]);
                printf("\nSet B: ");
                display(set[1]);

                set[2] = setDifference(set[0], set[1]);
                printf("\nDifference(A-B): ");
                display(set[2]);
                printf("\n");

                set[2] = setDifference(set[1], set[0]);
                printf("\nDifference(B-A): ");
                display(set[2]);
                printf("\n");
                break;
            case 7:
                printf("\nSet A: ");
                display(set[0]);
                printf("\nSet B: ");
                display(set[1]);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 8);
    return 0;
}
