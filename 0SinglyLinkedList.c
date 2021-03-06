#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head;

void createList(int n){
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
        printf("Unable to allocate memory.");
    else{
        printf("Input data for node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;
        for(i=2; i<=n; i++){
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL){
                printf("Unable to allocate memory.");
                break;
            }
            else{
                printf("Input data for node %d: ", i);
                scanf("%d", &data);
                newNode->data = data;
                newNode->next = NULL;
                temp->next = newNode;
                temp = temp->next;
            }
        }
    }
}

void deleteFirstNode(){
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

void displayList(){
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