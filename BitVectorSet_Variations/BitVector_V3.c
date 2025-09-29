#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 8
#define TEXT_MENU_CHOICES 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set set) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        set[i] = 0;
    }
}

bool isFull(Set set) {
    for(int i = 0; i < 8; i++){
        if(set[i] == 0) {
            return false;
        }
    }
    return true;
}

bool isEmpty(Set set) {
    for(int i = 0; i < 8; i++) {
        if(set[i] == 1) {
            return false;
        }
    }
    return true;
}

bool isWithinBounds(int choice) {
    return (choice >= 0) && (choice < 8);
}

bool isWithinSetBounds(int choice) {
    return (choice == 1) || (choice == 2);
}

void insert(Set set, int element) {
    if(!isWithinBounds(element)) {
        printf("Element out of bounds\n");
        return;
    }
    if(isFull(set)) {
        printf("Set is full\n");
        return;
    }

    set[element] = 1;
}

void delete(Set set, int element) {
    if(!isWithinBounds(element)) {
        printf("Element out of bounds\n");
        return;
    }
    if(isEmpty(set)) {
        printf("Set is empty\n");
        return;
    }

    set[element] = 0;
}

bool find(Set set, int element) {
    if(!isWithinBounds(element)) {
        printf("Element out of bounds\n");
        return false;
    }

    return set[element] == 1;
}

void setUnion(Set A, Set B, Set C) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] || B[i];
    }
}

void setIntersection(Set A, Set B, Set C) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && B[i];
    }
}

void setDifference(Set A, Set B, Set C) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = (A[i] == 1) && (B[i] == 0);
    }
}

void display(Set set) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d", set[i]);
    }
    printf(" / {");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        if(set[i]) {
            printf("%d ", i);
        }
    }
    printf(" }\n");
}


int main() {
    Set set[3];
    for(int i = 0; i < 3; i++) {
        initialize(set[i]);
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
                printf("Value to insert (MAX %d): ", ARRAY_SIZE - 1);
                scanf("%d", &value);
                printf("Set you want to insert the element to (1 for A, 2 for B): ");
                scanf("%d", &setChoice);
                if(!isWithinSetBounds(setChoice)) {
                    printf("Invalid choice\n");
                    break;
                }

                insert(set[setChoice - 1], value);
                break;
            case 2:
                printf("Value to delete from the set (MAX %d): ", ARRAY_SIZE - 1);
                scanf("%d", &value);
                printf("Set you want to delete the element from (1 for A, 2 for B): ");
                scanf("%d", &setChoice);
                if(!isWithinSetBounds(setChoice)) {
                    printf("Invalid choice\n");
                    break;
                }

                delete(set[setChoice - 1], value);
                break;
            case 3:
                printf("Value to find from the set (MAX %d): ", ARRAY_SIZE - 1);
                scanf("%d", &value);
                printf("Set you want to find the element from (1 for A, 2 for B): ");
                scanf("%d", &setChoice);
                if(!isWithinSetBounds(setChoice)) {
                    printf("Invalid choice\n");
                    break;
                }

                if(find(set[setChoice - 1], value)) {
                    printf("Element found!\n");
                }else {
                    printf("Element not found!\n");
                }
                break;
            case 4:
                printf("-------------- Union Set --------------");
                printf("\nSet A: ");
                display(set[0]);
                printf("\nSet B: ");
                display(set[1]);
                
                setUnion(set[0], set[1], set[2]);
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

                setIntersection(set[0], set[1], set[2]);
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

                setDifference(set[0], set[1], set[2]);
                printf("\nDifference(A-B): ");
                display(set[2]);
                printf("\n");

                setDifference(set[1], set[0], set[2]);
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