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
Node* createtree(){
    int data;
    cin>>data;

    if(data == -1) return NULL;

    Node* root = new Node(data);
    cout<<"Enter the data for the left of node "<<data<<" : ";
    root->left = createtree();
    cout<<"Enter the data for the right of node "<<data<<" : ";
    root->right = createtree();

    return root;
}
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
int main(){
    cout<<"Enter the data for the left of node  : ";
    Node* root = createtree();
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
// 5 10 15 -1 -1 20 -1 -1 30 40 -1 -1 50 -1 -1 