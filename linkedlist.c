#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
    LinkedList_t* list = createEmptyList();
    insertAtHead(list, 10);
    insertAtHead(list, 20);
    insertAtHead(list, 30);

    printLinkedList(list);
    reverseLinkedList(list);
    printLinkedList(list);
    insertAtTail(list, 40);
    insertAtTail(list, 50);
    insertAtTail(list, 60);
    printLinkedList(list);
    deleteNodeAtHead(list);
    printLinkedList(list);
    
    deleteList(list);

    return 0;
}

LinkedList_t* createEmptyList(){
    LinkedList_t* newList = (LinkedList_t*) malloc (sizeof(LinkedList_t));
    newList->head = NULL;
    return newList;
    
}

Node_t* createNode(int data){
    Node_t *newNode = (Node_t*) malloc (sizeof(Node_t));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void printLinkedList (LinkedList_t* list){
    Node_t *current = list->head;
    while( current!= NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

}

LinkedList_t* insertAtHead( LinkedList_t* list, int data){
    Node_t *newNode = createNode(data);
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    return list;
}

void insertAtTail( LinkedList_t* list, int data){
    Node_t *newNode = (Node_t*) malloc( sizeof(Node_t));
    newNode -> data = data;
    newNode -> next = NULL;
    Node_t *current = list->head;
    while( current -> next != NULL ){
        current = current -> next;
    }
    current -> next = newNode;
}

void deleteList(LinkedList_t* list){
    Node_t* current = list->head;
    while(current!=NULL){
        Node_t*temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

void deleteNodeAtHead(LinkedList_t* list){
    Node_t* temp = list->head;
    Node_t* head = temp->next;
    list->head = head;
    free(temp);
}
void reverseLinkedList(LinkedList_t* list){

    Node_t *current = list->head;
    Node_t *prev = NULL;
    while(current!=NULL){
        Node_t* next = current->next;
        current->next = prev;
        prev = current;
        list->head = current;
        current = next;
        
    }  
}