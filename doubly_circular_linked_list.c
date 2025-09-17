
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;

node* createnode(int x) {
    node *newnode = (node*)malloc(sizeof(node));
    if (!newnode) {
        printf("Memory not allocated!\n");
        exit(1);
    }
    newnode->data = x;
    newnode->next = newnode->prev = NULL;
    return newnode;
}

void insert_begin(int x) {
    node *newnode = createnode(x);
    if (head == NULL) {
        head = newnode;
        head->next = head;
        head->prev = head;
    } else {
        node *last = head->prev;
        newnode->next = head;
        newnode->prev = last;
        head->prev = newnode;
        last->next = newnode;
        head = newnode;
    }
}

void insert_end(int x) {
    node *newnode = createnode(x);
    if (head == NULL) {
        head = newnode;
        head->next = head;
        head->prev = head;
    } else {
        node *last = head->prev;
        last->next = newnode;
        newnode->prev = last;
        newnode->next = head;
        head->prev = newnode;
    }
}

void deletenode(int x) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    node *temp = head;
    do {//search for node
        if (temp->data == x) {//only one node
            if (temp->next == temp) {
                free(temp);
                head = NULL;
                return;
            }
            node *prev = temp->prev;
            node *next = temp->next;
            prev->next = next;
            next->prev = prev;
            if (temp == head) head = next;
            free(temp);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Element %d not found!\n", x);
}

void search(int x) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    node *temp = head;
    int pos = 1;
    do {
        if (temp->data == x) {
            printf("Element %d found at position %d\n", x, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element %d not found!\n", x);
}

void display_forward() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    node *temp = head;
    printf("List (forward): ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void display_reverse() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    node *temp = head->prev;
    printf("List (reverse): ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("\n");
}

int main() {
    int choice, n, value;
    while (1) {
        printf("\n--- Doubly Circular Linked List ---\n");
        printf("1. Insert at Begin\n");
        printf("2. Insert at End\n");
        printf("3. Display Forward\n");
        printf("4. Display Reverse\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter value: ");
                scanf("%d", &value);
                insert_begin(value);
            }
            display_forward();
            break;
        case 2:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end(value);
            }
            display_forward();
            break;
        case 3:
            display_forward();
            break;
        case 4:
            display_reverse();
            break;
        case 5:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deletenode(value);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

