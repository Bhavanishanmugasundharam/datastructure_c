
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;


node* create_node(int value) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}


void insert_end(int value) {
    node* newnode = create_node(value);
    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}


void display() {
    node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void search(int key) {
    node* temp = head;
    if(head==NULL)
    {
        printf("list id empty");
    }
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found");
            return;
        }
        temp = temp->next;

    }
    printf("not found");
}

int main() {
    int n, value, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        insert_end(value);
    }

    display();

    printf("Enter element to search: ");
    scanf("%d", &key);
    search(key);

    return 0;
}


