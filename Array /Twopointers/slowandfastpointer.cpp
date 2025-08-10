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
Node* cycledetection(Node*& head){
    bool flag = 0;
    //Method 1 - The hashset method 
    // //Step1 - creating the hashset for checking that the node is present or not in the linked list
    // unordered_set<Node*> store;
    // //Step 2 - for traversing on the list we need to create one dummy temp pointer
    // Node* temp = head;
    // //Step 3 - starting the traversing
    // while(temp != NULL){
        
    //     if(store.find(temp) != store.end()){
    //         return true;
    //     }

    //     store.insert(temp);

    //     temp = temp->next;
    // }
    // return false;

    //Method 2 - The main Method or the Two pointers algorithm called Floyd tortoise algorithm
    // Node* fast = head;
    // Node* slow = head;

    // while(fast != NULL && fast->next != NULL){
    //         fast = fast->next->next;
    //         slow = slow->next;

    //     if(fast == slow){
    //         flag = 1;
    //         break; //means cycle founded
    //     }
    // }
    // if(flag == 0) return NULL;

    // //Means cycle to hai ab hm chle uska starting point dhundne
    // slow = head;
    // while(slow != fast){
    //     slow = slow->next;
    //     fast = fast->next;
    // }
    // return slow;

    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

        if(fast == slow){
            //Means cycle to hai ab hm chle uska starting point dhundne
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
        return slow;
        }
    }
   return NULL;

}
int main(){
   Node* head = NULL;
   Node* tail = NULL;
   Node* first = new Node(10);
   Node* second = new Node(20);
   Node* third = new Node(30);
   Node* fourth = new Node(40);
   Node* fifth = new Node(50);
//    Node* sixth = new Node(10);

   head = first;
   first->next = second;
   second->next = third;
   third->next = fourth;
   fourth->next = fifth;
   fifth->next = first;
   tail = fifth;
   
   
//    printll(head);
   cout<<endl;
   if(cycledetection(head)) cout<<"Cycle is present inside this.."<<endl;
   else cout<<"Cycle is not present inside this.."<<endl;
    return 0;
}