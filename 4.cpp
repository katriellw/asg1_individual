#include <stdio.h>
#include <stdlib.h>

struct Node{
    int angka;
    Node *next;
}*head, *tail;

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

void printNode(Node *head){

    while(head != NULL){
        printf("%d ", head->angka);
        head = head->next;
    }
    printf("\n");
}

void removeDuplicates(){
    Node *curr = head;
    Node *next2;
    while(curr->next != NULL){
        if(curr->angka == curr->next->angka){
            next2 = curr->next->next;
            free(curr->next);
            curr->next = next2;
        }else{
            curr = curr->next;
        }
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
    
    printf("Sorted Linked List (With Duplicates):\n");
    printNode(head);

    printf("Linked List (Duplicates Removed):\n");
    removeDuplicates();
    printNode(head);

    return 0;
}