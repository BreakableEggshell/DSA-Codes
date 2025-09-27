#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List *initialize() {
    List *temp = (List *)malloc(sizeof(List));
    if(!temp) {
        printf("Memory allocation in initialize() failed.\n");
        exit(1);
    }
    
    temp->head = NULL;
    temp->count = 0;
    return temp;
}

void empty(List *list) {
    Node *trav = list->head;
    Node *trav2;
    
    while(trav != NULL) {
        trav2 = trav;
        trav = trav->next;
        free(trav2);
    }
    
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data) {
    Node *newItem = (Node *)malloc(sizeof(Node));
    if(!newItem) {
        printf("Memory allocation in insertFirst() failed.\n");
        exit(1);
    }
    newItem->data = data;
    newItem->next = list->head;
    list->head = newItem;
    (list->count)++;
}

void insertLast(List *list, int data) {
    if(list == NULL || list->head == NULL) {
        insertFirst(list, data);
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) {
        printf("Memory allocation in insertLast() failed.\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->next = NULL;
    (list->count)++;
    
    Node *trav = list->head;
    
    while(trav->next != NULL) {
        trav = trav->next;
    }
    trav->next = newNode;
}

void insertPos(List *list, int data, int index) {
    if(index < 0 || index > list->count) {
        printf("Invalid index.\n");
        return;
    }
    if(index == list->count) {
        insertLast(list, data);
        return;
    }
    if(list->head == NULL || index == 0) {
        insertFirst(list, data);
        return;
    }
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) {
        printf("Memory allocation in insertPos() failed.\n");
        exit(1);
    }
    newNode->data = data;
    
    Node *trav = list->head;
    for(int i = 0; i < index - 1; i++) {
        trav = trav->next;
    }
    
    newNode->next = trav->next;
    trav->next = newNode;
    
    (list->count)++;
}

void deleteStart(List *list) {
    if(list == NULL || list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    (list->count)--;
}

void deleteLast(List *list) {
    if(list == NULL || list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if(list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->count--;
        return;
    }
    
    Node *temp = list->head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
    (list->count)--;
}

void deletePos(List *list, int index) {
    if(list == NULL || list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if(index < 0 || index >= list->count) {
        printf("Invalid index.\n");
        return;
    }
    
    if(index == 0) {
        deleteStart(list);
        return;
    }
    
    Node *temp = list->head;
    Node *temp2;
    for(int i = 0; i < index; i++) {
        temp2 = temp;
        temp = temp->next;
    }
    
    temp2->next = temp->next;
    free(temp);
    
    (list->count)--;
}

int retrieve(List *list, int index) {
    if(list == NULL || list->head == NULL) {
        printf("List is empty.\n");
        return -1;
    }
    if(index < 0 || index >= list->count) {
        printf("Index is invalid.\n");
        return -1;
    }
    
    Node *trav = list->head;
    for(int i = 0; i < index; i++) {
        trav = trav->next;
    }
    
    return trav->data;
}

int location(List *list, int data) {
    if(list == NULL || list->head == NULL) return -1;
    
    Node *trav = list->head;
    int i = 0;
    while(trav != NULL && trav->data != data) {
        trav = trav->next;
        i++;
    }
    
    return (trav == NULL) ? -1 : i;
}

void display(List *list) {
    printf("Items in list:\n{");
    for(Node *trav = list->head; trav != NULL; trav = trav->next) {
        printf("%d", trav->data);
        if(trav->next != NULL) {
            printf(" -> ");
        }
    }
    printf("}\n");
}

int main() {
    List *L = initialize();
    char textMenu[10][20] = {"Insert First", "Insert Last", "Insert Position", "Delete Start",
                            "Delete Last", "Delete Position", "Retrieve", "Locate", "Display",
                            "Exit"
    };
    int choice = -1, data, index, temp;
    
    while(choice != 10) {
         printf("\n~~~~~~~~~~~~~~~~~~~~Linked List Variation 2~~~~~~~~~~~~~~~~~~~~\n");
        for(int i = 0; i < 10; i++) {
            printf("[%d] %s\n", i + 1, textMenu[i]);
        }
        printf("Your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1:
                printf("Insert item to be inserted at the first: ");
                scanf("%d", &data);
                insertFirst(L, data);
                break;
            case 2:
                printf("Insert item to be inserted at the last: ");
                scanf("%d", &data);
                insertLast(L, data);
                break;
            case 3:
                printf("Item to be inserted: ");
                scanf("%d", &data);
                printf("Insert position to be inserted into (0-index): ");
                scanf("%d", &index);
                insertPos(L, data, index);
                break;
            case 4:
                printf("First item will be deleted.\n");
                deleteStart(L);
                break;
            case 5:
                printf("Last item will be deleted.\n");
                deleteLast(L);
                break;
            case 6:
                printf("Insert index to be deleted: ");
                scanf("%d", &index);
                deletePos(L, index);
                break;
            case 7:
                printf("Insert index to find data: ");
                scanf("%d", &index);
                temp = retrieve(L, index);
                if(temp <= -1) {
                    printf("Invalid index.\n");
                }else {
                    printf("Data at index %d: %d", index, temp);
                }
                break;
            case 8:
                printf("Locate data index: ");
                scanf("%d", &data);
                temp = location(L, data);
                if(temp > -1) printf("%d can be found at index %d", data, temp);
                break;
            case 9:
                display(L);
                break;
            case 10:
                empty(L);
                return 0;
            default:
                printf("Invalid option");
        }
    }
    return 0;
}