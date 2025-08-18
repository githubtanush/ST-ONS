#include<iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node* next;
        Node* prev;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insertathead(Node*& head,Node*& tail,int data){
    //Step 1 - create the new Node
    Node* newNode = new Node(data);
    
    //Check two conditions that node is null or only a single node is present there
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        //if there are a single node or more node
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertattail(Node*& head,Node*& tail,int data){
    //Step 1 - create the new Node
    Node* newNode = new Node(data);
    
    //Check two conditions that node is null or only a single node is present there
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        //if there are a single node or more node
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void printll(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int getlength(Node*& head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertatanypoint(Node*& head,Node*& tail,int data,int pos){
    int len = getlength(head);
    if(pos == 1) insertathead(head,tail,data);
    else if(pos >= len) insertattail(head,tail,data);
    else{
        Node* newNode = new Node(data);
        // Node* temp = head;
        // while(pos > 2){
        //     pos--;
        //     temp = temp->next;
        // }
        // newNode->next = temp->next;
        // temp->next = newNode;


        //With three pointers
        Node* previ = NULL;
        Node* curr = head;
        while(pos > 1){
            pos--;
            previ = curr;
            curr = curr->next;
        }
        newNode->next = curr;
        curr->prev = newNode;
        previ->next = newNode;
        newNode->prev = previ;
    }
}
void deletell(Node*& head,Node*& tail,int pos){
    int len = getlength(head);
    if(head == NULL){
        cout<<"cannot delete !! Linkedlist is not created";
        return ;
    }
    if(pos > len) {
        cout<<"Invalid position ! because your linked list is smaller than this!!1";
        return ;
    }
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return ;
    }
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if(pos == len){
        // Node* temp = head;
        // while(temp->next != tail){
        //     temp = temp->next;
        // }
        // temp->next = NULL;
        // delete tail;
        // tail = temp;

        //This is the benefit of dll
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }   
    else{
        Node* previ = NULL;
        Node* curr = head;
        while(pos > 1){
            pos--;
            previ = curr;
            curr = curr->next;
        }
        previ->next = curr->next;
        curr->next->prev = previ;
        curr->next = NULL;
        delete curr;
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,98);
    insertathead(head,tail,893);
    insertathead(head,tail,278);
    insertathead(head,tail,10);
    insertathead(head,tail,23);
    insertattail(head,tail,2398);
    insertatanypoint(head,tail,2389,4);
    insertatanypoint(head,tail,29,4);
    deletell(head,tail,0);
    // deletell(head,tail,3);
    deletell(head,tail,7);
    printll(head);
    cout<<endl<<"Length of the Linked List is : "<<getlength(head)<<endl;
    return 0;
}