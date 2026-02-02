#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"



int main(){
    
    return 0;
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