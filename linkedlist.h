#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
    int data;
    struct Node* next;
} Node_t;

typedef struct LinkedList{
    Node_t* head;
}LinkedList_t;

void printLinkedList (LinkedList_t* list);
Node_t* createNode(int data);
LinkedList_t* createEmptyList();
LinkedList_t* insertAtHead( LinkedList_t* list, int data);
void insertAtTail( LinkedList_t* list, int data);


#endif // LINKEDLIST_H