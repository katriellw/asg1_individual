#include <stdio.h>
#include <stdlib.h>

struct Node{
    int angka;
    int index;
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
int CountIndex(){
    int x = 1;
    Node *curr = head;
    while(curr->next != NULL){
        curr->index = x;
        x++;
        curr = curr->next;
    }
    return x;
}

void FindMid(int mid){
    Node *curr = head;;
    while(curr != NULL){
        if(curr->index == mid){
            printf("Mid: %d (Node %d)\n", curr->angka, mid);
            break;
        }
        curr = curr->next;
    }
    return;
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

    int totalIndex = CountIndex();
    int mid;

    mid = (totalIndex/2)+1;
    FindMid(mid);

    return 0;
}