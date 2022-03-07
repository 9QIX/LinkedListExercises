#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;               // data of the node
    struct node *next;      // address of the next node
}*head;

void createList(int n){     // function to create the list
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)    // check whether the head is NULL and if so no memory allocation
        printf("Unable to allocate memory.");
    else{   // reads data for the node through keyboard
        printf("Input data for node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;      // links the address field to NULL
        temp = head;
        for(i=2; i<=n; i++){    // Creating n nodes and adding to linked list
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL){
                printf("Unable to allocate memory.");
                break;
            }
            else{
                printf("Input data for node %d: ", i);
                scanf("%d", &data);
                newNode->data = data;   // links the num field of newNode with data
                newNode->next = NULL;   // links the address field of newNode with NULL

                temp->next = newNode;   // links previous node
                temp = temp->next;
            }
        }
    }
}

void deleteFirstNode(){ // function to delete first node
    struct node *toDelete;

    if(head == NULL)
        printf("List is already empty.");
    else{
        toDelete = head;
        head = head->next;
        printf("\nData of node 1 which is being deleted is : %d\n", toDelete->data);
        free(toDelete);
    }
}

void displayList(){ // function to display the list
    struct node *temp;
    if(head == NULL)
        printf("List is empty.");
    else{
        temp = head;
        while(temp != NULL){
            printf("Data = %d\n", temp->data);
            temp = temp->next;
        }
    }
}

// driver code
int main(){
    int n;
    printf("Input the number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData entered in the list are : \n");
    displayList();

    deleteFirstNode();

    printf("\nData, after deletion of first node :\n");
    displayList();

    return 0;
}