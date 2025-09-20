#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct List {
    int array[MAX];
    int count;
} List;

List initialize(List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    if(position > L.count || position < 0) {
        printf("Position must be between 0 and the count.\n");
        return L;
    }

    if(L.count >= 100) {
        printf("List is full.\n");
        return L;
    }

    for(int i = L.count; i > position; i--) {
        L.array[i] = L.array[i - 1];
    }

    L.count++;
    L.array[position] = data;
    
    return L;
}

List deletePos(List L, int position) {
    if(L.count == 0) {
        printf("Array list is empty.");
        return L;
    }

    for(int i = position; i < L.count - 1; i++) {
        L.array[i] = L.array[i + 1];
    }
    L.count--;
    return L;
}

int locate(List L, int data) {
    for(int i = 0; i < L.count; i++) {
        if(L.array[i] == data) {
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data) {
    if(L.count >= MAX) {
        printf("List is full.\n");
        return L;
    }
    int i = 0;
    while(i < L.count && L.array[i] < data) {
        i++;
    }
    
    L = insertPos(L, data, i);
    return L;
}

void display(List L) {
    printf("Items in list:\n{");
    for(int i = 0; i < L.count; i++) {
        printf("%d", L.array[i]);
        if((L.count - 1) > i) {
            printf(", ");
        }
    }
    printf("}\n");
}


int main() {
    List L = initialize(L);
    char textMenu[6][20] = {"Insert Position", "Delete Position", "Locate", "Insert Sorted", "Display", "Exit"};
    int choice = -1, position, data, temp;

    while(choice != 0) {
        printf("\n~~~~~~~~~~~~~~~~~~~~Array List Variation 1~~~~~~~~~~~~~~~~~~~~\n");
        for(int i = 0; i < 6; i++) {
            printf("[%d] %s\n", i + 1, textMenu[i]);
        }
        printf("Your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 0:
                return 0;
            case 1:
                printf("Insert number: ");
                scanf("%d", &data);
                printf("Insert position (must be less than or equal to %d): ", L.count);
                scanf("%d", &position);
                L = insertPos(L, data, position);
                break;
            case 2:
                printf("Position of number to be deleted (0-indexed): ");
                scanf("%d", &position);
                L = deletePos(L, position);
                break;
            case 3:
                printf("Item to look the position for: ");
                scanf("%d", &data);
                temp = locate(L, data);
                printf("The item is at position %d", L.array[temp]);
                break;
            case 4:
                printf("Array will be sorted and the item will be inserted.\nInsert item to be inserted: ");
                scanf("%d", &data);
                L = insertSorted(L, data);
            case 5:
                display(L);
                break;
            case 6:
                printf("Exiting program...");
                return 0;
            default:
                printf("Not an available option. \n");
        }
    }
    

    L = insertPos(L, 10, 0);


    printf("Test: %d", L.array[0]);
    return 0;
}