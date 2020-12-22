#include <stdio.h>
#include <stdlib.h>

struct Node{
    int angka;
    Node *next;
};

Node *createNode(int angka){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->angka = angka;
    newNode->next = NULL;
    return newNode;
}

void pushTail(Node **head, Node **tail, int angka){
    Node *temp = createNode(angka);
    if(!*head){
        *head = *tail = temp;
    }else{
        (*tail)->next = temp;
        *tail = temp;
    }
}

Node *mergeNode(Node *head1, Node *head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    if(head1->angka < head2->angka){
        head1->next = mergeNode(head1->next, head2);
        return head1;
    }else{ 
        head2->next = mergeNode(head1, head2->next);
        return head2;
    }
}

void printNode(Node *merge){

    while(merge != NULL){
        printf("%d ", merge->angka);
        merge = merge->next;
    }
    printf("\n");
}


int main(){

    Node *head1 = NULL;
    Node *tail1 = NULL;
    int T, i, N;
    printf("Enter number of nodes (L1): ");
    scanf("%d", &T);
    printf("Enter %d numbers: \n", T);
    for(i = 1; i<=T; i++){
        scanf("%d", &N);
        pushTail(&head1, &tail1, N);
    }

    Node *head2 = NULL;
    Node *tail2 = NULL;
    printf("Enter number of nodes (L2): ");
    scanf("%d", &T);
    printf("Enter %d numbers: \n", T);
    for(i = 1; i<=T; i++){
        scanf("%d", &N);
        pushTail(&head2, &tail2, N);
    }

    printf("Linked List L1:\n");
    printNode(head1);
    printf("Linked List L2:\n");
    printNode(head2);

    Node *merged = mergeNode(head1, head2);

    printf("One Sorted Linked List (Merged):\n");
    printNode(merged);

    return 0;
}