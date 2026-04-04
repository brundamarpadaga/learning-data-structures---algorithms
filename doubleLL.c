#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node_t;

typedef struct LinkedList{
    Node_t* head;
}LinkedList_t;


Node_t* createNode(int data){
    Node_t* newNode = (Node_t*) malloc(sizeof(Node_t));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

LinkedList_t* createEmptyList(){
    LinkedList_t* newList = (LinkedList_t*) malloc(sizeof(LinkedList_t));
    newList->head = NULL;
    return newList;
}

void addAtHead(LinkedList_t* list, Node_t* node){
    if(list->head == NULL){
        list->head = node;
        return;
    }
    Node_t* head = list->head;
    node->next = list->head;
    head->prev = node;
    list->head = node;


}
void printLinkedList(LinkedList_t* list){
    Node_t* iter = list -> head;
    printf("HEAD -> ");
    while(iter!=NULL){
        printf("%d -> ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}

void printReverse(LinkedList_t* list){
    if(list->head == NULL){
        return;
    }
    Node_t* tail = list->head;
    
    while(tail!=NULL && tail->next != NULL  ){
        tail = tail -> next;
    }
    printf(" print reverse function %d \n", tail->data);
    Node_t* iter = tail;
    printf("TAIL -> ");
    while(iter != NULL){
        printf("%d -> ", iter->data);
        iter = iter->prev;
    }
    printf("\n");
}


void reverseLinkedList(LinkedList_t* list){

    if(list->head == NULL){
        return;
    }

    Node_t* iter = list->head;

    while(iter->next!=NULL){
        iter = iter->next;
    }
    // iter is now the tail of the linkedList
    printf(" reverse linked list function: %d \n", iter->data);
    //Node_t* tail = iter;
    list->head = iter;
    // essentially interchanging prev and next pointers but using a teporary node to store intermediatary node so its not overwritten during the interchange
    while(iter!=NULL){
        /* Node_t* temp = iter->next;
        iter->next = iter->prev;
        iter->prev = temp;
        iter = iter->next; */
        // Another way to do it :)
        Node_t* temp = iter->prev;
        iter->prev = iter->next;
        iter->next = temp;
        iter= iter->next;  
    }
    

}


int main(){
    LinkedList_t* list1 = createEmptyList();
    for(int i = 0; i<10; i++){
        addAtHead(list1, createNode(i));
    }
    printLinkedList(list1);
    printReverse(list1);
    reverseLinkedList(list1);
    printLinkedList(list1);
    return 0;
}