#include <iostream>
using namespace std;

class Node {
public:
    int data;   // data of the node
    Node* next; // address of the next node

    Node(){
        data = 0;
        next = nullptr;
    }
    explicit Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class Linkedlist {
    Node* head;

public:
    Linkedlist() { head = nullptr;}
    void insertNode(int);
    void printList();

    [[maybe_unused]] void deleteNode(int);
};

void Linkedlist::insertNode(int data){  // function to insert node in the list
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {

        temp = temp->next;
    }

    temp->next = newNode;
}

void Linkedlist::printList(){   // function to display the list
    Node* temp = head;

    if (head == nullptr) {
        cout << "List empty" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << "Data = " << temp->data << " \n";
        temp = temp->next;
    }
}

[[maybe_unused]] void Linkedlist::deleteNode(int) { // function to delete node
}

// driver code
int main(){
    Linkedlist list;
    int n;
    cout<< "Input the number of nodes:  ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cout<< "Input data for node " << i<< " :  " ;
        cin>>x;
        list.insertNode(x);
    }

    cout << "\nData entered in the list are : \n";

    list.printList();
    cout << endl;

    int temp;
    cout<<"Input data to insert at the end of the list :  ";
    cin>>temp;
    list.insertNode(temp);

    cout << "\nData, after inserted in the list are : \n";
    list.printList();
    cout << endl;

    return 0;
}