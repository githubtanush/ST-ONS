#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void createll(Node*& head,Node*& tail,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}
void printll(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int getlen(Node*& head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
Node* midd(Node*& head){
    int len = getlen(head);

    //Step1 - find the length of node till mid
    int pos = len / 2 + 1;
    //Step2 - Take currpos which initiate from 1
    int currpos = 1;
    //Step 3 - ek new node bnayenge temp ki jo iterate kregi
    Node* temp = head;
    //Step 4 - mein tab tak iterate krunga jab tak currpos pos ke brabar na ho jay
    while(currpos != pos){
        currpos++;
        temp = temp->next;
    }
    return temp;
}
// Node* middlenode(Node*& head){
    //Method 1 - slow and fast pointer
    // Node* slow = head;
    // Node* fast = head;
    // while(fast != NULL && fast->next != NULL){
    //     fast = fast->next->next;
    //     slow = slow->next;
    // }
    // return slow;
// }
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    createll(head,tail,82);
    createll(head,tail,822);
    createll(head,tail,983);
    createll(head,tail,87);
    createll(head,tail,894);
    createll(head,tail,232);

    printll(head);

    cout<<endl<<"MiddleNode of the linkedList is : "<<midd(head)->data<<endl;

    return 0;
}