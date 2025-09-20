#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct List {
    int *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L) {
    L->count = 0;
    L->max = LENGTH;
    L->elemPtr = (int *)malloc(sizeof(int) * L->max);
    if(!L->elemPtr) {
        printf("Memory allocation failed in initialization.\n");
        exit(1);
    }
}

void insertPos(List *L, int data, int position) {
    if(position > L->count || position < 0) {
        printf("Position must be between 0 and the count.\n");
        return;
    }

    if(L->count >= L->max) {
        printf("List is full.\n");
        return;
    }

    for(int i = L->count; i > position; i--) {
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    (L->count)++;
    L->elemPtr[position] = data;
}

void deletePos(List *L, int position) {
    if(L->count == 0) {
        printf("Array list is empty.");
        return;
    }
    if(L->count <= position || position < 0) {
        printf("Invalid position.");
        return;
    }

    for(int i = position; i < L->count - 1; i++) {
        L->elemPtr[i] = L->elemPtr[i + 1];
    }
    (L->count)--;
}

int locate(List *L, int data) {
    for(int i = 0; i < L->count; i++) {
        if(L->elemPtr[i] == data) {
            return i;
        }
    }
    return -1;
}

void insertSorted(List *L, int data) {
    if(L->count >= L->max) {
        printf("List is full.\n");
        return;
    }
    
    for (int i = 0; i < L->count - 1; i++) {
        for (int j = 0; j < L->count - i - 1; j++) {
            if (L->elemPtr[j] > L->elemPtr[j + 1]) {
                int temp = L->elemPtr[j];
                L->elemPtr[j] = L->elemPtr[j + 1];
                L->elemPtr[j + 1] = temp;
            }
        }
    }
    
    int i = 0;
    while (i < L->count && L->elemPtr[i] < data) {
        i++;
    }
    
    insertPos(L, data, i);
}

void display(List *L) {
    printf("Items in list:\n{");
    for(int i = 0; i < L->count; i++) {
        printf("%d", L->elemPtr[i]);
        if((L->count - 1) > i) {
            printf(", ");
        }
    }
    printf("}\n");
}


int main() {
    List *L = (List *)malloc(sizeof(List));
    initialize(L);
    char textMenu[5][20] = {"Insert Position", "Delete Position", "Locate", "Insert Sorted", "Display"};
    int choice = -1, position, data, temp;

    while(choice != 0) {
        printf("\n~~~~~~~~~~~~~~~~~~~~Array List Variation 1~~~~~~~~~~~~~~~~~~~~\n");
        for(int i = 0; i < 5; i++) {
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
                printf("Insert position (must be less than or equal to %d): ", L->count);
                scanf("%d", &position);
                insertPos(L, data, position);
                break;

            case 2:
                printf("Position of number to be deleted (0-indexed): ");
                scanf("%d", &position);
                deletePos(L, position);
                
                break;

            case 3:
                printf("Item to look the position for: ");
                scanf("%d", &data);
                temp = locate(L, data);
                if(temp != -1) {
                    printf("The item is at position %d\n", temp);
                }else {
                    printf("Item not found.\n");
                }
                
                break;
            case 4:
                printf("Array is sorted in ascending order. Array will be sorted and the item will be inserted.\nInsert item to be inserted: ");
                scanf("%d", &data);
                insertSorted(L, data);
                break;
            case 5:
                display(L);
                break;
            default:
                printf("Not an available option. \n");
        }
    }
    insertPos(L, 10, 0);

    printf("Test: %d", L->elemPtr[0]);
    
    free(L->elemPtr);
    free(L);
    return 0;
}

