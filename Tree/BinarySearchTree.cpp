#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:     
        int data;
        Node* left;
        Node* right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node*& root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<front->data<<" ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }

}
void preOrderTraversal(Node*& root){
    if( !root ) return ;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(Node*& root){
    if( !root ) return ;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node*& root){
    if( !root ) return ;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
Node* insertIntoBst(Node*& root,int data){
    //Base case
    if( !root ) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) insertIntoBst(root->right,data);
    if(data < root->data) insertIntoBst(root->left,data);

    return root;
}
void createBST(Node*& root){
    int data;
    cout<<"Enter the data : ";
    cin>>data;

    while(data != -1){
        root = insertIntoBst(root,data);
        cin>>data;
    }
}
int main(){
    cout<<"Enter the data for the left of node  : ";
    Node* root = NULL;
    createBST(root);
cout<<endl<<endl;
cout<<"Level Order Traversal for the tree is : "<<endl;
    levelOrderTraversal(root);
cout<<"preOrder Traversal for the tree is : ";
    preOrderTraversal(root);
cout<<endl<<"inOrder Traversal for the tree is : ";
    inOrderTraversal(root);
cout<<endl<<"postOrder Traversal for the tree is : ";
    postOrderTraversal(root);
    return 0;
}
// 5 10 15 40 20 30 50 -1