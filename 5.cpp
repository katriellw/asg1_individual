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

int CountIndex(){
    int x = 1;
    Node *curr = head;
    while(curr->next != NULL){
        x++;
        curr = curr->next;
    }
    return x;
}

void FindIndex(int num){
    int x = 1;
    Node *curr = head;
    while(curr){
        if(x == num){
            printf("%d\n", curr->angka);
        }
        x++;
        curr = curr->next;
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

    int indexCount = CountIndex();

    printf("Input a number: ");
    int num;
    scanf("%d", &num);
    int nodeIndex = (indexCount-num)+1;
    if(num == 1){
        printf("1st node from the end of the linked list:\n");
    }else if(num == 2){
        printf("2nd node from the end of the linked list:\n");
    }else{
        printf("%dth node from the end of the linked list:\n", num);
    }

    FindIndex(nodeIndex);


    return 0;
}