//Incomplete. Double check soon
#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V) {
    for (int i = 0; i < MAX; i++) {
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
    V->avail = 0;
}

int allocSpace(VHeap *V) {
    if (V->avail == -1) return -1;

    int index = V->avail;
    V->avail = V->H[index].next;

    return index;
}

void deallocSpace(VHeap *V, int index) {
    if (index < 0) return;
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int *L, VHeap *V, int elem) {
    if (V->avail == -1) return;

    int index = allocSpace(V);
    V->H[index].elem = elem;
    V->H[index].next = *L;
    *L = index;
}

void insertLast(int *L, VHeap *V, int elem) {
    if (V->avail == -1) return;

    int index = allocSpace(V);
    V->H[index].next = -1;
    V->H[index].elem = elem;

    if (*L == -1) {
        *L = index;
    } else {
        int trav = *L;
        while (V->H[trav].next != -1) {
            trav = V->H[trav].next;
        }
        V->H[trav].next = index;
    }
}

void insertPos(int *L, VHeap *V, int elem, int pos) {
    if (V->avail == -1) return;

    int index = allocSpace(V);
    V->H[index].elem = elem;

    // insert at head
    if (pos <= 0 || *L == -1) {
        V->H[index].next = *L;
        *L = index;
        return;
    }

    // traverse to position-1 or end
    int trav = *L;
    for (int i = 0; i < pos - 1 && V->H[trav].next != -1; i++) {
        trav = V->H[trav].next;
    }

    V->H[index].next = V->H[trav].next;
    V->H[trav].next = index;
}

void insertSorted(int *L, VHeap *V, int elem) {
    if (V->avail == -1) return;

    int index = allocSpace(V);
    V->H[index].elem = elem;

    if (*L == -1 || V->H[*L].elem > elem) {
        V->H[index].next = *L;
        *L = index;
    } else {
        int trav = *L;
        while (V->H[trav].next != -1 && V->H[V->H[trav].next].elem < elem) {
            trav = V->H[trav].next;
        }
        V->H[index].next = V->H[trav].next;
        V->H[trav].next = index;
    }
}

void deleteElem(int *L, VHeap *V, int elem) {
    if (*L == -1) return;

    int trav = *L, prev = -1;
    while (trav != -1 && V->H[trav].elem != elem) {
        prev = trav;
        trav = V->H[trav].next;
    }
    if (trav == -1) return; // not found

    if (trav == *L) {
        *L = V->H[trav].next;
    } else {
        V->H[prev].next = V->H[trav].next;
    }
    deallocSpace(V, trav);
}

void deleteAllOccurrence(int *L, VHeap *V, int elem) {
    while (*L != -1 && V->H[*L].elem == elem) {
        int temp = *L;
        *L = V->H[temp].next;
        deallocSpace(V, temp);
    }

    int trav = *L;
    while (trav != -1 && V->H[trav].next != -1) {
        int next = V->H[trav].next;
        if (V->H[next].elem == elem) {
            V->H[trav].next = V->H[next].next;
            deallocSpace(V, next);
        } else {
            trav = V->H[trav].next;
        }
    }
}

void display(int L, VHeap V) {
    printf("List: ");
    while (L != -1) {
        printf("%d -> ", V.H[L].elem);
        L = V.H[L].next;
    }
    printf("NULL\n");
}

int insertElementText() {
    int element;
    printf("Enter element: ");
    scanf("%d", &element);
    return element;
}

int insertPositionText() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    return pos;
}

int main() {
    VHeap V;
    int L = -1;
    initialize(&V);

    char textMenu[8][50] = {
        "Insert first", 
        "Insert last", 
        "Insert at a position", 
        "Insert sorted", 
        "Delete", 
        "Delete all occurrence", 
        "Display", 
        "Exit"
    };

    int choice = -1, value, pos;

    do {
        printf("\n----------------- Cursor Based List Variation 1 -----------------\n");
        for (int i = 0; i < 8; i++) {
            printf("[%d] %s\n", i + 1, textMenu[i]);
        }
        printf("Input option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                value = insertElementText();
                insertFirst(&L, &V, value);
                break;
            case 2:
                value = insertElementText();
                insertLast(&L, &V, value);
                break;
            case 3:
                value = insertElementText();
                pos = insertPositionText();
                insertPos(&L, &V, value, pos);
                break;
            case 4:
                value = insertElementText();
                insertSorted(&L, &V, value);
                break;
            case 5:
                value = insertElementText();
                deleteElem(&L, &V, value);
                break;
            case 6:
                value = insertElementText();
                deleteAllOccurrence(&L, &V, value);
                break;
            case 7:
                display(L, V);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 8);

    return 0;
}
