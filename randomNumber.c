#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Add node to the end of the linked list
struct Node* addNode(struct Node* head, int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    if (head == NULL) {
        head = node;
    } else {
        struct Node* cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
    }
    return head;
}

// Bubble sort
struct Node* bubble_sort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node* cur = head;
    while (cur != NULL) {
        struct Node* ptr = cur->next;
        while (ptr != NULL) {
            if (cur->data > ptr->data) {
                int temp = cur->data;
                cur->data = ptr->data;
                ptr->data = temp;
            }
            ptr = ptr->next;
        }
        cur = cur->next;
    }
    return head;
}

// Delete odd numbers from the linked list
struct Node* delete_odd(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    while (head != NULL && head->data % 2 != 0) {
        head = head->next;
    }
    struct Node* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->data % 2 != 0) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

// Create a linked list with random numbers
struct Node* create_list(int size) {
    struct Node* head = NULL;
    for (int i = 0; i < size; i++) {
        int data = rand() % 100 + 1;
        head = addNode(head, data);
    }
    return head;
}

// Print linked list
void print_list(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main program
int main() {
    // Create linked list with 10 random numbers
    int size = 10;
    struct Node* linked_list = create_list(size);
    printf("Original list: ");
    print_list(linked_list);
    
    // Sort linked list
    struct Node* sorted_list = bubble_sort(linked_list);
    printf("Sorted list: ");
    print_list(sorted_list);
    
    // Delete odd numbers from linked list
    struct Node* odd_deleted_list = delete_odd(sorted_list);
    printf("Odd deleted list: ");
    print_list(odd_deleted_list);
    
    return 0;
}
