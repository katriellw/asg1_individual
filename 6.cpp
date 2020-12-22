#include <stdio.h>
#include <stdlib.h>

struct Node{
    int angka;
    Node *next;
}*head, *tail, *headReversed, *tailReversed;

Node *createNode(int angka){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->angka = angka;
    newNode->next = NULL;
    return newNode;
}

void pushTail(int angka){
    Node *temp = createNode(angka);
    if(!head){
        head = tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

void pushTailNew(int angka){
    Node *temp = createNode(angka);
    if(!headReversed){
        headReversed = tailReversed = temp;
    }else{
        tailReversed->next = temp;
        tailReversed = temp;
    }
}

void printNode(Node *head){

    while(head != NULL){
        printf("%d ", head->angka);
        head = head->next;
    }
    printf("\n");
}

void Reverse(Node *head){
    if(head == NULL){
        return;
    }else{
        Reverse(head->next);
        pushTailNew(head->angka);
    }
}


int main(){
    int T, i, N;
    printf("Enter number of nodes: ");
    scanf("%d", &T);
    printf("Enter %d numbers: \n", T);
    for(i = 1; i<=T; i++){
        scanf("%d", &N);
        pushTail(N);
    }
    Reverse(head);

    printf("Linked List (Ascending):\n");
    printNode(head);

    printf("Linked List (Descending):\n");
    printNode(headReversed);
    
    return 0;
}