#include <stdio.h>
#include <stdlib.h>

struct Node{
    int angka;
    int flag;
    Node *next;
}*head, *tail;

Node *createNode(int angka){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->angka = angka;
    newNode->flag = 0;
    newNode->next = NULL;
    return newNode;
}

void Cycle(){
    int cycle = 0;
    Node *curr = head;
    while(curr != NULL){
        if(curr->flag == 0){
            curr->flag = 1;
            curr = curr->next;
        }else if(curr->flag == 1){
            printf("Cycle Found\n");
            cycle = 1;
            break;
        }
    }
    if(cycle == 0){
        printf("Cycle Not Found\n");
    }
    
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

int main(){
    //Cycle Found
    pushTail(2);
    pushTail(4);
    pushTail(6);
    tail->next = head;

    //Cycle Not Found
    // pushTail(2);
    // pushTail(4);
    // pushTail(6);

    Cycle();

    return 0;
}