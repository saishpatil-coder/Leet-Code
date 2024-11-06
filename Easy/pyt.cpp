#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* head = NULL;
node* temp = NULL;
node* pre_node = NULL;

void insert_start() {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Overflow! Unable to insert.\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Data %d inserted at start.\n", newnode->data);
}

void insert_end() {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Overflow! Unable to insert.\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    printf("Data %d inserted at end.\n", newnode->data);
}

void insert_position() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insert_start();
        return;
    }

    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Overflow! Unable to insert.\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    temp = head;
    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (i == pos-1) {
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Data %d inserted at position %d.\n", newnode->data, pos);
    } else {
        printf("Invalid position.\n");
        free(newnode);
    }
}

void delete_start() {
    if (head == NULL) {
        printf("Underflow! No element to delete.\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("Data %d deleted from start.\n", temp->data);
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("Underflow! No element to delete.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Data %d deleted from end.\n", head->data);
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("Data %d deleted from end.\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_position() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_start();
        return;
    }

    temp = head;
    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (i == pos-1) {
        node* del_node = temp->next;
        temp->next = del_node->next;
        printf("Data %d deleted from position %d.\n", del_node->data, pos);
        free(del_node);
    } else {
        printf("Invalid position.\n");
    }
}

void display() {
    if (head == NULL) {
        printf("No elements in the list.\n");
        return;
    }

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    do {
        printf("\n1) Insert at start\n2) Insert at end\n3) Insert at position\n4) Delete at start\n5) Delete at end\n6) Delete at position\n7) Display\n8) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_start(); break;
            case 2: insert_end(); break;
            case 3: insert_position(); break;
            case 4: delete_start(); break;
            case 5: delete_end(); break;
            case 6: delete_position(); break;
            case 7: display(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
