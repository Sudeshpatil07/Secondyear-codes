#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class node
{
    public:
        int data;
        int bal;
        node *left;
        node *right;


};
class Tree
{
    public:
        int ht;
        node *insert(node*,node*);
        node *rotateRight(node*);
        node *rotateLeft(node*);
        void inorder(node *);
        void height(node* ,int );
        node *balFactor(node*);
};
node *Tree ::balFactor(node *root)
{
    ht=0;
    height(root->left,0);
    int LH = ht;
    ht=0;
    height(root->right,0);
    int RH = ht;
    root->bal =LH-RH;
    return root;
}
void Tree ::height(node *root,int level)
{
    if(root)
    {
        if(ht<=level)
            ht=level+1;
        height(root->left,level+1);
        height(root->right,level+1);
    }
}
void Tree ::inorder(node* root)
{
    int i;
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" "<<root->bal<<endl;
        inorder(root->right);
    }
}
node *Tree::insert(node* root,node* s)
{
    if(s->data>root->data)
    {
        if(root->right ==NULL)
            root->right = s;
        else
            root->right = insert(root->right,s);
    }
    if(s->data<=root->data)
    {
        if(root->left ==NULL)
            root->left = s;
        else    root->left = insert(root->left,s);
    }
    root = balFactor(root);
    if(root->bal==2 && root->left->bal == 1)
        root = rotateRight(root);
    if(root->bal == -2 && root->right->bal == -1)
        root = rotateLeft(root);
    if(root->bal == 2 && root->left->bal == -1)
    {
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    }
    if(root->bal == -2 && root->right->bal ==1)
    {
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    root = balFactor(root);
    return root;
}
node *Tree :: rotateRight(node *root)
{
    node *temp;
    temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = balFactor(root);
    return temp;
}
node *Tree :: rotateLeft(node *root)
{
    node *temp;
    temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = balFactor(root);
    return temp;
}
int main()
{
    int ch,c;
    char temp;
    node *root,*s;
    Tree t;
    root = new node();
    root = NULL;
    do
    {
        s = new node();
        s->bal=0;
        s->left=NULL;
        s->right=NULL;
        cout<<"\n"<<"Enter node of a tree ::";
        cin>>s->data;
        if(root==NULL)
            root=s;
        else    
            root=t.insert(root,s);
        cout<<"\n\nInorder sequence of the tree is :\n\n";
        t.inorder(root);
        cout<<"\n\nWant to enter more nodes(y/n)";
        cin>>temp;
    }while(temp=='y');
    cout<<endl;
    return 0;


}