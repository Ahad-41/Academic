#include <stdio.h>
#include <stdlib.h>
typedef struct Node node;

struct Node{
    int data;
    node *prev, *next;
};

node *createNode(int value, node *next, node *prev) {
    node *newNode = (node*) malloc(sizeof(node));
    
    newNode->data = value;
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
}

node *prepend(node *head, int value) {
    node *newNode = createNode(value, head, NULL);
    newNode->next->prev = newNode;
    return newNode;
}

node *append(node *head, int value) {
    node *newNode = createNode(value, NULL, NULL);
    if (head == NULL) return newNode;

    node *currNode = head;
    while (currNode->next != NULL) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
    newNode->prev = currNode;

    return head;
}

void insert(node *afterThisNode, int value) {
    node *newNode = createNode(value, afterThisNode->next, afterThisNode);
    afterThisNode->next->prev = newNode;
    afterThisNode->next = newNode;
}

node *removeNode(node *head, node *removeThisNode) {
    if (removeThisNode == head) {
        head = removeThisNode->next;
        head->prev = NULL;
        free(removeThisNode);
        return head;
    }

    node *previousNode = removeThisNode->prev;
    node *nextNode = removeThisNode->next;

    previousNode->next = nextNode;
    nextNode->prev = previousNode; 
    free(removeThisNode);
    return head;
}

void printLinkedList(node *head) {
    node *currNode = head;
    while (currNode != NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main()
{
    node *head;
    head = createNode(10, NULL, NULL);
    printLinkedList(head);

    head = prepend(head, 100);
    printLinkedList(head);

    head = append(head, 50);
    printLinkedList(head);

    insert(head, 200);
    printLinkedList(head);

    head = removeNode(head, head);
    printLinkedList(head); 
}