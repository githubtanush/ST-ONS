#include<iostream>
#include<vector>
#include<unordered_set>
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
    //Step 1 - create the linked list
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

Node* getintersection(Node*& head1,Node*& head2){
    //Method 1 - Basic Brute method is that we take head1 node of first linked list  and 
    //then travel to head2 of the second linked list and then simply check is that present in the 
    //list or not if it is not present then we return NULL else we return the node 
    //Time complexity - O(M*N)
    //Space complexity - O(1)
    // Node* temp1 = head1;
    // while(temp1 != NULL){
    //     Node* temp2 = head2;
    //     while(temp2 != NULL){
    //     if(temp1 == temp2) return temp1;
    //     temp2 = temp2->next;
    //     }
    //     temp1 = temp1->next;
    // }
    // return NULL;


    //Method 2 - 1.) Hashset bnata hu acha kaam ho jayga
    //Time complexity - O(M+N)
    //Space complexity - O(M)
    // unordered_set<Node*> store;
    // Node* temp1 = head1;
    // while(temp1 != NULL){
    //     store.insert(temp1);
    //     temp1 = temp1->next;
    // }
    // Node* temp2 = head2;
    // while(temp2 != NULL){
    //     if(store.find(temp2) != store.end()) return temp2;
    //     temp2 = temp2->next;
    // }
    // return NULL;
    //Very good for time complexity but for space complexity this is bad..


    //Method3 - Two pointers chlata hu wait
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != temp2){

        temp1 = (temp1 == NULL) ? head2 : temp1->next;
        temp2 = (temp2 == NULL) ? head1 : temp2->next;
    }
    return temp1;

}

int main(){
   Node* head1 = NULL;
   Node* head2 = NULL;
   Node* tail2 = NULL;
   Node* tail1 = NULL;

   createll(head1,tail1,981);
   createll(head1,tail1,894);
   createll(head1,tail1,83);
   createll(head1,tail1,893);
   createll(head1,tail1,298);

   createll(head2,tail2,981);
   createll(head2,tail2,894);
   createll(head2,tail2,83);
   createll(head2,tail2,289);
   createll(head2,tail2,98);
   createll(head2,tail2,228);

   printll(head1);
   cout<<endl;
   printll(head2);
   cout<<endl;

   if (getintersection(head1,head2) != NULL) {
    cout << "The meeting point is : " << getintersection(head1,head2)->data << endl;
} else {
    cout << "The lists do not intersect." << endl;
}
    return 0;
}