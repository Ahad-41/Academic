#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node{
    int data;
    node *next;
};

// create a new node
node *createNode(int value, node *nextNode) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = value;
    newNode->next = nextNode;
    return newNode; 
}

// append node in begininig of the list
node *prepend(node *head, int value) {
    node *newNode = createNode(value, head);
    return newNode;
}

// insert a node in the list
void insert(node *afterThisNode, int value) {
    node *newNode = createNode(value, afterThisNode->next);
    afterThisNode->next = newNode;
}

// append node in end of the list
node *append(node *head, int value) {
    node *newNode = createNode(value, NULL);
    if (head == NULL) return newNode;
    
    node *currNode = head;
    while (currNode->next != NULL) currNode = currNode->next;
    currNode->next = newNode;

    return head;
}

// remove a node from list
node *removeNode(node *head, node *removeThisNode) {
    if (removeThisNode == head) {
        head = removeThisNode->next;
        free(removeThisNode);
        return head;
    }

    node *currNode = head;
    while (currNode != NULL) {
        if (currNode->next == removeThisNode) break;
        currNode = currNode->next;
    }

    if (currNode == NULL) return head;
    
    currNode->next = removeThisNode->next;
    free(removeThisNode);
    return head;
}

// reverse a linked list with loop
node *reverseLinkedList(node *head) {
    node *prevNode = NULL, *currNode = head, *nextNode = NULL;
    while (currNode != NULL) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    } 
    return prevNode;
}

// reverse a linked list with recursion
node *reverseLinkedListWithRecursion(node *head) {
    if (head == NULL || head->next == NULL) return head;

    node *newHead = reverseLinkedListWithRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// print all element of the linked list
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
    // Linked List ->
}